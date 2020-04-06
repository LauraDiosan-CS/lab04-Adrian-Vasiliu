#pragma once
#include <iostream>
using namespace std;

class GymExercise {
 private:
    char *name;
    int series;
    int reps;
    int weight_kg;
 public:
    GymExercise();
    GymExercise(const char *, int, int, int);
    GymExercise(const GymExercise &);
    ~GymExercise();
    char *get_name();
    int get_series();
    int get_reps();
    int get_weight_kg();
    void set_name(char *);
    void set_series(int);
    void set_reps(int);
    void set_weight_kg(int);
    GymExercise &operator=(const GymExercise &);
    bool operator==(const GymExercise &);
    friend ostream &operator<<(ostream &os, const GymExercise &s);
};
