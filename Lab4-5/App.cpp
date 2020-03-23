#include "Tests/Tests.h"
#include "UI/Console.h"
#include <iostream>
using namespace std;

int main() {
    cout << "\nRunning tests...\n";
    run_tests();
    cout << "Everything ok!\n";
    RepositorySTL repository;
    char name_string1[] = "Curls";
    char *name1 = name_string1;
    char name_string2[] = "Barbell";
    char *name2 = name_string2;
    GymExercise exercise1(name1, 4, 14, 5);
    GymExercise exercise2(name2, 3, 12, 10);
    repository.add_exercise(exercise1);
    repository.add_exercise(exercise2);
    GymExerciseService service(repository);
    Console console(service);
    console.run_console();
    return 0;
}
