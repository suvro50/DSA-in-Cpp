#include <iostream>
#include <vector>
#include <algorithm>

#define sw swap   // it define sw key for swap function .

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low; 

    for (int j = low; j < high; j++) {

        if (arr[j] > pivot) {
            sw(arr[i], arr[j]);
            i++;  
        }

    }
    
    swap(arr[i], arr[high]);
    return i;
}

void quick_sort(vector<int>& arr, int low, int high) {

    if (low < high) {
        int p = partition(arr, low, high);

        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> num(n);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    quick_sort(num, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}