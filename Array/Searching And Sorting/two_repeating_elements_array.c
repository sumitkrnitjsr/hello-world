// https://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/

/*
 Let the repeating numbers be X and Y, if we xor all the elements in the array and all integers from 1 to n, then the result is X xor Y.
 The 1’s in binary representation of X xor Y is corresponding to the different bits between X and Y. Suppose that the kth bit of X xor Y is 1, we can xor all the elements in the array and all integers from 1 to n, whose kth bits are 1. The result will be one of X and Y.
 */

void printRepeating(int arr[], int size)
{
    int xor = arr[0]; /* Will hold xor of all elements */
    int set_bit_no;  /* Will have only single set bit of xor */
    int i;
    int n = size - 2;
    int x = 0, y = 0;
    
    /* Get the xor of all elements in arr[] and {1, 2 .. n} */
    for(i = 1; i < size; i++)
        xor ^= arr[i];
    for(i = 1; i <= n; i++)
        xor ^= i;
    
    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor & ~(xor-1);
    
    /* Now divide elements in two sets by comparing rightmost set
     bit of xor with bit at same position in each element. */
    for(i = 0; i < size; i++)
    {
        if(arr[i] & set_bit_no)
            x = x ^ arr[i]; /*XOR of first set in arr[] */
        else
            y = y ^ arr[i]; /*XOR of second set in arr[] */
    }
    for(i = 1; i <= n; i++)
    {
        if(i & set_bit_no)
            x = x ^ i; /*XOR of first set in arr[] and {1, 2, ...n }*/
        else
            y = y ^ i; /*XOR of second set in arr[] and {1, 2, ...n } */
    }
    
    printf("n The two repeating elements are %d & %d ", x, y);
}


/*
 
 
 
 */



void printRepeating(int arr[], int size)
{
    int i;
    
    printf("n The repeating elements are");
    
    for(i = 0; i < size; i++)
    {
        if(arr[abs(arr[i])] > 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            printf(" %d ", abs(arr[i]));
    }
} 
