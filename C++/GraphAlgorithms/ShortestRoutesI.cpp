#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

struct Edge
{
    int from, to, weight;
    Edge(int from, int to, int weight) : from(from), to(to), weight(weight){}
};

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<Edge>> g(n+1);
    std::vector<bool> visited(n+1, false);
    std::vector<ll> distance(n+1, 1e18);
    Edge edge(0, 0, 0);
    for (int i = 0; i < m; i++)
    {
        std::cin >> edge.from >> edge.to >> edge.weight;
        g[edge.from].push_back(edge);
    }

    std::set<std::pair<ll,int>> pq;   
    visited[1] = true;
    distance[1] = 0;
    pq.insert({0,1});
    while(!pq.empty())
    {
        auto itr = pq.begin();
        int curr_node = itr->second;
        ll min_node_distance = itr->first;
        pq.erase(itr);
        visited[curr_node] = true;
        for (auto edge : g[curr_node])
        {
            if (!visited[edge.to])
            {
                ll new_distance = edge.weight + min_node_distance;
                // Check if edge.to is inserted in pq or not
                if (distance[edge.to] == 1e18)
                {
                    distance[edge.to] = new_distance;
                    pq.insert({new_distance, edge.to});
                }

                if (distance[edge.to] > new_distance)
                {
                    pq.erase({distance[edge.to], edge.to});
                    distance[edge.to] = new_distance;
                    pq.insert({distance[edge.to], edge.to});
                }            
            }
        }
    }
    for (int i = 1; i < n+1; i++)
        std::cout << distance[i] << " ";
}