#ifndef RESTOREPOINT_H
#define RESTOREPOINT_H

#include <ctime>
#include <string>
#include <vector> // Include for std::vector

class RestorePoint {
public:
    RestorePoint(time_t timestamp, const std::string& location, const std::vector<std::string>& files);
    time_t getTimestamp() const;
    std::string getLocation() const;
    std::vector<std::string> getFiles() const; // New method to get the list of files

private:
    time_t timestamp;
    std::string location; // Path to the backup directory/file
    std::vector<std::string> files; // List of files in the restore point
};

#endif