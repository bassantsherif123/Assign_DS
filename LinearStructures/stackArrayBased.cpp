#include <bits/stdc++.h>
using namespace std;

template <typename type>
class StackArrayBased
{
    type *arr;
    int size;
    int capacity;

    void growArray();

public:
    StackArrayBased();
    void push(type data);
    type pop();
    type top() const;
    bool isEmpty() const;
    int stackSize() const;
    void clear();
    void print() const;
    ~StackArrayBased();
};

template <typename type>
void StackArrayBased<type>::growArray()
{
    type *newArr = new type[capacity * 2];
    for (int i = 0; i < capacity; i++)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity *= 2;
};

template <typename type>
StackArrayBased<type>::StackArrayBased()
{
    size = 0;
    capacity = 10;
    arr = new type[capacity];
};

template <typename type>

void StackArrayBased<type>::push(type data)
{
    if (size == capacity)
    {
        growArray();
    }
    arr[size] = data;
    size++;
};

template <typename type>
type StackArrayBased<type>::pop()
{
    if (isEmpty())
        return type();
    type temp = arr[size - 1];
    arr[size] = '\0';
    size--;
    return temp;
};

template <typename type>
type StackArrayBased<type>::top() const
{
    if (isEmpty())
        return type();
    return arr[size - 1];
};

template <typename type>
bool StackArrayBased<type>::isEmpty() const
{
    return size == 0;
};

template <typename type>
int StackArrayBased<type>::stackSize() const
{
    return size;
};

template <typename type>
void StackArrayBased<type>::clear()
{
    if (isEmpty())
        return;

    for (int i = 0; i < size; i++)
    {
        arr[i] = '\0';
    }
    size = 0;
};

template <typename type>
void StackArrayBased<type>::print() const
{
    if (isEmpty())
        return;

    for (int i = size - 1; i >= 0; i--)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
};

template <typename type>
StackArrayBased<type>::~StackArrayBased()
{
    delete[] arr;
};