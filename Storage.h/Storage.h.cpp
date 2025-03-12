#ifndef STORAGE_H
#define STORAGE_H

#include <string>

class Storage {
public:
    virtual ~Storage() = default;
    virtual std::string save(const std::string& data, const std::string& objectName) = 0;
};

#endif#ifndef STORAGE_H
#define STORAGE_H

#include <string>

class Storage {
public:
    virtual ~Storage() = default;
    virtual std::string save(const std::string& data, const std::string& objectName) = 0;
};

#endif