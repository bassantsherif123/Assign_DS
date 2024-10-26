#include <bits/stdc++.h>
using namespace std;
//Main heap class
//choice = 0 for max heap, =1 for min heap
class Heap {
private:
    vector<int> heap;
public:
    void insert(int it,int choice) {
        heap.push_back(it);//add it as the last element in the heap
        int n=heap.size()-1;
        heapifyUp(n,choice);//then start swaping to put it in its right position
    }
    void displayHeap() {
        for (auto& item : heap) {
            cout<<item<<' ';
        }
        cout<<'\n';
    }
    void heapifyUp(int index,int choice) {//if a large element was down in max and vice versa in min
        int parent = ((index-1)/2);
        if(choice==0) {//MAX HEAPIFY
            while (index > 0 && heap[parent] < heap[index]) {//if it was greater than its parent then switch between them
                swap(heap[parent], heap[index]);
                index = parent;
                parent = ((index-1)/2);//now do it with the new parent
            }//till its on the right place
        }
        else {//MIN HEAPIFY
            while (index > 0 && heap[parent] > heap[index]) {//if it was smaller than its parent then switch between them
                swap(heap[parent], heap[index]);
                index = parent;
                parent = ((index-1)/2);//now do it with the new parent
            }//till its on the right place
        }
    }
    void heapifyDown(int i,int choice) {//if a small element was up
        int n=heap.size();
        int current = i;
        int left=(2*i + 1), right=(2*i +2);//his left and right childs
        if(choice==0) {//MAX HEAPIFY
            if(left<n && heap[left]>heap[current])current=left;
            if(right<n && heap[right]>heap[current])current=right;
            //now current is the largest number bet. the element and his left and right child
        }
        else {//MIN HEAPIFY
            if(left<n && heap[left]<heap[current])current=left;
            if(right<n && heap[right]<heap[current])current=right;
            //now current is the smallest number bet. the element and his left and right child
        }
        if(current!=i) {
            swap(heap[i],heap[current]);//swap between them
            heapifyDown(current,choice);//keep doing it till its on the right place
        }
    }
    int maxElement(int choice){
        if (heap.size() == 0) {
            cout<<"The heap is empty";//no elements
            return 0;
        }
        if(choice==0) {//MAX HEAPIFY
            int maxElement = heap[0];
            heap[0] = heap.back();//replace it with the last element
            heap.pop_back();
            heapifyDown(0,choice);//then resort the heap to put the last element in its right place and find the new root
            return maxElement;
        }
        else {//MIN HEAPIFY
            int maxElement=heap[0];
            int index=0;
            for(int i=0;i<heap.size();i++) {
                if (heap[i]>=maxElement) {//finding the largest element and its location
                    maxElement=heap[i];
                    index=i;
                }
            }
            heap.erase( next(heap.begin(),index ) );//erase it and since it's the largest in min heapify
            //so it has no children
            return maxElement;
        }
    }
    int minElement(int choice) {
        if (heap.size() == 0) {
            cout<<"The heap is empty";//no elements
            return 0;
        }
        if(choice==0) {//MAX HEAPIFY
            int minElement=heap[0];
            int index=0;
            for(int i=0;i<heap.size();i++) {
                if (heap[i]<=minElement) {//fing the smallest element and its location
                    minElement=heap[i];
                    index=i;
                }
            }
            heap.erase( next(heap.begin(),index ) );//erase it and since it's the smallest so it has no children
            return minElement;
        }
        else {
            int minElement = heap[0];
            heap[0] = heap.back();//replace it with the last element
            heap.pop_back();
            heapifyDown(0,choice);//then resort the heap to put the last element in its right place and find the new root
            return minElement;
        }
    }

};



