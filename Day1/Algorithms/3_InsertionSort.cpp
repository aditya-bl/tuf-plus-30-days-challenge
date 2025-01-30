class Solution {
public:
    vector<int> insertionSort(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            for(int j=i;j>0 && nums[j-1]>nums[j]; j--)
                swap(nums[j-1],nums[j]);
        }
        return nums;
    }
};


// Faster implementation - with shifting instead of swapping:

class Solution {
public:
    vector<int> insertionSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int key = nums[i];  // Pick the current element
            int j = i - 1;

            // Shift elements to the right instead of swapping
            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = key;  // Insert the key at the right position
        }
        return nums;
    }
};
