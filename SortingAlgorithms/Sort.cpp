#include <bits/stdc++.h>
using namespace std;

void Sort();

class Student
{
    string id;
    string name;
    double gpa;

public:
    Student(string ID, string n, double GPA) : id(ID), name(n), gpa(GPA) {}

    bool operator<(Student &another)
    {
        return (name < another.name);
    }

    bool operator<=(Student &another)
    {
        return (name <= another.name);
    }

    bool operator>=(Student &another)
    {
        return (gpa >= another.gpa);
    }

    bool operator>(Student &another)
    {
        return (gpa > another.gpa);
    }

    void print(ofstream &outputFile)
    {
        outputFile << name << '\n'
                   << id << '\n'
                   << gpa << "\n\n";
    }

    void print()
    {
        cout << name << '\n'
             << id << '\n'
             << gpa << "\n\n";
    }
};

int comparison;

//_____________________________________
// 1. Insertion Sort
template <typename T>
int insertionSort(vector<T> &v, bool GPA)
{
    int length = v.size();
    int comparisons = 0;
    for (int i = 1; i < length; i++)
    {
        comparisons++;
        T tmp = v[i];
        int j = i - 1;
        while (j >= 0 && ((GPA && tmp > v[j]) || (!GPA && tmp < v[j])))
        {
            comparisons = +2;
            v[j + 1] = v[j];
            j--;
        }
        if (j >= 0)
            comparisons++;
        v[j + 1] = tmp;
    }
    //    cout << "Number of comparisons: " << comparisons << endl;
    return comparisons;
}

//_____________________________________
// 2. Selection Sort
template <typename T>
void selectionSort(vector<T> &arr, bool GPA)
{
    int index{};
    int n = arr.size();
    for (int i = 0; i < n; i++, comparison++)
    {
        index = i;
        for (int j = i + 1; j < n; j++, comparison++)
        {
            if ((!GPA && arr[j] < arr[index]) || (GPA && arr[j] > arr[index]))
            {
                index = j;
            }
            comparison++;
        }
        swap(arr[i], arr[index]);
    }
}

//_____________________________________
// 3. Bubble Sort
template <typename T>
void BubbleSort(vector<T> &arr, bool GPA)
{
    if (GPA)
    {
        int n = arr.size();
        bool flag = true;
        // Loop in the whole array
        for (int i = 0; i < n; i++)
        {
            // A Loop without the ordered elements
            for (int j = 0; j < n - i - 1; j++)
            {
                // Put the greater elements in the start
                if (++comparison, arr[j + 1] > arr[j])
                {
                    swap(arr[j], arr[j + 1]);
                    flag = false; // To prove that it's not ordered
                }
            }
            // To break and stop looping if the array is already sorted
            if (flag)
                break;
        }
    }
    else
    {
        int n = arr.size();
        bool flag = true;
        // Loop in the whole array
        for (int i = 0; i < n; i++)
        {
            // A Loop without the ordered elements
            for (int j = 0; j < n - i - 1; j++)
            {
                // Put the smaller elements in the start
                if (++comparison, arr[j + 1] < arr[j])
                {
                    swap(arr[j], arr[j + 1]);
                    flag = false; // To prove that it's not ordered
                }
            }
            // To break and stop looping if the array is already sorted
            if (flag)
                break;
        }
    }
}
//_____________________________________
// 4. Shell Sort
template <typename T>
int shellSort(vector<T> &v, bool GPA)
{
    int length = v.size();
    int comparisons = 0;

    for (int gap = length / 2; gap > 0; gap /= 2, comparisons++)
    {
        for (int i = gap; i < length; i++, comparisons++)
        {
            T tmp = v[i];
            int j = i;

            while (j >= gap && ((GPA && tmp > v[j - gap]) || (!GPA && tmp < v[j - gap])))
            {
                comparisons = +2;
                v[j] = v[j - gap];
                j -= gap;
                if (j >= gap)
                    comparisons++;
                v[j] = tmp;
            }
        }
    }
    //    cout << "Number of comparisons: " << comparisons << endl;
    return comparisons;
}

//_____________________________________
// 5. Merge sort
template <class T>
void Merge(vector<T> &v, int begin, int middle, int end, bool GPA)
{

    // new temporary vectors for extra space
    vector<T> FirstSub;
    vector<T> SecondSub;
    int FirstSubSize = middle - begin + 1;
    int SecondSubSize = end - middle;

    // Put data in the temporary vectors
    for (int i = 0; i < FirstSubSize; i++)
    {
        FirstSub.push_back(v[begin + i]);
    }

    for (int i = 0; i < SecondSubSize; i++)
    {
        SecondSub.push_back(v[middle + 1 + i]);
    }

    int idxFirstSub = 0, idxSecondSub = 0, idxMerge = begin;

    // Merge Temporary vectors
    while (idxFirstSub < FirstSubSize && idxSecondSub < SecondSubSize)
    {
        // 2 comparisons for each loop despite it gives true or false
        if ((GPA && (FirstSub[idxFirstSub] >= SecondSub[idxSecondSub])) || (!GPA && (FirstSub[idxFirstSub] <= SecondSub[idxSecondSub])))
        {
            v[idxMerge++] = FirstSub[idxFirstSub++];
        }
        else
        {
            v[idxMerge++] = SecondSub[idxSecondSub++];
        }
        comparison += 2;
    }

    // Add if there are remaining elements in the first sub vector to the merged one
    while (idxFirstSub < FirstSubSize)
    {
        v[idxMerge++] = FirstSub[idxFirstSub++];
    }

    // Add if there are remaining elements in the second sub vector to the merged one
    while (idxSecondSub < SecondSubSize)
    {
        v[idxMerge++] = SecondSub[idxSecondSub++];
    }
}

//_____________________________________
// 6. Quicksort
template <typename T>
int partition(vector<T> &arr, int low, int high, bool GPA)
{
    int pivot = (low + high) / 2;
    swap(arr[pivot], arr[low]);

    int i = low, j = low + 1;
    while (j <= high)
    {
        if ((!GPA && arr[j] < arr[low]) || (GPA && arr[j] > arr[low]))
        {
            i++;
            swap(arr[i], arr[j]);
        }
        comparison += 2;
        j++;
    }
    swap(arr[i], arr[low]);
    return i;
}

template <typename T>
void quicksort(vector<T> &arr, int low, int high, bool GPA)
{
    if (low >= high)
    {
        return;
    }
    comparison++;

    int mid = partition(arr, low, high, GPA);
    quicksort(arr, low, mid - 1, GPA);
    quicksort(arr, mid + 1, high, GPA);
}

template <class T>
void MergeSort(vector<T> &v, int begin, int end, bool GPA)
{
    // Base Case
    if (begin >= end)
    {
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
void In()
{
    students.clear();
    ifstream Input("../SortingAlgorithms/students.txt");
    if (!Input)
    {
        cerr << "Failed to open the input file.\n";
        return;
    }
    else
    {
        int n;
        double gpa;
        string name, id;
        Input >> n;
        while (n--)
        {
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
void OutGPA()
{
    for (auto &x : students)
    {
        x.print(GPA);
    }
}

// write to SortedByName.txt after sorting by name
ofstream Name("../SortingAlgorithms/SortedByName.txt");
void OutName()
{
    for (auto &x : students)
    {
        x.print(Name);
    }
}

//________________________________
int main()
{
    Sort();
}

//________________________________
void Sort()
{
    // Start a counter with initial value that equals 0
    int SortingAlgo = 0;

    // Declare variables to calculate running time of function
    auto start = chrono::steady_clock::now(), end = chrono::steady_clock::now();
    auto RunningTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    while (++SortingAlgo)
    {
        In();
        switch (SortingAlgo)
        {
        case 1:
            GPA << "Algorithm: Insertion Sort\n";
            start = chrono::steady_clock::now();
            GPA << "Number of comparisons: " << insertionSort(students, 1) << '\n';
            end = chrono::steady_clock::now();
            RunningTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            GPA << "Running Time:" << RunningTime.count() / 1000000.0 << " milliseconds"
                << "\n";
            OutGPA();
            GPA << "//_________________________________\n";

            Name << "Algorithm: Insertion Sort\n";
            start = chrono::steady_clock::now();
            Name << "Number of comparisons: " << insertionSort(students, 0) << '\n';
            end = chrono::steady_clock::now();
            RunningTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            Name << "Running Time:" << RunningTime.count() / 1000000.0 << " milliseconds"
                 << "\n";
            OutName();
            Name << "//_________________________________\n";
            break;
        case 2:
            GPA << "Algorithm: Selection Sort\n";
            comparison = 0;
            start = chrono::steady_clock::now();
            selectionSort(students, 1);
            end = chrono::steady_clock::now();
            RunningTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            GPA << "Number of comparisons: " << comparison << '\n';
            GPA << "Running Time:" << RunningTime.count() / 1000000.0 << " milliseconds"
                << "\n";
            OutGPA();
            GPA << "//_________________________________\n";

            Name << "Algorithm: Selection Sort\n";
            comparison = 0;
            start = chrono::steady_clock::now();
            BubbleSort(students, 0);
            end = chrono::steady_clock::now();
            RunningTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            Name << "Number of comparisons: " << comparison << '\n';
            Name << "Running Time:" << RunningTime.count() / 1000000.0 << " milliseconds"
                 << "\n";
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
            GPA << "Running Time:" << RunningTime.count() / 1000000.0 << " milliseconds"
                << "\n";
            OutGPA();
            GPA << "//_________________________________\n";

            Name << "Algorithm: Bubble Sort\n";
            comparison = 0;
            start = chrono::steady_clock::now();
            BubbleSort(students, 0);
            end = chrono::steady_clock::now();
            RunningTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            Name << "Number of comparisons: " << comparison << '\n';
            Name << "Running Time:" << RunningTime.count() / 1000000.0 << " milliseconds"
                 << "\n";
            OutName();
            Name << "//_________________________________\n";
            break;
        case 4:
            GPA << "Algorithm: Shell Sort\n";
            start = chrono::steady_clock::now();
            GPA << "Number of comparisons: " << shellSort(students, 1) << '\n';
            end = chrono::steady_clock::now();
            RunningTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            GPA << "Running Time:" << RunningTime.count() / 1000000.0 << " milliseconds"
                << "\n";
            OutGPA();
            GPA << "//_________________________________\n";

            Name << "Algorithm: Shell Sort\n";
            start = chrono::steady_clock::now();
            Name << "Number of comparisons: " << shellSort(students, 0) << '\n';
            end = chrono::steady_clock::now();
            RunningTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            Name << "Running Time:" << RunningTime.count() / 1000000.0 << " milliseconds"
                 << "\n";
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
            GPA << "Running Time:" << RunningTime.count() / 1000000.0 << " milliseconds"
                << "\n";
            OutGPA();
            GPA << "//_________________________________\n";

            Name << "Algorithm: Merge Sort\n";
            comparison = 0;
            start = chrono::steady_clock::now();
            MergeSort(students, 0, students.size() - 1, 0);
            Name << "Number of comparisons: " << comparison << '\n';
            end = chrono::steady_clock::now();
            RunningTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            Name << "Running Time:" << RunningTime.count() / 1000000.0 << " milliseconds"
                 << "\n";
            OutName();
            Name << "//_________________________________\n";
            break;
        case 6:
            GPA << "Algorithm: Quick Sort\n";
            comparison = 0;
            start = chrono::steady_clock::now();
            quicksort(students, 0, students.size() - 1, 1);
            end = chrono::steady_clock::now();
            RunningTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            GPA << "Number of comparisons: " << comparison << '\n';
            GPA << "Running Time:" << RunningTime.count() / 1000000.0 << " milliseconds"
                << "\n";
            OutGPA();

            Name << "Algorithm: Quick Sort\n";
            comparison = 0;
            start = chrono::steady_clock::now();
            MergeSort(students, 0, students.size() - 1, 0);
            Name << "Number of comparisons: " << comparison << '\n';
            end = chrono::steady_clock::now();
            RunningTime = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            Name << "Running Time:" << RunningTime.count() / 1000000.0 << " milliseconds"
                 << "\n";
            OutName();
            break;
        }

        // Break when SortingAlgo is 6 as it reached last sorting algorithm
        if (SortingAlgo == 6)
        {
            break;
        }
    }
}
