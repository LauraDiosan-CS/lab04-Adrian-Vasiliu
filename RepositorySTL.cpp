#include "RepositorySTL.h"

RepositorySTL::RepositorySTL() {
}

void RepositorySTL::add_exercise(GymExercise gym_exercise) {
    exercises.push_back(gym_exercise);
}

void RepositorySTL::delete_exercise(GymExercise gym_exercise) {
    vector<GymExercise>::iterator it;
    it = find(exercises.begin(), exercises.end(), gym_exercise);
    if (it != exercises.end()) exercises.erase(it);
}

bool RepositorySTL::find_exercise(GymExercise gym_exercise) {
    vector<GymExercise>::iterator it;
    it = find(exercises.begin(), exercises.end(), gym_exercise);
    if (it != exercises.end()) return true;
    return false;
}

int RepositorySTL::size() {
    return exercises.size();
}

GymExercise RepositorySTL::get_exercise_from_position(int i) {
    return exercises[i];
}

RepositorySTL::~RepositorySTL() {}

vector<GymExercise> RepositorySTL::get_all() {
    return exercises;
}

void RepositorySTL::update_exercise(GymExercise gym_exercise, char *name, int series, int reps, int weight_kg) {
    for (int i = 0; i < exercises.size(); i++)
        if (exercises[i] == gym_exercise) {
            exercises[i].set_name(name);
            exercises[i].set_series(series);
            exercises[i].set_reps(reps);
            exercises[i].set_weight_kg(weight_kg);
            return;
        }
}
