#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d",&n);
    scanf("%d",&m);
    char s[500][500];
    int maxPair = 0;
    int numberOfPairs = 0;
    
    for(int i=0;i<n;i++){
        scanf("%s", s[i]);
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int currentPair = 0;
            //inside the string
            for(int k=0;k<m;k++){
                if (s[i][k] == '1' || s[j][k] == '1'){
                 //   printf("comparing word in line %d with line %d at position %d\n",i,j,k);
                    currentPair++;
                }
            }
            if (currentPair > maxPair){
                maxPair = currentPair;
                numberOfPairs = 1;
            } else
                if(currentPair == maxPair){
                numberOfPairs++;
            }
        }     
    }
    printf("%d\n", maxPair);
    printf("%d\n", numberOfPairs);
    

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
