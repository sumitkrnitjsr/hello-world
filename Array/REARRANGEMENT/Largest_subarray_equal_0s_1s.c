// https://leetcode.com/problems/contiguous-array/description/


int findMaxLength(int* nums, int numsSize) {
    int *p = (int*)malloc(2*numsSize*sizeof(int) + 1);
    int i;
    for(i=0;i<= 2*numsSize;i++) {
        p[i] = -2; // To distinguish starting index from other indices
    }
    p[numsSize] = -1; // Since whenever cout is 0, we met same n1==n0, same at i=0
    int count = 0;
    int maxSize = 0;
    for(i=0;i<numsSize;i++) {
        if(nums[i] == 0 ) {
            count--;
        }else{
            count++;
        }
        if(p[count+numsSize] < -1) {
            p[count+numsSize] = i;
        }else {
            // i - p[count+numsSize]  and not (i - p[count+numsSize] + 1) 
            maxSize = (maxSize > (i - p[count+numsSize] ))?maxSize:(i - p[count+numsSize] );
        }
    }
    
    return maxSize;
}
