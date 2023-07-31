#include <iostream>
#include <vector>
#include <set>

typedef long long ll;
std::vector<std::vector<std::pair<int,int>>> g;
std::vector<bool> visited;
std::set<std::pair<ll, int>> pq;

void add_edges(int node)
{
    visited[node] = true;
    for (auto edge : g[node])
        if (!visited[edge.second])
            pq.insert({edge.first, edge.second});
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    g.resize(n+1);
    visited.resize(n+1, false);
    int c1, c2, price;
    for (int i = 0; i < m; i++)
    {
        std::cin >> c1 >> c2 >> price;
        g[c1].push_back({price, c2});
        g[c2].push_back({price, c1});
    }

    add_edges(1);
    ll cost = 0;
    int mst_edges = 0;

    while (!pq.empty() && mst_edges < n-1)
    {
        auto itr = pq.begin();
        int edge_to = itr -> second;
        ll edge_cost = itr -> first;
        pq.erase(itr);
        if (visited[edge_to])
            continue;
        cost += edge_cost;
        mst_edges++;
        add_edges(edge_to);
    }
    if (mst_edges != n-1)
    {
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
    }
    std::cout << cost << std::endl;
}