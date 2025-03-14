#include "RestorePoint.h"

RestorePoint::RestorePoint(time_t timestamp, const std::string& location, const std::vector<std::string>& files)
    : timestamp(timestamp), location(location), files(files) {}

time_t RestorePoint::getTimestamp() const {
    return timestamp;
}

std::string RestorePoint::getLocation() const {
    return location;
}

std::vector<std::string> RestorePoint::getFiles() const { // Implementation of the new method
    return files;
}