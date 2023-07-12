#include <iostream>
#include <set>
#include <vector>
#include <deque>

std::vector<int> FindTopologicalOrder(std::vector<std::vector<int>>& g)
{
    int n = g.size()-1;

    std::vector<int> ordering(n+1);
    int index = 1;
    std::vector<int> in_degree(n+1,0);
    for (int i = 1; i < n+1; i++)
        for (int to : g[i])
            in_degree[to]++;

    std::deque<int> zero_in_degree;
    for (int i = 1; i < n+1; i++)
        if (in_degree[i] == 0)
            zero_in_degree.push_back(i);

    while (!zero_in_degree.empty())
    {
        int curr_node = zero_in_degree.front();
        ordering[index++] = curr_node;
        zero_in_degree.pop_front();

        for (int child : g[curr_node])
            if (--in_degree[child] == 0)
                zero_in_degree.push_back(child);
    }
    if (index != n+1)
        return std::vector<int> ();
    return ordering;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);     
    int n, m;
    std::cin >> n >> m;
    int INF = 1e9;
    std::vector<std::vector<int>> g(n+1);
    std::vector<int> cost(n+1, INF);
    std::vector<int> prev(n+1, -1);
    int c1, c2;
    for (int i = 0; i < m; i++)
    {
        std::cin >> c1 >> c2;
        if (c2 == 1)
            continue;
        g[c1].push_back(c2);
    }
    cost[1] = 0;

    std::vector<int> ordered_nodes = FindTopologicalOrder(g);
    for (int i = 1; i < n+1; i++)
    {   
        int node = ordered_nodes[i];
        for (int child : g[node])
        {
            int new_cost = cost[node] - 1; //Giving edge weight of -1 to all edges
            if (cost[child] > new_cost)
            {
                cost[child] = new_cost;
                prev[child] = node;
            }            
        }
    }

    if (cost[n] == INF)
    {
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
    }

    std::vector<int> answer;
    int city = n;
    while (city != -1)
    {
        answer.push_back(city);
        city = prev[city];
    }

    if (answer.back() != 1) //Edge cases no path from starting point && starting point not in answer
    {
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
    }

    std::cout << answer.size() << '\n';
    for (int i = answer.size() - 1; i >= 0; i--)
        std::cout << answer[i] << " ";
}