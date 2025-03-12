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

    std::string getName() const;

private:
    std::string name;
    std::vector<BackupObject> objects;
    Storage* storage;
    BackupAlgorithm* algorithm;
};

#endif
