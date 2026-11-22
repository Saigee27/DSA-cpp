/*
Merge Sort:

Sorts an array by recursively dividing it into two halves,
sorting each half, and merging them back together.

Time Complexity:
Best Case    - O(n log n)
Average Case - O(n log n)
Worst Case   - O(n log n)

Space Complexity:
O(n)

Stable Sorting Algorithm.
*/ 


#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted portions
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from right half
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back into original array
    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

// Merge Sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
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

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
