#include "FileRepository.h"
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

FileRepository::FileRepository() {
    file = nullptr;
}

FileRepository::FileRepository(const char *file_name) {
    file = file_name;
    ifstream f(file);
    string line;
    char *name = new char[50];
    string status_string;
    int memory_kb, status = 0;
    while (f >> name >> memory_kb >> status_string) {
        if (status_string == "RAM")
            status = 1;
        else if (status_string == "Swap")
            status = 2;
        if (strcmp(name, "") != 0) {
            Application app(name, memory_kb, status);
            apps.push_back(app);
        }
    }
    delete[] name;
    f.close();
}

FileRepository::~FileRepository() {
    delete[] file;
}

void FileRepository::read_file(const char *file_name) {
    apps.clear();
    file = file_name;
    ifstream f(file);
    char *name = new char[50];
    string status_string;
    int memory_kb, status = 0;
    while (f >> name >> memory_kb >> status_string) {
        if (status_string == "RAM")
            status = 1;
        else if (status_string == "Swap")
            status = 2;
        if (strcmp(name, "") != 0) {
            Application app(name, memory_kb, status);
            apps.push_back(app);
        }
    }
    delete[] name;
    f.close();
}

void FileRepository::write_file() {
    ofstream f(file);
    for (const auto &app : apps) {
        f << app;
    }
    f.close();
}

int FileRepository::get_position_of_application(const Application &app) {
    vector<Application>::iterator it;
    it = find(apps.begin(), apps.end(), app);
    if (it != apps.end()) {
        return distance(apps.begin(), it);
    }
    return -1;
}

void FileRepository::add_application(const Application &app) {
    apps.push_back(app);
    write_file();
}

void FileRepository::delete_application(const Application &app) {
    vector<Application>::iterator it;
    it = find(apps.begin(), apps.end(), app);
    if (it != apps.end()) apps.erase(it);
    write_file();
}

void FileRepository::update_application(const Application &app, char *name, int memory_kb, int status) {
    int position = get_position_of_application(app);
    apps[position].set_name(name);
    apps[position].set_memory_kb(memory_kb);
    apps[position].set_status(status);
    write_file();
}

Application FileRepository::get_application_from_position(int position) {
    return apps[position];
}

vector<Application> FileRepository::get_all() {
    return apps;
}

int FileRepository::get_size() {
    return apps.size();
}
