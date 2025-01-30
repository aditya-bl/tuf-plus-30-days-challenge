class Solution {
public:
    vector<int> bubbleSort(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            for(int j=0;j<nums.size()-i-1;j++){
                if(nums[j+1]<nums[j])
                    swap(nums[j],nums[j+1]);
            }
        }
        return nums;
    }
};
