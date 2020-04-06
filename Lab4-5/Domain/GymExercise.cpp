#include "GymExercise.h"
#include <cstring>

GymExercise::GymExercise() {
    name = nullptr;
    series = reps = weight_kg = 0;
}

GymExercise::GymExercise(const char *name, int series, int reps, int weight_kg) {
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);
    this->series = series;
    this->reps = reps;
    this->weight_kg = weight_kg;
}

GymExercise::GymExercise(const GymExercise &gym_exercise) {
    name = new char[strlen(gym_exercise.name) + 1];
    strcpy_s(name, strlen(gym_exercise.name) + 1, gym_exercise.name);
    series = gym_exercise.series;
    reps = gym_exercise.reps;
    weight_kg = gym_exercise.weight_kg;
}

GymExercise::~GymExercise() {
    delete[]name;
    name = nullptr;
    series = reps = weight_kg = -1;
}

char *GymExercise::get_name() {
    return name;
}

void GymExercise::set_name(char *new_name) {
    delete[]name;
    name = new char[strlen(new_name) + 1];
    strcpy_s(name, strlen(new_name) + 1, new_name);
}

int GymExercise::get_series() {
    return series;
}

void GymExercise::set_series(int new_series) {
    series = new_series;
}

int GymExercise::get_reps() {
    return reps;
}

void GymExercise::set_reps(int new_reps) {
    reps = new_reps;
}

int GymExercise::get_weight_kg() {
    return weight_kg;
}

void GymExercise::set_weight_kg(int new_weight_kg) {
    weight_kg = new_weight_kg;
}

GymExercise &GymExercise::operator=(const GymExercise &gym_exercise) {
    if (this == &gym_exercise) return *this;
    delete[] name;
    if (gym_exercise.name != nullptr) {
        name = new char[strlen(gym_exercise.name) + 1];
        strcpy_s(name, strlen(gym_exercise.name) + 1, gym_exercise.name);
    } else name = nullptr;
    series = gym_exercise.series;
    reps = gym_exercise.reps;
    weight_kg = gym_exercise.weight_kg;
    return *this;
}

bool GymExercise::operator==(const GymExercise &gym_exercise) {
    return (strcmp(name, gym_exercise.name) == 0) and (series == gym_exercise.series) and (reps == gym_exercise.reps)
            and (weight_kg == gym_exercise.weight_kg);
}

ostream &operator<<(ostream &os, const GymExercise &gym_exercise) {
    os << gym_exercise.name << ": " << gym_exercise.series << " series, " << gym_exercise.reps << " reps, " << "with "
       << gym_exercise.weight_kg << " kg."
       << endl;
    return os;
}
