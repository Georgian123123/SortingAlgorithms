#include <iostream>
#include <math.h>


void putInVector(int *sortVector, int n) {
    for(int i = 0; i < n; ++i) {
        std :: cin >> sortVector[i];
    }
}

void showVector(int *sortVector, int n) {

    for(int i = 0; i < n; ++i) {
        std :: cout << sortVector[i] << std :: endl;
    }
}
int findPivot(int beginVector, int endVector, int middleVector, int *sortVector) {

    if(sortVector[middleVector] < sortVector[beginVector]) {
        int aux = sortVector[middleVector];
        sortVector[middleVector] = sortVector[beginVector];
        sortVector[beginVector] = aux;
    }
    if(sortVector[endVector] < sortVector[beginVector]) {
        int aux = sortVector[endVector];
        sortVector[endVector] = sortVector[beginVector];
        sortVector[beginVector] = aux;
    }
    if(sortVector[middleVector] > sortVector[endVector]) {
        int aux = sortVector[endVector];
        sortVector[endVector] = sortVector[middleVector];
        sortVector[middleVector] = aux;
    }
   return sortVector[0];
}
void swapNumbers(int number1, int number2, int *sortedVector) {

    int auxiliar = sortedVector[number1];
    sortedVector[number1] = sortedVector[number2];
    sortedVector[number2] = auxiliar;
}
int partitionVector(int beginVector, int endVector, int *sortVector, int pivot) {
    int i = beginVector;
    int j = endVector;

    do {
        ++i;
    } while (sortVector[i] <= pivot);

    do {
        --j;
    } while(sortVector[j] > pivot);

    if(i < j) {
        swapNumbers(i, j, sortVector);
    }
    return j;
}

int heapSort(int i, int nHeap, int *sortVector, int beginVector) {
        int temp = sortVector[beginVector + i - 1];
        int child;

        while (i <= (nHeap / 2)) {
            child = 2 * i;

            if (child < nHeap && sortVector[beginVector + child - 1] < sortVector[beginVector + child])
                child++;

            if (temp >= sortVector[beginVector + child - 1])
                break;

            sortVector[beginVector + i - 1] = sortVector[beginVector + child - 1];
            i = child;
        }
        sortVector[beginVector + i - 1] = temp;
}

void heaps(int beginVector, int endVector, int *sortedVector, int nHeap) {
    for(int i = (nHeap) / 2; i >= 1; --i) {
        heapSort(i, nHeap, sortedVector, beginVector);
    }
}

void heapSorting(int beginVector, int endVector, int *sortedVector) {

    int nHeap = endVector - beginVector;
    heaps(beginVector, endVector, sortedVector, nHeap);

    for(int i = nHeap; i >= 1; --i) {
        int aux = beginVector + i;
        swapNumbers(beginVector, aux, sortedVector);
        heapSort(1, i, sortedVector, beginVector);
    }
}
int insertionSort(int beginVector, int endVector, int *sortVector) {


    for(int i = beginVector; i <= endVector; ++i) {
        int key = sortVector[i];
        int j = i;

        while(j > beginVector && sortVector[j - 1] > key) {
            sortVector[j] = sortVector[j - 1];
            j--;
        }
        sortVector[j] = key;
    }

}
void sortDataUtil(int beginVector, int endVector, int depthLimit, int *sortVector) {

    if(endVector - beginVector > 16) {
        if(depthLimit == 0) {
            heapSorting(beginVector, endVector, sortVector);
            return;
        }
        depthLimit -= 1;
        int pivot = findPivot(beginVector, endVector, (endVector - beginVector) / 2, sortVector);
        int p = partitionVector(beginVector, endVector, sortVector, 1);
        sortDataUtil(beginVector, pivot - 1, depthLimit, sortVector);
        sortDataUtil(pivot + 1, endVector, depthLimit, sortVector);
    } else {
        insertionSort(beginVector, endVector, sortVector);
    }
}
void sortData(int beginVector, int endVector, int *sortVector) {


    int depthLimit = (int) (2 * log(endVector));
    sortDataUtil(beginVector, endVector, depthLimit, sortVector);
}
int main() {
    int n;
    std :: cout << "cate numere :";
    std :: cin >> n;
    int *sortVector = new int[n];
    putInVector(sortVector, n);
    sortData(0, n - 1, sortVector);
    showVector(sortVector, n);
}
