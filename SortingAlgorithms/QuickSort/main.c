#include <stdio.h>
#include <stdlib.h> //qsort function is here

//declare a size
#define SIZE 10

int findPartition(*numbers, int lo, int hi)
{

    int pivotIndex = (int)(lo + hi)/2;

    int pivotValue = numbers[pivotIndex];
    //put the chosen pivot at numbers[hi]
    int temp = numbers[pivotIndex];
    numbers[pivotIndex] = numbers[hi];
    numbers[hi] = temp;

    int storeIndex = lo;
    //Compare remaining array elements againts pivotValue = numbers[hi]
    for(int i=lo; i<= hi-1; i++)
    {
        if(numbers[i]<pivotValue)
        {
             temp = numbers[i];
            numbers[i] = numbers[storeIndex];
            numbers[storeIndex] = temp;
            storeIndex++;
        }
    }

     temp = numbers[storeIndex];
    numbers[storeIndex] = numbers[hi];
    numbers[hi] = temp; //Move Pivot to its final place

    return storeIndex;
}
void quickSort(*numbers, int lo,int hi)
{
    if (lo < hi)
    {
        int p = findPartition(numbers, lo, hi);
        quickSort(numbers, lo, p-1);
        quickSort(numbers, p+1, hi);

    }
}

int main()
{

    int numbers[SIZE];
    int x;

    //populate the array
    srand((unsigned)time(NULL));
    for(x = 0; x< SIZE; x++)
    {
        numbers[x] = rand() % 100 + 1;
    }

    //Display unsorted array
    for(x = 0; x< SIZE; x++)
    {
        printf("%3d ", numbers[x] );
    }
    putchar('\n');

    //sort the array with quick sort from the library
    // qsort(numbers, SIZE, sizeof(int), compare);
    quickSort(numbers,0,SIZE-1);

     //Display sorted array
    for(x = 0; x< SIZE; x++)
    {
        printf("%3d ", numbers[x] );
    }
    putchar('\n');

    return 0;
}
