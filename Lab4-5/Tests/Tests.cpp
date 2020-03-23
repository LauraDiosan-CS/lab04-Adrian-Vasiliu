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
    assert(repository.size() == 1);
    repository.update_exercise(exercise1, name1, 3, 12, 5);
    GymExercise new_exercise1(name1, 3, 12, 5);
    assert(repository.get_exercise_from_position(0) == new_exercise1);

    delete[] name1, delete[] name2;
}
