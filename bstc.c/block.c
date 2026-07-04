#include<stdio.h>

int main()
{
    int a[10][10], visited[10]={0};
    int q[10], front=0, rear=0;
    int n, i, j, v;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    scanf("%d",&v);

    visited[v]=1;
    q[rear++]=v;

    while(front<rear)
    {
        v=q[front++];
        printf("%d ",v);

        for(i=0;i<n;i++)
            if(a[v][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                q[rear++]=i;
            }
    }
}