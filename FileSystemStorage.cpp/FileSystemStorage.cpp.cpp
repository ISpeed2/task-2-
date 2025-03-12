#include "FileSystemStorage.h"
#include <fstream>
#include <sstream>
#include <sys/stat.h> // For creating directories
#include <direct.h> // for _mkdir on Windows
#include "Exceptions/BackupException.h"

FileSystemStorage::FileSystemStorage(const std::string& baseDirectory) : baseDirectory(baseDirectory) {
    // Ensure the base directory exists
    if (!FileUtils::directoryExists(baseDirectory)) {
        if (!FileUtils::createDirectory(baseDirectory)) {
            throw CouldNotSaveFile("Could not create base directory: " + baseDirectory);
        }
    }
}

std::string FileSystemStorage::save(const std::string& data, const std::string& objectName) {
    std::string fullPath;
    if (objectName.empty()) {
        fullPath = baseDirectory;
    }
    else {
        fullPath = baseDirectory + "/" + objectName;
    }

    // Check if objectName contains a directory, if so create the directory
    size_t last_slash_pos = objectName.find_last_of("/");
    if (last_slash_pos != std::string::npos) {
        std::string directoryPath = baseDirectory + "/" + objectName.substr(0, last_slash_pos);
        if (!FileUtils::directoryExists(directoryPath)) {
            if (!FileUtils::createDirectory(directoryPath)) {
                throw CouldNotSaveFile("Could not create directory: " + directoryPath);
            }
        }
    }

    // Check if fullPath is a directory.  If so, just return fullPath.
    if (data.empty()) { // if no data we treat this like we just want the directory created
        if (!FileUtils::directoryExists(fullPath)) {
            if (!FileUtils::createDirectory(fullPath)) {
                throw CouldNotSaveFile("Could not create directory: " + fullPath);
            }
        }
        return fullPath;
    }

    std::ofstream outputFile(fullPath, std::ios::binary);
    if (!outputFile.is_open()) {
        throw CouldNotSaveFile("Could not open file for writing: " + fullPath);
    }

    outputFile << data;
    outputFile.close();

    return fullPath;
}