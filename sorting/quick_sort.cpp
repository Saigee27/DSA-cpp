
/*
Quick Sort:

Sorts an array by selecting a pivot element and partitioning
the array such that smaller elements are placed before the pivot
and larger elements are placed after it.

The process is recursively repeated for both partitions.

Time Complexity:
Best Case    - O(n log n)
Average Case - O(n log n)
Worst Case   - O(n^2)

Space Complexity:
Average Case - O(log n)
Worst Case   - O(n)

Unstable Sorting Algorithm.
*/

#include <iostream>
#include <vector>
using namespace std;

// Partition function
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size!";
        return 0;
    }

    vector<int> arr(n);

    cout << "Enter " << n << " elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
