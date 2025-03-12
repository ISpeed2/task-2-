#ifndef BACKUPOBJECT_H
#define BACKUPOBJECT_H

#include <string>
#include "Exceptions/BackupException.h" // Add this include
#include <stdexcept>

class BackupObject {
public:
    BackupObject(const std::string& path);
    std::string getPath() const;

private:
    std::string path;
};

#endif