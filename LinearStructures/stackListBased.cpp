#include <bits/stdc++.h>
using namespace std;

template <typename type>
class Node
{
public:
    type data;
    Node<type> *next;

    Node() : data{}, next{nullptr}
    {
    }

    Node(type data) : data{data}, next{nullptr}
    {
    }
};

template <typename type>
class Stack
{
    Node<type> *topNode;
    int size;

public:
    Stack();
    void push(type data);
    type pop();
    type top() const;
    bool isEmpty() const;
    int stackSize() const;
    void clear();
    void print() const;
    ~Stack();
};

template <typename type>
Stack<type>::Stack() : topNode{nullptr}, size{}
{
}

template <typename type>
void Stack<type>::push(type data)
{
    Node<type> *temp = new Node<type>(data);
    if (topNode)
        temp->next = topNode;
    topNode = temp;
    size++;
}

template <typename type>
type Stack<type>::pop()
{
    if (isEmpty())
        return type();

    type temp = topNode->data;
    Node<type> *temp2 = topNode;
    topNode = topNode->next;
    delete temp2;
    size--;
    return temp;
}

template <typename type>
type Stack<type>::top() const
{
    if (isEmpty())
        return type();

    return topNode->data;
}

template <typename type>
bool Stack<type>::isEmpty() const
{
    return size == 0;
}

template <typename type>
int Stack<type>::stackSize() const
{
    return size;
}

template <typename type>
void Stack<type>::clear()
{
    while (!isEmpty())
        pop();
}

template <typename type>
void Stack<type>::print() const
{
    if (isEmpty())
        return;
    Node<type> *temp = topNode;
    while (temp)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}

template <typename type>
Stack<type>::~Stack()
{
    clear();
}
