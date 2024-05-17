#include <bits/stdc++.h>
using namespace std;

template <typename T>
class AVLNode {
public:
    T value;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(T value) : value{value}, left{nullptr}, right{nullptr}, height{1} {}
};

template <typename T>
class AVLTree {
    AVLNode<T>* root;

    int getHeight(AVLNode<T>* const node) const;
    int getBalance(AVLNode<T>* const node) const;
    AVLNode<T>* rotateLeft(AVLNode<T>* disbalancedNode);
    AVLNode<T>* rotateRight(AVLNode<T>* disbalancedNode);
    AVLNode<T>* insert(AVLNode<T>* root, const T value);
    AVLNode<T>* getMinNode(AVLNode<T>* root) const;
    AVLNode<T>* remove(AVLNode<T>* root, const T value);
    void inOrder(AVLNode<T>* root, vector<T>& items) const;
    void breadthFirstTraversal(AVLNode<T> *root) const;
    void deleteTree(AVLNode<T>* node);

public:
    AVLTree() : root{nullptr} {}

    void insert(const T value);
    void remove(const T value);
    void display() const;
    void displayByNameAscending() const;
    void displayByNameDescending() const;
    void displayByPriceAscending() const;
    void displayByPriceDescending() const;

    ~AVLTree();
};

template <typename T>
int AVLTree<T>::getHeight(AVLNode<T>* const node) const{
    if (node == nullptr)
        return 0;
    return node->height;
}

template <typename T>
int AVLTree<T>::getBalance(AVLNode<T>* const node) const{
    if (!node)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

template <typename T>
AVLNode<T>* AVLTree<T>::rotateLeft(AVLNode<T>* disbalancedNode){
    AVLNode<T>* newRoot = disbalancedNode->right;
    disbalancedNode->right = disbalancedNode->right->left;
    newRoot->left = disbalancedNode;
    disbalancedNode->height = 1 + max(getHeight(disbalancedNode->left), getHeight(disbalancedNode->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;
}

template <typename T>
AVLNode<T>* AVLTree<T>::rotateRight(AVLNode<T>* disbalancedNode) {
    AVLNode<T>* newRoot = disbalancedNode->left;
    disbalancedNode->left = disbalancedNode->left->right;
    newRoot->right = disbalancedNode;
    disbalancedNode->height = 1 + max(getHeight(disbalancedNode->left), getHeight(disbalancedNode->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;
}

template <typename T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T>* root, const T value) {
    if (!root)
        return new AVLNode<T>(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balanceFactor = getBalance(root);

    if (balanceFactor > 1 && value < root->left->value) // left left
        return rotateRight(root);

    if (balanceFactor < -1 && value > root->right->value) // right right
        return rotateLeft(root);

    if (balanceFactor > 1 && value > root->left->value) { // left right
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balanceFactor < -1 && value < root->right->value) { // right left
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

template <typename T>
AVLNode<T>* AVLTree<T>::getMinNode(AVLNode<T>* root) const {
    if (!root || !root->left)
        return root;
    return getMinNode(root->left);
}

template <typename T>
AVLNode<T>* AVLTree<T>::remove(AVLNode<T>* root, const T value) {
    if (!root)
        return root;

    if (value < root->value)
        root->left = remove(root->left, value);
    else if (value > root->value)
        root->right = remove(root->right, value);
    else {
        AVLNode<T>* temp = nullptr;
        if (!root->left) {
            temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            temp = root->left;
            delete root;
            return temp;
        }
        temp = getMinNode(root->right);
        root->value = temp->value;
        root->right = remove(root->right, temp->value);
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) // left left
        return rotateRight(root);

    if (balance < -1 && getBalance(root->right) <= 0) // right right
        return rotateLeft(root);

    if (balance > 1 && getBalance(root->left) < 0) { // left right
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) { // right left
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

template <typename T>
void AVLTree<T>::breadthFirstTraversal(AVLNode<T>* root) const {
    if (root == nullptr)
        return;

    queue<AVLNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        AVLNode<T>* node = q.front();
        q.pop();
        node->value.print();

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}

template <typename T>
void AVLTree<T>::insert(T value) {
    root = insert(root, value);
}

template <typename T>
void AVLTree<T>::remove(T value) {
    root = remove(root, value);
}

template <typename T>
void AVLTree<T>::display() const {
    breadthFirstTraversal(root);
}
template <typename T>
void AVLTree<T>::inOrder(AVLNode<T>* root, vector<T>& items) const {
    if (root != nullptr) {
        inOrder(root->left, items);
        items.push_back(root->value);
        inOrder(root->right, items);
    }
}

template <typename T>
void AVLTree<T>::displayByNameAscending() const {
    vector<T> items;
    inOrder(root, items);
    for (const T& item : items)
        item.print();
}

template <typename T>
void AVLTree<T>::displayByNameDescending() const {
    vector<T> items;
    inOrder(root, items);
    reverse(items.begin(), items.end());
    for (const T& item : items)
        item.print();
}

template <typename T>
void AVLTree<T>::displayByPriceAscending() const {
    vector<T> items;
    inOrder(root, items);
    sort(items.begin(), items.end(), [](const T& a, const T& b) {
        return a <= b;
    });
    for (const T& item : items)
        item.print();
}

template <typename T>
void AVLTree<T>::displayByPriceDescending() const {
    vector<T> items;
    inOrder(root, items);
    sort(items.begin(), items.end(), [](const T& a, const T& b) {
        return a > b;
    });
    for (const T& item : items)
        item.print();
}

template <typename T>
void AVLTree<T>::deleteTree(AVLNode<T>* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

template <typename T>
AVLTree<T>::~AVLTree()
{
    deleteTree(root);
}