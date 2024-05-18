#include <bits/stdc++.h>
#include "Item.h"
using namespace std;

class BST{
    class Node{
    public:
        Item value;
        Node *left, *right;
        Node(Item& x): value(x), left(nullptr), right(nullptr){}
    };
    Node* root;
    vector<Item> it;
    int size = 0;
    void inOrder(Node* x);
    void reverseInOrder(Node* x);
    void removeNode(Node*& n);
public:
    BST(): root(nullptr) {}
    void add(Item x, bool price);
    void remove(Item x);
    bool search(Item x);
    int length();
    bool isEmpty();
    void displayNormally();
    void displaySortedByNameAscending();
    void displaySortedByNameDescending();
    void displaySortedByPriceAscending();
    void displaySortedByPriceDescending();
    ~BST();
};

void BST::add(Item x, bool price) {
    // bool price decides wether the tree is going to be implemented using item name or price
    Node *current = root, *parent = nullptr;
    while(current != nullptr) {
        parent = current;

        if((!price && current->value < x)
            || (price && current->value <= x)) {

            // go to right subtree if item to be added is greater than current
            current = current->right;
        }
        else {

            // go to left subtree if item to be added is less than current
            current = current->left;
        }
    }
    if(isEmpty()) {
        root = new Node(x);
    }
    else if((!price && parent->value >= x)
            || (price && parent->value > x)) {

        // item added to left subtree if parent item is greater than it
        parent->left = new Node(x);
    }
    else {

        // item added to right subtree if parent item is smaller than it
        parent->right = new Node(x);
    }

    // add item to vector
    it.push_back(x);


    size++;
}

void BST::inOrder(BST::Node *x) {
    // Left Root Right
    if (x == nullptr) {
        return;
    }
    inOrder(x->left);
    x->value.print();
    inOrder(x->right);
}

void BST::reverseInOrder(BST::Node *x) {
    // Right Root Left
    if (x == nullptr) {
        return;
    }
    reverseInOrder(x->right);
    x->value.print();
    reverseInOrder(x->left);
}

void BST::displayNormally() {
    for (auto x: it) {
        x.print();
    }
}

void BST::displaySortedByNameAscending() {
    inOrder(root);
}

void BST::displaySortedByNameDescending() {
    reverseInOrder(root);
}

void BST::displaySortedByPriceAscending() {
    inOrder(root);
}

void BST::displaySortedByPriceDescending() {
    reverseInOrder(root);
}

bool BST::isEmpty() {
    return root == nullptr;
}

void BST::removeNode(BST::Node *&n) {
    Node *predecessor, *parent, *tmp;
    if (n == nullptr) {
        cout << "The node you want to delete doesn't exist\n";
    }
    else if (n->left == nullptr && n->right == nullptr) {

        // Node has no children "A leaf"
        // replace with null
        delete n;
        n = nullptr;
    } else if (n->left == nullptr) {

        // Node has no left child
        // connect the parent to the right child and remove the node
        tmp = n;
        n = n->right;
        delete tmp;
    } else if (n->right == nullptr) {

        // Node has no right child
        // connect the parent to the left child and remove the node
        tmp = n;
        n = n->left;
        delete tmp;
    } else {

        // Node has both children
        // find predecessor to delete using delete by coping method
        // go to the left subtree
        predecessor = n->left;
        parent = nullptr;

        // while the node still has a right child (is not null)
        // Assign the right child to current
        // we want to find the first smaller value than the one in the given node
        while (predecessor->right != nullptr) {
            parent = predecessor;
            predecessor = predecessor->right;
        }

        // copy predecessor value to the node
        n->value = predecessor->value;

        if (parent != nullptr) {
            // If the predecessor is not the direct node's left child to be deleted
            // Assign the node's right pointer to point to the left subtree of the predecessor
            parent->right = predecessor->left;
        }
        else {
            // If the predecessor is the direct node's left child to be deleted
            // Assign the node's left pointer to skip over the successor
            n->left = predecessor->left;
        }

        // delete the predecessor as it is copied to the node we want to delete
        delete predecessor;
    }
}

void BST::remove(Item x) {
    Node *parent, *current;
    bool found = false;

    if (isEmpty()) {
        cout << "Tree has no item to delete.\n";
        return;
    }
    else {
        parent = nullptr;
        current = root;

        // search for the item
        while (current != nullptr && !found) {
            if (current->value == x) {
                found = true;
            }
            else {
                parent = current;
                if (current->value >= x) {
                    current = current->left;
                }
                else {
                    current = current->right;
                }
            }
        }
    }

    if (current == nullptr) {
        cout << "Couldn't find the item you want to delete in the tree.\n";
    }
    else if (found) {
        // remove the node after finding it

        if (current == root) {
            removeNode(root);
        }
        else if (parent->left == current) {
            removeNode(parent->left);
        }
        else {
            removeNode(parent->right);
        }

        // delete item from vector
        auto i = std::find(it.begin(), it.end(), x);
        if (i != it.end()) {
            it.erase(i);
        }

        size--;
    }
}

int BST::length() {
    return size;
}

bool BST::search(Item x) {
    Node *parent, *current;
    bool found = false;

    if (isEmpty()) {
        cout << "Tree has no item to delete.\n";
        return false;
    }

    parent = nullptr;
    current = root;
    while (current != nullptr && !found) {
        // loop to search for the item in tree
        if (current->value == x) {
            found = true;
        }
        else {
            parent = current;
            if (current->value >= x) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
    }
    return found;
}

BST::~BST() {
    root = nullptr;
}

