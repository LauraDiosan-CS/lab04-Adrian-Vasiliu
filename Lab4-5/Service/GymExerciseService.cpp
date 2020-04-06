#include "GymExerciseService.h"

GymExerciseService::GymExerciseService() = default;

GymExerciseService::GymExerciseService(const ArrayRepository &repository) {
    this->repository = repository;
}

GymExerciseService::~GymExerciseService() = default;

bool GymExerciseService::find_exercise(const GymExercise &gym_exercise) {
    return repository.get_position_of_exercise(gym_exercise) != -1;
}

void GymExerciseService::add_exercise(char *name, int series, int reps, int weight_kg) {
    GymExercise gym_exercise(name, series, reps, weight_kg);
    repository.add_exercise(gym_exercise);
}

void GymExerciseService::delete_exercise(int position) {
    GymExercise gym_exercise = repository.get_exercise_from_position(position);
    repository.delete_exercise(gym_exercise);
}

void GymExerciseService::update_exercise(int position, char *name, int series, int reps, int weight_kg) {
    GymExercise gym_exercise = repository.get_exercise_from_position(position);
    repository.update_exercise(gym_exercise, name, series, reps, weight_kg);
}

int GymExerciseService::get_size() {
    return repository.get_size();
}

GymExercise *GymExerciseService::get_all() {
    return repository.get_all();
}

GymExercise GymExerciseService::get_exercise_from_position(int position) {
    return repository.get_exercise_from_position(position);
}

void GymExerciseService::get_exercises_with_seriesRepsWeight_bigger_x(int x, int &result_size,
                                                                      GymExercise result[]) {
    result_size = 0;
    GymExercise *exercises = get_all();
    for (int i = 0; i < get_size(); i++)
        if (exercises[i].get_series() * exercises[i].get_reps() * exercises[i].get_weight_kg() > x)
            result[result_size++] = exercises[i];
}

void GymExerciseService::remove_exercises_with_repsWeight_smaller_5() {
    GymExercise *exercises = get_all();
    for (int i = 0; i < get_size(); i++)
        if (exercises[i].get_reps() * exercises[i].get_weight_kg() < 5)
            repository.delete_exercise(exercises[i]);
}
