#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int selected = i;

        //Find min element in the rest of array
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[selected]) {
                selected = j;
            }
        }

        swap(a[i], a[selected]);
    }
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j + 1] < a[j]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        //Move key to the [0, i] sub array that still keep the non-descending order
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

void copyArray(int* sourceLeft, int* sourceRight, int* destination) {
    int* index = destination;
    for (int* element = sourceLeft; element != sourceRight; element++) {
        *(index++) = *element;
    }
}

void merge(int* left, int sizeLeft, int* right, int sizeRight, int* result) {
    int i = 0, j = 0, k = 0;

    while (i < sizeLeft && j < sizeRight) {
        if (left[i] < right[j]) result[k++] = left[i++];
        else result[k++] = right[j++];
    }

    if (i < sizeLeft) copyArray(left + i, left + sizeLeft, result + k);
    k += sizeLeft - i;

    if (j < sizeRight) copyArray(right + i, right + sizeRight, result + k);
}

void mergeSort(int a[], int n) {
    if (n > 1) {
        int mid = n / 2;
        int* b = new int[mid];
        int* c = new int[n - mid];

        copyArray(a, a + mid, b);
        copyArray(a + mid, a + n, c);

        mergeSort(b, mid);
        mergeSort(c, n - mid);
        merge(b, mid, c, n - mid, a);
    }
}

int partition(int a[], int l, int r) {
    int p = l + (r - l) / 2;

    while (l <= r) {
        while (a[l] < a[p] && l <= r) l++;
        while (a[p] < a[r] && l <= r) r--;

        if (l <= r) {
            swap(a[l], a[r]);
            l++; r--;
        }
    }

    return l;
}

void qsort(int a[], int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);

        qsort(a, l, p - 1);
        qsort(a, p + 1, r);
    }
}

void quickSort(int a[], int n) {
    qsort(a, 0, n - 1);
}

int getParent(int i) {
    return (i - 1) / 2;
}

int getLeftChild(int i) {
    return 2 * i + 1;
}

int getRightChild(int i) {
    return 2 * i + 2;
}

void maxHeapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    //Not need to do any thing when the node is at right order
    if (largest != i) {
        swap(a[i], a[largest]);

        maxHeapify(a, n, largest);
    }
}

void buildMaxHeap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(a, n, i);
    }
}

void heapSort(int a[], int n) {
    buildMaxHeap(a, n);

    for (int i = n - 1; i > 0; i--) {
        swap(a[i], a[0]);

        maxHeapify(a, i, 0);
    }
}

//Require: The input file must follows the rule below
//First line: n is the size of the array
//Second line: a1 a2 a3 ... an are the element of the array saperated by one space
void loadArray(int* &a, int &n) {
    ifstream f("Input.txt");

    f >> n;

    a = new int[n];
    for (int i = 0; i < n; i++) {
        f >> a[i];
    }

    f.close();
}

void makeTest() {
    ofstream f("Input.txt");

    int n;
    cout << "Enter the size of the array: "; cin >> n;

    f << n << '\n';
    for (int i = 0; i < n; i++) {
        f << rand() % 1000000 << ' ';
    }

    f.close();
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main()
{
    //Produce test case automatically
    //makeTest();

    //Initialize input
    int n;
    int* a;
    loadArray(a, n);

    //Save the start time
    cout << "******************* Sorting process started! *******************\n\n";
    auto start = chrono::high_resolution_clock::now();

    //Implement sorting
    quickSort(a, n);

    //Calculate the execution time
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    //Show the execution time
    cout << "The sorting process finish in " << duration.count() / 1000 << " ms.\n";

    //Output
    //printArray(a, n);

    delete[] a;
    a = NULL;
}