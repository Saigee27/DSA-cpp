/*
Linear Search:

Linear Search checks each element of an array one by one from left to right
until the target element is found or the entire array has been searched.

If the target is found, its index is displayed. If the target is not present,
the program reports that the element was not found.

Time Complexity:
Best Case  - O(1)
Worst Case - O(n)

Space Complexity:
O(1)
*/

#include <iostream>
int main()
{
    int arr[] = {10, 25, 7, 42, 18, 99, 100, 45, 67, 34, 78, 81};
    int target = 0;
    std::cout<<"Insert the number to be found: ";
    std::cin>>target;
    int n = sizeof(arr)/sizeof(arr[0]);
    bool found=false;
    for (int i=0; i<n; i++)
    {
        if(target==arr[i])
        {
            std::cout<<"The number "<<arr[i]<<" is found at "<<i<<" index";
            found=true;
            break;
        }
    }
    if(!found)
    {
        std::cout<<"There is no number in the given list";       
    }
        
}