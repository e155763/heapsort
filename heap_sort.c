/*******************************************
 *
 * This program is heap sort algorithm.
 * 
 ******************************************/

#include <stdio.h>
#include <stdlib.h>
#include "heap_sort.h"

int main(int argc, char *argv[])
{
    int num = 0;
    printf("Please enter the array size (int): ");
    scanf("%d", &num);
    int heap[num];
    int array[num];
    int sorted_array[num];

    random_array(array, 0, num);
    puts("-----start-----");
    heap_sort(heap, array, sorted_array, num);
    puts("------end------");
    for (int i = 0; i < num; i++)
    {
        if (i % 10 == 0)
        {
            printf("\n");
        }
        printf("%d ", sorted_array[i]);
    }

    return 0;
}

void heap_sort(int *heap, int *array, int *sorted_array, int num)
{
    int n = num - 1;
    int *tail = &n;
    make_heap(heap, array, num);
    for (int i = 0; i < num; i++)
    {
        sorted_array[i] = find_min(heap);
        delete_min(heap, tail);
    }
}

void random_array(int *array, int seed, int num)
{
    srand(seed);

    for (int i = 0; i < num; i++)
    {
        array[i] = rand() % (ARRAY_MAX + 1);
    }
}