#include<iostream>
#include<string>

using namespace std;

void swap(int* x, int* y){
    int temp = *x;
    *x = *y ;
    *y = temp;
}

void heapify(int arr[], int n, int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int smallest = i;
    if (l < n &&  arr[l] < arr[smallest]){
        smallest = l;
    }
    if (r < n && arr[r] < arr[smallest]){
        smallest = r;
    }
    if (smallest != i){
        swap(arr[i],arr[smallest]); //swap with the smallest node;
        heapify(arr, n, smallest);
    }

}

void heapsort(int arr[],int n){
    for (int i = (n)/2 - 1;i>=0;i--){ // i is floor((n)/2 - 1)
        heapify(arr, n, i); //make the root is the smallest.
    }
    for (int i=n-1;i>0;i--){
        swap(arr[i],arr[0]);
        heapify(arr, i, 0); //replace the last one with the first one and make the root is the minimum in the 
                            // shrink array.
    }
}

void printarray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
        cout << "\n";
    }

}

int main(){
    int a[] = {1,10,5,2,6,4,8,0};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "length a = " << n << endl;
    cout << "\n";
    cout << "before sorting: ";
    printarray(a, n);
    cout << "after sorting: ";
    heapsort(a, n); 
    printarray(a, n);
}

