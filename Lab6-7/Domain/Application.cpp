#include "Application.h"
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

Application::Application() {
    name = nullptr;
    memory_kb = status = 0;
}

Application::Application(const char *name, int memory_kb, int status) {
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);
    this->memory_kb = memory_kb;
    this->status = status;
}

Application::Application(const string &line) {
    std::istringstream iss(line);
    string tok1, tok2, tok3;
    iss >> tok1 >> tok2 >> tok3;
    name = new char[tok1.length() + 1];
    strcpy_s(name, tok1.length() + 1, tok1.c_str());
    memory_kb = stoi(tok2);
    status = stoi(tok3);
}

Application::Application(const Application &application) {
    name = new char[strlen(application.name) + 1];
    strcpy_s(name, strlen(application.name) + 1, application.name);
    memory_kb = application.memory_kb;
    status = application.status;
}

Application::~Application() {
    delete[]name;
    name = nullptr;
    memory_kb = status = -1;
}

char *Application::get_name() {
    return name;
}

void Application::set_name(char *new_name) {
    delete[]name;
    name = new char[strlen(new_name) + 1];
    strcpy_s(name, strlen(new_name) + 1, new_name);
}

int Application::get_memory_kb() {
    return memory_kb;
}

void Application::set_memory_kb(int new_memory_kb) {
    memory_kb = new_memory_kb;
}

int Application::get_status() {
    return status;
}

void Application::set_status(int new_status) {
    status = new_status;
}

Application &Application::operator=(const Application &application) {
    if (this == &application) return *this;
    delete[] name;
    if (application.name != nullptr) {
        name = new char[strlen(application.name) + 1];
        strcpy_s(name, strlen(application.name) + 1, application.name);
    } else name = nullptr;
    memory_kb = application.memory_kb;
    status = application.status;
    return *this;
}

bool Application::operator==(const Application &application) {
    return (strcmp(name, application.name) == 0) and (memory_kb == application.memory_kb) and
            (status == application.status);
}

bool Application::operator<(const Application &application) {
    return (strcmp(name, application.name) < 0);
}

ostream &operator<<(ostream &os, const Application &application) {
    string status;
    if (application.status == 1)
        status = "RAM";
    else if (application.status == 2)
        status = "Swap";
    os << application.name << " " << application.memory_kb << " " << status << endl;
    return os;
}

istream &operator>>(istream &is, Application &application) {
    char name_string[50];
    is >> name_string;
    char *name = name_string;
    int memory_kb, status;
    cin >> memory_kb >> status;
    application.set_name(name);
    application.set_memory_kb(memory_kb);
    application.set_status(status);
    delete[] name;
    return is;
}
