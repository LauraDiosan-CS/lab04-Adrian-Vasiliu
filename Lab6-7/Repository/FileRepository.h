#pragma once
#include "../Domain/Application.h"
#include <vector>
using namespace std;

class FileRepository {
 private:
    vector<Application> apps;
    const char *file;
 public:
    FileRepository();
    explicit FileRepository(const char *);
    ~FileRepository();
    void read_file(const char *);
    void write_file();
    int get_position_of_application(const Application &);
    void add_application(const Application &);
    void delete_application(const Application &);
    void update_application(const Application &, char *, int, int);
    int get_size();
    vector<Application> get_all();
    Application get_application_from_position(int);
};
