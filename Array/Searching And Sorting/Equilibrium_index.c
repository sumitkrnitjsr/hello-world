// https://www.geeksforgeeks.org/equilibrium-index-of-an-array/

int equilibrium(int arr[], int n)
{
    int sum = 0;      // initialize sum of whole array
    int leftsum = 0; // initialize leftsum
    int i;
    
    /* Find sum of the whole array */
    for (i = 0; i < n; ++i)
        sum += arr[i];
    
    for( i = 0; i < n; ++i)
    {
        sum -= arr[i]; // sum is now right sum for index i
        
        if(leftsum == sum)
            return i;
        
        leftsum += arr[i];
    }
    
    /* If no equilibrium index found, then return 0 */
    return -1;
}
