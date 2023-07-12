#include <iostream>
#include <vector>
#include <queue>

int n, m;
std::vector<std::vector<int>> g;
std::vector<int> visited;
std::vector<int> prev;

void bfs()
{
    std::queue<int> queue;
    queue.push(1);
    visited[1] = true;
    while (!queue.empty())
    {
        int u = queue.front();
        queue.pop();
        for (auto v : g[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                queue.push(v);
                prev[v] = u; 
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> n >> m;
    g.resize(n+1);
    visited.resize(n+1);
    prev.resize(n+1, -1);
    int num1, num2;
    for (int i = 0; i < m; i++)
    {
        std::cin >> num1 >> num2;
        g[num1].push_back(num2);
        g[num2].push_back(num1);         
    }

    bfs();

    int i = n;
    std::vector<int> answer;
    while (i != -1) 
    {
        answer.push_back(i);
        i = prev[i];                
    } 

    if (answer.back() != 1)
    {
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
    }

    std::cout << answer.size() << '\n';
    for (int i = answer.size()-1; i >= 0; i--)
    {
        std::cout << answer[i] << " ";
    }
}