#include "TestFunctions.h"


//DEBUG FUNCTIONS

	void display(int* array_ptr, int size)
	{
		cout << "Displaying Array: ";
		for (int i = 0; i < size; i++)
		{
			cout << array_ptr[i] << " ";
		}
		cout << "\n\n";
	}



//ARRAY CREATION FUNCTIONS

	void create_array(int* &array_, int size)
	{
		array_ = new int[size];
	}

	void create_random(int* &array_, int size)
	{
		delete array_;
		array_ = new int[size];

		for (int i = 0; i < size; i++)
		{
			array_[i] = rand() % 1000;
		}
	}

	void create_ascending(int* &array_, int size)
	{
		delete array_;
		array_ = new int[size];

		for (int i = 0; i < size; i++)
		{
			array_[i] = i;
		}
	}

	void create_descending(int* &array_, int size)
	{
		delete array_;
		array_ = new int[size];

		for (int i = 0; i < size; i++)
		{
			array_[i] = size - i - 1;
		}
	}



//SORTING FUNCTIONS

	void selection_sort(int* &array_, int size)
	{
		int smallest = 0; //will point to smallest of unsorted list
		int holder; //holds values during swithing so we don't lose data

		for (int i = 0; i < size; i++)
		{
			smallest = i; //smallest set to default beginning of unsorted

			//scour unsorted for smallest position
				for (int j = i; j < size; j++)
				{
					if (array_[j] < array_[smallest])
					{
						smallest = j;
					}
				}

			//switch position i with smallest
				holder = array_[i];
				array_[i] = array_[smallest];
				array_[smallest] = holder;
		}
	}

	void insertion_sort(int* &array_, int size)
	{
		int holder;

		//iterate through each item
		for (int i = 0; i < size; i++)
		{
			//while item is smaller than one before, swap
			while (array_[i] < array_[i - 1])
			{
				holder = array_[i - 1];
				array_[i - 1] = array_[i];
				array_[i] = holder;
				i--;
			}	
		}
	}

	void merge_sort(int* &array_, int from, int to)
	{
		if (from != to)
		{
			int middle1 = (to - from) / 2 + from;
			int middle2 = middle1 + 1;
			merge_sort(array_, from, middle1);
			merge_sort(array_, middle2, to);

			//MERGE
				int *copy = new int[to - from + 1];
				int m1 = from;
				int m2 = middle2;
				int i = 0; //i for iterator

				while ((m1 <= middle1) and (m2 <= to))
				{
					if (array_[m1] < array_[m2])
					{
						copy[i] = array_[m1];
						m1++;
					}
					else
					{
						copy[i] = array_[m2];
						m2++;
					}
					i++;
				}

				while (m1 <= middle1)
				{
					copy[i] = array_[m1];
					m1++;
					i++;
				}

				while (m2 <= to)
				{
					copy[i] = array_[m2];
					m2++;
					i++;
				}

				for (int i = from; i <= to; i++)
				{
					array_[i] = copy[i - from];
				}
		}
		else
		{
			return;
		}
	}



//TESTING FUNCTIONS

	//measures time in nanoseconds for 10 runs, returns average
	double sorting_runtime(void(*sorting_function)(int* &array_, int size), void(*array_creation_function)(int* &array_, int size), int size)
	{
		double total = 0.0;

		for (int i = 0; i < 10; i++)
		{
			//create array each trial
			int* array_1;
			create_array(array_1, size);
			array_creation_function(array_1, size);

			//test sorting of array
			auto start = chrono::high_resolution_clock().now();
			sorting_function(array_1, size);
			auto end = chrono::high_resolution_clock().now();

			//add to total and release memory
			auto runtime = chrono::duration_cast<chrono::microseconds>(end - start).count();
			total += double(runtime);
			delete array_1;
		}

		double average = total / 10;
		return average;
	}

	//measures time in nanoseconds for 10 runs, returns average
	double mergesort_runtime(void(*array_creation_function)(int* &array_, int size), int size)
	{
		double total = 0.0;

		for (int i = 0; i < 10; i++)
		{
			//create array each trial
			int* array_1;
			create_array(array_1, size);
			array_creation_function(array_1, size);

			//test sorting of array
			auto start = chrono::high_resolution_clock().now();
			merge_sort(array_1, 0, (size - 1));
			auto end = chrono::high_resolution_clock().now();

			//add to total and release memory
			auto runtime = chrono::duration_cast<chrono::microseconds>(end - start).count();
			total += double(runtime);
			delete array_1;
		}

		double average = total / 10;
		return average;
	}