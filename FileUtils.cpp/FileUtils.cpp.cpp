#include "FileUtils.h"
#include <fstream>
#include <sys/stat.h>
#ifdef _WIN32
#include <direct.h>   // For _mkdir
#else
#include <unistd.h>  // For mkdir
#include <limits.h>
#endif

bool FileUtils::fileExists(const std::string& path) {
    std::ifstream file(path);
    return file.good();
}

bool FileUtils::directoryExists(const std::string& path) {
    struct stat info;
    if (stat(path.c_str(), &info) != 0) {
        return false;
    }
    return (info.st_mode & S_IFDIR) != 0;
}

bool FileUtils::createDirectory(const std::string& path) {
#ifdef _WIN32
    return _mkdir(path.c_str()) == 0;
#else
    return mkdir(path.c_str(), 0777) == 0;
#endif
}

std::string FileUtils::getFileName(const std::string& path) {
    size_t lastSlash = path.find_last_of("/\\");
    if (lastSlash == std::string::npos) {
        return path;
    }
    return path.substr(lastSlash + 1);
}