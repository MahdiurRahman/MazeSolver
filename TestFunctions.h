#ifndef TESTFUNCTIONS_
#define TESTFUNCTIONS_
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;


//DEBUG FUNCTIONS

	void display(int* array_ptr, int size);



//ARRAY CREATION FUNCTIONS

	void create_array(int* &array_, int size);

	void create_random(int* &array_, int size);

	void create_ascending(int* &array_, int size);

	void create_descending(int* &array_, int size);



//SORTING FUNCTIONS

	void selection_sort(int* &array_, int size);

	void insertion_sort(int* &array_, int size);

	void merge_sort(int* &array_, int from, int to);



//TESTING FUNCTIONS

	double sorting_runtime(void(*sorting_function)(int* &array_, int size), void(*array_creation_function)(int* &array_, int size), int size);

	double mergesort_runtime(void(*array_creation_function)(int* &array_, int size), int size);



#endif