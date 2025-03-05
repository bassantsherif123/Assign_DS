#include <bits/stdc++.h>
#include "Heap.cpp"
//Priority queue class and example using it
//choice = 0 for max heap, =1 for min heap
using namespace std;
class priorityQueue {
private:
    Heap pq;
public:
    void insertPQ(int it,int choice) {
        pq.insert(it,choice);//insertion maintains the heap property.
    }
    int maxElementPQ(int choice) {//extracting the highest priority element.
        if(choice==0) {//descending order so the highest priority is the max element
            int max = pq.maxElement(choice);
            return max;
        }
        else {//ascending order so the highest priority is the min element
            int min = pq.minElement(choice);
            return min;
        }
    }
};
int main() {
    priorityQueue p;
    int choice;
    cout<<"Please enter 0 if you want Descending pq or any other integer if you want Ascending pq:\n";
    cin>>choice;
    p.insertPQ(5,choice);
    p.insertPQ(3,choice);
    p.insertPQ(7,choice);
    cout<<p.maxElementPQ(choice)<<'\n';
    cout<<p.maxElementPQ(choice)<<'\n';
}
