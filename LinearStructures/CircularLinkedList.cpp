#include <iostream>
using namespace std;

template<typename T>
class CircularLinkedList {
private:
    class Node {
    public:
        T data;
        Node* next;

        Node(const T& element) : data(element), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;


public:
    CircularLinkedList() : head(nullptr), size(0) {}

    void insertAtHead(const T& element) {
        Node* newNode = new Node(element);
        if (head == nullptr) {
            head = tail = newNode;
            head->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
        ++size;
    }

    void insertAtTail(const T& element) {
        if (head == nullptr) {
            insertAtHead(element);
        } else {
            Node* newNode = new Node(element);
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
            ++size;
        }
    }


    void insertAt(const T& element, int index) {
        if (index < 0 || index > size) {
            cerr << "Index given is out of range\n";
            return;
        }

        if (index == 0) {
            insertAtHead(element);
        } else if (index == size) {
            insertAtTail(element);
        } else {
            Node* prevNode = nullptr;
            Node* currentNode = head;
            for (int i = 0; i < index; ++i) {
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
            Node* newNode = new Node(element);
            newNode->next = currentNode;
            prevNode->next = newNode;
            ++size;
        }
    }

    void removeAtHead() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* newHead = head->next;
            tail->next = newHead;
            delete head;
            head = newHead;
        }
        --size;
    }

    void removeAtTail() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* prevNode = head;
            while (prevNode->next != tail) {
                prevNode = prevNode->next;
            }
            delete tail;
            tail = prevNode;
            tail->next = head;
        }
        --size;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) {
            cerr << "Index given is out of range\n";
            return;
        }

        if (index == 0) {
            removeAtHead();
        } else if (index == size - 1) {
            removeAtTail();
        } else {
            Node* prevNode = head;
            for (int i = 0; i < index - 1; ++i) {
                prevNode = prevNode->next;
            }
            Node* nodeToRemove = prevNode->next;
            prevNode->next = nodeToRemove->next;
            delete nodeToRemove;
            --size;
        }
    }


    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size) {
            cout << "Invalid indices." << endl;
            return;
        }
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (firstItemIdx == secondItemIdx) {
            return; // No need to swap if the indices are the same
        }
        Node* prevFirst = nullptr;
        Node* firstNode = head;
        for (int i = 0; i < firstItemIdx; ++i) {
            prevFirst = firstNode;
            firstNode = firstNode->next;
        }

        Node* prevSecond = nullptr;
        Node* secondNode = head;
        for (int i = 0; i < secondItemIdx; ++i) {
            prevSecond = secondNode;
            secondNode = secondNode->next;
        }

        if (prevFirst != nullptr) {
            prevFirst->next = secondNode;
        } else {
            head = secondNode;

        }

        if (prevSecond != nullptr) {
            prevSecond->next = firstNode;
        } else {
            head = firstNode;

        }
        Node* temp = firstNode->next;
        firstNode->next = secondNode->next;
        secondNode->next = temp;

        if (firstNode == tail) {
            tail = secondNode;
            secondNode->next=head;
        } else if (secondNode == tail) {
            tail = firstNode;
            firstNode->next=head;
        }
    }

    T retrieveAt(int index) const {
        if (index < 0 || index >= size) {
            cout << "Invalid index." << endl;
            return T();
        }

        Node* currentNode = head;
        for (int i = 0; i < index; ++i) {
            currentNode = currentNode->next;
        }
        return currentNode->data;
    }

    void replaceAt(const T& newElement, int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index." << endl;
            return;
        }

        Node* currentNode = head;
        for (int i = 0; i < index; ++i) {
            currentNode = currentNode->next;
        }
        currentNode->data = newElement;
    }

    bool isExist(const T& element) const {
        Node* current = head;
        for (int i = 0; i < size; ++i) {
            if (current->data == element) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool isItemAtEqual(const T& element, int index) const {
        if (index < 0 || index >= size) {
            cout << "Invalid index." << endl;
            return false;
        }
        return (retrieveAt(index) == element);
    }

    bool isEmpty() const {
        return size == 0;
    }

    int linkedListSize() const {
        return size;
    }

    void clear() {
        while (!isEmpty()) {
            removeAtHead();
        }
    }

    void print() const {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        for (int i = 0; i < size; ++i) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~CircularLinkedList() {
        clear();
    }

};

// int main() {
//     CircularLinkedList<int> myList;

//     myList.insertAtHead(1);
//     myList.insertAtHead(2);
//     myList.insertAtTail(3);
//     myList.insertAt(4, 1);

//     myList.print(); // Output: 2 4 1 3

//     myList.removeAt(2);

//     myList.print(); // Output: 2 4 3

//     myList.replaceAt(5, 1);

//     myList.print();

//     bool exists = myList.isExist(5);
//     cout << exists << endl;

//     bool isEqual = myList.isItemAtEqual(3, 2);
//     cout << isEqual << endl;
//     cout << "Element at index 0: " << myList.retrieveAt(0) << endl;

//     myList.swap(0, 1);

//     myList.print();

//     bool empty = myList.isEmpty();
//     cout << empty << endl;

//     int size = myList.linkedListSize();
//     cout << size << endl;

//     myList.clear();

//     myList.print();

//     return 0;
// }
