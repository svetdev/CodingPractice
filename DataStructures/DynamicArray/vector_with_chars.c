#include <stdio.h>
#include <stdlib.h>

#define VECTOR_INITIAL_CAPACITY 100

typedef struct {
    int size; //slots used so far
    int capacity; //total available slots
    char *data; // array of chars we're storing
} Vector;

void vector_append(Vector *vector, char value);

void vector_init(Vector *vector){
//Initialize size and capacity
    vector->size = 0;
    vector->capacity = VECTOR_INITIAL_CAPACITY;

    //allocate memore for vector->data
    vector->data = malloc(sizeof(char) * vector->capacity);
}

void vector_init_from_string(Vector *vector, char* string){
    vector_init(vector);

    for (int i=0; i< strlen(string); i++){
        vector_append(vector, string[i]);
    }
}

void vector_double_capacity_if_full(Vector *vector){
    if(vector->size >= vector->capacity){
        vector->capacity *= 2;
        vector->data = realloc(vector->data, sizeof(char) * vector->capacity);
    }
}

void vector_append(Vector *vector, char value){
    //double capacity if full
    if(vector->size >= vector->capacity){
        vector_double_capacity_if_full(vector);
    }
    vector->data[vector->size++] = value;

}

char vector_get(Vector *vector, int index){
    if(index >= vector->size || index<0){
        printf("Index %d is out of bounds for Vector",index);
        exit(1);
    }
    return vector->data[index];
}

void vector_set(Vector *vector, int index, char value){
    //fill the array with the value index elements
    while(index >= vector->size){
        vector_append(vector, ' ');
    }
    vector->data[index] = value;
  //  vector->size++;
}

void vector_print(Vector *vector){
        for (int i=0; i<vector->size; i++){
                printf("%c", vector->data[i]);
        }
    printf("\n");
}

void vector_free(Vector *vector){
    free(vector->data);
}

//sorting string
void vector_sort(Vector *vector){
    for (int i=0; i<vector->size; i++){
        for (int j=i+1; j<vector->size; j++){
            if (vector->data[i] > vector->data[j]){
                char p = vector->data[i];
                vector->data[i] = vector->data[j];
                vector->data[j] = p;
            }
        }
    }
}

int main()
{
    Vector vector;
   // vector_init(&vector);
     vector_init_from_string(&vector, "Test string");
    //  for (int i = 0; i< 1000; i++){
    //    vector_set(&vector, i, 'Q');
    //}
    vector_sort(&vector);
    vector_print(&vector);
    printf("Vector capacity %d and size %d\n",vector.capacity, vector.size);

    vector_free(&vector);
    return 0;
}
