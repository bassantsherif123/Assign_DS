#include <bits/stdc++.h>
#include "Item.h"
using namespace std;


void heapify(vector<Item>&a, int n, int i, int choice){//Max heapify or Min heapify
    if(choice==1) {
        int largest =i;
        int left=(2*i + 1), right=(2*i +2);
        if(left<n && a[left]>a[largest])largest=left;
        if(right<n && a[right]>a[largest])largest=right;
        if(largest!=i){
            swap(a[i],a[largest]);
            heapify(a,n,largest,choice);
        }
    }
    else if(choice==2) {
        int largest =i;
        int left=(2*i + 1), right=(2*i +2);
        if(left<n && a[left]<=a[largest])largest=left;
        if(right<n && a[right]<=a[largest])largest=right;
        if(largest!=i){
            swap(a[i],a[largest]);
            heapify(a,n,largest,choice);
        }
    }
    else if(choice==3) {
        int largest =i;
        int left=(2*i + 1), right=(2*i +2);
        if(left<n && a[left]>=a[largest])largest=left;
        if(right<n && a[right]>=a[largest])largest=right;
        if(largest!=i){
            swap(a[i],a[largest]);
            heapify(a,n,largest,choice);
        }
    }
    else if(choice==4) {
        int largest =i;
        int left=(2*i + 1), right=(2*i +2);
        if(left<n && a[left]<a[largest])largest=left;
        if(right<n && a[right]<a[largest])largest=right;
        if(largest!=i){
            swap(a[i],a[largest]);
            heapify(a,n,largest,choice);
        }
    }
}

void heapSort(vector<Item>&a, int n, int choice){//The main heap sort function
    for(int i=(n/2-1);i>=0;i--){
        heapify(a,n,i,choice);//build the heap
    }
    for(int i = n -1;i>=0;i--){
        swap(a[0], a[i]);//arrange the array in an order(the first element is arranged)
        heapify(a,i,0,choice);//build the heap again for the rest of the items
    }
}
class heap {
private:
    vector<Item> items;
public:
    void add(Item it) {
        items.push_back(it);
    }
    void remove(Item it) {//search for the item by its name then remove it
        bool flag = true;
        for(int i=0;i<items.size();i++) {
            if(items[i] == it) {
                items.erase(items.begin()+i);
                flag=false;
                break;
            }
        }
        if(flag)cout<<"No such item/n";
    }
    void displayItems() {
        for (auto& item : items) {
            item.print();
        }
    }

    void sortPrice(int choice) {//take the choice of the user of how he wants to arrange and then send it to the sorting function 
        vector<Item> copy;
        copy = items;
        heapSort(copy,copy.size(),choice);

        for (auto& item : copy) {//display the sorted items
            item.print();
        }
    }
};
