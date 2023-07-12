#include <iostream>
#include <vector>

typedef long long ll;

struct Edge
{
    int from, to, cost;
    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};


int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    Edge edge(0,0,0);
    ll INF = 1e15;
    std::vector<Edge> edge_list(m, edge); 
    std::vector<ll> score(n+1, INF); //min score for all rooms (negation will give max)
    score[1] = 0;

    for (int i = 0; i < m; i++)
    {
        std::cin >> edge_list[i].from >> edge_list[i].to >> edge_list[i].cost;
        edge_list[i].cost = -edge_list[i].cost;
        if (edge_list[i].from == 1 && edge_list[i].to == 1 && edge_list[i].cost != 0)
            score[1] = 1;
    }

    for (int i = 0; i < n-1; i++)
        for (int e = 0; e < m; e++)
        {
            Edge edge = edge_list[e];
            if (!(score[edge.from] == INF && score[edge.to] == INF)) //It just updates values of INF which leads to false comparison in future
                if (score[edge.to] > score[edge.from] + edge.cost)
                    score[edge.to] = score[edge.from] + edge.cost;  
        }

    for (int i = 0; i < n-1; i++)
        for (int e = 0; e < m; e++)
        {
            Edge edge = edge_list[e];
            if (!(score[edge.from] == INF && score[edge.to] == INF))
                if (score[edge.to] > score[edge.from] + edge.cost)
                    score[edge.to] = -INF; 
        }

    if (score[n] == -INF)
    {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::cout << -score[n] << std::endl;
}