#include <stdio.h>
#include <limits.h>
#define INFINITY 9999
#define MAX 100

int G[MAX][MAX], i, j, n, u;
int c[MAX][MAX], d[MAX], trace[MAX];
int free[MAX], count, min, next;

void LoadGraph()
{
	printf("Nhap so dinh: "); scanf("%d", &n);
    printf("Nhap ma tran khoang cach:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d",&G[i][j]);
//    printf("\nNhap dinh bat dau: ");
//    scanf("%d", &u);
} 

void Init(int s)
{
	for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G[i][j] == 0) c[i][j] = INFINITY;
            else c[i][j] = G[i][j];
    for(i = 0; i < n; i++)
    {
        d[i] = c[s][i];
        trace[i] = s;
        free[i] = 0;
    }
}

void Dijkstra(int G[MAX][MAX], int n, int s)
{
    d[s] = 0;
    free[s] = 1;
    count = 1;
    while (count < n-1)
    {
        min = INFINITY;
        for (i = 0; i < n; i++)
            if ((d[i] < min) && (!free[i]))
            {
                min = d[i];
                next = i;
            }
            free[next] = 1;
            for (i = 0; i < n; i++)
                if (!free[i])
                    if (min + c[next][i] < d[i])
                    {
                        d[i] = min + c[next][i];
                        trace[i] = next;
                    }
        count++;
    }
}

void PrintResult(int s)
{
	for (i = 0; i < n; i++)
        if (i != s)
        {
            printf("\nKhoang cach den dinh %d = %d", i, d[i]);
            printf("\nDuong di: %d",i);
            j = i;
            do
            {
                j = trace[j];
                printf(" <- %d", j);
            }
			while (j != s);
    }
}

int main()
{
	LoadGraph();
	for (u = 0; u < n; u++)
	{
		printf("\nKhoang cach tu dinh %d den cac dinh con lai:\n", u);
		Init(u);
	    Dijkstra(G, n, u);
	    PrintResult(u);
	    printf("\n");
	}
}
