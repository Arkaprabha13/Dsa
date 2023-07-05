class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
    int total_sum = accumulate(nums.begin(), nums.end(), 0); // calculate total sum of elements in the array
    int left_sum = 0; // initialize left sum to 0
    
    for(int i = 0; i < nums.size(); i++) {
        if(left_sum == total_sum - left_sum - nums[i]) {
            return i;
        }
        left_sum += nums[i]; // add current element to the left sum
    }
    
    return -1; // return -1 if no pivot index is found
}
    
};

/*
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
*/
