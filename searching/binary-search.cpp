#include <iostream>
int main()
{
    int arr[] = {3, 7, 12, 18, 25, 42, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout<<"Enter target: ";
    int left=0, right=n-1, target=0;
    std::cin>>target;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(target==arr[mid])
        {
            std::cout<<"target "<<arr[mid]<<" found at index "<<mid;
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
    std::cout << "Target not found";
    return 0;
}