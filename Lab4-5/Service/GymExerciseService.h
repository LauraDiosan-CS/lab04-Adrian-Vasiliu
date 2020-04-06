#pragma once
#include "../Repository/ArrayRepository.h"

class GymExerciseService {
 private:
    ArrayRepository repository;
 public:
    GymExerciseService();
    explicit GymExerciseService(const ArrayRepository &);
    ~GymExerciseService();
    bool find_exercise(const GymExercise &);
    void add_exercise(char *, int, int, int);
    void delete_exercise(int);
    void update_exercise(int, char *, int, int, int);
    int get_size();
    GymExercise *get_all();
    GymExercise get_exercise_from_position(int position);
    void get_exercises_with_seriesRepsWeight_bigger_x(int x, int &result_size, GymExercise result[]);
    void remove_exercises_with_repsWeight_smaller_5();
};
