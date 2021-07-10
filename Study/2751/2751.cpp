#include <cstdio>

void merge(int* sorted, int* arr, int begin, int mid, int end);
void mergeSort(int* sorted, int* arr, int begin, int end);
void printArr(int* arr, int n);

int main(void) {
    int n;
    scanf("%d", &n);

    int* arr = new int[n];
    int* sorted = new int[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergeSort(sorted, arr, 0, n - 1);
    printArr(arr, n);

    delete[] arr;
    return 0;
}

void merge(int* sorted, int* arr, int begin, int mid, int end) {
    int i, j, k;
    i = begin;
    j = mid + 1;
    k = begin;

    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            sorted[k] = arr[i];
            i++;
        }
        else {
            sorted[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i > mid) {
        for(int a = j; a <= end; a++, k++)
            sorted[k] = arr[a];
    }
    else {
        for(int a = i; a <= mid; a++, k++)
            sorted[k] = arr[a];
    }

    for(int a = begin; a <= end; a++)
        arr[a] = sorted[a];
}

void mergeSort(int* sorted, int* arr, int begin, int end) {
    int mid;
    if(begin < end) {
        mid = (begin + end) / 2;
        mergeSort(sorted, arr, begin, mid);
        mergeSort(sorted, arr, mid + 1, end);
        merge(sorted, arr, begin, mid, end);
    }
}

void printArr(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}