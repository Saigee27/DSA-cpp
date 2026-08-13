/*
Bubble Sort

Idea:
Compare adjacent elements and swap them
if they are in the wrong order.

Time Complexity:
Best:    O(n)*
Average: O(n²)
Worst:   O(n²)

Space Complexity:
O(1)

In-place:
Yes

Stable:
Yes
*/

/*
* Best case O(n) applies when the algorithm
  uses an optimization to detect no swaps.
  Without that optimization, best case is O(n²).
*/

#include <iostream>
int main()
{
    int arr[10]= {6, 2, 9, 1, 5, 11, 10, 3, 15, 13};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int j=0; j<n-1; j++)
    {
        for (int i=0; i<n-1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
            
        }

    }
    
    for (int i=0; i<n; i++)
    {
       std::cout<<arr[i]<<" "; 
    }
}

