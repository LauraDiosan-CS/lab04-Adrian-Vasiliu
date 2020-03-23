#include "GymExerciseService.h"

GymExerciseService::GymExerciseService() = default;

GymExerciseService::GymExerciseService(const RepositorySTL &repository_stl) {
    repository = repository_stl;
}

GymExerciseService::~GymExerciseService() = default;

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

bool GymExerciseService::find_exercise(const GymExercise &gym_exercise) {
    return repository.find_exercise(gym_exercise);
}

int GymExerciseService::size() {
    return repository.size();
}

GymExercise GymExerciseService::get_exercise_from_position(int position) {
    return repository.get_exercise_from_position(position);
}

vector<GymExercise> GymExerciseService::get_all() {
    return repository.get_all();
}
