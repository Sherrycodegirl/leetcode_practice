//quicksort.cpp
// Edit by sherry Qin, on Feb 3rd 2022. quick_sort.cpp
#include <iostream>
#include <string>

using namespace std;

void swap(int* x, int*y){
    int temp = *x;
    *x = *y;
    *y = *x;
}

// Partiiton function takes the last element as the pivot,
// 
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1; // the index of the 

    for (int j=low; j<=high-1; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;

}

void quicksort(int arr[], int low, int high){
    if (low < high){
        int par= partition(arr, low, high);
        quicksort(arr,low,par-1);
        quicksort(arr,par+1,high);
    }
}

void printarray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
        cout << "\n";
    }

}


int main(){
    int arr[]={1,4,3,6,5,8,5,3,9};
    auto n = sizeof(arr)/sizeof(arr[0]);
    cout << "The original array is \n";
    printarray(arr,n);
    cout << "After sorting the array is: \n";
    quicksort(arr, 0,n-1);
    printarray(arr,n);
    return 0;
}