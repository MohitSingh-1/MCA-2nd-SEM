#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>        //for rnad and srand
#include <ctime>        
using namespace std;

void insertionSort(vector<int>& vec){
    int key;
    int j;
    for(int i=1;i<vec.size();i++){
        key = vec[i];
        j=i-1;
        while(j>=0 && key < vec[j] ){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
    }
}
void printVector(vector<int> vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
int main(){
    srand(time(0));
    vector<int> vec={4,2,5,1,20,12};
    printVector(vec);
    insertionSort(vec);
    printVector(vec);

    int n;
    int minBound=1,maxBound=100;
    cout<<"Enter data size : ";
    cin>>n;
    vector<int> nums(n,-1);
    for(int i=0;i<10;i++){
        for(int j=0;j<n;j++){
            int randomNumber = minBound + rand()%(maxBound-minBound+1);
            nums[j] = randomNumber;
        }
        printVector(nums);
        
    }
    return 0;
}