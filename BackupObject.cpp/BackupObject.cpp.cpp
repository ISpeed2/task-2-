#include "BackupObject.h"
#include "Exceptions/BackupException.h" // Make sure to include it
#include <stdexcept>

BackupObject::BackupObject(const std::string& path) : path(path) {
    if (path.empty()) {
        throw std::invalid_argument("Path cannot be empty."); // Or use your custom exception
    }
}

std::string BackupObject::getPath() const {
    return path;
}