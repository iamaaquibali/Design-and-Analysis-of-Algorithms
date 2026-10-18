#include <stdio.h>

#define INF 1000000000

struct Edge
{
    int u;
    int v;
    int w;
};

void printPath(int parent[], int src, int vertex)
{
    int path[1001];
    int count = 0;
    int current = vertex;
    int i;

    while (current != -1)
    {
        path[count++] = current;

        if (current == src)
            break;

        current = parent[current];
    }

    for (i = count - 1; i >= 0; i--)
    {
        printf("%d", path[i]);

        if (i != 0)
            printf("->");
    }
}

int main()
{
    int V, E;
    int i, j;
    int src;
    int dist[1001];
    int parent[1001];
    struct Edge edges[10000];
    int negativeCycle = 0;

    scanf("%d", &V);
    scanf("%d", &E);

    for (i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);
    }

    scanf("%d", &src);

    /* Initialize distances and parents */
    for (i = 1; i <= V; i++)
    {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[src] = 0;

    /* Bellman-Ford relaxation */
    for (i = 1; i <= V - 1; i++)
    {
        int updated = 0;

        for (j = 0; j < E; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                updated = 1;
            }
        }

        if (!updated)
            break;
    }

    /* Check for negative weight cycle */
    for (j = 0; j < E; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            negativeCycle = 1;
            break;
        }
    }

    if (negativeCycle)
    {
        printf("Negative cycle detected\n");
        return 0;
    }

    /* Print shortest distances and paths */
    for (i = 1; i <= V; i++)
    {
        if (i == src)
            continue;

        if (dist[i] == INF)
        {
            printf("%d INF None\n", i);
        }
        else
        {
            printf("%d %d ", i, dist[i]);
            printPath(parent, src, i);
            printf("\n");
        }
    }

    return 0;
}
