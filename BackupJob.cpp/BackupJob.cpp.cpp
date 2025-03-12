#include "BackupJob.h"
#include "Exceptions/BackupException.h"
#include "Utils/FileUtils.h"

BackupJob::BackupJob(const std::string& name, Storage* storage, BackupAlgorithm* algorithm)
    : name(name), storage(storage), algorithm(algorithm) {}

BackupJob::~BackupJob() {
    delete storage;
    delete algorithm;
}

void BackupJob::addObject(const BackupObject& object) {
    if (!FileUtils::fileExists(object.getPath())) {
        throw FileNotFoundException(object.getPath());
    }
    objects.push_back(object);
}

void BackupJob::removeObject(const BackupObject& object) {
    for (size_t i = 0; i < objects.size(); ++i) {
        if (objects[i].getPath() == object.getPath()) {
            objects.erase(objects.begin() + i);
            return;
        }
    }
    throw ObjectNotFoundException(object.getPath());
}

RestorePoint BackupJob::createRestorePoint() {
    return algorithm->createRestorePoint(objects, storage);
}

std::string BackupJob::getName() const {
    return name;
}
