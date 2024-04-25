#include<bits/stdc++.h>
using namespace std;
template <class T,int size=100>
class Queue{
private:
      int first, last;
      T Q[size];
public:
    Queue(){
      //Initialize the data
      first = last =-1;
    }
    void enqueue(T);
    T dequeue();
    T firstElement();
    bool isFull(){
      // if the last element of the array is at the end then return true
      if(last==(size-1)){
        return true;
      }
      else return false;
    }
    bool isEmpty(){
      //check that there is no elements
      if(first==-1 && last==-1){
        return true;
      }
      else return false;
    }
    int queueSize(){
      //print the size of the queue
      return last+1;
    }
    void clear(){
      //all the data will be reassigned if you add new element
      first = last =-1;
    }
    void print(){
      if(isEmpty()){
        cout<<"Empty list\n";
      }
      else{
        //print the content
        for(int i=first;i<=last;i++){
          cout<<Q[i]<<" ";
        }
        cout<<'\n';
      }
    }
};

template <class T,int size>
void Queue<T,size>::enqueue(T element){
  if(isFull()){
    //check that it's not full
    cout<<"Full list\n";
    return;
    }
  else if(isEmpty()){
    //put in the first place if it's empty
    first=last=0;
    Q[last]=element;
  }
  else{
    //add the element
    last++;
    Q[last]=element;
  }
}

template <class T,int size>
T Queue<T,size>::dequeue(){
  if(isEmpty()){
    cout<<"Empty list\n";
    return -1;
    }
  else if(first == last){
    //if it's the first element
    T x = Q[first];
    first = last =-1;
    return x;
  }
  else{
    //remove the first element and move all the rest of the elements to go a step back
    T x = Q[0];
    for(int i=0; i<=last;i++){
      Q[i]=Q[i+1];
    }
    last--;
    return x;
  }
}

template <class T,int size>
T Queue<T,size>::firstElement(){
      //return first element of the array if it's not empty
      if(isEmpty()){
        cout<<"Empty list\n";
        return -1;
      }
      else{
        return Q[first];
      }
    };

// int main(){
//   Queue<int>q;
//   q.enqueue(5);
//   q.enqueue(1);
//   q.enqueue(3);//q = {5,1,3}
//   cout<<"The size: "<<q.queueSize()<<'\n';//3 elements
//   cout<<"The first element is: "<<q.firstElement()<<'\n';//5 
//   cout<<"The removed element is: "<<q.dequeue()<<'\n';//5 removed
//   q.print();//1,3
//   q.clear();
//   q.print();//The list is empty
// }
