// 20200408_Week9Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
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
			SelectionSort(numbers, numberSize);
			firstFifty(numbers); // print the first 50
			saveArray(savedNumbers, numbers, numberSize); // revert array back to original state
			system("Pause");
			break;
		case 2:
			cout << "insertion" << endl;
			saveArray(numbers, savedNumbers, numberSize); // save array before sorted
			InsertionSort(numbers, numberSize);
			firstFifty(numbers); // print the first 50
			saveArray(savedNumbers, numbers, numberSize); // revert array back to original state
			system("Pause");

			break;
		case 3:
			cout << "bubble" << endl;
			saveArray(numbers, savedNumbers, numberSize); // save array before sorted
			BubbleSort(numbers, numberSize);
			firstFifty(numbers); // print the first 50
			saveArray(savedNumbers, numbers, numberSize); // revert array back to original state
			system("Pause");

			break;
		case 4:
			cout << "merge" << endl;
			saveArray(numbers, savedNumbers, numberSize); // save array before sorted
			MergeSort(numbers, 0, numberSize-1);
			firstFifty(numbers); // print the first 50
			saveArray(savedNumbers, numbers, numberSize); // revert array back to original state
			system("Pause");

			break;
		case 5:
			cout << "quick" << endl;
			saveArray(numbers, savedNumbers, numberSize); // save array before sorted
			quickSort(numbers, 0, numberSize - 1);
			firstFifty(numbers); // print the first 50
			saveArray(savedNumbers, numbers, numberSize); // revert array back to original state
			system("Pause");

			break;
		case 6:
			cout << "heap" << endl;
			saveArray(numbers, savedNumbers, numberSize); // save array before sorted
			Heapsort(numbers, numberSize);
			firstFifty(numbers); // print the first 50
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
