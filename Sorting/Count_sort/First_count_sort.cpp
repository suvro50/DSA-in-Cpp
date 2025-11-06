#include<iostream>
using namespace std;

int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int find_min(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

void count_sort(int arr[], int n) {
    int max = find_max(arr, n);
    int min = find_min(arr, n);
    
    int range = max - min  + 1;  // total elements or range between min and max (inclusive)

    int* count = new int[range](); // *dynamic array declaration

    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;  // shift to 0-based
    }

    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + min;  // shift back to original value
            count[i]--;
        }
    }

    delete[] count;  // free memory

    cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

}

int main() {
    int n=6;
    int arr[n] = {4, -2, 9, 0, -5, 7};
    count_sort(arr, n);

    return 0;
} 