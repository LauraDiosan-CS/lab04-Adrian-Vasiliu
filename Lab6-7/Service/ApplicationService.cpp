#include "ApplicationService.h"

ApplicationService::ApplicationService() {
    RAM_max = RAM_free = 2048;
}

ApplicationService::ApplicationService(const FileRepository &repo) {
    this->repo = repo;
    RAM_max = RAM_free = 2048;
    map<int, Application> apps = this->repo.get_all();
    for (int i = 0; i < apps.size(); i++)
        RAM_free -= apps[i].get_memory_kb();
}

ApplicationService::~ApplicationService() = default;

void ApplicationService::check_RAM() {
    map<int, Application> apps = repo.get_all();
    for (int i = 0; i < apps.size(); i++)
        if (apps[i].get_status() == 2 && apps[i].get_memory_kb() <= RAM_free) {
            repo.update_application(apps[i], apps[i].get_name(), apps[i].get_memory_kb(), 1);
            RAM_free -= apps[i].get_memory_kb();
            cout << apps[i].get_name() << ", " << apps[i].get_memory_kb() << " KB: old status = Swap, new status = "
                                                                             "RAM\n";
        }
}

Application ApplicationService::RAM_or_Swap(Application app) {
    if (app.get_memory_kb() <= RAM_free)
        app.set_status(1), RAM_free -= app.get_memory_kb();
    else {
        int i = 0;
        map<int, Application> apps = repo.get_all();
        while (app.get_memory_kb() > RAM_free) {
            if (apps[i].get_status() == 1) {
                repo.update_application(apps[i], apps[i].get_name(), apps[i].get_memory_kb(), 2);
                RAM_free += apps[i].get_memory_kb();
                cout << apps[i].get_name() << ", " << apps[i].get_memory_kb() << " KB: old status = RAM, new status = "
                                                                                 "Swap\n";
            }
            i++;
        }
        app.set_status(1), RAM_free -= app.get_memory_kb();

    }
    return app;
}

int ApplicationService::get_position_of_application(const Application &application) {
    return repo.get_position_of_application(application);
}

int ApplicationService::add_application(char *name, int memory_kb, int status) {
    if (memory_kb <= RAM_max) {
        Application app(name, memory_kb, status);
        app = RAM_or_Swap(app);
        repo.add_application(app);
        //repo.write_file();
        return 0;
    } else return -1;
}

void ApplicationService::delete_application(int position) {
    Application app = repo.get_application_from_position(position);
    if (app.get_status() == 1)
        RAM_free += app.get_memory_kb();
    repo.delete_application(app);
    check_RAM();
    //repo.write_file();
}

void ApplicationService::update_application(int position, char *name, int memory_kb, int status) {
    Application application = repo.get_application_from_position(position);
    repo.update_application(application, name, memory_kb, status);
    check_RAM();
    //repo.write_file();
}

int ApplicationService::get_size() {
    return repo.get_size();
}

map<int, Application> ApplicationService::get_all() {
    return repo.get_all();
}

Application ApplicationService::get_application_from_position(int position) {
    return repo.get_application_from_position(position);
}
