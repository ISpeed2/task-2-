#include <iostream>
#include "BackupJob/BackupJob.h"
#include "BackupObject/BackupObject.h"
#include "Storage/FileSystemStorage.h" // corrected path
#include "Storage/ZipFileSystemStorage.h" // corrected path
#include "BackupAlgorithm/SplitStorageAlgorithm.h" // corrected path
#include "BackupAlgorithm/SingleStorageAlgorithm.h" // corrected path
#include "Exceptions/BackupException.h"
#include "RestorePoint/RestorePoint.h" // corrected path - important

int main() {
    try {
        // Choose storage type:
        // 1 - FileSystemStorage
        // 2 - ZipFileSystemStorage
        int storageType;
        std::cout << "Choose storage type (1: FileSystemStorage, 2: ZipFileSystemStorage): ";
        std::cin >> storageType;

        Storage* storage = nullptr;
        if (storageType == 1) {
            storage = new FileSystemStorage("backup_repository");
        }
        else if (storageType == 2) {
            storage = new ZipFileSystemStorage("backup_repository");
        }
        else {
            std::cerr << "Invalid storage type." << std::endl;
            return 1;
        }

        // Choose backup algorithm:
        // 1 - SplitStorageAlgorithm
        // 2 - SingleStorageAlgorithm
        int algorithmType;
        std::cout << "Choose backup algorithm (1: SplitStorageAlgorithm, 2: SingleStorageAlgorithm): ";
        std::cin >> algorithmType;

        BackupAlgorithm* algorithm = nullptr;
        if (algorithmType == 1) {
            algorithm = new SplitStorageAlgorithm();
        }
        else if (algorithmType == 2) {
            algorithm = new SingleStorageAlgorithm();
        }
        else {
            std::cerr << "Invalid algorithm type." << std::endl;
            delete storage; // Clean up storage before exiting
            return 1;
        }

        // Create Backup Job
        BackupJob job("MyBackupJob", storage, algorithm);

        // Add Backup Objects
        BackupObject file1("data/file1.txt");
        BackupObject file2("data/file2.txt"); //This must exist

        job.addObject(file1);
        job.addObject(file2);

        // Create Restore Point
        RestorePoint restorePoint = job.createRestorePoint();

        std::cout << "Backup created at: " << restorePoint.getLocation() << std::endl;

    }
    catch (const BackupException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}