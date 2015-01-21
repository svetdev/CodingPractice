#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t,n;
    scanf("%d",&t);
    char string[100000];
    char *s;
    int length,count;
    for(int i = 0; i<t; i++)
    {
        scanf("%s", string);    
        s = string;
        length = strlen(string);
        count = 0;
        for(int i=0; i<length-1; i++){
            while(string[i] == string[i+1]){
              count++; 
              i++;
              if (i>= length-1){
                  break;
              }
            }
        }
          
        printf("%d\n",count);
    }  
    return 0;
}
