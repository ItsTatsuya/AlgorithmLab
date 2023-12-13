//Dijakstra's Algorithm

#include <iostream>
using namespace std;

int Dijakstra(int n, int cost[10][10], int source, int dest)
{
    int dist[10], visited[10], min, u, v;
    for (int i = 1; i <= n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }
    visited[source] = 1;
    for (int i = 1; i <= n; i++)
    {
        min = 999;
        for (int j = 1; j <= n; j++)
        {
            if (min > dist[j] && visited[j] == 0)
            {
                min = dist[j];
                u = j;
            }
        }
        visited[u] = 1;
        for (v = 1; v <= n; v++)
        {
            if (visited[v] == 0)
            {
                if (dist[v] > dist[u] + cost[u][v])
                    dist[v] = dist[u] + cost[u][v];
            }
        }
    }
    return dist[dest];
}

int main()
{
    int n, cost[10][10], source, dest, dist;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the cost matrix: ";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> cost[i][j];
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the destination vertex: ";
    cin >> dest;
    dist = Dijakstra(n, cost, source, dest);
    cout << "The shortest distance between " << source << " and " << dest << " is " << dist << endl;
    return 0;
}

