/*
 * FS.h
 *
 *  Created on: 12 abr. 2020
 *      Author: Diego
 */

#ifndef MOCKLIBRARY_FS_H_
#define MOCKLIBRARY_FS_H_
#include <memory>
#include "string.h"

namespace fs {

class File;
class Dir;

class FileImpl;
typedef std::shared_ptr<FileImpl> FileImplPtr;
class FSImpl;
typedef std::shared_ptr<FSImpl> FSImplPtr;
class DirImpl;
typedef std::shared_ptr<DirImpl> DirImplPtr;

template <typename Tfs>
bool mount(Tfs& fs, const char* mountPoint);

enum SeekMode {
    SeekSet = 0,
    SeekCur = 1,
    SeekEnd = 2
};

class File
{
public:
    File(FileImplPtr p = FileImplPtr()) : _p(p) {}

    // Print methods:
    size_t write(uint8_t);
    size_t write(const uint8_t *buf, size_t size);

    // Stream methods:
    int available();
    int read();
    int peek();
    void flush();
    size_t readBytes(char *buffer, size_t length);
    size_t read(uint8_t* buf, size_t size);
    bool seek(uint32_t pos, SeekMode mode);
    bool seek(uint32_t pos) {
        return seek(pos, SeekSet);
    }
    size_t position() const;
    size_t size() const;
    void close();
    operator bool() const;
    const char* name() const;

protected:
    FileImplPtr _p;
};

class Dir {
public:
    Dir(DirImplPtr impl = DirImplPtr()): _impl(impl) { }

    File openFile(const char* mode);
    char* fileName();
    size_t fileSize();
    bool next();

protected:
    DirImplPtr _impl;
};

struct FSInfo {
    size_t totalBytes;
    size_t usedBytes;
    size_t blockSize;
    size_t pageSize;
    size_t maxOpenFiles;
    size_t maxPathLength;
};

class FS
{
public:
    FS(FSImplPtr impl) : _impl(impl) { }

    bool begin();
    void end();

    bool format();
    bool info(FSInfo& info);

    File open(const char* path, const char* mode);
    bool exists(const char* path);
    Dir openDir(const char* path);
    bool remove(const char* path);
    bool rename(const char* pathFrom, const char* pathTo);


protected:
    FSImplPtr _impl;
};

} // namespace fs

#ifndef FS_NO_GLOBALS
using fs::FS;
using fs::File;
using fs::Dir;
using fs::SeekMode;
using fs::SeekSet;
using fs::SeekCur;
using fs::SeekEnd;
using fs::FSInfo;
#endif //FS_NO_GLOBALS

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_SPIFFS)
extern fs::FS SPIFFS;
#endif


#endif /* MOCKLIBRARY_FS_H_ */
