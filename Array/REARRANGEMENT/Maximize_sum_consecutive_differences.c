//
//  Maximize_sum_consecutive_differences.c
//  Interview Prep
//
//  Created by SUMIT TIWARY on 31/12/17.
//  Copyright © 2017 SUMIT TIWARY. All rights reserved.
//

#include <stdio.h>

int maxSum(int arr[], int n)
{
    int sum = 0;
    
    // Sorting the array.
    sort(arr, arr + n);
    
    // Subtracting a1, a2, a3,....., a(n/2)-1, an/2
    // twice and adding a(n/2)+1, a(n/2)+2, a(n/2)+3,.
    // ...., an - 1, an twice.
    
    
    for (int i = 0; i < n/2; i++)
    {
        sum -= (2 * arr[i]);
        sum += (2 * arr[n - i - 1]);
    }
    
    return sum;
}
