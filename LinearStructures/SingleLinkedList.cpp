#include <bits/stdc++.h>
//#include "Node.cpp"

using namespace std;

template<class T>
class SingleLinkedList{
    class Node{
    public:
        T item;
        Node* Next;
//        Node* Previous;
//    Node(const T&value):item(value),Next(nullptr),Previous(nullptr){}
    };
    Node* head;
    Node* tail;
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
    Node *newNode = new Node;
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
    Node *newNode = new Node;
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
            size++;
        }
    }
}
template<class T>
void SingleLinkedList<T>::removeAtHead() {
    if (isEmpty()) {
        cerr << "Empty list can't remove item\n";
    } else {
        Node *temp = head;
        head = head->Next;
        delete temp;
        size--;
    }
}
template<class T>
void SingleLinkedList<T>::removeAtTail() {
    if (isEmpty()) {
        cerr << "Empty list can't remove item\n";
    } else if (size == 1) {
        removeAtHead();
    } else {
        Node *temp = head->Next;
        Node *prevToTemp = head;
        while (temp != tail) {
            prevToTemp = temp;
            temp = temp->Next;
        }
        delete temp;
        prevToTemp->Next = nullptr;
        tail = prevToTemp;
        size--;
    }
}
template<class T>
void SingleLinkedList<T>::removeAt(int idx) {
    // print error message if index given is out of range
    if (idx < 0 || idx >= size) {
        cerr << "Index given is out of range\n";
    } else {
        if (idx == 0) {
            removeAtHead();
        } else if (idx == size - 1) {
            removeAtTail();
        } else {
            Node *prevToTemp = nullptr;
            Node *temp = head;
            while (idx--) {
                prevToTemp = temp;
                temp = temp->Next;
            }
            prevToTemp->Next = temp->Next;
            delete temp;
            size--;
        }
    }
}
template<class T>
T SingleLinkedList<T>::retrieveAt(int idx) {
    // print error message if index given is out of range
    if (idx < 0 || idx >= size) {
        cerr << "Index given is out of range\n";
    } else {
        Node *current = head;
        while (idx--) {
            current = current->Next;
        }
        return current->item;
    }
}
template<class T>
void SingleLinkedList<T>::replaceAt(T newValue, int idx) {
    // print error message if index given is out of range
    if (idx < 0 || idx >= size) {
        cerr << "Index given is out of range\n";
    } else {
        // replace the item at a specific index with another
        Node *current = head;
        while (idx--) {
            current = current->Next;
        }
        current->item = newValue;
    }
}
template<class T>
bool SingleLinkedList<T>::isExist(T value) {
    // start with a node that points to the head then move it till it reaches the end
    Node *current = head;
    while (current != nullptr) {
        // Return true if there is an item in the list that matches the value given
        if (current->item == value) {
            return true;
        }
        current = current->Next;
    }
    return false;
}
template<class T>
bool SingleLinkedList<T>::isItemAtEqual(T value, int idx) {
    // print error message if index given is out of range
    if (idx < 0 || idx >= size) {
        cerr << "Index given is out of range\n";
        return false;
    }
    // return the result of comparing the value when calling retrieve at function and the value given
    return (retrieveAt(idx) == value);
}
// swap two nodes without swapping data.
template<class T>
void SingleLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    // print error message if index given is out of range
    if ((firstItemIdx < 0 || firstItemIdx >= size)
        && (secondItemIdx < 0 || secondItemIdx >= size)) {
        cerr << "Index given is out of range\n";
    } else {
        Node *PrevToFirst = nullptr;
        Node *first = head;
        Node *PrevToSecond = nullptr;
        Node *second = head;

        // Let each node point to the given index
        while (firstItemIdx--) {
            PrevToFirst = first;
            first = first->Next;
        }
        while (secondItemIdx--) {
            PrevToSecond = second;
            second = second->Next;
        }

        // if PrevToFirst is not null then First is not head
        // so make PrevToFirst->Next point to second else the head would be second
        if (PrevToFirst != nullptr) {
            PrevToFirst->Next = second;
        } else {
            head = second;
        }

        // if PrevToSecond is not null then second is not head
        // so make PrevToSecond->Next point to first else the head would be first
        if (PrevToSecond != nullptr) {
            PrevToSecond->Next = first;
        } else {
            head = first;
        }

        Node *temp = second->Next;
        second->Next = first->Next;
        first->Next = temp;
    }
}
template<class T>
bool SingleLinkedList<T>::isEmpty() {
    // check if size = zero
    return size == 0;
}
template<class T>
int SingleLinkedList<T>::linkedListSize() {
    return size;
}
template<class T>
void SingleLinkedList<T>::clear() {
    // Empty the list
    while (!isEmpty()) {
        removeAtHead();
    }
}
template<class T>
void SingleLinkedList<T>::print() {
    if (isEmpty()) {
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
//    SingleLinkedList<int> s;
//    s.insertAtHead(20); // {20}
//    s.insertAtTail(10); // {20, 10}
//    s.insertAtTail(30); // {20, 10, 30}
//    s.insertAtHead(5); // {5, 20, 10, 30}
//    s.removeAt(2); // {5, 20, 30}
//    s.replaceAt(10, 2); // {5, 20, 10}
//    s.insertAt(25, 3); // {5, 20, 10, 25}
//    cout << "Element '5': " << (s.isExist(5)? "exists\n":"Not exists\n");
//    s.print();
//    cout << "Element at index 3 equals: " << s.retrieveAt(3) << '\n';
//    s.swap(0,2); // {10, 20, 5, 25}
//    s.swap(1,3); // {10, 25, 5, 20}
//    s.print();
//    s.clear();
//    s.print();
//    cout << "Size = " << s.linkedListSize() << '\n';
//}
