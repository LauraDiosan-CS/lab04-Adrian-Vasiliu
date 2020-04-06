#include "Console.h"
#include <iostream>
using namespace std;

Console::Console() = default;

Console::Console(const GymExerciseService &gym_exercise_service) {
    service = gym_exercise_service;
}

Console::~Console() = default;

void Console::add_exercise() {
    char name_string[50];
    int series, reps, weight_kg;
    cout << "Name: ";
    cin >> name_string;
    char *name = name_string;
    cout << "Number of series: ";
    cin >> series;
    cout << "Number of reps: ";
    cin >> reps;
    cout << "Weight(in kg): ";
    cin >> weight_kg;
    service.add_exercise(name, series, reps, weight_kg);
    cout << "\nExercise added\n";
}

void Console::delete_exercise() {
    int position;
    cout << "Delete exercise from position:";
    cin >> position;
    service.delete_exercise(position - 1);
    cout << "\nExercise deleted\n";
}

void Console::update_exercise() {
    int position;
    cout << "Update exercise from position:";
    cin >> position;
    char name_string[50];
    int series, reps, weight_kg;
    cout << "Name: ";
    cin >> name_string;
    char *name = name_string;
    cout << "Number of series: ";
    cin >> series;
    cout << "Number of reps: ";
    cin >> reps;
    cout << "Weight(in kg): ";
    cin >> weight_kg;
    service.update_exercise(position - 1, name, series, reps, weight_kg);
    cout << "\nExercise updated\n";
}

void Console::show_exercises() {
    GymExercise *exercises = service.get_all();
    for (int i = 0; i < service.get_size(); i++)
        cout << i + 1 << ". " << exercises[i];
    cout << endl;
}

void Console::show_exercises_with_seriesRepsWeight_bigger_x() {
    int x, result_size = 0;
    GymExercise result[service.get_size()];
    cout << "x = ";
    cin >> x;
    service.get_exercises_with_seriesRepsWeight_bigger_x(x, result_size, result);
    for (int i = 0; i < result_size; i++)
        cout << i + 1 << ". " << result[i];
    cout << endl;
}

void Console::remove_exercises_with_repsWeight_smaller_5() {
    service.remove_exercises_with_repsWeight_smaller_5();
    cout << "Done!" << endl;
}

void Console::run_console() {
    bool work = true;
    int option = 0;
    while (work) {
        cout << "\n1. Add a gym exercise\n"
             << "2. Delete a gym exercise\n"
             << "3. Update a gym exercise\n"
             << "4. Show all gym exercises\n"
             << "5. Show exercises with series*reps*weight > x\n"
             << "6. Remove exercises with reps*weight < 5\n"
             << "7. Exit\n"
             << "\nOption: ";
        cin >> option;
        if (option == 1)
            add_exercise();
        else if (option == 2)
            delete_exercise();
        else if (option == 3)
            update_exercise();
        else if (option == 4)
            show_exercises();
        else if (option == 5)
            show_exercises_with_seriesRepsWeight_bigger_x();
        else if (option == 6)
            remove_exercises_with_repsWeight_smaller_5();
        else if (option == 7)
            work = false;
        else
            cout << "Invalid option! Retry!\n";
    }
}
