#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p, n, i;

    scanf("%d", &n);

    p = (int*)malloc(n * sizeof(int));

    if(p == NULL)
    {
        printf("Memory allocation failed");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Elements in the array are:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }

    free(p);

    return 0;
}
