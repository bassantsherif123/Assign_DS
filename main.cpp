
#include <bits/stdc++.h>
using namespace std;
class item {
public:
    string name;
    string category;
    int price;

    item(string n, string c, int p) {
        name=n;
        category=c;
        price=p;
    }
    bool operator>(item &it) {//price ascendingly
        return price>it.price;
    }
    bool operator>=(item &it) {//name ascendingly
        return name>it.name;
    }
    bool operator<=(item &it) {//price descindingly
        return price<it.price;
    }
    bool operator<(item &it) {//name ascendingly
        return name<it.name;
    }
    void displayItem() {
        std::cout << name << " (" << category << "): $" <<price << "\n";

    }
};

void heapify(vector<item>&a, int n, int i, int choice){
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

void heapSort(vector<item>&a, int n, int choice){
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
    vector<item> items;
public:
    void add(item it) {
        items.push_back(it);
    }
    void remove(item it) {
        bool flag = true;
        for(int i=0;i<items.size();i++) {
            if(items[i].name==it.name) {
                items.erase(items.begin()+i);
                flag=false;
                break;
            }
        }
        if(flag)cout<<"No such item/n";
    }
    void displayItems() {
        for (const auto& item : items) {
            std::cout << item.name << " (" << item.category << "): $" << item.price << "\n";
        }
    }

    void sortPrice(int choice) {
        vector<item> copy;
        copy = items;
        heapSort(copy,copy.size(),choice);

        for (const auto& item : copy) {
            std::cout << item.name << " (" << item.category << "): $" << item.price << "\n";
        }
    }
};



//sort price ascendingly  1
//sort price descendingly  2
//sort name ascendingly 3
//sort name descendingly  4
int main() {
    heap x;
    bool f=true;

    while (f) {
        cout<<"1. Add item data,\n2. Remove item data,\n3. Display the item data normally\n"
              "4. Display all the items sorted by their name ascending\n"
              "5. Display all the items sorted by their name descending,\n"
              "6. Display all the items sorted by their prices ascending\n"
              "7. Display all the items sorted by their prices descending.\n"
              "any other number to exit\n";
        int choice;
        cin>>choice;
        if(choice==1) {
            string n,c;
            int p;
            cout<<"Enter the name of the item:";
            cin>>n;
            cout<<"Enter the category of the item:";
            cin>>c;
            cout<<"Enter the price of the item:";
            cin>>p;
            item v (n,c,p);
            x.add(v);
        }
        else if(choice==2) {
            string n,c;
            int p;
            cout<<"Enter the name of the item you want to remove:";
            cin>>n;
            cout<<"Enter the category of the item:";
            cin>>c;
            cout<<"Enter the price of the item:";
            cin>>p;
            item v (n,c,p);
            x.remove(v);
        }
        else if(choice==3) {
            x.displayItems();
        }
        else if(choice == 4) {
            x.sortPrice(3);
        }
        else if(choice == 5) {
            x.sortPrice(4);
        }
        else if(choice == 6) {
            x.sortPrice(1);
        }
        else if(choice == 7) {
            x.sortPrice(2);
        }
        else {
            f=false;
        }
    }
    cout<<"\nDONE\n";
}

