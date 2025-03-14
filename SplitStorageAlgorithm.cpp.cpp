#include "SplitStorageAlgorithm.h"
#include <sstream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "Exceptions/BackupException.h"
#include "Utils/FileUtils.h"

RestorePoint SplitStorageAlgorithm::createRestorePoint(const std::vector<BackupObject>& objects, Storage* storage) {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    std::stringstream ss;
    ss << "backup_" << std::put_time(ltm, "%Y%m%d%H%M%S");
    std::string restorePointDirName = ss.str();

    // Create the restore point directory inside the storage location
    std::string restorePointPath = storage->save("", restorePointDirName); // Pass an empty string to create a directory

    std::vector<std::string> filesInRestorePoint; // Create a list to store the filenames

    for (const auto& object : objects) {
        std::ifstream inputFile(object.getPath(), std::ios::binary);
        if (!inputFile.is_open()) {
            throw FileOpenException(object.getPath());
        }

        std::stringstream buffer;
        buffer << inputFile.rdbuf();
        std::string fileContent = buffer.str();
        inputFile.close();

        // Save each file into its own directory inside the restore point directory
        std::string objectFileName = FileUtils::getFileName(object.getPath());
        std::string objectDirectoryPath = storage->save(fileContent, restorePointPath + "/" + objectFileName); // Pass an directory with filename
        if (objectDirectoryPath.empty()) {
            throw CouldNotSaveFile(restorePointPath + "/" + objectFileName);
        }
        filesInRestorePoint.push_back(objectFileName); // Add the filename to the list
    }

    return RestorePoint(now, restorePointPath, filesInRestorePoint); // Pass the list to the constructor
}
