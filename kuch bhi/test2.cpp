#include <iostream>
int main()
{
    int arr[] = {12, 45, 7, 89, 34, 56};
    int max = arr[0];
    int secmax = arr[0];
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<n; i++)
    {
        if(max<arr[i])
        {
            secmax=max;
            max=arr[i];
        }
        else if(arr[i]>secmax && arr[i]!=max)
        {
            secmax=arr[i];
        }
      
    }
    std::cout << "Second largest = " << secmax;
}