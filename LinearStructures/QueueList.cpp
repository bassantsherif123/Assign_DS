#include<bits/stdc++.h>
using namespace std;
template<class T>
struct node{
  T info;
  node<T> *next;
};
template<class T>
class Queue{
private:
  int size;
  node<T>*first, *last;
public:
  Queue(){
    this->first= nullptr;
    this->last= nullptr;
    size =0;
  }
  void enqueue(T element);
  T dequeue();
  T firstElement();
  bool isEmpty(){
    if(size==0 || first == nullptr){
      return true;
    }
    else return false;
  }
  int queueSize(){
    return size;
  }
  void clear(){
    node<T> *x;
    while(first!=nullptr){
      x=first;
      first = first->next;
      delete x;
    }
    last= first;
    size = 0;
  }
  void print(){
    if(isEmpty()){
      cout<<"Empty list\n";
      return;
    }
    node<T> *x;
    x=first;
    while (x!=nullptr)
    {
      cout<<x->info<<" ";
      x = x->next;
    }
    cout<<'\n';
  }
};

template <class T>
void Queue<T>::enqueue(T element){
  size++;
  node<T> * newN = new node<T>;
  newN->info = element;
  newN->next = nullptr;
  if(isEmpty()){
    first = newN;
    last = newN;
  }
  else{
    last->next = newN;
    last = newN;
  }
}

template <class T>
T Queue<T>::dequeue(){
  if(isEmpty()){
    cout<<"Empty list\n";
    return -1;
  }
  size--;
  T out = first->info;
  node<T> *x = first;
  first = first->next;
  delete x;
  return out;
}

template <class T>
T Queue<T>::firstElement(){
  if(isEmpty()){
    cout<<"Empty list\n";
    return -1;
  }
  else{
    return first->info;
  }
}

// int main(){
//   Queue<int>q;
//   q.enqueue(1);
//   q.enqueue(2);
//   q.enqueue(3);//q = {5,1,3}
//   cout<<"The size: "<<q.queueSize()<<'\n';//3 elements
//   cout<<"The first element is: "<<q.firstElement()<<'\n';//5 
//   cout<<"The removed element is: "<<q.dequeue()<<'\n';//5 removed
//   q.print();//1,3
//   q.clear();
//   q.print();//The list is empty
// }
