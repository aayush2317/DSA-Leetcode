class Solution {
public:
    int partition(vector<int>& nums,int low,int high)
    {
        int pivot = nums[high];
    int i = low;

    for(int j = low; j < high; j++)
    {
        if(nums[j] < pivot)
        {
            swap(nums[i], nums[j]);
            i++;
        }
    }

    swap(nums[i], nums[high]);

    return i;
}
    int quickSelect(vector<int>& nums, int low, int high, int target)
    {
        int pivotIndex=partition(nums,low,high);
        if (pivotIndex == target)
        {
            return nums[target];
        }
        else if (pivotIndex < target) {
            return quickSelect(nums, pivotIndex + 1, high, target);
        }
        else {
            return quickSelect(nums, low, pivotIndex - 1, target);
        }

    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int target=n-k;
        return quickSelect(nums,0,n-1,target);
    }
};