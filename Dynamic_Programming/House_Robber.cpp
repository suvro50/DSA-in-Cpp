#include <iostream>
#include <vector>
using namespace std;

    int rob(vector<int>& nums) {

       int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> maxmoney(n);

        maxmoney[0] = nums[0];
        maxmoney[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++){

            maxmoney[i] = max(maxmoney[i-2] + nums[i], maxmoney[i-1]);
       }

        return maxmoney[n-1];
}

int main() {
    int n;
    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the money in each house: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

   
    int result = rob(nums);

    cout << "Maximum money that can be robbed: " << result << endl;

    return 0;
}
