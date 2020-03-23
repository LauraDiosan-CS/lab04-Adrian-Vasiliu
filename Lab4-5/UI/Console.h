#pragma once
#include "../Service/GymExerciseService.h"

class Console {
 private:
    GymExerciseService service;
    void add_exercise();
    void delete_exercise();
    void update_exercise();
    void show_exercises();
 public:
    Console();
    explicit Console(const GymExerciseService &);
    ~Console();
    void run_console();
};
