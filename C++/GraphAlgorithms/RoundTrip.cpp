#include <iostream>
#include <vector>

int n, m;
std::vector<int> parent;
std::vector<bool> visited;
std::vector<std::vector<int>> g;
int start_city, end_city;

bool dfs(int node)
{
    visited[node] = true;
    for (int child : g[node])
    {
        if (parent[node] == child) continue;
        if (!visited[child])
        {
            parent[child] = node;
            if (dfs(child))
                return true;
        }
        else
        {
            end_city = node;
            start_city = child;
            return true;
        }
    }
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> n >> m;
    parent.resize(n+1, -1);
    visited.resize(n+1, false);
    g.resize(n+1);

    int c1, c2;
    for (int i = 0; i < m; i++)
    {
        std::cin >> c1 >> c2;
        g[c1].push_back(c2);
        g[c2].push_back(c1);        
    }

    //Explore all connected components
    bool cycle_found = false;
    for (int i = 1; i < n+1; i++)
    {
        if (!visited[i])
            cycle_found = dfs(i);
        if (cycle_found)
            break;
    }

    if (!cycle_found)
    {
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
    }

    std::vector<int> answer;
    int city = end_city;
    while (city != start_city)
    {
        answer.push_back(city);
        city = parent[city];
    }
    
    std::cout << answer.size() + 2 << '\n';
    std::cout << start_city << " ";
    for (int i = 0; i < answer.size(); i ++)
        std::cout << answer[i] << " ";
    std::cout << start_city << std::endl;
}