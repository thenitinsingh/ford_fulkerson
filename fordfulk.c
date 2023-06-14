#include <stdio.h>
#define P 0
#define Q 1
#define R 2
#define MAX_NODE 1000
#define INF 99999
int n;
int e;
int capacity[MAX_NODE][MAX_NODE];
int flow[MAX_NODE][MAX_NODE];
int color[MAX_NODE];
int pred[MAX_NODE];

int min(int x, int y)
{
    return x < y ? x : y;
}

int top, down;
int q[MAX_NODE + 2];

void enq(int x)
{
    q[down] = x;
    down++;
    color[x] = Q;
}

int deq()
{
    int x = q[top];
    top++;
    color[x] = R;
    return x;
}

int bfs(int start, int target)
{
    int u, ver1;
    for (u = 0; u < n; u++)
    {
        color[u] = P;
    }
    top = down = 0;
    enq(start);
    pred[start] = -1;
    while (top != down)
    {
        u = deq();
        for (ver1 = 0; ver1 < n; ver1++)
        {
            if (color[ver1] == P && capacity[u][ver1] - flow[u][ver1] > 0)
            {
                enq(ver1);
                pred[ver1] = u;
            }
        }
    }
    return color[target] == R;
}
int fordFulkerson(int source, int sink)
{
    int i, j, u;
    int max_flow = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            flow[i][j] = 0;
        }
    }

    while (bfs(source, sink))
    {
        int increment = INF;
        for (u = n - 1; pred[u] >= 0; u = pred[u])
        {
            increment = min(increment, capacity[pred[u]][u] - flow[pred[u]][u]);
        }
        for (u = n - 1; pred[u] >= 0; u = pred[u])
        {
            flow[pred[u]][u] += increment;
            flow[u][pred[u]] -= increment;
        }
        max_flow += increment;
    }
    return max_flow;
}

int main()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter capacity matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &capacity[i][j]);
        }
    }
    printf("Enter source and sink node: ");
    int s, t;
    scanf("%d", &s);
    scanf("%d", &t);
    printf("Maximum flow is %d\n", fordFulkerson(s, t));
}
