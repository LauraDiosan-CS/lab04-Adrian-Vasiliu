#pragma once
#include "../Repository/RepositorySTL.h"

class GymExerciseService {
 private:
    RepositorySTL repository;
 public:
    GymExerciseService();
    explicit GymExerciseService(const RepositorySTL &);
    ~GymExerciseService();
    void add_exercise(char *, int, int, int);
    void delete_exercise(int);
    void update_exercise(int, char *, int, int, int);
    int size();
    GymExercise get_exercise_from_position(int position);
    vector<GymExercise> get_all();
};
