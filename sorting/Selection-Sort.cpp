
/*
Selection Sort

Idea:
Find the smallest element from the unsorted
portion and place it at the beginning.

Time Complexity:
Best:    O(n²)
Average: O(n²)
Worst:   O(n²)

Space Complexity:
O(1)

In-place:
Yes

Stable:
No
*/

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid array size!";
        return 0;
    }

    int arr[n];

    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int smallestind = 0;

    for (int i = 0; i < n - 1; i++)
    {
        smallestind = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallestind])
            {
                smallestind = j;
            }
        }

        if (smallestind != i)
        {
            int temp = arr[i];
            arr[i] = arr[smallestind];
            arr[smallestind] = temp;
        }
    }

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
