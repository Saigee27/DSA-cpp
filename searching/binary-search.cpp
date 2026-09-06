/*
Binary Search:

Searches for a target in a sorted array by repeatedly dividing
the search range into two halves.

Time Complexity:
Best Case  - O(1)
Worst Case - O(log n)

Space Complexity:
O(1)
*/

#include <iostream>
int main()
{
    int arr[] = {3, 7, 12, 18, 25, 36, 42, 50, 55, 63, 78, 81, 89, 99, 100};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout<<"Enter target: ";
    int left=0, right=n-1, target=0;
    std::cin>>target;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(target==arr[mid])
        {
            std::cout<<"Target number "<<arr[mid]<<" found at index "<<mid;
            return 0;
        }
        else if(arr[mid] < target)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    std::cout << "Target number not found";
    return 0;
}