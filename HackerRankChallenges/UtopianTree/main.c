#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int t,n;
    scanf("%d",&t);
    int height;
    for(int i = 0; i<t; i++)
    {
        height=1;
        scanf("%d",&n);    
        for(int j=0; j<n; j++)
        {
            if (j%2 == 0)
            {
                height*=2;  
            } else
            {
                height++;    
            }
        }
        printf("%d\n",height);
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}