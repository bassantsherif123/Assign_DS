#include<bits/stdc++.h>
using namespace std;
void countSort(vector<int>&arr){
  int n =arr.size();
  int max = arr[0];
  for(int i=0 ; i<n; i++){
    if(arr[i]>max){
      max=arr[i];//Get the max element in the array
    }
  }
  int countArray[max+1];
  for(int i=0 ;i<max+1;i++){
    countArray[i]=0;//intialize the count array with 0
  }
  for(int i=0;i<n;i++){
    countArray[arr[i]]++;// count how many time the number occurred
  }
  int index=0;
  for(int i=0;i<=max ;i++){//return the data sorted to the array(ascendingly)
    while(countArray[i]>0){
      arr[index]=i;
      index++;
      countArray[i]--;
    }
  }
  int greater[n];
  int x=0;
  for(int i=n-1;i>=0;i--){
    greater[x]=arr[i];//resort the data descindingly
    x++;
  }
  for(int i=0;i<n;i++){
    arr[i]= greater[i];//return it to the original array
  }
}
int main(){
  vector<int>students;
  students.push_back(70);  
  students.push_back(1);
  students.push_back(18);
  students.push_back(800);
  countSort(students);
  for(auto i:students){
    cout<<i<<"\n";
  }
}