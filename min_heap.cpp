//min_heap.cpp
/* Operations on min heap are getmini(), remove min: extractmin(),change a key: decreasekey()
insert(), delete().
*/

#include<iostream>
#include<string>

using namespace std;

void swap(int *x, int *y);

class minHeap
{
    int *harr; //pointer to the array of elements in heap;
    int capacity; // maximum possible size of a heap;
    int heapsize; // current number of elements in a heap;
    public:
    int get_heapsize(){
        return heapsize;
    };
    minHeap(int capacity); //constructor.
    void miniheapify(int); //heapify a subtree with the root at given index.
    int parent(int i) 
    {return (i-1)/2;}
    int left(int i)
    {
        return 2*i+1;
    }
    int right(int i)
    {
        return 2*i+2;
    }
    int extractmin();

    void decreasekey(int i, int new_val);

    int getmin(){
        return harr[0];
    }

    void deletekey(int i); //delete a key at index i;

    void insertkey(int k); //insert a new key;

};

void swap(int* x, int* y){
    int temp = *x;
    *x = *y ;
    *y = temp;
}

minHeap::minHeap(int cap){
    heapsize = 0;
    harr = new int[cap];
    capacity = cap;

}

void minHeap::insertkey(int k){
    if (heapsize == capacity){
        cout << "\n Overflow: can't insert new key" << endl;
    }
    heapsize++;
    int i = heapsize -1;
    harr[i] = k;

    while(i!=0 && harr[parent(i)]>harr[i]){
        swap(harr[parent(i)],harr[i]);
        i = parent(i); // traverse to make sure the root is the minimum.
    }
}

void minHeap::decreasekey(int i, int new_val){
    harr[i] = new_val;
    while(i!=0 && harr[parent(i)]>harr[i]){
        swap(harr[parent(i)],harr[i]);
        i = parent(i);
    }
}

void::minHeap::miniheapify(int k){
    int l = left(k);
    int r = right(k);
    int smallest = k;
    if (l < heapsize && harr[l]<harr[k]){
        smallest = l;
    }
    if (r < heapsize && harr[r] < harr[smallest]){
        smallest = r;
    }
    if (smallest != k){
        swap(harr[k],harr[smallest]);
        miniheapify(smallest);
    }
    
}

// method of removing the root from a min heap.
int minHeap::extractmin(){
    if (heapsize <= 0){
        cout << "no elements" << endl;
        return INT_MAX;
    }
    if (heapsize == 1){
        heapsize--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heapsize-1]; // key operation.
    heapsize--;
    miniheapify(0);
    return root;
}

void minHeap::deletekey(int i){
    decreasekey(i, INT_MIN);
    extractmin();
}

int main(){
    minHeap a(11);
    int b[11];
    int temp,count=0;
    a.insertkey(2);
    a.insertkey(3);
    a.insertkey(1);
    a.insertkey(15);
    a.insertkey(5);
    a.insertkey(4);
    a.insertkey(45);
    while(a.get_heapsize() > 0){
    b[count]=a.extractmin();
    temp = b[count];
    count++;
    cout << temp << endl;
    }
    //cout << "print array b \n" << b << endl;

    return 0;
}
