
// Think About - 24 year support 
// Algorithm of Binary Search
// STEP-1 Simple binary search we got the element(target equal), we will directly return element(index) which equal to target
// STEP-2 we have to find the starting and ending position of a given target value.
// STEP-3 we have to continue search left side of array - "This is last position of target element or not"
// STEP-4 we have to continue search right side of array, to make sure "This is last position of target element or not"
// We have to write two Different method to serach [left position,right position] of array
// Time complexity - 0(logN)
// space complexity - 0(1)


/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

const findFirstPosition = (nums,target) => {
    var start = 0;
    var end = nums.length - 1;
    var mid = Math.floor(start+(end-start)/2);

    var firstIndex = -1;
    while(start <= end){
        if(nums[mid] == target){
            firstIndex = mid;
            end = mid - 1;
        }else if(nums[mid] < target){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = Math.floor(start+(end-start)/2);
    }
    return firstIndex;
}

const findSecondPosition = (nums,target) =>{
    var start = 0;
    var end = nums.length - 1;
    var mid = Math.floor(start+(end-start)/2);

    var secondIndex = -1;
    while(start <= end){
        if(nums[mid] == target){
            secondIndex = mid;
            start = mid + 1;
        }else if(nums[mid] < target){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = Math.floor(start+(end-start)/2);
    }
    return secondIndex;
}

var searchRange = function(nums, target) {
    let firstPosition = findFirstPosition(nums,target);
    let secondPosition = findSecondPosition(nums,target);
    return [firstPosition,secondPosition];
};