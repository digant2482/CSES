#include <iostream>
#include <vector>

std::vector<std::vector<int>> g;
std::vector<int> path;

void dfs(int node)
{
    while (!g[node].empty())
    {
        int child = g[node].back();
        g[node].pop_back();
        dfs(child);
    }
    path.push_back(node);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> in_degrees(n+1);
    std::vector<int> out_degrees(n+1);
    g.resize(n+1);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b;
        g[a].push_back(b);    
        in_degrees[b]++;
        out_degrees[a]++; 
    }

    int count = 0;
    for (int i = 1; i < n+1; i++)
    {
        if (out_degrees[i] > in_degrees[i] || in_degrees[i] > out_degrees[i])  
        {
            count++;
            if (out_degrees[i] - in_degrees[i] > 1 || in_degrees[i] - out_degrees[i] > 1)
            {
                std::cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    if (count != 2)
    {
        std::cout << "IMPOSSIBLE";
        return 0;
    }

    dfs(1);
    if (path.size() != m+1 || path.back() != 1 || path.front() != n)
    {
        std::cout << "IMPOSSIBLE";
        return 0;
    }

    for (int i = path.size() - 1; i >= 0; i--)
        std::cout << path[i] << " ";
}