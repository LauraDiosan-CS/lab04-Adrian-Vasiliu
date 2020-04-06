#include "Tests/Tests.h"
#include "UI/Console.h"
#include <iostream>
using namespace std;

int main() {
    cout << "\nRunning tests...\n";
    run_tests();
    cout << "Everything ok!\n";
    FileRepository repository("storage.txt");
    ApplicationService service(repository);
    Console console(service);
    console.run_console();
    return 0;
}
