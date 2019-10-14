/*Rabin-Karp Pattern Matching*/
#include <stdio.h>
#include <string.h>
#include <math.h>
void rabinKarp(char text[],char pat[],int q);

int main(void){
    char text[100],pat[100];
    printf("Enter text : ");
    scanf(" %s",text);
    printf("Enter pattern : ");
    scanf(" %s",pat);

    rabinKarp(text,pat,13);

    return 0;
}
void rabinKarp(char text[],char pat[],int q)
{
    //Consider n = length of text and m = length of Pattern
    int m = strlen(pat);
    int n = strlen(text);
    //We assume d=52 (lowercase and uppercase letters only)
    // q is prime number
    int d = 256;
    int h = ((int)pow(d,m-1)) % q; //h is highest order digit for an m digit window
    int p = 0; // Initialise hash value for Pattern
    int t = 0; // Initialise hash value for first m digit window in text

    //Now calculate p and t[0] in O(m) time
    int i,j;
    for (i = 0; i < m; i++) {
        p = (d*p + pat[i]) % q;
        t = (d*t + text[i]) % q;
    }

    //Now this loop will match hash values in O(n-m+1) time
    for(i=0;i<=n-m;i++){
        if(p==t){
            //We have to do character by character matching if hash values matching
            for(j=0;j<m;j++){
                if(pat[j]==text[i+j])
                    continue;
                else
                    break;
            }
            if(j==m)
                printf("Pattern found at index %d\n",i);
        }
        //Now calculate new hash
        if(i<n-m){
            t = ( (d*(t-text[i]*h)) + text[i+m] ) % q;
            if(t<0) t = t+q;
        }
    }
}
