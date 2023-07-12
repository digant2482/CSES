#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

typedef long long ll;
int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, m, k;
    std::cin >> n >> m >> k;
    ll INF = 1e17;
    std::vector<std::vector<std::pair<int,int>>> g(n+1);
    std::vector<std::vector<ll>> cost(n+1);
    for(int i = 1; i <= n; i++)
	{
		cost[i].resize(k);
		for(int j = 0; j <k; ++j)
		{
			cost[i][j] = INF;
		}
	}
	cost[1][0] = 0;

    int from, to, weight;
    for (int i = 0; i < m; i++)
    {
        std::cin >> from >> to >> weight;
        g[from].push_back({weight,to});
    }
    std::multiset<std::pair<ll,int>> pq;
    pq.insert({0,1});

    while(!pq.empty())
    {
        auto itr = pq.begin();
        int curr_node = itr->second;
        ll cost_node = itr->first;
        pq.erase(itr);
        if (cost[curr_node][k-1] < cost_node)
            continue;
        
        for (auto edge : g[curr_node])
        {
            int edge_to = edge.second;
            int edge_cost = edge.first;
            ll new_cost = cost_node + edge_cost;
            if (cost[edge_to][k-1] > new_cost)
            {
                pq.insert({new_cost, edge_to});
                cost[edge_to][k-1] = new_cost;
                std::sort(cost[edge_to].begin(), cost[edge_to].end());                                
            }
        }
    }
    for (int i = 0; i < k; i++)
        std::cout << cost[n][i] << " ";
}