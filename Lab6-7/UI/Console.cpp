#include "Console.h"
#include <iostream>
using namespace std;

Console::Console() = default;

Console::Console(const ApplicationService &application_service) {
    service = application_service;
}

Console::~Console() = default;

void Console::add_application() {
    char name_string[50];
    int memory_kb, status = 0;
    cout << "Name: ";
    cin >> name_string;
    char *name = name_string;
    cout << "Memory (in KB): ";
    cin >> memory_kb;
    int ok = service.add_application(name, memory_kb, status);
    if (ok == 0)
        cout << "Application added\n";
    else if (ok == -1) cout << "Error: The application exceeds the maximum capacity of RAM!";
}

void Console::delete_application() {
    int position;
    cout << "Delete application from position:";
    cin >> position;
    service.delete_application(position - 1);
    cout << "Application deleted\n";
}

void Console::update_application() {
    int position;
    cout << "Update application from position:";
    cin >> position;
    char name_string[50];
    int memory_kb, status;
    cout << "Name: ";
    cin >> name_string;
    char *name = name_string;
    cout << "Memory (in KB): ";
    cin >> memory_kb;
    cout << "Status (1=RAM or 2=swap): ";
    cin >> status;
    service.update_application(position - 1, name, memory_kb, status);
    cout << "Application updated\n";
}

void Console::show_applications() {
    map<int, Application> apps = service.get_all();
    for (int i = 0; i < service.get_size(); i++)
        cout << i + 1 << ". " << apps[i];
}



void Console::run_console() {
    cout << "\nInfo: Maximum capacity of RAM is 2048 KB!\n";
    bool work = true;
    int option = 0;
    while (work) {
        cout << "\n"
             << "1. Add an application\n"
             << "2. Delete an application\n"
             << "3. Update an application\n"
             << "4. Show all applications\n"
             << "5. Exit\n"
             << "\nOption: ";
        cin >> option;
        if (option == 1)
            add_application();
        else if (option == 2)
            delete_application();
        else if (option == 3)
            update_application();
        else if (option == 4)
            show_applications();
        else if (option == 5)
            work = false;
        else
            cout << "Invalid option! Retry!\n";
    }
}
