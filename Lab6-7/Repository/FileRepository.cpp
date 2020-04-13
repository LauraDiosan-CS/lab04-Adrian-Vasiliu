#include "FileRepository.h"
#include "../Domain/Application.h"
#include <fstream>
#include <cstring>
using namespace std;

FileRepository::FileRepository() {
    file = nullptr;
}

FileRepository::FileRepository(const char *file_name) {
    file = file_name;
    read_file(file);
}

FileRepository::~FileRepository() = default;

void FileRepository::read_file(const char *file_name) {
    apps.clear();
    file = file_name;
    ifstream f(file);
    char *name = new char[50];
    int memory_kb, status = 0;
    string status_string;
    while (f >> name >> memory_kb >> status_string) {
        if (status_string == "RAM")
            status = 1;
        else if (status_string == "Swap")
            status = 2;
        if (strcmp(name, "") != 0) {
            Application app(name, memory_kb, status);
            add_application(app);
        }
    }
    delete[] name;
    f.close();
}

void FileRepository::write_file() {
    ofstream f(file);
    for (int i = 0; i <= apps.size(); i++)
        f << apps[i];
    f.close();
}
