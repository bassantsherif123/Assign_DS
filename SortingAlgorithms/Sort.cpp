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

    void print(){
        cout << name << '\n' << id << '\n' << gpa << "\n\n";
    }
};

int comparison;

//_____________________________________
// 3. Bubble Sort
template<typename T>
void BubbleSort(vector<T>&arr, bool GPA){
    if(GPA){
        int n=arr.size();
        bool flag=true;
        //Loop in the whole array
        for(int i=0;i<n;i++){
            //A Loop without the ordered elements
            for(int j=0;j<n-i-1;j++){
//                comparison++;
                //Put the greater elements in the start
                if(arr[j+1]>arr[j]){
                    comparison++;
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
                    comparison++;
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
// 5. Merge sort
template<class T>
void Merge(vector<T>&v, int begin, int middle, int end, bool GPA){

    // new temporary vectors for extra space
    vector<T> FirstSub;
    vector<T> SecondSub;
    int FirstSubSize = middle - begin + 1;
    int SecondSubSize = end - middle;

    // Put data in the temporary vectors
    for(int i = 0; i < FirstSubSize; i++){
        FirstSub.push_back(v[begin + i]);
        comparison++;
    }

    for(int i = 0; i < SecondSubSize; i++){
        SecondSub.push_back(v[middle + 1 + i]);
        comparison++;
    }

    int idxFirstSub = 0, idxSecondSub = 0, idxMerge = begin;

    // Merge Temporary vectors
    while(idxFirstSub < FirstSubSize
          && idxSecondSub < SecondSubSize){
        if((GPA && (FirstSub[idxFirstSub] >= SecondSub[idxSecondSub]))
           || (!GPA && (FirstSub[idxFirstSub] <= SecondSub[idxSecondSub])) ){
            v[idxMerge++] = FirstSub[idxFirstSub++];
            comparison++;
        }
        else {
            v[idxMerge++] = SecondSub[idxSecondSub++];
            comparison++;
        }
    }

    // Add if there are remaining elements in the first sub vector to the merged one
    while(idxFirstSub < FirstSubSize){
        v[idxMerge++] = FirstSub[idxFirstSub++];
        comparison++;
    }

    // Add if there are remaining elements in the second sub vector to the merged one
    while(idxSecondSub < SecondSubSize){
        v[idxMerge++] = SecondSub[idxSecondSub++];
        comparison++;
    }
}

template<class T>
void MergeSort(vector<T>&v, int begin, int end, bool GPA){
    // Base Case
    if (begin >= end){
        comparison++;
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

//________________________________
void Sort(){
    // Start a counter with initial value that equals 0
    int SortingAlgo = 0;

    // Declare variables to calculate running time of function
    auto start = chrono::steady_clock::now(), end = chrono::steady_clock::now();
    auto RunningTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    while(++SortingAlgo){
        In();
        switch(SortingAlgo){
            case 1:
                GPA << "Algorithm: Insertion Sort\n";
                OutGPA();
                GPA << "//_________________________________\n";

                Name << "Algorithm: Insertion Sort\n";
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
                comparison = 0;
                start = chrono::steady_clock::now();
                BubbleSort(students, 1);
                end = chrono::steady_clock::now();
                RunningTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                GPA << "Number of comparisons: " << comparison << '\n';
                GPA << "Running Time:" << RunningTime.count() / 1000000.0 << " milliseconds" << "\n";
                OutGPA();
                GPA << "//_________________________________\n";

                Name << "Algorithm: Bubble Sort\n";
                comparison = 0;
                start = chrono::steady_clock::now();
                BubbleSort(students, 0);
                end = chrono::steady_clock::now();
                RunningTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                Name << "Number of comparisons: " << comparison << '\n';
                Name << "Running Time:" << RunningTime.count() / 1000000.0 << " milliseconds" << "\n";
                OutName();
                Name << "//_________________________________\n";
                break;
            case 4:
                GPA << "Algorithm: Shell Sort\n";
                OutGPA();
                GPA << "//_________________________________\n";

                Name << "Algorithm: Shell Sort\n";
                OutName();
                Name << "//_________________________________\n";
                break;
            case 5:
                GPA << "Algorithm: Merge Sort\n";
                comparison = 0;
                start = chrono::steady_clock::now();
                MergeSort(students, 0, students.size() - 1, 1);
                end = chrono::steady_clock::now();
                RunningTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                GPA << "Number of comparisons: " << comparison << '\n';
                GPA << "Running Time:" << RunningTime.count() / 1000000.0 << " milliseconds" << "\n";
                OutGPA();
                GPA << "//_________________________________\n";

                Name << "Algorithm: Merge Sort\n";
                comparison = 0;
                start = chrono::steady_clock::now();
                MergeSort(students, 0, students.size() - 1, 0);
                Name << "Number of comparisons: " << comparison << '\n';
                end = chrono::steady_clock::now();
                RunningTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                Name << "Running Time:" << RunningTime.count() / 1000000.0 << " milliseconds" << "\n";
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
