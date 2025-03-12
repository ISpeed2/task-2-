#ifndef BACKUPOBJECT_H
#define BACKUPOBJECT_H

#include <string>

class BackupObject {
public:
    BackupObject(const std::string& path);
    std::string getPath() const;

private:
    std::string path;
};

#endif
