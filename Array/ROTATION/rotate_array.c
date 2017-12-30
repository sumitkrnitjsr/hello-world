// https://leetcode.com/problems/rotate-array/solution/


#include<stdio.h>

// rotate with memory O(n)
void rotateNaive(int* nums, int numsSize, int k) {
    
    k = k%numsSize; // This is important otherwise malloc may crash for memory limit
    
    int *p = (int*)malloc(k*sizeof(int));
    int j=0;
    for(int i=numsSize-k;i<numsSize;i++) {
        p[j] = nums[i];
        j++;
    }
    
    for(int i=numsSize-k-1;i>=0;i--) {
        nums[i+k] = nums[i];
    }
    
    for(int i=0;i<k;i++) {
        nums[i] = p[i];
    }
   // free(p);
}



// rotate with O(1) space
void rotateOneByOne(int* nums, int numsSize, int k) {
    
    k = k%numsSize;
    
    int start,count;
    count = start = 0;
    for(;count<numsSize;start++) {
        int current = start;
        int carry = nums[current];
        do{
            int next = (current+k)%numsSize;
            int temp = nums[next];
            nums[next] = carry;
            carry = temp;
            current = next;
            count++;
        }while(current !=  start);
        
    }
}






//rotate with O(1) space

void rotateReversal(int* nums, int numsSize, int k) {
    
    k = k%numsSize;
    int start,end;
    start = 0;
    end = numsSize-1-k;
    
    while(start <  end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;  end--;
    }
    
    start = numsSize-k;
    end = numsSize-1;
    
    while(start <  end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;  end--;
    }
    
    start = 0;
    end = numsSize-1;
    
    while(start <  end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;  end--;
    }
    
    
    
}






















