#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int maxXor(int l, int r) {
    int maxSum = 0;
    int temp;
    for (int i=l; i<r; i++){
        for (int j=i+1;j<=r;j++){
            temp = i^j;
            if (maxSum<temp){
                maxSum = temp;
            }
        }
    }
    
return maxSum;
}
int main() {
    int res;
    int _l;
    scanf("%d", &_l);
    
    int _r;
    scanf("%d", &_r);
    
    res = maxXor(_l, _r);
    printf("%d", res);
    
    return 0;
}
