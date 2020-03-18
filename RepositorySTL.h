#pragma once

#include "GymExercise.h"
#include <vector>
using namespace std;

class RepositorySTL {
 private:
    vector<GymExercise> exercises;
 public:
    RepositorySTL();
    void add_exercise(GymExercise);
    bool find_exercise(GymExercise);
    void delete_exercise(GymExercise);
    void update_exercise(GymExercise, char *, int, int, int);
    GymExercise get_exercise_from_position(int);
    vector<GymExercise> get_all();
    int size();
    ~RepositorySTL();
};
