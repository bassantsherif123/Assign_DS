#include <bits/stdc++.h>
using namespace std;

template<class T>
class DoubleLinkedList{
    class Node{
    public:
        T item;
        Node* Next;
        Node* Previous;
//    Node(const T&value):item(value),Next(nullptr),Previous(nullptr){}
    };
    Node* head;
    Node* tail;
    int size;
public:
    DoubleLinkedList():head(nullptr), tail(nullptr), size(0){}
    void insertAtHead(T value);
    void insertAtTail(T value);
    void insertAt(T value, int idx);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int idx);
    T retrieveAt(int idx);
    void replaceAt(T newValue, int idx);
    bool isExist(T value);
    bool isItemAtEqual(T value, int idx);
    void swap(int firstItemIdx, int secondItemIdx);
    bool isEmpty();
    int linkedListSize();
    void clear();
    void print();
    ~DoubleLinkedList(){
        clear();
    }
};

template<class T>
void DoubleLinkedList<T>::insertAtHead(T value) {
    Node *newNode = new Node;
    newNode->item = value;
    if (isEmpty()) {
        head = tail = newNode;
        newNode->Next = newNode->Previous = nullptr;
    } else {
        newNode->Next = head;
        newNode->Previous = nullptr;
        head->Previous = newNode;
        head = newNode;
    }
    size++;
}
template<class T>
void DoubleLinkedList<T>::insertAtTail(T value) {
    Node *newNode = new Node;
    newNode->item = value;
    if (isEmpty()) {
        head = tail = newNode;
        newNode->Next = newNode->Previous = nullptr;
    } else {
        newNode->Next = nullptr;
        newNode->Previous = tail;
        tail->Next = newNode;
        tail = newNode;
    }
    size++;
}
template<class T>
void DoubleLinkedList<T>::insertAt(T value, int idx) {
    // print error message if index given is out of range
    // except the idx = size as it means insert at tail
    if (idx < 0 || idx > size) {
        cerr << "Index given is out of range\n";
    } else {
        Node *newNode = new Node;
        newNode->item = value;
        if (idx == 0) {
            insertAtHead(value);
        } else if (idx == size) {
            insertAtTail(value);
        } else {
            Node *current = head;
            while (--idx) {
                current = current->Next;
            }
            newNode->Next = current->Next;
            current->Next = newNode;
            newNode->Previous = current;
            current->Next->Previous = newNode;
            size++;
        }
    }
}
template<class T>
void DoubleLinkedList<T>::removeAtHead() {
    if (isEmpty()) {
        cerr << "Empty list can't remove item\n";
    } else {
        Node *temp = head;
        head->Previous = nullptr;
        head = head->Next;
        delete temp;
        size--;
    }
}
template<class T>
void DoubleLinkedList<T>::removeAtTail(){
    if (isEmpty()) {
        cerr << "Empty list can't remove item\n";
    }
    else if(size ==1){
        removeAtHead();
    }
    else {
        Node *temp = head -> Next;
        Node *prevToTemp = head;
        while(temp!= tail){
            prevToTemp = temp;
            temp = temp->Next;
        }
        delete temp;
        prevToTemp -> Next = nullptr;
        tail = prevToTemp;
        size--;
    }
}
template<class T>
void DoubleLinkedList<T>::removeAt(int idx){
    if (idx < 0 || idx >= size) {
        cerr << "Index given is out of range\n";
    }
    else{
        if(idx == 0){
            removeAtHead();
        }
        else if(idx == size - 1){
            removeAtTail();
        }
        else{
            Node *prevToTemp = nullptr;
            Node *temp = head;
            while(idx--){
                prevToTemp = temp;
                temp = temp -> Next;
            }
            prevToTemp -> Next = temp -> Next;
            temp->Next->Previous = prevToTemp;
            delete temp;
            size--;
        }
    }
}
template<class T>
T DoubleLinkedList<T>::retrieveAt(int idx){
    if (idx < 0 || idx >= size) {
        cerr << "Index given is out of range\n";
    }
    else {
        Node *current = head;
        while (idx--) {
            current = current->Next;
        }
        return current->item;
    }
}
template<class T>
void DoubleLinkedList<T>::replaceAt(T newValue, int idx){
    if (idx < 0 || idx >= size) {
        cerr << "Index given is out of range\n";
    }
    else{
        Node *current = head;
        while (idx--) {
            current = current->Next;
        }
        current->item = newValue;
    }
}
template<class T>
bool DoubleLinkedList<T>::isExist(T value) {
    Node *current = head;
    while(current!= nullptr){
        if(current->item == value){
            return true;
        }
        current = current->Next;
    }
    return false;
}
template<class T>
bool DoubleLinkedList<T>::isItemAtEqual(T value, int idx) {
    if (idx < 0 || idx >= size) {
        cerr << "Index given is out of range\n";
        return false;
    }
    return (retrieveAt(idx) == value);
}
// swap two nodes without swapping data.
template<class T>
void DoubleLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    if ((firstItemIdx < 0 || firstItemIdx >= size) && (secondItemIdx < 0 || secondItemIdx >= size)) {
        cerr << "Index given is out of range\n";
    } else {
        Node *first = head;
        Node *second = head;
        while (firstItemIdx--) {
            first = first->Next;
        }
        while (secondItemIdx--) {
            second = second->Next;
        }

        // if first->Previous is not null then First is not head
        // so make first->Previous->Next point to second else the head would be second
        if (first->Previous != nullptr) {
            first->Previous->Next = second;
        } else {
            head = second;
        }

        // if second->Previous is not null then second is not head
        // so make second->Previous->Next point to first else the head would be first
        if (second->Previous != nullptr) {
            second->Previous->Next = first;
        } else {
            head = first;
        }

        // extra node to be able to point to the previous to the nodes without losing them
        Node *tempPrev = first->Previous;
        first->Previous = second->Previous;
        second->Previous = tempPrev;

        // extra node to be able to point to the next to the nodes without losing them
        Node *tempNext = first->Next;
        first->Next = second->Next;
        second->Next = tempNext;

        // update the previous so that it points to the correct nodes
        if (first->Next != nullptr) {
            first->Next->Previous = first;
        } else {
            tail = first;
        }

        if (second->Next != nullptr) {
            second->Next->Previous = second;
        } else {
            tail = second;
        }
    }
}
template<class T>
bool DoubleLinkedList<T>::isEmpty() {
    // check if size = zero
    return size == 0;
}
template<class T>
int DoubleLinkedList<T>::linkedListSize() {
    return size;
}
template<class T>
void DoubleLinkedList<T>::clear() {
    // Empty the list
    while(!isEmpty()){
        removeAtHead();
    }
}
template<class T>
void DoubleLinkedList<T>::print() {
    if(isEmpty()){
        cout << "Empty List\n";
        return;
    }
    Node *current = head;
    while (current != nullptr) {
        cout << current->item << '\n';
        current = current->Next;
    }
}

//int main(){
//    DoubleLinkedList<int> d;
//    d.insertAtHead(20); // {20}
//    d.insertAtTail(10); // {20, 10}
//    d.insertAtTail(30); // {20, 10, 30}
//    d.insertAtHead(5); // {5, 20, 10, 30}
//    d.removeAt(2); // {5, 20, 30}
//    d.replaceAt(10, 2); // {5, 20, 10}
//    d.insertAt(25, 3); // {5, 20, 10, 25}
//    cout << "Element '5': " << (d.isExist(5)? "exists\n":"Not exists\n");
//    d.print();
//    cout << "Element at index 3 equals: " << d.retrieveAt(3) << '\n';
//    d.swap(0,2); // {10, 20, 5, 25}
//    d.swap(1,3); // {10, 25, 5, 20}
//    d.print();
//    d.clear();
//    d.print();
//    cout << "Size = " << d.linkedListSize() << '\n';
//}
