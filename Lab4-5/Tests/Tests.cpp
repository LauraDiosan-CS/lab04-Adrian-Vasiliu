#include "../Domain/GymExercise.h"
#include "../Repository/ArrayRepository.h"
#include "../Service/GymExerciseService.h"
#include <cassert>
#include <cstring>
using namespace std;

void run_tests() {
    char *name1 = new char[6]{'C', 'u', 'r', 'l', 's'};
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

    ArrayRepository repository;
    repository.add_exercise(exercise1);
    repository.add_exercise(exercise2);
    assert(repository.get_position_of_exercise(exercise1) == 0);
    assert(repository.get_position_of_exercise(exercise2) == 1);
    assert(repository.get_size() == 2);
    repository.delete_exercise(exercise2);
    assert(repository.get_position_of_exercise(exercise1) == 0);
    assert(repository.get_size() == 1);
    repository.update_exercise(exercise1, name1, 3, 12, 5);
    GymExercise new_exercise1(name1, 3, 12, 5);
    assert(repository.get_exercise_from_position(0) == new_exercise1);
    delete[] name1, delete[] name2;

    GymExerciseService service(repository);
    char *new_name = new char[8]{'B', 'a', 'r', 'b', 'e', 'l', 'l'};
    service.add_exercise(new_name, 3, 8, 10);
    GymExercise new_exercise(new_name, 3, 8, 10);
    assert(service.find_exercise(new_exercise));
    assert(service.get_exercise_from_position(1) == new_exercise);
    assert(service.get_size() == 2);
    new_name = new char[8]{'H', 'a', 'm', 'm', 'e', 'r', 's'};
    service.update_exercise(1, new_name, 4, 6, 10);
    GymExercise updated_exercise(new_name, 4, 6, 10);
    assert(service.get_exercise_from_position(1) == updated_exercise);

    service.add_exercise(new_name, 3, 2, 1);
    service.remove_exercises_with_repsWeight_smaller_5();
    assert(service.find_exercise(new_exercise) == 0);
    assert(service.get_size() == 2);
    delete[] new_name;
}
