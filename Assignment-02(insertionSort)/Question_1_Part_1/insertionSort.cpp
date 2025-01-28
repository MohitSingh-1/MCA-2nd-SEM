#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm> //for rnad and srand
#include <ctime>
#include <fstream>
using namespace std;

int insertionSort(int *arr, int size){
    int comparision = 0;
    int key;
    int j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            comparision++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return comparision;
}

int main()
{
    srand(time(0));

    int minBound = 1, maxBound = 100;
    int *arr;

    // file opening
    ofstream csvFile("search_comparisons.csv");
    csvFile << "DataSize,BestCase,WorstCase,AverageCase\n";

    for (int i = 10; i <= 100; i = i + 5)
    {
        int bestCase = INT16_MAX;
        int worstCase = INT16_MIN;
        int averageCase = 0;
        for (int j = 0; j < 10; j++)
        {

            arr = new int[i];
            for (int k = 0; k < i; k++)
            {
                int randomNumber = minBound + rand() % (maxBound - minBound + 1);
                arr[k] = randomNumber;
            }
            int compare = insertionSort(arr, i);
            bestCase = bestCase > compare ? compare : bestCase;
            worstCase = worstCase > compare ? worstCase : compare;
            averageCase += compare;

            delete[] arr;
            // printArray(arr, i);
        }

        // inserting data in the csv file
        csvFile << i << "," << bestCase << "," << worstCase << "," << averageCase / 10 << "\n";
    }
    return 0;
}