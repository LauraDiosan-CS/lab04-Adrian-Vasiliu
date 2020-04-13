#include "MapRepository.h"
#include <algorithm>
using namespace std;

MapRepository::MapRepository() = default;

MapRepository::~MapRepository() = default;

int MapRepository::get_position_of_application(const Application &app) {
    for (int i = 0; i < apps.size(); i++)
        if (apps[i] == app)
            return i;
    return -1;
}

void MapRepository::add_application(const Application &app) {
    apps.insert(pair<int, Application>(apps.size(), app));
}

void MapRepository::delete_application(const Application &app) {
    int i = get_position_of_application(app);
    apps.erase(i);
    for (int j = i + 1; j < apps.size() + 1; j++) {
        pair<int, Application> p = pair<int, Application>(j - 1, apps[j]);
        apps.erase(j);
        apps.insert(p);
    }
}

void MapRepository::update_application(const Application &app, char *name, int memory_kb, int status) {
    int position = get_position_of_application(app);
    apps[position].set_name(name);
    apps[position].set_memory_kb(memory_kb);
    apps[position].set_status(status);
}

Application MapRepository::get_application_from_position(int position) {
    return apps[position];
}

map<int, Application> MapRepository::get_all() {
    return apps;
}

int MapRepository::get_size() {
    return apps.size();
}
