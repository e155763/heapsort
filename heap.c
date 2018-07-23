/*******************************************
 *
 * This program creates a heap.
 * 
 ******************************************/

#include "heap.h"

void make_heap(int *heap, int *array, int num)
{
    for (int i = 0; i < num; i++)
    {
        insert_value(heap, array[i], i);
        shift_up(heap, i);
    }
}

void insert_value(int *heap, int value, int node)
{
    heap[node] = value;
}

void swap_value(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void delete_min(int *heap, int *tail)
{
    heap[0] = heap[*tail];
    *tail -= 1;
    shift_down(heap, 0, tail);
}

int find_min(int *heap)
{
    return heap[0];
}

void shift_down(int *heap, int node, int *tail)
{
    int temp = INF;
    if (get_right(node) <= *tail)
    {
        temp = heap[get_right(node)];
    }

    if (get_left(node) <= *tail)
    {
        if (heap[get_left(node)] < heap[node] && heap[get_left(node)] < temp)
        {
            swap_value(&heap[node], &heap[get_left(node)]);
            shift_down(heap, get_left(node), tail);
        }
        else if (temp < heap[node])
        {
            swap_value(&heap[node], &heap[get_right(node)]);
            shift_down(heap, get_right(node), tail);
        }
    }
}

void shift_up(int *heap, int node)
{

    if (node > 0 && heap[node] < heap[get_parent(node)])
    {
        swap_value(&heap[node], &heap[get_parent(node)]);
        node = get_parent(node);
        shift_up(heap, node);
    }
}

int get_parent(int node)
{
    return (node - 1) / 2;
}

int get_left(int node)
{
    return 2 * node + 1;
}

int get_right(int node)
{
    return 2 * node + 2;
}