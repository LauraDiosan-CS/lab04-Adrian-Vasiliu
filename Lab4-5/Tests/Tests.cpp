#include "../Domain/GymExercise.h"
#include "../Repository/RepositorySTL.h"
#include "../Service/GymExerciseService.h"
#include <cassert>
#include <cstring>
using namespace std;

void run_tests() {
    char name_string1[] = "Curls";
    char *name1 = name_string1;
    char name_string2[] = "";
    char *name2 = name_string2;
    GymExercise exercise1(name1, 4, 14, 5);
    GymExercise exercise2(name2, 0, 0, 0);

    assert(strcmp(exercise1.get_name(), "Curls") == 0);
    assert(exercise1.get_series() == 4);
    assert(exercise1.get_reps() == 14);
    assert(exercise1.get_weight_kg() == 5);

    assert(strcmp(exercise2.get_name(), name2) == 0);
    assert(exercise2.get_series() == 0);
    assert(exercise2.get_reps() == 0);
    assert(exercise2.get_weight_kg() == 0);

    RepositorySTL repository;
    repository.add_exercise(exercise1);
    repository.add_exercise(exercise2);
    assert(repository.find_exercise(exercise1));
    assert(repository.find_exercise(exercise2));
    assert(repository.size() == 2);
    repository.delete_exercise(exercise2);
    assert(repository.find_exercise(exercise2) == 0);
    assert(repository.size() == 1);
    repository.update_exercise(exercise1, name1, 3, 12, 5);
    GymExercise new_exercise1(name1, 3, 12, 5);
    assert(repository.get_exercise_from_position(0) == new_exercise1);

    GymExerciseService service(repository);
    char new_name_string[] = "Barbell";
    char *new_name = new_name_string;
    service.add_exercise(new_name, 3, 8, 10);
    GymExercise new_exercise(new_name, 3, 8, 10);
    assert(service.find_exercise(new_exercise));
    assert(service.get_exercise_from_position(1) == new_exercise);
    assert(service.size() == 2);
    char other_name_string[] = "Hammers";
    service.update_exercise(1, other_name_string, 4, 6, 10);
    GymExercise updated_exercise(other_name_string, 4, 6, 10);
    assert(service.get_exercise_from_position(1) == updated_exercise);
    delete[] name1, delete[] name2;
}
