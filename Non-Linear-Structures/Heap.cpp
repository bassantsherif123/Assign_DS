#include <bits/stdc++.h>
#include "Item.h"
using namespace std;


void heapify(vector<Item>&a, int n, int i, int choice){
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

void heapSort(vector<Item>&a, int n, int choice){
    for(int i=(n/2-1);i>=0;i--){
        heapify(a,n,i,choice);
    }
    for(int i = n -1;i>=0;i--){
        swap(a[0], a[i]);
        heapify(a,i,0,choice);
    }
}
class heap {
private:
    vector<Item> items;
public:
    void add(Item it) {
        items.push_back(it);
    }
    void remove(Item it) {
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

    void sortPrice(int choice) {
        vector<Item> copy;
        copy = items;
        heapSort(copy,copy.size(),choice);

        for (auto& item : copy) {
            item.print();
        }
    }
};
