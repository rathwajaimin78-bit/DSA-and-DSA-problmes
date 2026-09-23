//  linear queue - arrangment of data follows FIFO
/*
    1. Insertion( enqueue ): -
    2. Deletion( dequeue ):  -

    4. Condition for  queue empty: frontInd = backInd.
    5. Condition for  queue full: backInd = size-1.

    updated to circular queue
    circular queue - index become circular increment ( ex- i = i%4 give 0 , 1 , 2, 3, 0 ,1 ,2 ... )

    advntage -  can ues all speac (not possible in linear queue)
    */

#include <stdio.h>
#include <stdlib.h>
typedef struct circular_queue // like a storage
{
    int size;

    int *array; // dynimacliy memory first point address
    int frontind;
    int backind;
} circular_queue;

void empty_or_not(circular_queue *point)
{

    if ((point->frontind) % point->size == (point->backind) % point->size)
    {
        printf("circular queue is empty ! \n");
    }
    else
    {
        printf("circular queue is not empty ! \n");
    }
}

void full_or_not(circular_queue *point)
{

    if ((point->backind + 1) % point->size == (point->size - 1) % point->size)
    {
        printf("circular queue is full ! \n");
    }
    else
    {
        printf("circular queue is not full ! \n");
    }
}

void print_queue(circular_queue *storage)
{

    for (int i = storage->frontind + 1; i <= storage->backind; i++)
    {
        printf("index %d : %d \n", i, storage->array[i]);
    }
    printf(" \n");
}
int enqueue(int value, circular_queue *name)
{

    if ((name->backind + 1) % name->size == (name->size - 1) % name->size)
    {
        full_or_not(name);
        printf("circular queue overflow ! \n");
        return 0;
    }
    else
    {
        name->backind = (name->backind + 1) % name->size; // incresing index Circularly
        (name->array[name->backind]) = value;
        printf("successfully %d enqueued \n", value);
    }
}
int denqueue(circular_queue *name)
{ // not completed , update completed !

    if ((name->frontind + 1) % name->size == (name->backind + 1) % name->size) // checking circular_queue
    {
        empty_or_not(name);

        return 0;
    }
    else
    {
        int delting_value = name->array[name->frontind + 1];
        printf("successfully denqueue %d  \n", name->array[name->frontind + 1]);
        return name->frontind = (name->frontind + 1) % name->size; // decresing index
    }
}

int main()
{
    circular_queue *storage = (circular_queue *)malloc(sizeof(circular_queue));
    storage->size = 6;
    storage->array = (int *)malloc(storage->size * sizeof(int));
    // -1 show no elemnt remning(nothing any elment) after 0th elemnt
    storage->frontind = storage->backind = 0; // number%size never give negitve value !

    enqueue(2, storage);
    enqueue(3, storage);
    enqueue(4, storage);
    enqueue(5, storage);
    enqueue(6, storage);
    enqueue(7, storage);

    denqueue(storage);
    denqueue(storage);
    denqueue(storage);
    denqueue(storage);
    denqueue(storage);

    denqueue(storage);
    print_queue(storage);
    free(storage->array);
    free(storage);
    return 0;
}