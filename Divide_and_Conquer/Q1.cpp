#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& arr, int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    long long count = 0;
    int i = 0; 
    int j = 0;
    int k = left; 

    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {

            arr[k] = L[i];
            i++;

        } else {

            arr[k] = R[j];
            j++;
            count += (n1 - i); 
        }

        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return count;
}

long long mergeSort(vector<int>& arr, int left, int right) {
    long long count = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid + 1, right);

        count += merge(arr, left, mid, right); 
    }
    return count;
}


long long count_inversion(vector<int>& arr) {

    return mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long result = count_inversion(v);
    
    cout << "#inversions: " << result << endl;


    return 0;
}