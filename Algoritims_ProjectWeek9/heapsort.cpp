#include <iostream>
#include "heapsort.h"
using namespace std;

void MaxHeapPercolateDown(int nodeIndex, int heapArray[], int arraySize) {
    int childIndex = 2 * nodeIndex + 1;
    int value = heapArray[nodeIndex];

        while (childIndex < arraySize) {
            // Find the max among the node and all the node's children
            int maxValue = value;
            int maxIndex = -1;
                for (int i = 0; i < 2 && i + childIndex < arraySize; i++) {
                    if (heapArray[i + childIndex] > maxValue) {
                        maxValue = heapArray[i + childIndex];
                        maxIndex = i + childIndex;
                    }
                }

            if (maxValue == value) {
                return;
            }
            else {
                int temp = heapArray[nodeIndex];
                heapArray[nodeIndex] = heapArray[maxIndex];
                heapArray[maxIndex] = temp;
                nodeIndex = maxIndex;
                childIndex = 2 * nodeIndex + 1;
            }
        }
}

void Heapsort(int numbers[], int numbersSize) {
    // Heapify numbers array
    for (int i = numbersSize / 2 - 1; i >= 0; i--) {
        MaxHeapPercolateDown(i, numbers, numbersSize);
    }

    for (int i = numbersSize - 1; i > 0; i--) {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        MaxHeapPercolateDown(0, numbers, i);
    }
}