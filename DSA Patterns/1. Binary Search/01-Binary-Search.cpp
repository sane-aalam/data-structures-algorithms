
// 📌 Doing is new thinking
// 📌 Binary Search – Summary
// Binary Search is an efficient algorithm used to find the position of a target element in a sorted array.

// Time Complexity: O(log n)
// Space Complexity: O(1) (iterative) or O(log n) (recursive)

// It repeatedly divides the search range in half:
// Find the middle element.
// If it's the target → return index.
// If target < middle → search left half.
// Else → search right half.

// Real-Life Example:
// Looking up a word in a dictionary 
// Let’s say you want to find the word “Binary” in an English dictionary:
// You don’t start from page 1, right?
// You open somewhere in the middle → let’s say the page starts with “Mathematics.”
// “Binary” comes before “Mathematics,” so you go left (earlier pages).
// Keep repeating this until you find the exact page.
// That’s binary search in action: cut the search space in half every time 

// How to identify the pattern of Binary Search
// You have to think
// 1. Sorted array
// 2. Sorted in Rotated Sorted Array
// 3. Search Space (Allocation)
// 5. Sorted and Rotated Order

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
                        start = mid + 1;
                    }else{
                        end = mid - 1;
                    }
                }
            return -1;
        }
    };