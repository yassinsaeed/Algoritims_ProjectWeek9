#include <iostream>
#include "bubblesort.h"
using namespace std;

void BubbleSort(int numbers[], int arraysize) {
    int temp;
    for (int i = 0; i < arraysize - 1; i++) {
        for (int j = 0; j < arraysize - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}