#include <iostream>
#include "BackupJob/BackupJob.h"
#include "BackupObject/BackupObject.h"
#include "Storage/FileSystemStorage.h"
#include "BackupAlgorithm/SplitStorageAlgorithm.h"
#include "Exceptions/BackupException.h"

int main() {
    try {
        // 1. Define Storage
        FileSystemStorage* storage = new FileSystemStorage("backup_repository");

        // 2. Define Backup Algorithm
        SplitStorageAlgorithm* algorithm = new SplitStorageAlgorithm();

        // 3. Create Backup Job
        BackupJob job("MyBackupJob", storage, algorithm);

        // 4. Add Backup Objects
        BackupObject file1("data/file1.txt");
        BackupObject file2("data/file2.txt"); //This must exist

        job.addObject(file1);
        job.addObject(file2);

        // 5. Create Restore Point
        RestorePoint restorePoint = job.createRestorePoint();

        std::cout << "Backup created at: " << restorePoint.getLocation() << std::endl;
    }
    catch (const BackupException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
