
/*

Recursive Binary Search

Idea:
Find the middle element and compare it with the target.
Recursively search the left or right half.

Base Case:
If low > high, return -1.

Time Complexity:
Best:    O(1)
Average: O(log n)
Worst:   O(log n)

Space Complexity:
O(log n)

In-place:
Yes, the search does not modify the array.

Stable:
Not applicable.

Prerequisite:
The array must be sorted in ascending order.
Bubble Sort is used below to sort the user's input.

*/

#include <iostream>
using namespace std;

int BS(int arr[], int low, int high, int target)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;

    if (arr[mid] < target)
        return BS(arr, mid + 1, high, target);

    return BS(arr, low, mid - 1, target);
}

int main()
{
    int n;

    cout << "Enter array size: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid array size.\n";
        return 1;
    }

    int arr[n];

    cout << "Enter " << n << " elements:\n";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Bubble Sort: arrange elements in ascending order
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << '\n';

    int target;

    cout << "Enter target: ";
    cin >> target;

    int result = BS(arr, 0, n - 1, target);

    if (result != -1)
        cout << "Target found at index " << result;
    else
        cout << "Target not found.";

    return 0;
}