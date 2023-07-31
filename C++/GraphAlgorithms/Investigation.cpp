#include <iostream>
#include <vector>
#include <set>

typedef long long ll;
ll INF = 1e18;
int mod = 1e9 + 7;

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int,int>>> g(n+1); //Graph
    std::vector<ll> cost(n+1, INF); //Min cost upto each node
    std::vector<int> min_cost_total_paths(n+1, 0); //Paths to every node (Given minimum cost upto that node is attained by path)
    std::vector<int> min_flights(n+1, INF); //Min flights required to achieve min cost upto a node
    std::vector<int> max_flights(n+1, 0); //Max flights required to achieve min cost upto a node
    cost[1] = 0;
    min_cost_total_paths[1] = 1;
    min_flights[1] = 0;
    int c1, c2, price;
    for (int i = 0; i < m; i++)
    {
        std::cin >> c1 >> c2 >> price;
        g[c1].push_back({price, c2});
    }

    std::set<std::pair<ll,int>> pq;
    pq.insert({0,1});

    while (!pq.empty())
    { 
        auto itr = pq.begin();
        int curr_node = itr ->second;
        ll node_cost = itr ->first;
        pq.erase(itr);
        if (cost[curr_node] < node_cost)
            continue;

        for (auto edge:g[curr_node])
        { 
            int edge_to = edge.second;
            int edge_cost = edge.first;
            ll new_distance = cost[curr_node] + edge_cost;
            if (cost[edge_to] > new_distance)
            {
                cost[edge_to] = new_distance;
                min_cost_total_paths[edge_to] = min_cost_total_paths[curr_node]; //paths when you first find the min value
                min_flights[edge_to] = min_flights[curr_node] + 1;
                max_flights[edge_to] = max_flights[curr_node] + 1;
                pq.insert({cost[edge_to], edge_to});
            }
            else if (cost[edge_to] == new_distance)
            {
                min_cost_total_paths[edge_to] += min_cost_total_paths[curr_node]; 
                min_cost_total_paths[edge_to] %= mod;
                min_flights[edge_to] = std::min(min_flights[edge_to], min_flights[curr_node] + 1);
                max_flights[edge_to] = std::max(max_flights[edge_to], max_flights[curr_node] + 1);
            }
        }
    }
    std::cout << cost[n] << " "; //Minimum price
    std::cout << min_cost_total_paths[n] << " "; //Mininum price routes
    std::cout << min_flights[n] << " "; //Minimum number of flights
    std::cout << max_flights[n] << std::endl; //Maximum number of flights
}