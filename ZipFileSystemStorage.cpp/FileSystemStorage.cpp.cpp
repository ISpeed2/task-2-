#include "ZipFileSystemStorage.h"
#include <fstream>
#include <sstream>
#include "Exceptions/BackupException.h"
#include "Utils/FileUtils.h"
#include <iostream>
#include <zip.h>

ZipFileSystemStorage::ZipFileSystemStorage(const std::string& baseDirectory) : baseDirectory(baseDirectory) {
    // Ensure the base directory exists
    if (!FileUtils::directoryExists(baseDirectory)) {
        if (!FileUtils::createDirectory(baseDirectory)) {
            throw CouldNotSaveFile("Could not create base directory: " + baseDirectory);
        }
    }
}

std::string ZipFileSystemStorage::save(const std::string& data, const std::string& objectName) {
    std::string fullPath;
    if (objectName.empty()) {
        fullPath = baseDirectory;
    }
    else {
        fullPath = baseDirectory + "/" + objectName + ".zip"; // Store as ZIP file
    }

    // Create ZIP archive
    int errorp = 0;
    zip_t* zipFile = zip_open(fullPath.c_str(), ZIP_CREATE | ZIP_TRUNCATE, &errorp);

    if (zipFile == NULL) {
        char buf[100];
        zip_error_to_str(buf, sizeof(buf), errorp, errno);
        std::cerr << "error creating zipfile: " << buf << "\n";
        throw CouldNotSaveFile("Could not create zip archive: " + fullPath);
    }

    if (!data.empty()) {
        // Add data to ZIP archive
        zip_source_t* source = zip_source_buffer(zipFile, data.c_str(), data.length(), 0);
        if (source == NULL) {
            zip_close(zipFile);
            throw CouldNotSaveFile("Could not create zip source for: " + fullPath);
        }

        zip_int64_t index = zip_file_add(zipFile, objectName.c_str(), source, ZIP_FL_OVERWRITE);
        if (index < 0) {
            zip_source_free(source);
            zip_close(zipFile);
            throw CouldNotSaveFile("Could not add file to zip archive: " + fullPath);
        }

        zip_source_keep(source); // Important: Keep the source data for zip_close
    }

    // Close ZIP archive
    if (zip_close(zipFile) < 0) {
        throw CouldNotSaveFile("Could not close zip archive: " + fullPath);
    }

    return fullPath;
}