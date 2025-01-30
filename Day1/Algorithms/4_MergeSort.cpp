class Solution {
private:
    vector<int> merge(vector<int> leftArr, vector<int> rightArr){
        vector<int> mergedArr = {};
        int leftIndex=0, rightIndex=0, leftSize=leftArr.size(), rightSize=rightArr.size();
        while(leftIndex < leftSize && rightIndex < rightSize){
            if(leftArr[leftIndex] < rightArr[rightIndex]){
                mergedArr.push_back(leftArr[leftIndex++]);
            }else{
                mergedArr.push_back(rightArr[rightIndex++]);
            }
        }
        while(leftIndex < leftSize){
            mergedArr.push_back(leftArr[leftIndex++]);
        }
        while(rightIndex < rightSize){
            mergedArr.push_back(rightArr[rightIndex++]);
        }
        return mergedArr;
    }

    vector<int> mergeSortArr(vector<int>& nums,int left,int right){
        if(left==right){
            vector<int> subArr = {nums[left]};
            return subArr;
        }
        int middle = (left+right)/2;
        vector<int> leftArr = mergeSortArr(nums,left,middle);
        vector<int> rightArr = mergeSortArr(nums,middle+1,right);

        return merge(leftArr,rightArr);
    }
public:
    vector<int> mergeSort(vector<int>& nums) {
        return mergeSortArr(nums,0,nums.size()-1);
    }
};

// Faster Implementation - with value by reference

class Solution {
private:
    void merge(vector<int>& nums, int left, int mid, int right) {
        int lSize = mid - left + 1;
        int rSize = right - mid;
        
        // Create temporary arrays
        vector<int> leftArr(lSize), rightArr(rSize);
        
        // Copy data to temporary arrays
        for (int i = 0; i < lSize; i++)
            leftArr[i] = nums[left + i];
        for (int j = 0; j < rSize; j++)
            rightArr[j] = nums[mid + 1 + j];

        // Merge back into nums[]
        int i = 0, j = 0, k = left;
        while (i < lSize && j < rSize) {
            if (leftArr[i] <= rightArr[j]) 
                nums[k++] = leftArr[i++];
            else 
                nums[k++] = rightArr[j++];
        }
        
        // Copy any remaining elements
        while (i < lSize) 
            nums[k++] = leftArr[i++];
        while (j < rSize) 
            nums[k++] = rightArr[j++];
    }

    void mergeSortArr(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSortArr(nums, left, mid);
        mergeSortArr(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

public:
    vector<int> mergeSort(vector<int>& nums) {
        mergeSortArr(nums, 0, nums.size() - 1);
        return nums;
    }
};
