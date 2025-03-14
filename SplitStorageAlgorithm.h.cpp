#ifndef SPLITSTORAGEALGORITHM_H
#define SPLITSTORAGEALGORITHM_H

#include "BackupAlgorithm/BackupAlgorithm.h"

class SplitStorageAlgorithm : public BackupAlgorithm {
public:
    RestorePoint createRestorePoint(const std::vector<BackupObject>& objects, Storage* storage) override;
};

#endif
