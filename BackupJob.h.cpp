#ifndef BACKUPJOB_H
#define BACKUPJOB_H

#include <vector>
#include <string>
#include "BackupObject/BackupObject.h"
#include "RestorePoint/RestorePoint.h"
#include "Storage/Storage.h"
#include "BackupAlgorithm/BackupAlgorithm.h"

class BackupJob {
public:
    BackupJob(const std::string& name, Storage* storage, BackupAlgorithm* algorithm);
    ~BackupJob();

    void addObject(const BackupObject& object);
    void removeObject(const BackupObject& object);
    RestorePoint createRestorePoint();
    std::vector<RestorePoint> getRestorePoints() const; // Add a method to get the list of RestorePoints

    std::string getName() const;

private:
    std::string name;
    std::vector<RestorePoint> restorePoints; // Change this from BackupObject to RestorePoint
    Storage* storage;
    BackupAlgorithm* algorithm;
};

#endif