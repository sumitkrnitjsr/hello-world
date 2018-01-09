// https://www.geeksforgeeks.org/find-four-numbers-with-sum-equal-to-given-sum/

void find4Numbers(int A[], int n, int X)
{
    int l, r;
    
    // Sort the array in increasing order, using library
    // function for quick sort
    qsort (A, n, sizeof(A[0]), compare);
    
    /* Now fix the first 2 elements one by one and find
     the other two elements */
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i+1; j < n - 2; j++)
        {
            // Initialize two variables as indexes of the first and last
            // elements in the remaining elements
            l = j + 1;
            r = n-1;
            
            // To find the remaining two elements, move the index
            // variables (l & r) toward each other.
            while (l < r)
            {
                if( A[i] + A[j] + A[l] + A[r] == X)
                {
                    printf("%d, %d, %d, %d", A[i], A[j],
                           A[l], A[r]);
                    l++; r--;
                }
                else if (A[i] + A[j] + A[l] + A[r] < X)
                    l++;
                else // A[i] + A[j] + A[l] + A[r] > X
                    r--;
            } // end of while
        } // end of inner for loop
    } // end of outer for loop
}

// https://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/

void findFourElements (int arr[], int n, int X)
{
    int i, j;
    
    // Create an auxiliary array to store all pair sums
    int size = (n*(n-1))/2;
    struct pairSum aux[size];
    
    /* Generate all possible pairs from A[] and store sums
     of all possible pairs in aux[] */
    int k = 0;
    for (i = 0; i < n-1; i++)
    {
        for (j = i+1; j < n; j++)
        {
            aux[k].sum = arr[i] + arr[j];
            aux[k].first = i;
            aux[k].sec = j;
            k++;
        }
    }
    
    // Sort the aux[] array using library function for sorting
    qsort (aux, size, sizeof(aux[0]), compare);
    
    // Now start two index variables from two corners of array
    // and move them toward each other.
    i = 0;
    j = size-1;
    while (i < size && j >=0 )
    {
        if ((aux[i].sum + aux[j].sum == X) && noCommon(aux[i], aux[j]))
        {
            printf ("%d, %d, %d, %d\n", arr[aux[i].first], arr[aux[i].sec],
                    arr[aux[j].first], arr[aux[j].sec]);
            return;
        }
        else if (aux[i].sum + aux[j].sum < X)
            i++;
        else
            j--;
    }
}
