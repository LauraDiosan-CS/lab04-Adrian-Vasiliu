#include "ArrayRepository.h"

ArrayRepository::ArrayRepository() {
    size = 0;
}

ArrayRepository::~ArrayRepository() = default;

int ArrayRepository::get_position_of_exercise(const GymExercise& gym_exercise) {
    for (int i = 0; i < size; i++)
        if (exercises[i] == gym_exercise) return i;
    return -1;
}

void ArrayRepository::add_exercise(const GymExercise& gym_exercise) {
    exercises[size++] = gym_exercise;
}

void ArrayRepository::delete_exercise(const GymExercise& gym_exercise) {
    int position = get_position_of_exercise(gym_exercise);
    if (position != -1)
        exercises[position] = exercises[--size];
}

void ArrayRepository::update_exercise(const GymExercise& gym_exercise,
                                      char *name,
                                      int series,
                                      int reps,
                                      int weight_kg) {
    int position = get_position_of_exercise(gym_exercise);
    if (position != -1) {
        exercises[position].set_name(name);
        exercises[position].set_series(series);
        exercises[position].set_reps(reps);
        exercises[position].set_weight_kg(weight_kg);
    }
}

GymExercise ArrayRepository::get_exercise_from_position(int position) {
    return exercises[position];
}

GymExercise *ArrayRepository::get_all() {
    return exercises;
}

int ArrayRepository::get_size() {
    return size;
}
