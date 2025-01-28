#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <climits>
#include <fstream>
#include <chrono>           // to compute time taken by the program or loop
using namespace std; 
// using namespace chrono;

void linearSearch(int *arr, int size, int key, int &compCount){
    for (int i = 0; i < size; i++){
        compCount += 1;
        if (arr[i] == key){
            return;
        }
    }
    return;
}

void printVector(vector<int> vec){
    for(int i=0;i<vec.size();i++){
        std::cout<<vec[i]<<" ";
    }
    std::cout<<endl;
}

int main(){
    srand(time(0));
    int randomNumber,compCount=0;       //comparision count variable
    int* arr;
    int* key;
    int minBound=1,start;

    
    // file opening 
    ofstream csvFile("search_comparisons.csv");
    csvFile << "Data Size,Best Case,Worst Case,Average Case,Time Taken\n"; 

    
    // vector's to store the best, average and worst case
    vector<int> bestCase;
    vector<int> averageCase;
    vector<int> worstCase;


    for(int i=10;i<=1000;i=i+5){
        int bCase=INT16_MAX;
        int wCase=INT16_MIN;
        int aCase=0;
        start=0;
        int maxBound=i;
        arr = new int[i];
        key = new int[i+1];
        int element;
        for(element=1 ; element<=i ; element++){
            randomNumber = minBound + rand() % (maxBound - minBound + 1);
            arr[start] = randomNumber;
            randomNumber = minBound + rand() % (maxBound - minBound + 1);
            key[start] = randomNumber;
            start += 1;
        }
        key[start] = element;

        auto timeStart = chrono::high_resolution_clock::now();
        for(int j=0;j<i+1;j++){            
            compCount=0;
            linearSearch(arr,i,key[j],compCount);

            aCase += compCount;
            wCase = wCase>compCount?wCase:compCount;
            bCase = bCase>compCount?compCount:bCase;
        }

        //Inserting best, average and worst case in their respective vectors
        bestCase.push_back(bCase);
        worstCase.push_back(wCase);
        averageCase.push_back(aCase/i);
        
        auto timeStop = chrono::high_resolution_clock::now();
        auto totalTime = chrono::duration_cast<chrono::microseconds>(timeStop - timeStart);
        std::cout<<"Total time taken "<<i<<" : "<<totalTime.count()<<endl;

        // pushing data in the file
        csvFile << i << "," << bCase << "," << wCase << "," << aCase/i <<","<< totalTime.count() << "\n";

        // Unallocating the current array for element and array for the key
        delete[] arr;
        delete[] key;
    }

    // closing file
    csvFile.close(); 
    std::cout << "Results have been exported to 'search_comparisons.csv'." << endl;

    // cout<<"Best Case : ";
    // printVector(bestCase);
    
    // cout<<"Worst Case : ";
    // printVector(worstCase);

    // cout<<"Average Case : ";
    // printVector(averageCase);

    return 0;
}