#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> adj_list[N];
int d[N];
const int INF = 1e9;
int main()
{
    int nodes, edges;
    bool negetive_cycle = false;
    cin >> nodes >> edges;
    for (int i = 1; i <= nodes; i++)
    {
        d[i] = INF;
    }
    for (int i = 0; i < edges; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj_list[from].push_back({to, weight});
    }
    int src = 1;
    d[src] = 0;
    for (int i = 1; i <= nodes; i++)
    {
        for (int currentNode = 1; currentNode <= nodes; currentNode++)
        {
            for (pair<int, int> adj_node : adj_list[currentNode])
            {
                int u = currentNode;
                int v = adj_node.first;
                int w = adj_node.second;
                if (d[u] + w < d[v])
                {
                    d[v] = d[u] + w;
                    if (i == nodes)
                    {
                        negetive_cycle = true;
                    }
                }
            }
        }
    }

    if (negetive_cycle)
    {
        cout << "Negetive cycle found in the grpah";
    }
    else
    {
        for (int i = 1; i <= nodes; i++)
        {
            cout << d[i] << " ";
        }
    }
    cout << endl;

    return 0;
}