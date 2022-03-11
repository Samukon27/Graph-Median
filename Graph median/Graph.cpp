#include "Graph.h"

Graph::Graph()
{
    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 999;
        }
    }
}

void Graph::PrintArray(int dist[][V])
{
    cout << "Graph array:" << endl;
    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++)
        {  
            cout << dist[i][j] << "   ";
        }
        cout << endl;
    }

}

void Graph::median(int dist[][V])
{
    int median, sum = 0, MinSum = 32000;
    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
        {
            sum = sum + dist[i][j];
        }
        if (sum < MinSum)
        {
            MinSum = sum;
        }
        sum = 0;
    }
    cout << "The graph median/s = ";
    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
        {
            sum = sum + dist[i][j];
        }
        if (sum == MinSum)
        {
            cout << i << " ";
        }
        sum = 0;
    }
    cout << endl;
}

void Graph::floydWarshall(int graph[][V])
{
    int dist[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++) 
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != 999
                        && dist[i][k] != 999))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    PrintArray(dist);
    median(dist);
}

void Graph::addEdge(int x, int y, bool direction)
{
    int L;
         
    if (x >= V || x < 0 || y >= V || y < 0)
        cout << "Out of bounds" << endl;   
    
    else if (x == y)
        cout << "There can not be a distance between a point and itself" << endl;
    
    else 
    {
        cout << "Input distance between the two points" << endl;
        cin >> L;

        graph[x][y] = L;
        if (direction == true)
            graph[x][y] = L;
    }
}

void Graph::removeEdge(int x, int y, bool direction)
{
    if (x >= V || x < 0 || y >= V || y < 0)
        cout << "Not Avaliable" << endl;

    else if (x == y)
        cout << "There is no edge between the point and itself" << endl;
    else
    {
        graph[x][y] = 999;
        if (direction == true)
            graph[x][y] = 999;
    }
}

void Graph::clearGraph(int graph[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 999;
        }
    }
}






