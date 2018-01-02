// https://www.geeksforgeeks.org/find-a-sorted-subsequence-of-size-3-in-linear-time/

#include <stdio.h>


void find3Numbers(int arr[], int n)
{
    int max = n-1; //Index of maximum element from right side
    int min = 0; //Index of minimum element from left side
    int i;
    
    // Create an array that will store index of a smaller
    // element on left side. If there is no smaller element
    // on left side, then smaller[i] will be -1.
    int *smaller = new int[n];
    smaller[0] = -1;  // first entry will always be -1
    for (i = 1; i < n; i++)
    {
        if (arr[i] <= arr[min])
        {
            min = i;
            smaller[i] = -1;
        }
        else
            smaller[i] = min;
    }
    
    // Create another array that will store index of a
    // greater element on right side. If there is no greater
    // element on right side, then greater[i] will be -1.
    int *greater = new int[n];
    greater[n-1] = -1;  // last entry will always be -1
    for (i = n-2; i >= 0; i--)
    {
        if (arr[i] >= arr[max])
        {
            max = i;
            greater[i] = -1;
        }
        else
            greater[i] = max;
    }
    
    // Now find a number which has both a greater number on
    // right side and smaller number on left side
    for (i = 0; i < n; i++)
    {
        if (smaller[i] != -1 && greater[i] != -1)
        {
            printf("%d %d %d", arr[smaller[i]],
                   arr[i], arr[greater[i]]);
            return;
        }
    }
    
    // If we reach number, then there are no such 3 numbers
    printf("No such triplet found");
    
    // Free the dynamically alloced memory to avoid memory leak
    delete [] smaller;
    delete [] greater;
    
    return;
}
