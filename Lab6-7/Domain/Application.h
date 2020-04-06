#pragma once
#include <iostream>
using namespace std;

class Application {
 private:
    char *name;
    int memory_kb;
    int status;
 public:
    Application();
    Application(const char *, int, int);
    explicit Application(const string &);
    Application(const Application &);
    ~Application();
    char *get_name();
    int get_memory_kb();
    int get_status();
    void set_name(char *);
    void set_memory_kb(int);
    void set_status(int);
    Application &operator=(const Application &);
    bool operator==(const Application &);
    bool operator<(const Application &);
    friend ostream &operator<<(ostream &os, const Application &s);
    friend istream &operator>>(istream &, Application &);
};
