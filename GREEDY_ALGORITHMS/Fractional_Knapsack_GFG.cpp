#include<bits/stdc++.h>
using namespace std;

 struct item {
        int weight;
        double value;
};

 bool compare(const item& a, const item& b) {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        if (r1 == r2) return a.value > b.value;
        return r1 > r2;
    }

class Solution {
public:

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {

        int n = val.size();
        vector<item> items(n);

        for(int i = 0; i < n; i++) {
            items[i].value = val[i];
            items[i].weight = wt[i];
        }

        sort(items.begin(), items.end(), compare);

        double total = 0.0;
        int currentWeight = 0;

        for(int i = 0; i < n; i++) {

            if (currentWeight + items[i].weight <= capacity) {
                total += items[i].value;
                currentWeight += items[i].weight;
            }
            else {
                int remain = capacity - currentWeight;
                double perKg = (double)items[i].value / (double)items[i].weight;
                total += remain * perKg;
                break;
            }
        }

        return total;
    }
};

int main() {

    vector<int> val = {60, 100, 120};
    vector<int> wt  = {10, 20, 30};
    int capacity = 50;

    Solution s;
    cout << s.fractionalKnapsack(val, wt, capacity);

    return 0;
}
 