#ifndef SINGLESTORAGEALGORITHM_H
#define SINGLESTORAGEALGORITHM_H

#include "BackupAlgorithm/BackupAlgorithm.h"

class SingleStorageAlgorithm : public BackupAlgorithm {
public:
    RestorePoint createRestorePoint(const std::vector<BackupObject>& objects, Storage* storage) override;
};

#endif