#include "RestorePoint.h"

RestorePoint::RestorePoint(time_t timestamp, const std::string& location)
    : timestamp(timestamp), location(location) {}

time_t RestorePoint::getTimestamp() const {
    return timestamp;
}

std::string RestorePoint::getLocation() const {
    return location;
}
