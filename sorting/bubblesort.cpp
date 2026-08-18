/*
Bubble Sort

Idea:
Compare adjacent elements and swap them
if they are in the wrong order.

Time Complexity:
Best:    O(n²)
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
int main()
{
    int arr[10]= {6, 2, 9, 1, 5, 11, 10, 3, 15, 13};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }

    }
    
    for (int i=0; i<n; i++)
    {
       std::cout<<arr[i]<<" "; 
    }
}

