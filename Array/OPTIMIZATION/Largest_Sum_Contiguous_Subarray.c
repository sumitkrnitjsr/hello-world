// https://leetcode.com/problems/maximum-subarray/description/


int maxSubArray(int* nums, int numsSize) {
    
    int max_here, global_max;
    max_here = 0;
    global_max = INT_MIN;
    int i;
    for(i=0;i<numsSize;i++) {
        global_max = ((max_here + nums[i]) > global_max)?max_here+nums[i]:global_max;
        max_here = ((max_here + nums[i]) > 0)?max_here+nums[i]:0;
    }
    return global_max;
}
