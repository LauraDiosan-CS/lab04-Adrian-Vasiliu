#include "ApplicationService.h"

ApplicationService::ApplicationService() = default;

ApplicationService::ApplicationService(const FileRepository &repo) {
    this->repo = repo;
}

ApplicationService::~ApplicationService() = default;

int ApplicationService::get_position_of_application(const Application &application) {
    return repo.get_position_of_application(application);
}

void ApplicationService::add_application(char *name, int memory_kb, int status) {
    Application app(name, memory_kb, status);
    repo.add_application(app);
}

void ApplicationService::delete_application(int position) {
    Application app = repo.get_application_from_position(position);
    repo.delete_application(app);
}

void ApplicationService::update_application(int position, char *name, int memory_kb, int status) {
    Application application = repo.get_application_from_position(position);
    repo.update_application(application, name, memory_kb, status);
}

int ApplicationService::get_size() {
    return repo.get_size();
}

vector<Application> ApplicationService::get_all() {
    return repo.get_all();
}

Application ApplicationService::get_application_from_position(int position) {
    return repo.get_application_from_position(position);
}
