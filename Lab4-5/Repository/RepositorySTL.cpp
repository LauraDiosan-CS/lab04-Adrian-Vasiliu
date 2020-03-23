#include "RepositorySTL.h"
#include <algorithm>
using namespace std;

RepositorySTL::RepositorySTL() = default;

RepositorySTL::~RepositorySTL() = default;

void RepositorySTL::add_exercise(const GymExercise &gym_exercise) {
    exercises.push_back(gym_exercise);
}

void RepositorySTL::delete_exercise(const GymExercise &gym_exercise) {
    vector<GymExercise>::iterator it;
    it = find(exercises.begin(), exercises.end(), gym_exercise);
    if (it != exercises.end()) exercises.erase(it);
}

void RepositorySTL::update_exercise(const GymExercise &gym_exercise, char *name, int series, int reps, int weight_kg) {
    for (auto &exercise : exercises)
        if (exercise == gym_exercise) {
            exercise.set_name(name);
            exercise.set_series(series);
            exercise.set_reps(reps);
            exercise.set_weight_kg(weight_kg);
            return;
        }
}

bool RepositorySTL::find_exercise(const GymExercise &gym_exercise) {
    vector<GymExercise>::iterator it;
    it = find(exercises.begin(), exercises.end(), gym_exercise);
    return it != exercises.end();
}

GymExercise RepositorySTL::get_exercise_from_position(int position) {
    return exercises[position];
}

vector<GymExercise> RepositorySTL::get_all() {
    return exercises;
}

int RepositorySTL::size() {
    return exercises.size();
}
