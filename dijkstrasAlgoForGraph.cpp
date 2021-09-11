#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

vector<int> dijkstras(vector<vector<pair<int, int>>> graph, int start)
{
    vector<int> dist(graph.size(), INT_MAX);

    //<weight , vertex > pair

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //start add pq where distance is zero
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[u].size(); ++i)
        {
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

void addEdge(vector<vector<pair<int, int>>> &graph, int u, int v, int w)
{
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}

int main()
{
    vector<vector<pair<int, int>>> graph(9, vector<pair<int, int>>(9));

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    vector<int> dist = dijkstras(graph , 0);

    //  printing vertex and distance from source   


    cout << "vertex  :  distances from source \n";
    cout << "--------------------------------\n";


    for (int i = 0; i < 9; i++)
    {
        cout<< i <<"\t:\t" << dist[i] << "\n";
    }
    

    return 0;
}
