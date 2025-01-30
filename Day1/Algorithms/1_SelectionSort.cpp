class Solution {
public:
    vector<int> selectionSort(vector<int>& nums) {
        for(int i=0;i<(nums.size()-1);i++){
            int indexOfSmallest = i;
            for(int j=i+1;j<nums.size();j++)
                if(nums[j] < nums[indexOfSmallest])
                    indexOfSmallest = j;
            swap(nums[i],nums[indexOfSmallest]);
        }
        return nums;
    }
};
