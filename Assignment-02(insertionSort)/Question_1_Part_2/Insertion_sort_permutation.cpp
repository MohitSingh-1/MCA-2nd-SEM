#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm> //for rnad and srand
#include <ctime>
#include <fstream>
using namespace std;

// Insertion sort function
int insertionSort(vector<int> arr, int size){
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

// to print vector
void print(vector<int> vec){
    cout<<endl;
    cout<<"Array is : ";
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

// function to swap two numbers in a vector
void swap(vector<int>& vec,int start,int end){
    int temp = vec[start];
    vec[start] = vec[end];
    vec[end] = temp;
}

//Function to find permutation of the given vector vec
void permute(vector<int> vec,vector<vector<int>>& ans,int index){
    if(index>= vec.size()){
        ans.push_back(vec);
        return;
    }
    for(int i=index;i<vec.size();i++){
        swap(vec,index,i);
        permute(vec,ans,index+1);
        swap(vec,index,i);
    }
}

int fact(int n){
    if(n<=1)return 1;
    return n*fact(n-1);
}

// Main function
int main(){
    srand(time(0));
    int size=5;
    vector<int> vec;

    for(int i=0;i<size;i++){
        int random_number = rand()%100;
        vec.push_back(random_number);
    }
    print(vec);

    vector<vector<int>> pVector;
    int index=0;
    permute(vec,pVector,index);

    int bestCase = INT16_MAX;
    int worstCase = INT16_MIN;
    int averageCase = 0;
    for(int i=0;i<fact(size);i++){
        //sorting the data and taking the number of comparision as output
        int compare = insertionSort(pVector[i],size);
        bestCase = bestCase > compare ? compare : bestCase;
        worstCase = worstCase > compare ? worstCase : compare;
        averageCase += compare;
    }

    // output (time complexity)
    cout<<"Best Case : "<<bestCase<<endl;
    cout<<"Worst Case : "<<worstCase<<endl;
    cout<<"Average Case : "<<averageCase/fact(size)<<endl;
    return 0;
}