#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000
#define MAX_VAL 1000000001

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int candies[MAX];

/** The code to read from STDIN and output to STDOUT has been provided by us, for convenience. You may or may not use this. **/
 
int main() {
    
    int N,K,z,max,min,unfairness=MAX_VAL,new_unfairness;
    int i;
    
    scanf("%d %d",&N,&K);
    for(i = 0;i < N;i++)
        scanf("%d",candies + i);
  
    //sort an array
    qsort(candies, N, sizeof(int), cmpfunc);
    
    //int unfairness = candies[K-1] - candies[0];
      for(i=0;i<N-K;i++) {
		z=K+i-1;	// Z decides the size of new subarray
		if(z>(N-1)){ break;}
		min=candies[i];	// The minimum value of subarray is the first element
		max=candies[z];  // The maximum value of subarray is the last element
		new_unfairness = max-min; //Calculate the unfairness value
		if(new_unfairness<unfairness){ //Compare unfaireness value with previous one and see if it is less than old one
			//Update unfairness
			unfairness=new_unfairness; //If found less, then update old value with the new one.
		}
	}
    printf("%d",unfairness);
    return 0;
}