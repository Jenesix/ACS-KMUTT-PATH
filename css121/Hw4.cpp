#include <iostream>
#include <vector>

using namespace std;

struct MyData {
    int colNo;
    int colA;
    int colB;
    int colC;
};

int partition(vector<MyData>& arr, int low, int high, int colIndex) {
    MyData pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (colIndex == 1) {
            if (arr[j].colA <= pivot.colA) {
                if (arr[j].colA == pivot.colA) {
                    if (arr[j].colB <= pivot.colB) {
                        if (arr[j].colB == pivot.colB) {
                            if (arr[j].colC <= pivot.colC) {
                                i++;
                                swap(arr[i], arr[j]);
                            }
                        } else {
                            i++;
                            swap(arr[i], arr[j]);
                        }
                    }
                } else {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
        } else if (colIndex == 2) {
            if (arr[j].colB <= pivot.colB) {
                if (arr[j].colB == pivot.colB) {
                    if (arr[j].colC <= pivot.colC) {
                        if (arr[j].colC == pivot.colC) {
                            if (arr[j].colA <= pivot.colA) {
                                i++;
                                swap(arr[i], arr[j]);
                            }
                        } else {
                            i++;
                            swap(arr[i], arr[j]);
                        }
                    }
                } else {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
        } else {
            if (arr[j].colC <= pivot.colC) {
                if (arr[j].colC == pivot.colC) {
                    if (arr[j].colA <= pivot.colA) {
                        if (arr[j].colA == pivot.colA) {
                            if (arr[j].colB <= pivot.colB) {
                                i++;
                                swap(arr[i], arr[j]);
                            }
                        } else {
                            i++;
                            swap(arr[i], arr[j]);
                        }
                    }
                } else {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(vector<MyData>& arr, int low, int high, int colIndex) {
    if (low < high) {
        int pivot = partition(arr, low, high, colIndex);

        quicksort(arr, low, pivot - 1, colIndex);
        quicksort(arr, pivot + 1, high, colIndex);
    }
}

void printData(vector<MyData>& arr) {
    for (const auto& data : arr) {
        cout << data.colNo << "  " << data.colA << "  "  << data.colB << "  " << data.colC << endl;
    }
}


int main() {
    vector<MyData> arr = {
        { 1, 1, 1, 4 },
        { 2, 3, 1, 1 },
        { 3, 4, 4, 4 },
        { 4, 2, 4, 4 },
        { 5, 3, 5, 3 },
        { 6, 4, 3, 3 },
        { 7, 1, 3, 3 },
        { 8, 2, 4, 3 },
        { 9, 3, 3, 5 },
        { 10, 1, 5, 3 },
        { 11, 1, 1, 4 },
        { 12, 4, 1, 1 },
        { 13, 5, 2, 3 },
        { 14, 3, 5, 2 },
    };
    cout << "Sorting by A first, then B, then C:\n";
    quicksort(arr, 0, arr.size() - 1, 1);
    printData(arr);
    cout << endl;
    cout << "Sorting by B first, then C, then A:\n";
    quicksort(arr, 0, arr.size() - 1, 2);
    printData(arr);
}