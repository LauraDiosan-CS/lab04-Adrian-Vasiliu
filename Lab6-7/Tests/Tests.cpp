#include "../Domain/Application.h"
#include "../Repository/FileRepository.h"
#include "../Service/ApplicationService.h"
#include <cassert>
#include <cstring>
using namespace std;

void run_tests() {
    char *name1 = new char[7]{'C', 'h', 'r', 'o', 'm', 'e'};
    char *name2 = new char[6]{'C', 'L', 'i', 'o', 'n'};
    Application app1(name1, 512, 1);
    Application app2(name2, 1024, 2);

    assert(strcmp(app1.get_name(), "Chrome") == 0);
    assert(app1.get_memory_kb() == 512);
    assert(app1.get_status() == 1);

    assert(strcmp(app2.get_name(), name2) == 0);
    assert(app2.get_memory_kb() == 1024);
    assert(app2.get_status() == 2);

    FileRepository repository;
    repository.add_application(app1);
    repository.add_application(app2);
    assert(repository.get_position_of_application(app1) == 0);
    assert(repository.get_position_of_application(app2) == 1);
    assert(repository.get_application_from_position(0) == app1);
    assert(repository.get_application_from_position(1) == app2);
    assert(repository.get_size() == 2);
    repository.delete_application(app2);
    assert(repository.get_size() == 1);
    assert(repository.get_position_of_application(app2) == -1);
    repository.update_application(app1, name2, 750, 1);
    Application new_app(name2, 750, 1);
    assert(repository.get_position_of_application(new_app) == 0);
    assert(repository.get_application_from_position(0) == new_app);

    FileRepository repository2("test_file.txt");
    repository2.read_file("test_file.txt");
    ApplicationService service(repository2);
    assert(service.get_size() == 1);
    assert(service.get_application_from_position(0).get_memory_kb() == 16);
    service.add_application(name1, 512, 1);
    Application newest_app(name1, 512, 1);
    assert(service.get_size() == 2);
    assert(service.get_position_of_application(newest_app) == 1);
    assert(service.get_application_from_position(1) == newest_app);
    service.update_application(1, name2, 512, 2);
    Application updated_app(name2, 512, 2);
    assert(service.get_position_of_application(updated_app) == 1);
    assert(service.get_application_from_position(1) == updated_app);
    service.delete_application(1);
    assert(service.get_size() == 1);
    assert(repository.get_position_of_application(updated_app) == -1);
    delete[] name1, delete[] name2;
}
