
// int nums = [33,30,24,17,15,10,9]
// int target = 15
// Think reverse order: 
// It repeatedly divides the search range in half:
// Find the middle element.
// If it's the target → return index.
// If target < middle → search right half.
// Else → search left half.

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int start = 0;
            int end = nums.size() - 1;
            int mid = -1;
    
                while(start <= end){
                    mid = start + (end-start)/2;
                    if(nums[mid] == target){
                        return mid;
                    }else if(nums[mid] < target){
                        end = mid - 1;
                    }else{
                        start = mid + 1;
                    }
                }
            return -1;
        }
};