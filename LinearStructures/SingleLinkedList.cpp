#include <bits/stdc++.h>
using namespace std;

template<class T>
class Node{
public:
    T item;
    Node* Next;
    Node* Previous;
//    Node(const T&value):item(value),Next(nullptr),Previous(nullptr){}
};

template<class T>
class SingleLinkedList{
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    SingleLinkedList():head(nullptr), tail(nullptr), size(0){}
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
    // swap two nodes without swapping data.
    bool isEmpty();
    int linkedListSize();
    void clear();
    void print();
    ~SingleLinkedList(){
        clear();
    }
};

template<class T>
void SingleLinkedList<T>::insertAtHead(T value) {
    Node<T> *newNode = new Node<T>;
    newNode->item = value;
    if (isEmpty()) {
        head = tail = newNode;
        newNode->Next = nullptr;
    } else {
        newNode->Next = head;
        head = newNode;
    }
    size++;
}
template<class T>
void SingleLinkedList<T>::insertAtTail(T value) {
    Node<T> *newNode = new Node<T>;
    newNode->item = value;
    if (isEmpty()) {
        head = tail = newNode;
        newNode->Next = nullptr;
    } else {
        tail->Next = newNode;
        newNode->Next = nullptr;
        tail = newNode;
    }
    size++;
}
template<class T>
void SingleLinkedList<T>::insertAt(T value, int idx) {
    if (idx < 0 || idx > size) {
        cerr << "Index given is out of range\n";
    } else {
        Node<T> *newNode = new Node<T>;
        newNode->item = value;
        if (idx == 0) {
            insertAtHead(value);
        } else if (idx == size) {
            insertAtTail(value);
        } else {
            Node<T> *current = head;
            while (--idx) {
                current = current->Next;
            }
            newNode->Next = current->Next;
            current->Next = newNode;
            size++;
        }
    }
}
template<class T>
void SingleLinkedList<T>::removeAtHead() {
    if (isEmpty()) {
        cerr << "Empty list can't remove item\n";
    } else {
        Node<T> *temp = head;
        head = head->Next;
        delete temp;
        size--;
    }
}
template<class T>
void SingleLinkedList<T>::removeAtTail(){
    if (isEmpty()) {
        cerr << "Empty list can't remove item\n";
    }
    else if(size ==1){
        removeAtHead();
    }
    else {
        Node<T> *temp = head -> Next;
        Node<T> *prevToTemp = head;
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
void SingleLinkedList<T>::removeAt(int idx){
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
            Node<T> *prevToTemp = nullptr;
            Node<T> *temp = head;
            while(idx--){
                prevToTemp = temp;
                temp = temp -> Next;
            }
            prevToTemp -> Next = temp -> Next;
            delete temp;
            size--;
        }
    }
}
template<class T>
T SingleLinkedList<T>::retrieveAt(int idx){
    if (idx < 0 || idx >= size) {
        cerr << "Index given is out of range\n";
    }
    else {
        Node<T> *current = head;
        while (idx--) {
            current = current->Next;
        }
        return current->item;
    }
}
template<class T>
void SingleLinkedList<T>::replaceAt (T newValue, int idx){
    if (idx < 0 || idx >= size) {
        cerr << "Index given is out of range\n";
    }
    else{
        Node<T> *current = head;
        while (idx--) {
            current = current->Next;
        }
        current->item = newValue;
    }
}
template<class T>
bool SingleLinkedList<T>::isExist(T value) {
    Node<T> *current = head;
    while(current!= nullptr){
        if(current->item == value){
            return true;
        }
        current = current->Next;
    }
    return false;
}
template<class T>
bool SingleLinkedList<T>::isItemAtEqual(T value, int idx) {
    if (idx < 0 || idx >= size) {
        cerr << "Index given is out of range\n";
        return false;
    }
    return (retrieveAt(idx) == value);
}
template<class T>
void SingleLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    if ((firstItemIdx < 0 || firstItemIdx >= size) && (secondItemIdx < 0 || secondItemIdx >= size)) {
        cerr << "Index given is out of range\n";
    }
    else {
        Node<T> *first = head;
        Node<T> *second = head;
        while (firstItemIdx--) {
            first = first->Next;
        }
        while (secondItemIdx--) {
            second = second->Next;
        }
        T temp = first -> item;
        first -> item = second -> item;
        second -> item = temp;
    }
}
template<class T>
bool SingleLinkedList<T>::isEmpty() {
    return size == 0;
}
template<class T>
int SingleLinkedList<T>::linkedListSize() {
    return size;
}
template<class T>
void SingleLinkedList<T>::clear() {
    while(!isEmpty()){
        removeAtHead();
    }
}
template<class T>
void SingleLinkedList<T>::print() {
    Node<T> *current = head;
    while (current != nullptr) {
        cout << current->item << '\n';
        current = current->Next;
    }
}


int main(){
    SingleLinkedList<int> s;
    s.insertAtHead(20);
    s.insertAtTail(10);
    s.insertAtTail(30);
    s.insertAtHead(5);
    s.removeAt(2);
    s.replaceAt(10, 2);
    cout << s.isExist(10) << '\n';
    s.swap(0,2);
    //s.clear();
    s.print();
    cout << s.linkedListSize();
}
