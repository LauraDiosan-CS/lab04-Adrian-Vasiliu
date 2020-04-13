#pragma once
#include "MapRepository.h"

class FileRepository : public MapRepository {
 private:
    const char *file;;
 public:
    FileRepository();
    explicit FileRepository(const char *);
    ~FileRepository();
    void read_file(const char *);
    void write_file();
};
