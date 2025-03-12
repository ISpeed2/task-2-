#include "BackupObject.h"

BackupObject::BackupObject(const std::string& path) : path(path) {}

std::string BackupObject::getPath() const {
    return path;
}
