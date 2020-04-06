#pragma once
#include "../Repository/FileRepository.h"

class ApplicationService {
 private:
    FileRepository repo;
 public:
    ApplicationService();
    explicit ApplicationService(const FileRepository &);
    ~ApplicationService();
    int get_position_of_application(const Application &);
    void add_application(char *, int, int);
    void delete_application(int);
    void update_application(int, char *, int, int);
    int get_size();
    vector<Application> get_all();
    Application get_application_from_position(int position);
};
