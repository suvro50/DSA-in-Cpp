#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& a, int l, int r) {
    if (l == r) return a[l];      // Base case: single element

    int mid = (l + r) / 2;

    int leftMajor  = majorityElement(a, l, mid);
    int rightMajor = majorityElement(a, mid + 1, r);

    if (leftMajor == rightMajor) return leftMajor;

    int leftCount = 0, rightCount = 0;
    for (int i = l; i <= r; i++) {
        if (a[i] == leftMajor) leftCount++;
        if (a[i] == rightMajor) rightCount++;
    }

    return (leftCount > rightCount) ? leftMajor : rightMajor;
}

int main() {
    vector<int> a = {1,1,1,1,1,2,2,2,2};

    int ans = majorityElement(a, 0, a.size() - 1);
    cout << "Majority element: " << ans << endl;

    return 0;
}
