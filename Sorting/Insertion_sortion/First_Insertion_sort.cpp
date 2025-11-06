#include <iostream>
using namespace std;
int main()
{

    int n = 6;
    int arr[n] = {5, 4, 7, 3, 6, 9};

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i;
        while (j >0 && arr[j-1] > key)
        {
            arr[j] = arr[j-1];
            j--;
        }
       arr[j]=key;
    }
    
     cout<<"After sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}