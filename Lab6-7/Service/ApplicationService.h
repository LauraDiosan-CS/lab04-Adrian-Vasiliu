#pragma once
#include "../Repository/FileRepository.h"

class ApplicationService {
 private:
    FileRepository repo;
    int RAM_max, RAM_free;
    void check_RAM();
    Application RAM_or_Swap(Application app);
 public:
    ApplicationService();
    explicit ApplicationService(const FileRepository &);
    ~ApplicationService();
    int get_position_of_application(const Application &);
    int add_application(char *, int, int);
    void delete_application(int);
    void update_application(int, char *, int, int);
    int get_size();
    map<int, Application> get_all();
    Application get_application_from_position(int position);
};
