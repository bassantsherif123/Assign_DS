#include <bits/stdc++.h>
using namespace std;

void Non_Linear();

class Item
{
    string itemName;
    string category;
    int price;
public:
    Item(string name, string c, int p) : itemName(name), category(c), price(p) {}
    bool operator<(const Item& other)
    {
        return itemName < other.itemName;
    }
    bool operator>=(const Item &other)
    {
        return itemName >= other.itemName;
    }
    bool operator<=(const Item &other)
    {
        return price <= other.price;
    }
    bool operator>(const Item& other)
    {
        return price > other.price;
    }
    bool operator==(const Item &other)
    {
        return itemName == other.itemName && category == other.category && price == other.price;
    }
    void print(ofstream &outputFile)
    {
        outputFile << "Name: " << itemName << '\n'
                   << "Category: " << category << '\n'
                   << "price: $" << price << "\n\n";
    }
    void print()
    {
        cout << "Name: " << itemName << '\n'
             << "Category: " << category << '\n'
             << "price: $" << price << "\n\n";
    }
};

//_____________________________________
   
class BST{
    class Node{
    public:
        Item value;
        Node *left, *right;
        Node(Item& x): value(x), left(nullptr), right(nullptr){}
    };
    Node* root;
    void inOrder(Node* x) {
        // Left Root Right
        if (x == nullptr) {
            return;
        }
        inOrder(x->left);
        x->value.print();
        inOrder(x->right);
    }
    void reverseInOrder(Node* x) {
        // Right Root Left
        if (x == nullptr) {
            return;
        }
        reverseInOrder(x->right);
        x->value.print();
        reverseInOrder(x->left);
    }
//    void removeNode(Node* n) {
//        Node *current, *parent, *tmp;
//        if(n == nullptr) {
//            cout << "The node you want to delete doesn't exist\n";
//        }
//        else if(n->left == nullptr && n->right == nullptr) {
//            tmp = n;
//            n = nullptr;
//            delete tmp;
//        }
//        else if(n->left == nullptr) {
//            // Node has no left child
//            tmp = n;
//            n = tmp->right;
//            delete tmp;
//        }
//        else if(n->right == nullptr) {
//            // Node has no right child
//            tmp = n;
//            n = tmp->left;
//            delete tmp;
//        }
//        else {
//            // Node has both children
//            current = n->left;
//            parent = nullptr;
//            while(current->right != nullptr) {
//                parent = current;
//                current = current->right;
//            }
//            n->left = current->left;
//            if(parent == nullptr) {
//                n->left = current->left;
//            }
//            else {
//                parent->right = current->left;
//            }
//            delete current;
//        }
//    }
public:
    BST(): root(nullptr) {}
    void add(Item x, bool price);
//    void remove(Item x) {
//        Node *parent, *current;
//        bool found = false;
//        if (isEmpty()) {
//            cout << "Tree has no item to delete.\n";
//        }
//        else {
//            current = root;
//            parent = root;
//            while(current != nullptr && !found) {
//                if(current->value == x) {
//                    found = true;
//                }
//                else {
//                    parent = current;
//                    if(current->value >= x) {
//                        current = current->left;
//                    }
//                    else {
//                        current = current->right;
//                    }
//                }
//            }
//            if(current == nullptr) {
//                cout << "Couldn't find the item you want to delete in the tree.\n";
//            }
//            else if(found) {
//                if(current == root) {
//                    removeNode(root);
//                }
//                else if(parent->value >= x) {
//                    removeNode(parent->left);
//                }
//                else {
//                    removeNode(parent->right);
//                }
//            }
//        }
//    }
    bool isEmpty() {
        return root == nullptr;
    }

    void displaySortedByNameAscending() {
        inOrder(root);
    }
    void displaySortedByNameDescending() {
        reverseInOrder(root);
    }
    void displaySortedByPriceAscending() {
        inOrder(root);
    }
    void displaySortedByPriceDescending() {
        reverseInOrder(root);
    }
};

void BST::add(Item x, bool price) {
    // Items are added in tree according to itemName
    Node *current = root, *parent = nullptr;
    while(current != nullptr) {
        parent = current;
        if((!price && current->value < x) || (price && current->value <= x)) {
            current = current->right;
        }
        else {
            current = current->left;
        }
    }
    if(root == nullptr) {
        root = new Node(x);
    }
    else if((!price && parent->value >= x) || (price && parent->value > x)) {
        parent->left = new Node(x);
    }
    else {
        parent->right = new Node(x);
    }
}

//______________________________________
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


// _____________________________________
vector<Item> items;

// read from input.txt
void readItems(istream& Input)
{
    items.clear();
    if (!Input)
    {
        cerr << "Failed to open the input file.\n";
        return;
    }
    else
    {
        int n;
        string name, c;
        int p;
        Input >> n;
        while (n--)
        {
            Input.ignore();
            getline(Input, name);
            getline(Input, c);
            Input >> p;
            items.push_back(Item(name, c, p));
        }
    }
}

//_____________________________________
int main() {
//    BST t1,t2;
//cout << t1.isEmpty() << '\n';
//
//    t1.add(Item("tt", "ii", 9), 0);
//    t1.add(Item("i", "c", 90), 0);
//    t2.add(Item("tt", "ii", 9), 1);
//    t2.add(Item("i", "c", 90), 1);
//    cout << t2.isEmpty() << '\n';
    ifstream Input("../input.txt");
    readItems(Input);
    Non_Linear();
//    BST<int> t;
//cout << t.isEmpty() << '\n';
//t.insert(5);
//    cout << t.isEmpty() << '\n';
//    cout << t.search(5) << '\n';
    return 0;
}

//_____________________________________
void menu(){
    // Shows the menu the user can choose from
    cout<<"Please select a non-linear structure:\n"
          "1- Binary Search Trees (BST)\n"
          "2- Heaps\n"
          "3- AVL Trees\n";
}

void miniMenu(){
    cout << "Choose the operation you want to apply or 0 to exit::\n"
            "1. Add item data.\n"
            "2. Remove item data.\n"
            "3. Display the item data normally.\n"
            "4. Display all the items sorted by their name ascending.\n"
            "5. Display all the items sorted by their name descending.\n"
            "6. Display all the items sorted by their prices ascending.\n"
            "7. Display all the items sorted by their prices descending.\n";
}

void Non_Linear(){
    int ChooseStruct, ChooseOp;

    // Call Menu function to show the menu
    menu();
    cin >> ChooseStruct;
    while(ChooseStruct != 1 && ChooseStruct != 2 && ChooseStruct != 3) {
        cout << "Your choice doesn't exist in the menu.\n";
        menu();
        cin >> ChooseStruct;
    }

    // Goes to the case according to user's choice
    if (ChooseStruct == 1) {
        string x, y;
        int z;
        BST tName, tPrice;
        for (auto& item: items) {
            tName.add(item, 0);
            tPrice.add(item, 1);
        }
        miniMenu();
        while (cin >> ChooseOp, ChooseOp != 0) {
            switch (ChooseOp) {
                case 1:
                    cout << "Enter the item details in the corresponding order\n(Name, Category, Price):\n";
                    cin >> x >> y >> z;
                    tName.add(Item(x, y, z), 0);
                    tPrice.add(Item(x, y, z), 1);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    tName.displaySortedByNameAscending();
                    break;
                case 5:
                    tName.displaySortedByNameDescending();
                    break;
                case 6:
                    tPrice.displaySortedByPriceAscending();
                    break;
                case 7:
                    tPrice.displaySortedByPriceDescending();
                    break;
                default:
                    cout << "Your choice doesn't exist in the menu.\n";
                    break;
            }
            miniMenu();
        }
    }
    else if(ChooseStruct == 2) {
        heap x;
        for (auto& item: items) {
            x.add(item);
        }
        string n,c;
        int p;
        miniMenu();
        while (cin >> ChooseOp, ChooseOp != 0) {
            switch (ChooseOp) {
                case 1:
                    cout<<"Enter the name of the item:";
                    cin>>n;
                    cout<<"Enter the category of the item:";
                    cin>>c;
                    cout<<"Enter the price of the item:";
                    cin>>p;
                    x.add(Item (n,c,p));
                    break;
                case 2:
                    cout<<"Enter the name of the item you want to remove:";
                    cin>>n;
                    cout<<"Enter the category of the item:";
                    cin>>c;
                    cout<<"Enter the price of the item:";
                    cin>>p;
                    x.remove(Item (n,c,p));
                    break;
                case 3:
                    x.displayItems();
                    break;
                case 4:
                    x.sortPrice(3);
                    break;
                case 5:
                    x.sortPrice(4);
                    break;
                case 6:
                    x.sortPrice(1);
                    break;
                case 7:
                    x.sortPrice(2);
                    break;
                default:
                    cout << "Your choice doesn't exist in the menu.\n";
                    break;
            }
            miniMenu();
        }
    }
    else {
        miniMenu();
        while (cin >> ChooseOp, ChooseOp != 0) {
            switch (ChooseOp) {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                default:
                    cout << "Your choice doesn't exist in the menu.\n";
                    break;
            }
            miniMenu();
        }
    }
}

