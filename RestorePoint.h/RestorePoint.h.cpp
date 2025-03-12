#ifndef RESTOREPOINT_H
#define RESTOREPOINT_H

#include <ctime>
#include <string>

class RestorePoint {
public:
    RestorePoint(time_t timestamp, const std::string& location);
    time_t getTimestamp() const;
    std::string getLocation() const;

private:
    time_t timestamp;
    std::string location; // Path to the backup directory/file
};

#endif