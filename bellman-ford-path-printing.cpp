#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> adj_list[N];
long long d[N];
const long long INF = 1e18;
int parent[N];
int main()
{
    int nodes, edges;
    bool negetive_cycle = false;
    int last_updated_node = -1;
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
                    parent[v] = u;
                    if (i == nodes)
                    {
                        negetive_cycle = true;
                        last_updated_node = i;
                    }
                }
            }
        }
    }

    if (negetive_cycle)
    {
        cout << "YES" << endl;
        int selected_node = last_updated_node;
        for (int i = 1; i < nodes - 1; i++)
        {
            selected_node = parent[selected_node];
        }
        int cycle_first_node = selected_node;
        vector<int> cycle;
        cycle.push_back(selected_node);
        while (true)
        {
            selected_node = parent[selected_node];
            cycle.push_back(selected_node);
            if (selected_node == cycle_first_node)
            {
                break;
            }
        }
        reverse(cycle.begin(), cycle.end());
        for (int node : cycle)
        {
            cout << node << " ";
        }
        cout << endl;
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