// https://www.geeksforgeeks.org/find-maximum-value-of-sum-iarri-with-only-rotations-on-given-array-allowed/


#include <stdio.h>


//Find maximum value of Sum( i*arr[i]) with only rotations on given array allowed

int maxSum(int arr[], int n)
{
    // Find array sum and i*arr[i] with no rotation
    int arrSum = 0;  // Stores sum of arr[i]
    int currVal = 0;  // Stores sum of i*arr[i]
    for (int i=0; i<n; i++)
    {
        arrSum = arrSum + arr[i];
        currVal = currVal+(i*arr[i]);
    }

    int maxVal = currVal;
    
    // Try all rotations one by one and find
    // the maximum rotation sum.
    for (int j=1; j<n; j++)
    {
        currVal = currVal + arrSum-n*arr[n-j];
        if (currVal > maxVal)
            maxVal = currVal;
    }
   
    return maxVal;
}
