#include "Tests.h"
#include "GymExercise.h"
#include "RepositorySTL.h"
#include <cassert>
#include <vector>
#include <cstring>
using namespace std;

void test_GymExercise() {
	GymExercise exercise1("Curls", 4, 14, 5);
	GymExercise exercise2("Barbell", 3, 10, 10);
	RepositorySTL repository;
	repository.add_exercise(exercise1);
	repository.add_exercise(exercise2);
	vector<GymExercise> exercises = repository.get_all();

	assert(repository.size() == 2);

	assert(strcmp(exercises[0].get_name(), "Curls") == 0);
	assert(exercises[0].get_series() == 4);
	assert(exercises[0].get_reps() == 14);
	assert(exercises[0].get_weight_kg() == 5);

	assert(strcmp(exercises[1].get_name(), "Barbell") == 0);
	assert(exercises[1].get_series() == 3);
	assert(exercises[1].get_reps() == 10);
	assert(exercises[1].get_weight_kg() == 10);

}
