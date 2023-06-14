# Sort Algorithms
This repository contains implementations of various fundamental sorting algorithms. The implemented algorithms include:
* Selection Sort
* Bubble Sort
* Insertion Sort
* Merge Sort
* Quick Sort
* Heap Sort
* Counting Sort
* Radix Sort
* Bucket Sort

## Usage
### Sorting Process and Time Measurement
To measure the execution time of the sorting process and display it to the console, you can follow the example code snippet below:

    measure(a, n, mergeSort);
  
Replace the `mergeSort` function call with the desired sorting algorithm of your choice. Moreover, you can call many `measure` functions to compare many sorting algorithms.

### Input File
The repository includes a file named `Input.txt` which can be used to store input cases for sorting. The input file must follow the specified format:
1. First line: n is the size of the array.
2. Second line: a[1] a[2] a[3] ... a[n] are the elements of the array separated by one space.

You can manually adjust the content of `Input.txt` to modify the input case. <br/>

Alternatively, you can use the `makeTest` function provided in the code to generate random test cases with a specific size.

## Acknowledgements
I would like to express my sincere gratitude to my teacher, Ph.D. Nguyen Hai Minh, for her guidance and expertise in the subject of Data Structures and Algorithms. Her knowledge and dedication have greatly contributed to my understanding of sorting algorithms and their implementation. I am thankful for the valuable lessons and support provided throughout the learning process.
