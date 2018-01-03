// https://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/

int findSmallest(int arr[], int n)
{
    int res = 1; // Initialize result
    
    // Traverse the array and increment 'res' if arr[i] is
    // smaller than or equal to 'res'.
    for (int i = 0; i < n && arr[i] <= res; i++)
        res = res + arr[i];
    
    return res;
}
