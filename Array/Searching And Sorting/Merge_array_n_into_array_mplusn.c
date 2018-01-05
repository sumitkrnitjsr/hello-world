// https://www.geeksforgeeks.org/merge-one-array-of-size-n-into-another-one-of-size-mn/

// Move m elements of mPlusN[] to end.


void moveToEnd(int mPlusN[], int size)
{
    int i = 0, j = size - 1;
    for (i = size-1; i >= 0; i--)
        if (mPlusN[i] != NA)
        {
            mPlusN[j] = mPlusN[i];
            j--;
        }
}

/* Merges array N[] of size n into array mPlusN[]
 of size m+n*/
int merge(int mPlusN[], int N[], int m, int n)
{
    int i = n;  /* Current index of i/p part of mPlusN[]*/
    int j = 0; /* Current index of N[]*/
    int k = 0; /* Current index of of output mPlusN[]*/
    while (k < (m+n))
    {
        /* Take an element from mPlusN[] if
         a) value of the picked element is smaller and we have
         not reached end of it
         b) We have reached end of N[] */
        if ((i < (m+n) && mPlusN[i] <= N[j]) || (j == n))
        {
            mPlusN[k] = mPlusN[i];
            k++;
            i++;
        }
        else  // Otherwise take element from N[]
        {
            mPlusN[k] = N[j];
            k++;
            j++;
        }
    }
}
