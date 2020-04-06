#pragma once
#include "../Domain/GymExercise.h"

class ArrayRepository {
 private:
    int size;
    GymExercise exercises[100];
 public:
    ArrayRepository();
    ~ArrayRepository();
    int get_position_of_exercise(const GymExercise&);
    void add_exercise(const GymExercise&);
    void delete_exercise(const GymExercise&);
    void update_exercise(const GymExercise& gym_exercise, char *, int, int, int);
    int get_size();
    GymExercise *get_all();
    GymExercise get_exercise_from_position(int);
};
