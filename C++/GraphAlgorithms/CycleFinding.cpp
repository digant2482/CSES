#include <iostream>
#include <vector>

typedef long long ll;
struct Edge
{
    int from, to, len;
    Edge(int from, int to, int len) : from(from), to(to), len(len) {}

};


int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    ll INF = 1e15;
    std::vector<Edge> edge_list;
    std::vector<ll> distance(n+1, INF);
    std::vector<int> prev(n+1, -1);
    distance[0] = 0;

    for (int i = 1; i < n+1; i++)
    {
        Edge edge(0, i, 0);
        edge_list.push_back(edge);
    }

    Edge edge(0,0,0);
    for (int i = 0; i < m; i++)
    {
        std::cin >> edge.from >> edge.to >> edge.len;
        edge_list.push_back(edge);
    }
    
    int x;
    for (int i = 0; i < n+1; i++)
    {
        x = -1;
        for (auto edge : edge_list)
            if (distance[edge.to] > distance[edge.from] + edge.len)
            {
                x = edge.from;
                prev[edge.to] = edge.from;
                distance[edge.to] = distance[edge.from] + edge.len;
            }
    }
    
    if (x == -1)
    {   
        std::cout << "NO" << std::endl;
        return 0;
    }

    std::cout << "YES" << '\n';

    //To a node inside of a negative cycle
    for (int i = 0; i < n; i++)
        x = prev[x];

    std::vector<int> answer;
    int curr_node = x;
    //loop until final node is start node

    while (curr_node != x || answer.size() == 0)
    {
        answer.push_back(curr_node);
        curr_node = prev[curr_node];        
    }

    answer.push_back(curr_node);            
    for (int i = answer.size() - 1; i >= 0 ; i--)
        std::cout << answer[i] << " ";
}