// 20200408_Week9Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <string>
#include <iomanip>
#include "quicksort.h"
#include "bubblesort.h"
#include "selection.h"
#include "insertionsort.h"
#include "merge.h"
#include "heapsort.h"

using namespace std;

void randomize(int numbers[], int numberSize) {
	for (int i = 0; i < numberSize - 1; i++) {
		numbers[i] = rand() % 1000 + 1;
	}
}

void saveArray(int numbers[], int savedNumbers[], int numberSize){
	for (int i = 0; i < numberSize - 1; i++) {
		savedNumbers[i] = numbers[i];
	}
}

void firstFifty(int array[]) {
	for (int i = 0; i < 49; i++) {
		cout << array[i] << endl;
	}
}

int main()
{
	//empty 10000 size array
	const int numberSize = 10000;
	int numbers[numberSize];
	int savedNumbers[numberSize];
	randomize(numbers, numberSize);
	clock_t start, end;
	double time_taken;
	bool yes = true;
	do {
		system("cls");
		int selection;
		cout << "Choose which algorithm to use to sort the array:\n" <<
			"1 - Selection Sort\n" <<
			"2 - Insertion Sort\n" <<
			"3 - Bubble Sort\n" <<
			"4 - Merge Sort\n" <<
			"5 - Quick Sort\n" <<
			"6 - Heap Sort\n" <<
			"0 - Exit\n";
		cout << "Enter the number of the selection here: ";
		cin >> selection;


		switch (selection) {
		case 1:
			cout << "Selection" << endl;
			saveArray(numbers, savedNumbers, numberSize); // save array before sorted

			start = clock();
			SelectionSort(numbers, numberSize);
			end = clock();

			firstFifty(numbers); // print the first 50

			time_taken = double(end - start) / double(CLOCKS_PER_SEC);
			cout << "Time taken by selection sort algorithm is : " << fixed
				<< time_taken << setprecision(5);
			cout << " sec " << endl;

			saveArray(savedNumbers, numbers, numberSize); // revert array back to original state
			system("Pause");
			break;
		case 2:
			cout << "insertion" << endl;
			saveArray(numbers, savedNumbers, numberSize); // save array before sorted

			start = clock();

			InsertionSort(numbers, numberSize);

			end = clock();
			
			firstFifty(numbers); // print the first 50

			time_taken = double(end - start) / double(CLOCKS_PER_SEC);
			cout << "Time taken by insertion sort algorithm is : " << fixed
				<< time_taken << setprecision(5);
			cout << " sec " << endl;

			saveArray(savedNumbers, numbers, numberSize); // revert array back to original state
			system("Pause");

			break;
		case 3:
			cout << "bubble" << endl;
			saveArray(numbers, savedNumbers, numberSize); // save array before sorted

			start = clock();
			BubbleSort(numbers, numberSize);
			end = clock();

			firstFifty(numbers); // print the first 50

			time_taken = double(end - start) / double(CLOCKS_PER_SEC);
			cout << "Time taken by bubble sort algorithm is : " << fixed
				<< time_taken << setprecision(5);
			cout << " sec " << endl;

			saveArray(savedNumbers, numbers, numberSize); // revert array back to original state
			system("Pause");

			break;
		case 4:
			cout << "merge" << endl;
			saveArray(numbers, savedNumbers, numberSize); // save array before sorted

			start = clock();
			MergeSort(numbers, 0, numberSize-1);
			end = clock();

			firstFifty(numbers); // print the first 50

			time_taken = double(end - start) / double(CLOCKS_PER_SEC);
			cout << "Time taken by merge sort algorithm is : " << fixed
				<< time_taken << setprecision(5);
			cout << " sec " << endl;

			saveArray(savedNumbers, numbers, numberSize); // revert array back to original state
			system("Pause");

			break;
		case 5:
			cout << "quick" << endl;
			saveArray(numbers, savedNumbers, numberSize); // save array before sorted

			start = clock();
			quickSort(numbers, 0, numberSize - 1);
			end = clock();

			firstFifty(numbers); // print the first 50

			time_taken = double(end - start) / double(CLOCKS_PER_SEC);
			cout << "Time taken by quick sort algorithm is : " << fixed
				<< time_taken << setprecision(5);
			cout << " sec " << endl;

			saveArray(savedNumbers, numbers, numberSize); // revert array back to original state
			system("Pause");

			break;
		case 6:
			cout << "heap" << endl;
			saveArray(numbers, savedNumbers, numberSize); // save array before sorted

			start = clock();
			Heapsort(numbers, numberSize);
			end = clock();

			firstFifty(numbers); // print the first 50

			time_taken = double(end - start) / double(CLOCKS_PER_SEC);
			cout << "Time taken by program is : " << fixed
				<< time_taken << setprecision(5);
			cout << " sec " << endl;

			saveArray(savedNumbers, numbers, numberSize); // revert array back to original state
			system("Pause");

			break;
		case 0:
			cout << "exit" << endl;
			yes = false;
			break;
		default:
			cout << "Invalid. Try again.\n";
			system("Pause");
		}
		
	} while (yes == true);
}
