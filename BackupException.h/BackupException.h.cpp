#ifndef BACKUPEXCEPTION_H
#define BACKUPEXCEPTION_H

#include <stdexcept>
#include <string>

class BackupException : public std::runtime_error {
public:
    BackupException(const std::string& message) : std::runtime_error(message) {}
};

class FileNotFoundException : public BackupException {
public:
    FileNotFoundException(const std::string& filename) : BackupException("File not found: " + filename) {}
};

class ObjectNotFoundException : public BackupException {
public:
    ObjectNotFoundException(const std::string& objectName) : BackupException("Object not found: " + objectName) {}
};

class FileOpenException : public BackupException {
public:
    FileOpenException(const std::string& filename) : BackupException("Could not open file: " + filename) {}
};

class CouldNotSaveFile : public BackupException {
public:
    CouldNotSaveFile(const std::string& filename) : BackupException("Could not save file: " + filename) {}
};

#endif
