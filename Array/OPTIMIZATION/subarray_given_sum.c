// https://www.geeksforgeeks.org/find-subarray-with-given-sum/

// Non negative integers create huge difference from O(n3) to O(n2)
// Below is for positive only


int subArraySum(int arr[], int n, int sum)
{
    /* Initialize curr_sum as value of first element
     and starting point as 0 */
    int curr_sum = arr[0], start = 0, i;
    
    /* Add elements one by one to curr_sum and if the curr_sum exceeds the
     sum, then remove starting element */
    for (i = 1; i <= n; i++)
    {
        // If curr_sum exceeds the sum, then remove the starting elements
        while (curr_sum > sum && start < i-1)
        {
            curr_sum = curr_sum - arr[start];
            start++;
        }
        
        // If curr_sum becomes equal to sum, then return true
        if (curr_sum == sum)
        {
            printf ("Sum found between indexes %d and %d", start, i-1);
            return 1;
        }
        
        // Add this element to curr_sum
        if (i < n)
            curr_sum = curr_sum + arr[i];
    }
    
    // If we reach here, then no subarray
    printf("No subarray found");
    return 0;
}
