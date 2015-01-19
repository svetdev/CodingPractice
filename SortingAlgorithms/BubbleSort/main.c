#include <stdio.h>
#include <stdlib.h>

//declare a size
#define SIZE 10

void bubbleSort(*numbers)
{
     int outer, inner, temp;
     for(outer = 0; outer< SIZE; outer++)
    {
        for(int inner = outer+1;inner < SIZE; inner++)
        {
            if (numbers[outer] > numbers[inner])
            {
                temp = numbers[outer];
                numbers[outer] = numbers[inner];
                numbers[inner] = temp;
            }
        }
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

    //sort the array
    bubbleSort(numbers);

     //Display sorted array
    for(x = 0; x< SIZE; x++)
    {
        printf("%3d ", numbers[x] );
    }
    putchar('\n');

    printf("Hello world!\n");
    return 0;
}
