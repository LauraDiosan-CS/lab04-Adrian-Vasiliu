#pragma once
#include "../Domain/Application.h"
#include <map>
using namespace std;

class MapRepository {
 protected:
    map<int, Application> apps;
 public:
    MapRepository();
    ~MapRepository();
    int get_position_of_application(const Application &);
    void add_application(const Application &);
    void delete_application(const Application &);
    void update_application(const Application &, char *, int, int);
    int get_size();
    map<int, Application> get_all();
    Application get_application_from_position(int);
};
