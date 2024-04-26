#include <bits/stdc++.h>
using namespace std;

void Sort();

class Student{
    string id;
    string name;
    double gpa;
public:
    Student(string ID, string n, double GPA):id(ID), name(n), gpa(GPA){}

    bool operator<(Student &another){
        return (name < another.name);
    }

    bool operator<=(Student &another){
        return (name <= another.name);
    }

    bool operator>=(Student &another){
        return (gpa >= another.gpa);
    }

    bool operator>(Student &another){
        return (gpa > another.gpa);
    }

    void print(ofstream& outputFile){
        outputFile << name << '\n' << id << '\n' << gpa << "\n\n";
    }
};

//_____________________________________
// 5. Merge sort
void Merge(vector<Student>&v, int begin, int middle, int end, bool GPA){

    // new temporary vectors for extra space
    vector<Student> FirstSub;
    vector<Student> SecondSub;
    int FirstSubSize = middle - begin + 1;
    int SecondSubSize = end - middle;

    // Put data in the temporary vectors
    for(int i = 0; i < FirstSubSize; i++){
        FirstSub.push_back(v[begin + i]);
    }

    for(int i = 0; i < SecondSubSize; i++){
        SecondSub.push_back(v[middle + 1 + i]);
    }

    int idxFirstSub = 0, idxSecondSub = 0, idxMerge = begin;

    // Merge Temporary vectors
    while(idxFirstSub < FirstSubSize
        && idxSecondSub < SecondSubSize){
        if((GPA && (FirstSub[idxFirstSub] >= SecondSub[idxSecondSub]))
            || (!GPA && (FirstSub[idxFirstSub] <= SecondSub[idxSecondSub])) ){
            v[idxMerge++] = FirstSub[idxFirstSub++];
        }
        else {
            v[idxMerge++] = SecondSub[idxSecondSub++];
        }
    }

    // Add if there are remaining elements in the first sub vector to the merged one
    while(idxFirstSub < FirstSubSize){
        v[idxMerge++] = FirstSub[idxFirstSub++];
    }

    // Add if there are remaining elements in the second sub vector to the merged one
    while(idxSecondSub < SecondSubSize){
        v[idxMerge++] = SecondSub[idxSecondSub++];
    }
}

void MergeSort(vector<Student>&v, int begin, int end, bool GPA){
    // Base Case
    if (begin >= end){
        return;
    }

    // Divide the vector
    int middle = begin + (end - begin) / 2;

    // conquer the first half
    MergeSort(v, begin, middle, GPA);

    // conquer the second half
    MergeSort(v, middle + 1, end, GPA);

    // Merge the two halves
    Merge(v, begin, middle, end, GPA);
}
//_____________________________________
//BubbleSort
template<typename T>
void BubbleSort(vector<T>&arr, bool GPA){
  if(GPA){
    int n=arr.size();
    bool flag=true;
    //Loop in the whole array
    for(int i=0;i<n;i++){
    //A Loop without the ordered elements 
    for(int j=0;j<n-i-1;j++){
      //Put the greater elements in the start
      if(arr[j+1]>arr[j]){
        swap(arr[j],arr[j+1]);
        flag=false;//To prove that it's not ordered
      }
    }
    //To break and stop looping if the array is already sorted
    if(flag)break;
  }
  }
  else{
    int n=arr.size();
    bool flag=true;
    //Loop in the whole array
    for(int i=0;i<n;i++){
      //A Loop without the ordered elements 
    for(int j=0;j<n-i-1;j++){
      //Put the smaller elements in the start
      if(arr[j+1]<arr[j]){
        swap(arr[j],arr[j+1]);
        flag=false;//To prove that it's not ordered
      }
    }
    //To break and stop looping if the array is already sorted
    if(flag)break;
  }
  }
    
}
//_____________________________________
//insertionsort
template <typename T>
int insertionSort(vector<T> &v, bool GPA){  
    int length = v.size();
    int comparisons = 0;
    for (int i = 1; i < length; i++) {
        comparisons++;
        T tmp = v[i];
        int j = i - 1;
        while (j >= 0 && ((GPA && tmp > v[j]) || (!GPA && tmp < v[j]))) {
            comparisons=+2;
            v[j + 1] = v[j];
            j--;
        }
        if (j >= 0)
            comparisons++;
        v[j + 1] = tmp;
    }
    cout << "Number of comparisons: " << comparisons << endl;
    return comparisons;
}
//_____________________________________
//shellsort
template<typename T>
int shellSort(vector<T>& v, bool GPA) {
    int length = v.size();
    int comparisons = 0;

    for (int gap = length / 2; gap > 0; gap /= 2,comparisons++) {
        for (int i = gap; i < length; i++,comparisons++) {
            T tmp = v[i];
            int j = i;

            while (j >= gap && ((GPA && tmp > v[j - gap]) || (!GPA && tmp < v[j - gap]))) {
                comparisons=+2;
                v[j] = v[j - gap];
                j -= gap;
                if (j >= gap) comparisons++;
                v[j] = tmp;
            }
        }
        
    }
    cout << "Number of comparisons: " << comparisons << endl;
    return comparisons;
}

//_____________________________________
vector<Student> students;

// read from students.txt
void In(){
    students.clear();
    ifstream Input("../SortingAlgorithms/students.txt");
    if(!Input){
        cerr << "Failed to open the input file.\n";
        return;
    }
    else{
        int n;
        double gpa;
        string name, id;
        Input >> n;
        while(n--) {
            Input.ignore();
            getline(Input, name);
            getline(Input, id);
            Input >> gpa;
            students.push_back(Student(id, name, gpa));
        }
    }
}

// write to SortedByGPA.txt after sorting by gpa
ofstream GPA("../SortingAlgorithms/SortedByGPA.txt");
void OutGPA() {
    for (auto &x: students) {
        x.print(GPA);
    }
}

// write to SortedByName.txt after sorting by name
ofstream Name("../SortingAlgorithms/SortedByName.txt");
void OutName(){
    for (auto &x: students) {
        x.print(Name);
    }
}

//________________________________
int main() {
    Sort();
}

void Sort(){
    // Start a counter with initial value that equals 0
    int SortingAlgo = 0;

    // Declare variables to calculate running time of function
    clock_t start, end;
    double RunningTime;

    while(++SortingAlgo){
        In();
        switch(SortingAlgo){
            case 1:
                GPA << "Algorithm: Insertion Sort\n";
                insertionSort(students,1);
                OutGPA();
                GPA << "//_________________________________\n";

                Name << "Algorithm: Insertion Sort\n";
                insertionSort(students,0);
                OutName();
                Name << "//_________________________________\n";
                break;
            case 2:
                GPA << "Algorithm: Selection Sort\n";
                OutGPA();
                GPA << "//_________________________________\n";


                Name << "Algorithm: Selection Sort\n";
                OutName();
                Name << "//_________________________________\n";
                break;
            case 3:
                GPA << "Algorithm: Bubble Sort\n";
                BubbleSort(students,1);
                OutGPA();
                GPA << "//_________________________________\n";


                Name << "Algorithm: Bubble Sort\n";
                BubbleSort(students,0);
                OutName();
                Name << "//_________________________________\n";
                break;
            case 4:
                GPA << "Algorithm: Shell Sort\n";
                 shellSort(students,1);
                OutGPA();
                GPA << "//_________________________________\n";


                Name << "Algorithm: Shell Sort\n";
                 shellSort(students,0);
                OutName();
                Name << "//_________________________________\n";
                break;
            case 5:
                GPA << "Algorithm: Merge Sort\n";
                start = clock();
                MergeSort(students, 0, students.size() - 1, 1);
                end = clock();
                RunningTime = double(end - start);
                GPA << "Running time: " << RunningTime << " milliseconds\n";
                OutGPA();
                GPA << "//_________________________________\n";

                Name << "Algorithm: Merge Sort\n";
                start = clock();
                MergeSort(students, 0, students.size() - 1, 0);
                end = clock();
                RunningTime = double(end - start);
                Name << "Running time: " << RunningTime << " milliseconds\n";
                OutName();
                Name << "//_________________________________\n";
                break;
            case 6:
                GPA << "Algorithm: Quick Sort\n";
                OutGPA();

                Name << "Algorithm: Quick Sort\n";
                OutName();
                break;
        }

        // Break when SortingAlgo is 6 as it reached last sorting algorithm
        if(SortingAlgo == 6){
            break;
        }
    }
}
