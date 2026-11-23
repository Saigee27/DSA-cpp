
/*
Insertion Sort:

Idea:
Builds a sorted array one element at a time.
Takes an element and inserts it into its correct position
by shifting larger elements to the right.

Time Complexity:
Best:    O(n)
Average: O(n²)
Worst:   O(n²)

Space Complexity:
O(1)

In-place:
Yes

Stable:
Yes
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

    for (int i = 1; i < n; i++)
    {
        int Num = arr[i];
        int j;

        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > Num)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = Num;
    }

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
