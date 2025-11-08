#include <stdio.h>
#include <stdlib.h>

// (*a).total_size = tSize;
// (*a).used_size = uSize;

// // int *ptr = (int *)malloc(tSize * sizeof(int));
// (*a).ptr = (int *)malloc(tSize * sizeof(int));
struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{

    // Short-cut
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}
void set(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter Element: ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main()
{
    struct myArray marks;
    createArray(&marks, 100, 20);
    set(&marks);
    show(&marks);
}