
// brurhforce-code 
class Solution {
    public long maximumTripletValue(int[] nums) {
     long result = 0;
        int n = nums.length;
        for (int i=0;i<n-2;i++){
            for (int j=i+1;j<n-1;j++){
                for (int k=j+1;k<n;k++){
                    if (i<j && j<k){
                        result = Math.max(((long)nums[i]-(long)nums[j])*nums[k], result);
                    }
                }
            }
        }
        return result;
    }
}