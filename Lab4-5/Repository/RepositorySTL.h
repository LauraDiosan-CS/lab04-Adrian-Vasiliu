#pragma once
#include "../Domain/GymExercise.h"
#include <vector>
using namespace std;

class RepositorySTL {
 private:
    vector<GymExercise> exercises;
 public:
    RepositorySTL();
    ~RepositorySTL();
    void add_exercise(const GymExercise &);
    void delete_exercise(const GymExercise &);
    void update_exercise(const GymExercise &, char *, int, int, int);
    bool find_exercise(const GymExercise &);
    int size();
    vector<GymExercise> get_all();
    GymExercise get_exercise_from_position(int);
};
