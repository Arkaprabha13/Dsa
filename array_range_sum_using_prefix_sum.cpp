#include <iostream>
#include <vector>

using namespace std;

vector<int> calculatePrefixSum(const vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixSum(n, 0);

    prefixSum[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    return prefixSum;
}

int getRangeSum(const vector<int>& prefixSum, int left, int right) {
    if (left == 0) {
        return prefixSum[right];
    } else {
        return prefixSum[right] - prefixSum[left - 1];
    }
}

int main() {
    // Example usage
    vector<int> nums ;
    int n;
    cout<<"N-> ";cin>>n;
    for (int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        nums.push_back(a);
    }
    vector<int> prefixSum = calculatePrefixSum(nums);

    // Range Sum Queries
    int left ; // starting index of the range
    int right ; // ending index of the range
    cout<<"Left->";cin>>left;
    cout<<"right->";cin>>right;
    
    int rangeSum = getRangeSum(prefixSum, left, right);
    cout << "The sum of elements in the range [" << left << ", " << right << "] is: " << rangeSum << endl;

    return 0;
}
