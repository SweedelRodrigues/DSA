#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int st, int end) {
    int pivot = arr[end];

    int idx = st - 1;

    for (int j = st; j < end; j++) {
        if (arr[j] <= pivot) {
            idx++;
            swap(arr[idx], arr[j]);
        }
    }

    idx++;
    swap(arr[idx], arr[end]);   // place pivot at correct position

    return idx;
}

void quickSort(vector<int>& arr, int st, int end) {
    if (st < end) {
        int pivotIdx = partition(arr, st, end);

        quickSort(arr, st, pivotIdx - 1);   // left half
        quickSort(arr, pivotIdx + 1, end);  // right half
    }
}

int main() {
    vector<int> arr = {1, 2, 31, 95, 8, 92, 11};

    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}