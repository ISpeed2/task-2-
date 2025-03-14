#include "SingleStorageAlgorithm.h"
#include <sstream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "Exceptions/BackupException.h"
#include "Utils/FileUtils.h"

RestorePoint SingleStorageAlgorithm::createRestorePoint(const std::vector<BackupObject>& objects, Storage* storage) {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    std::stringstream ss;
    ss << "backup_" << std::put_time(ltm, "%Y%m%d%H%M%S");
    std::string restorePointFileName = ss.str();
    std::string restorePointPath = storage->save("", restorePointFileName);

    std::stringstream combinedContent;
    for (const auto& object : objects) {
        std::ifstream inputFile(object.getPath(), std::ios::binary);
        if (!inputFile.is_open()) {
            throw FileOpenException(object.getPath());
        }

        std::stringstream buffer;
        buffer << inputFile.rdbuf();
        std::string fileContent = buffer.str();
        inputFile.close();

        combinedContent << fileContent; // Append file content to the combined content
    }

    storage->save(combinedContent.str(), restorePointFileName);

    return RestorePoint(now, restorePointPath, {});
}
