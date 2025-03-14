cmake_minimum_required(VERSION 3.0)
project(backup_system)

set(CMAKE_CXX_STANDARD 17)

find_package(LibZip REQUIRED)
include_directories(${LIBZIP_INCLUDE_DIR})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/BackupJob
    ${CMAKE_CURRENT_SOURCE_DIR}/BackupObject
    ${CMAKE_CURRENT_SOURCE_DIR}/RestorePoint
    ${CMAKE_CURRENT_SOURCE_DIR}/Storage
    ${CMAKE_CURRENT_SOURCE_DIR}/BackupAlgorithm
    ${CMAKE_CURRENT_SOURCE_DIR}/Exceptions
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils
)

add_executable(backup_system main.cpp
    BackupJob/BackupJob.cpp
    BackupObject/BackupObject.cpp
    RestorePoint/RestorePoint.cpp
    Storage/FileSystemStorage.cpp
    Storage/ZipFileSystemStorage.cpp
    BackupAlgorithm/SplitStorageAlgorithm.cpp
    BackupAlgorithm/SingleStorageAlgorithm.cpp # Added SingleStorageAlgorithm
    Exceptions/BackupException.cpp
    Utils/FileUtils.cpp
)
target_link_libraries(backup_system ${LIBZIP_LIBRARIES})