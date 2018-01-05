/* https://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/
*/

bool hasArrayTwoCandidates(int A[], int arr_size, int sum)
{
    int l, r;
    
    /* Sort the elements */
    quickSort(A, 0, arr_size-1);
    
    /* Now look for the two candidates in the sorted
     array*/
    l = 0;
    r = arr_size-1;
    while (l < r)
    {
        if(A[l] + A[r] == sum)
            return 1;
        else if(A[l] + A[r] < sum)
            l++;
        else // A[i] + A[j] > sum
            r--;
    }
    return 0;
}
