#define INF 99999999

void make_heap(int *heap, int *array, int num);
void insert_value(int *heap, int value, int node);
void shift_up(int *heap, int node);
void shift_down(int *heap, int node, int *tail);
int find_min(int *heap);
void delete_min(int *heap, int *tail);
void swap_value(int *a, int *b);
int get_parent(int node);
int get_left(int node);
int get_right(int node);