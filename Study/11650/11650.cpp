#include <cstdio>

void merge(int** sorted, int** arr, int begin, int mid, int end);
void mergeSort(int** sorted, int** arr, int begin, int end);
void printArr(int** arr, int n);

int main(void) {
    int n;
    scanf("%d", &n);

    int** arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[2];
    }
    int** sorted = new int*[n];
    for(int i = 0; i < n; i++) {
        sorted[i] = new int[2];
    }

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    mergeSort(sorted, arr, 0, n - 1);
    printArr(arr, n);

    for(int i = 0; i < n; i++) {
        delete[] arr[i];
        delete[] sorted[i];
    }
    delete[] arr;
    delete[] sorted;
    return 0;
}

void merge(int** sorted, int** arr, int begin, int mid, int end) {
    int i, j, k;
    i = begin;
    j = mid + 1;
    k = begin;

    while(i <= mid && j <= end) {
        if(arr[i][0] < arr[j][0]) {
            sorted[k][0] = arr[i][0];
            sorted[k][1] = arr[i][1];
            i++;
        }
        else if(arr[i][0] == arr[j][0]) {
            if(arr[i][1] < arr[j][1]) {
                sorted[k][0] = arr[i][0];
                sorted[k][1] = arr[i][1];
                i++;
            }
            else {
                sorted[k][0] = arr[j][0];
                sorted[k][1] = arr[j][1];
                j++;
            }
        }
        else {
            sorted[k][0] = arr[j][0];
            sorted[k][1] = arr[j][1];
            j++;
        }
        k++;
    }
    if(i > mid) {
        for(int a = j; a <= end; a++, k++) {
            sorted[k][0] = arr[a][0];
            sorted[k][1] = arr[a][1];
        }
    }
    else {
        for(int a = i; a <= mid; a++, k++) {
            sorted[k][0] = arr[a][0];
            sorted[k][1] = arr[a][1];
        }
    }

    for(int a = begin; a <= end; a++) {
        arr[a][0] = sorted[a][0];
        arr[a][1] = sorted[a][1];
    }
}

void mergeSort(int** sorted, int** arr, int begin, int end) {
    int mid;
    if(begin < end) {
        mid = (begin + end) / 2;
        mergeSort(sorted, arr, begin, mid);
        mergeSort(sorted, arr, mid + 1, end);
        merge(sorted, arr, begin, mid, end);
    }
}

void printArr(int** arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }
}