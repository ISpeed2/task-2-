#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>

class FileUtils {
public:
    static bool fileExists(const std::string& path);
    static bool directoryExists(const std::string& path);
    static bool createDirectory(const std::string& path);
    static std::string getFileName(const std::string& path);
};

#endif
