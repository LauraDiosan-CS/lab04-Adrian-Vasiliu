#pragma once
#include "../Service/ApplicationService.h"

class Console {
 private:
    ApplicationService service;
    void add_application();
    void delete_application();
    void update_application();
    void show_applications();
 public:
    Console();
    explicit Console(const ApplicationService &);
    ~Console();
    void run_console();
};
