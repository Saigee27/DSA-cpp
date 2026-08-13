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
int main()
{
    int arr[10]= {6, 2, 9, 1, 5, 11, 10, 3, 15, 13};
    int n = sizeof(arr)/sizeof(arr[0]);
    int smallestind=0;

    for (int i=0; i<n-1; i++)
    {
        smallestind=i;
        for(int j=i+1; j<n; j++)
        {
            
            if (arr[j]<arr[smallestind])
            {
                smallestind=j;
            }
        }

        if (smallestind != i)
        {
            int temp = arr[i];
            arr[i] = arr[smallestind];
            arr[smallestind] = temp;
        }
    }

    for (int i=0; i<n; i++)
{
    std::cout<<arr[i]<<" ";
}
}

