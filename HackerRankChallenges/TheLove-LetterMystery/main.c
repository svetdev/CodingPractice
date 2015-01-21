#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t,n;
    scanf("%d",&t);
    char string[10000];
    char *s;
    int length,count;
    for(int i = 0; i<t; i++)
    {
        scanf("%s", string);    
        s = string;
        length = strlen(string);
        count = 0;
        for(int i=0; i<(int)floor(length/2); i++){
           
           if(string[i] != string[length-i-1]){
               count += abs(string[i] - string[length-i-1]);
           }
        }
          
        printf("%d\n",count);
    }  
    
    return 0;
}