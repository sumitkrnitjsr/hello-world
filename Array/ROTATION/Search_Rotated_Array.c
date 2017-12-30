// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#include <stdio.h>

// You may assume no duplicate exists in the array. it's important

int search(int* nums, int numsSize, int target) {
    
    int low,high;
    
    low = 0;
    high = numsSize - 1;
    int pos = -1;
    
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(mid + 1 <= numsSize-1 && nums[mid] > nums[mid + 1]) {
            pos = mid;
            break;
        }else if(nums[mid] >= nums[low] ) { // Equals sign is important
            low = mid+1;
        }else {
            high = mid-1;
        }
        
    }
    
    low = 0;
    high = numsSize - 1;
    
    if(pos != -1) {
        pos = (pos + 1)%numsSize;
        
        if(target >= nums[low] && target <= nums[pos-1]) {
            high = pos - 1;
        }else{
            low = pos;
        }
        
    }
    
    
    while(low <= high) {
        int mid = low + (high - low)/2;
        
        if(nums[mid] == target) return mid;
        if(nums[mid] < target) {
            low = mid + 1;
        }else {
            high = mid-1;
        }
        
    }
    
    return -1;
}









// <= "=" signs are important
int searchSingleLoop(int* nums, int numsSize, int target) {
    
    int low,high;
    low = 0;
    high = numsSize - 1;
    
    while(low <= high) {
        
        int mid = low + (high - low)/2;
        
        if(nums[mid] ==  target) return mid;
        
        if(nums[low] <= nums[mid]) {
            
            if(nums[low] <= target && nums[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
            
        }else {
            
            if(nums[mid] <target && nums[high] >= target) {
                low = mid + 1;
            }else {
                high = mid-1;
            }
            
        }
        
    }
    
    return -1;
}
