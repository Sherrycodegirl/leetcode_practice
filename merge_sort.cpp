// Edit by sherry Qin, on Feb 3rd 2022. merge_sort.cpp
#include <iostream>
#include <string>

using namespace std;

void merge(int arr[], int const left, int const mid, int const right){
    auto const subarrayone = mid - left + 1;
    auto const subarraytwo = right - mid;

    auto *leftarr = new int[subarrayone];
    auto *rightarr = new int[subarraytwo];

    for (int i=0;i<subarrayone; i++){
        leftarr[i] = arr[left+i];
    }
    
    for (int i=0;i< subarraytwo;i++){
        rightarr[i] = arr[mid+i+1];
    }

    auto index_subarrone = 0, index_subarrtwo=0;
    int index_mergedarr = left; //initial index of merged array.


    while (index_subarrone < subarrayone && index_subarrtwo < subarraytwo)
    {
        if (leftarr[index_subarrone] <= rightarr[index_subarrtwo]){
            arr[index_mergedarr] = leftarr[index_subarrone];
            index_subarrone++;

        }
        else{
            arr[index_mergedarr] = rightarr[index_subarrtwo];
            index_subarrtwo++;

        }
        index_mergedarr++;
    }

    while(index_subarrtwo < subarraytwo){
        arr[index_mergedarr] = rightarr[index_subarrtwo];
        index_subarrtwo++;
        index_mergedarr++; 
    }
    while(index_subarrone < subarrayone){
        arr[index_mergedarr] = leftarr[index_subarrone];
        index_subarrone++;
        index_mergedarr++;
    }

}

void mergesort(int arr[], int const begin, int const end){
    if (begin >=end){
        return; // key: stop condition;
    }
    auto mid = (begin+end)/2;
    mergesort(arr, begin, mid);
    mergesort(arr,mid+1,end);
    merge(arr,begin,mid,end); // divide and conquer.

}

void printarray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
        cout << "\n";
    }

}


int main(){
    int arr[]={1,4,3,6,5,8,5,3};
    auto n = sizeof(arr)/sizeof(arr[0]);
    cout << "The original array is \n";
    printarray(arr,n);
    cout << "After sorting thr array is: \n";
    mergesort(arr, 0,n-1);
    printarray(arr,n);
    return 0;
}