#include<iostream>
using namespace std;

int partition_position(int arr[], int low, int high)
{
    int pivot = high;
    int blue_color = low-1;

    for(int red_color=low; red_color<high; red_color++)
    {


        if(arr[red_color]<arr[pivot])   //only work when red_color smaller than pivot  ,  or avoite
        {
            blue_color++;

            int temp = arr[blue_color];
            arr[blue_color] = arr[red_color];
            arr[red_color] = temp;
        }
    }

    blue_color++;

    int temp = arr[pivot];
    arr[pivot] = arr[blue_color];
    arr[blue_color] = temp;

    return blue_color;
}

void quick_sort(int arr[], int low, int high)
{

    if(low<high)
    {
        int partition_index = partition_position(arr, low, high);
        quick_sort(arr, low, partition_index-1);
        quick_sort(arr, partition_index+1, high);
    }
}
int main()
{
    int arr[7] = {50, 30, 80, 10, 20, 60, 40};

    quick_sort(arr, 0, 6);

    for(int i=0; i<7; i++)
    {
       cout<<arr[i]<<" ";
    }


}
