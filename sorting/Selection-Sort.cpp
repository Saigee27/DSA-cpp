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

