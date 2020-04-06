#include "Tests/Tests.h"
#include "UI/Console.h"
#include <iostream>
using namespace std;

int main() {
    cout << "\nRunning tests...\n";
    run_tests();
    cout << "Everything ok!\n";
    ArrayRepository repository;
    char *name1 = new char[6]{'C', 'u', 'r', 'l', 's'};
    char *name2 = new char[8]{'B', 'a', 'r', 'b', 'e', 'l', 'l'};
    GymExercise exercise1(name1, 4, 14, 5);
    GymExercise exercise2(name2, 3, 12, 10);
    repository.add_exercise(exercise1);
    repository.add_exercise(exercise2);
    GymExerciseService service(repository);
    Console console(service);
    console.run_console();
    return 0;
}
