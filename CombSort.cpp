#include <iostream>

void readVector(int *sortVector, int n) {
    for(int i = 0; i < n; ++i) {
        std :: cin >> sortVector[i];
    }
}

void showVector(int *sortVector, int n) {
    for(int i = 0; i < n; ++i) {
        std :: cout << sortVector[i] << " ";
    }
}

void swapElements(int *sortVector, int i, int j) {
    int aux = sortVector[i];
    sortVector[i] = sortVector[j];
    sortVector[j] = aux;
}
int getGap(int gap) {
    gap = (gap * 10) / 13;
    if(gap < 1) {
        return 1;
    }
    return gap;
}
void combSort(int n, int *sortVector) {
   int gap = n;
   bool swapped = true;

   while(gap != 1 || swapped == true) {
        gap = getGap(gap);

        swapped = false;
        for(int i = 0; i < n - gap; ++i) {
            if(sortVector[i] > sortVector[i + gap]) {
                swapElements(sortVector, i, i + gap);
                swapped = true;
            }
        }
   }
}
int main() {
    int *sortVector;
    int n;
    std :: cout << "Cate elemente doresti :";
    std :: cin >> n;
    sortVector = new int[n];

    readVector(sortVector, n);

    combSort(n, sortVector);

    showVector(sortVector, n);
}
