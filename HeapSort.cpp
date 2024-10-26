#include <bits/stdc++.h>
#include "Heap.cpp"
//Heap sort function and an example using all the heap class functions
//choice = 0 for max heap, =1 for min heap
using namespace std;
void heapSort(int arr[],int size){
    Heap h;
    for(int i=0; i<size;i++) {
        h.insert(arr[i],0);//Build a max heap from the array
    }
    for(int i=0; i<size;i++) {//repeatedly extract the max element from the heap
        arr[i]= h.maxElement(0);//descindengly ordered
    }

    for(int i=size-1;i>=0;i--) {
        cout<<arr[i]<<' ';//rebuild it until the array is sorted.
    }
    cout<<'\n';
}
int main() {
    int arr[]={5,7,12,3,9};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"SORTED ARRAY ";heapSort(arr,size);//tring the heap sort function
    int choice;
    cout<<"Please enter 0 if you want MAX HEAP or any other integer if you want MIN HEAP:\n";
    cin>>choice;
    Heap heap;
    for(int i=0;i<size;i++) {//tring the insert function
        heap.insert(arr[i],choice);
    }
    cout<<"HEAP ";heap.displayHeap();
    heap.insert(8,choice);
    cout<<"Heap after inserting 8: ";
    heap.displayHeap();
    cout<<"MAX ELEMENT ";
    cout<<heap.maxElement(choice)<<"\n";//tring the extract max function
    cout<<"Heap after extracting max element: ";
    heap.displayHeap();
    cout<<"MIN ELEMENT ";
    cout<<heap.minElement(choice)<<"\n";//tring the extract min function
    cout<<"Heap after extracting min element: ";
    heap.displayHeap();


}