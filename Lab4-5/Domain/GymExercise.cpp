#include "GymExercise.h"
#include <cstring>

GymExercise::GymExercise() {
    name = nullptr;
    series = reps = weight_kg = 0;
}

GymExercise::GymExercise(char *name, int series, int reps, int weight_kg) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->series = series;
    this->reps = reps;
    this->weight_kg = weight_kg;
}

GymExercise::GymExercise(const GymExercise &gym_exercise) {
    name = new char[strlen(gym_exercise.name) + 1];
    strcpy(name, gym_exercise.name);
    series = gym_exercise.series;
    reps = gym_exercise.reps;
    weight_kg = gym_exercise.weight_kg;
}

GymExercise::~GymExercise() {
    delete[]name;
    name = nullptr;
    series = reps = weight_kg = -1;
}

GymExercise &GymExercise::operator=(const GymExercise &gym_exercise) {
    if (this == &gym_exercise) return *this;
    delete[] name;
    name = new char[strlen(gym_exercise.name) + 1];
    strcpy(name, gym_exercise.name);
    series = gym_exercise.series;
    reps = gym_exercise.reps;
    weight_kg = gym_exercise.weight_kg;
    return *this;
}

char *GymExercise::get_name() {
    return name;
}

void GymExercise::set_name(char *new_name) {
    delete[]name;
    name = new char[strlen(new_name) + 1];
    strcpy(name, new_name);
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
