#ifndef ZIPFILESYSTEMSTORAGE_H
#define ZIPFILESYSTEMSTORAGE_H

#include "Storage.h"
#include <string>

class ZipFileSystemStorage : public Storage {
public:
    ZipFileSystemStorage(const std::string& baseDirectory);
    std::string save(const std::string& data, const std::string& objectName) override;

private:
    std::string baseDirectory;
};

#endif