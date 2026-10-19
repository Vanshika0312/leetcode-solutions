class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        for(int i =0;i<n;i++){
            sort(nums.begin(), nums.end());
    
        }
        return nums[0];
    }
};