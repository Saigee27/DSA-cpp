#include <iostream>
int main()
{
    int arr[10]= {6, 2, 9, 1, 5, 11, 10, 3, 15, 13};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=1; i<n; i++)
    {
        int Num = arr[i];
        int j;
        for(j=i-1; j>=0; j--)
        {
            if(arr[j]>Num)
            {
                arr[j+1]=arr[j];
            }
            else
            {
                break;
            }
            
        }
        arr[j+1]=Num;
        
    }

    for(int i=0; i<n; i++)
    {
        std::cout<<arr[i]<<" ";
    }
}