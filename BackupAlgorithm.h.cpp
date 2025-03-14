#ifndef BACKUPALGORITHM_H
#define BACKUPALGORITHM_H

#include <vector>
#include "RestorePoint/RestorePoint.h"
#include "Storage/Storage.h"
#include "BackupObject/BackupObject.h"

class BackupAlgorithm {
public:
    virtual ~BackupAlgorithm() = default;
    virtual RestorePoint createRestorePoint(const std::vector<BackupObject>& objects, Storage* storage) = 0;
};

#endif