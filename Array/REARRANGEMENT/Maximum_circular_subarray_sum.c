// https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/


// The function returns maximum circular contiguous sum
// in a[]
int maxCircularSum(int a[], int n)
{
    // Case 1: get the maximum sum using standard kadane'
    // s algorithm
    int max_kadane = kadane(a, n);
    
    // Case 2: Now find the maximum sum that includes
    // corner elements.
    int max_wrap = 0, i;
    for (i=0; i<n; i++)
    {
        max_wrap += a[i]; // Calculate array-sum
        a[i] = -a[i];  // invert the array (change sign)
    }
    
    // max sum with corner elements will be:
    // array-sum - (-max subarray sum of inverted array)
    max_wrap = max_wrap + kadane(a, n);
    
    // The maximum circular sum will be maximum of two sums
    return (max_wrap > max_kadane)? max_wrap: max_kadane;
}
