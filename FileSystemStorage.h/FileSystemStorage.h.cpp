#ifndef FILESYSTEMSTORAGE_H
#define FILESYSTEMSTORAGE_H

#include "Storage.h"
#include <string>

class FileSystemStorage : public Storage {
public:
    FileSystemStorage(const std::string& baseDirectory);
    std::string save(const std::string& data, const std::string& objectName) override;

private:
    std::string baseDirectory;
};

#endif