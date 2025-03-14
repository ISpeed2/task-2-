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
    // The objects are not stored.
    //objects.push_back(object);
}

void BackupJob::removeObject(const BackupObject& object) {
    // The objects are not stored.
    //for (size_t i = 0; i < objects.size(); ++i) {
    //    if (objects[i].getPath() == object.getPath()) {
    //        objects.erase(objects.begin() + i);
    //        return;
    //    }
    //}
    //throw ObjectNotFoundException(object.getPath());
}

RestorePoint BackupJob::createRestorePoint() {
    //Create list of Backup Objects to pass it to the Backup Algorithm.
    std::vector<BackupObject> objects;
    //Restore point is created, after creating the restore point, we add this restore point to the collection.
    RestorePoint restorePoint = algorithm->createRestorePoint(objects, storage);
    restorePoints.push_back(restorePoint);
    return restorePoint;
}

std::vector<RestorePoint> BackupJob::getRestorePoints() const {
    return restorePoints;
}

std::string BackupJob::getName() const {
    return name;
}
