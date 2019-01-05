#include "TestFunctions.h"
#include<iostream>
using namespace std;

int main()
{
	srand(time(NULL));
	int size = 10;

	//ATTENTION!!
		//Lines 13 to 113 are preliminary tests. Uncomment them if you need to.
	
	//ARRAY TESTS: see if arrays properly produced
		/*cout << "*************************************************************************************";
		cout << "\n\nARRAY TESTS: see if arrays properly produced\n\n";
		int* a = nullptr;
		size = 10;
		create_array(a, size);

		cout << "Testing if array shows up as random:\n";
		create_random(a, size);
		display(a, size);

		cout << "Testing if array shows up as ascending:\n";
		create_ascending(a, size);
		display(a, size);

		cout << "Testing if array shows up as descending:\n";
		create_descending(a, size);
		display(a, size);
		delete a;


	//SORTING TEST: seeing if sorting algorithms work
		cout << "*************************************************************************************";
		cout << "\n\SORTING TESTS: see if sorting algorithms work properly\n\n";

		//SELECTION SORT
			create_array(a, size);
			create_random(a, size);
			cout << "\n\n\nTesting SELECTION-SORT on RANDOM:\n";
			display(a, size);
			selection_sort(a, size);
			display(a, size);
			delete a;

			create_array(a, size);
			create_ascending(a, size);
			cout << "Testing SELECTION-SORT on ASCENDING:\n";
			display(a, size);
			selection_sort(a, size);
			display(a, size);
			delete a;

			create_array(a, size);
			create_descending(a, size);
			cout << "Testing SELECTION-SORT on DESCENDING:\n";
			display(a, size);
			selection_sort(a, size);
			display(a, size);
			delete a;


		//INSERTION SORT
			create_array(a, size);
			create_random(a, size);
			cout << "\n\n\nTesting INSERTION-SORT on RANDOM:\n";
			display(a, size);
			insertion_sort(a, size);
			display(a, size);
			delete a;

			create_array(a, size);
			create_ascending(a, size);
			cout << "Testing INSERTION-SORT on ASCENDING:\n";
			display(a, size);
			insertion_sort(a, size);
			display(a, size);
			delete a;

			create_array(a, size);
			create_descending(a, size);
			cout << "Testing INSERTION-SORT on DESCENDING:\n";
			display(a, size);
			insertion_sort(a, size);
			display(a, size);
			delete a;

	
		//MERGESORT
			create_array(a, size);
			create_random(a, size);
			cout << "\n\n\nTesting MERGESORT on RANDOM:\n";
			display(a, size);
			merge_sort(a, 0, 9);
			display(a, size);
			delete a;

			create_array(a, size);
			create_ascending(a, size);
			cout << "Testing MERGESORT on ASCENDING:\n";
			display(a, size);
			merge_sort(a, 0, 9);
			display(a, size);
			delete a;

			create_array(a, size);
			create_descending(a, size);
			cout << "Testing MERGESORT on DESCENDING:\n";
			display(a, size);
			merge_sort(a, 0, 9);
			display(a, size);
			delete a;*/


	//RUNTIME TESTS: 
		cout << "*******************************************************************";
		cout << "\n\RUNTIME TESTS: see how long each algorithm takes\n\n";


		cout << "*********SELECTION SORT*********\n";

		size = 50;
		cout << "RANDOM:\n";
		for (int i = 0; i < 20; i++)
		{
			cout << "SELECTION-SORT on RANDOM array of size " << size << ": ";
			cout << sorting_runtime(selection_sort, create_random, size) << " microseconds\n";
			size += 50;
		}

		size = 50;
		cout << "\nASCENDING:\n";
		for (int i = 0; i < 20; i++)
		{
			cout << "SELECTION-SORT on ASCENDING array of size " << size << ": ";
			cout << sorting_runtime(selection_sort, create_ascending, size) << " microseconds\n";
			size += 50;
		}

		size = 50;
		cout << "\nDESCENDING:\n";
		for (int i = 0; i < 20; i++)
		{
			cout << "SELECTION-SORT on DESCENDING array of size " << size << ": ";
			cout << sorting_runtime(selection_sort, create_descending, size) << " microseconds\n";
			size += 50;
		}


		cout << "\n*********INSERTION SORT*********\n";

		size = 50;
		cout << "RANDOM:\n";
		for (int i = 0; i < 20; i++)
		{
			cout << "INSERTION-SORT on RANDOM array of size " << size << ": ";
			cout << sorting_runtime(insertion_sort, create_random, size) << " microseconds\n";
			size += 50;
		}

		size = 50;
		cout << "\nASCENDING:\n";
		for (int i = 0; i < 20; i++)
		{
			cout << "INSERTION-SORT on ASCENDING array of size " << size << ": ";
			cout << sorting_runtime(insertion_sort, create_ascending, size) << " microseconds\n";
			size += 50;
		}

		size = 50;
		cout << "\nDESCENDING:\n";
		for (int i = 0; i < 20; i++)
		{
			cout << "INSERTION-SORT on DESCENDING array of size " << size << ": ";
			cout << sorting_runtime(insertion_sort, create_descending, size) << " microseconds\n";
			size += 50;
		}


		cout << "\n\n*********MERGE-SORT*********\n";

		size = 50;
		cout << "RANDOM:\n";
		for (int i = 0; i < 20; i++)
		{
			cout << "MERGE-SORT on RANDOM array of size " << size << ": ";
			cout << mergesort_runtime(create_random, size) << " microseconds\n";
			size += 50;
		}

		size = 50;
		cout << "\nASCENDING:\n";
		for (int i = 0; i < 20; i++)
		{
			cout << "MERGE-SORT on ASCENDING array of size " << size << ": ";
			cout << mergesort_runtime(create_random, size) << " microseconds\n";
			size += 50;
		}

		size = 50;
		cout << "\nDESCENDING:\n";
		for (int i = 0; i < 20; i++)
		{
			cout << "MERGE-SORT on DESCENDING array of size " << size << ": ";
			cout << mergesort_runtime(create_random, size) << " microseconds\n";
			size += 50;
		}


	cout << endl;	
	system("pause;");
	return 0;
}