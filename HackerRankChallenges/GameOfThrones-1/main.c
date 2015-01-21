
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
void findPalind(char *arr)
{
    char *s;
    s = arr;
    int flag = 0;
  int n[ 256 ]; /* n is an array of 256 integers */
   int i,j;
 
   /* initialize elements of array n to 0 */         
   for ( i = 0; i < 256; i++ )
   {
      n[ i ] = 0;
   }
   
    int length = strlen(s);
    for ( i=0;i<length;i++){
        int temp = (int)s[i];
        n[temp]++;
        //printf("%d",temp);
    }
    
     for (j = 0; j < 256; j++ )
   {
      if(n[j] % 2 != 0){
          flag++;
      }
   }
 
 
    
    if (flag<2)
        printf("YES\n");
    else
        printf("NO\n");
    
    return;
}
int main() {

    char arr[100001];
    scanf("%s",arr);
    findPalind(arr);
    return 0;
}