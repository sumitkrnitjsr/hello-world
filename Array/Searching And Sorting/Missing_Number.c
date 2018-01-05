// https://www.geeksforgeeks.org/find-the-missing-number/

/*
 1) XOR all the array elements, let the result of XOR be X1.
 2) XOR all numbers from 1 to n, let XOR be X2.
 3) XOR of X1 and X2 gives the missing number.
 */

int getMissingNo(int a[], int n)
{
    int i;
    int x1 = a[0]; /* For xor of all the elements in array */
    int x2 = 1; /* For xor of all the elements from 1 to n+1 */
    
    for (i = 1; i< n; i++)
        x1 = x1^a[i];
    
    for ( i = 2; i <= n+1; i++)
        x2 = x2^i;
    
    return (x1^x2);
}
