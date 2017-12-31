// Sort an array in wave form
#include <stdio.h>


//  if we make sure that all even positioned (at index 0, 2, 4, ..) elements are greater than their adjacent odd elements

void sortInWave(int arr[], int n)
{
    
    for (int i = 0; i < n; i+=2)
    {
        // If current even element is smaller than previous
        if (i>0 && arr[i-1] > arr[i] )
            swap(&arr[i], &arr[i-1]);
        
        // If current even element is smaller than next
        if (i<n-1 && arr[i] < arr[i+1] )
            swap(&arr[i], &arr[i + 1]);
    }
}
