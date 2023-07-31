#include <iostream>
#include <vector>
#include <stack>

std::vector<std::vector<std::pair<int,int>>> g;
std::vector<int> path;

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    g.resize(n+1);
    std::vector<int> visited(m+1, false);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }

    for (int i = 1; i < n+1; i++)
    {
        if (g[i].size() % 2 == 1)
        {
            std::cout << "IMPOSSIBLE";
            return 0;
        }
    }

    std::stack<int> s;
    std::vector<int> answer_array;
    s.push(1);
    while (!s.empty())
    {
        int node = s.top();
        int f = 0;
        while(!g[node].empty())
        {
            auto [element, edge_id] = g[node].back();
            g[node].pop_back();
            if (!visited[edge_id])
            {
                f = 1;
                visited[edge_id] = true;
                s.push(element);
                break;
            }
        }
        if (!f)
        {
            answer_array.push_back(node);
            s.pop();
        }
    }
    if (answer_array.size() != m+1)
    {
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
    }
    for (int i = 0; i < answer_array.size() ; i++)
        std::cout << answer_array[i] << " ";
}