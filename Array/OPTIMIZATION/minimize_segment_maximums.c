// https://www.geeksforgeeks.org/divide-array-k-segments-maximize-maximum-segment-minimums/

/*
 You are given an array A. You need to divide this array into exactly K non-empty segments and check whether the minimum element S amongst the maximum elements amongst all segments is less than Q or not.
 */

public static void main(String args[] ) throws Exception {
    Scanner s = new Scanner(System.in);
    int name = s.nextInt();
    while(name > 0) {
        int numSize = s.nextInt();
        int seg = s.nextInt();
        int min = s.nextInt();
        int i;
        int arr[] = new int[numSize];
        for(i=1;i<= numSize;i++) {
            int number;
            number = s.nextInt();
            arr[i-1] = number;
        }
        
        
        int tempmin = -1 ;
        if (seg == 1) {
            tempmin = -1;
            for(i=0;i<numSize;i++) {
                tempmin = arr[i]>tempmin?arr[i]:tempmin;
            }
        }
        
        if (seg == 2) {
            int max1,max2;
            max1 = arr[0];
            max2 = arr[numSize-1];
            tempmin = max1<max2?max1:max2;
        }
        
        if(seg >= 3) {
            tempmin = 1000000001;
            for(i=0;i<numSize;i++) {
                tempmin = arr[i]<tempmin?arr[i]:tempmin;
            }
        }
        
        
        if(min <=  tempmin) {
            System.out.println("NO");
        }else{
            System.out.println(Integer.toString(tempmin));
        }
        name--;
        
    }
}

