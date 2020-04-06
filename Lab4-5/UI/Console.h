#pragma once
#include "../Service/GymExerciseService.h"

class Console {
 private:
    GymExerciseService service;
    void add_exercise();
    void delete_exercise();
    void update_exercise();
    void show_exercises();
    void show_exercises_with_seriesRepsWeight_bigger_x();
    void remove_exercises_with_repsWeight_smaller_5();
 public:
    Console();
    explicit Console(const GymExerciseService &);
    ~Console();
    void run_console();
};
