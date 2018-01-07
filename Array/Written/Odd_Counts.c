/*
 You are given a binary string (containing only 0s and 1s) which contains 0's or 1's. Find the total number of sub-strings which has odd decimal representation of its bits.
 
 Consider binary representation from left to right, means decimal value of 1101 is 11.
 
 Here sub-string means continuous stream of character's from string.

 */

#include<stdio.h>
int main() {
    char s[1000001];
    scanf("%s",s);
    int i;
    long long count = 0;
    int len = 0;
    
    while(s[len] != '\0') len++;
    
    for(i=0;i<len;i++) {
        if(s[i] == '1') {
            count += (len-i);
        }
        
    }
    printf("%lld",count);
    return 0;
}
