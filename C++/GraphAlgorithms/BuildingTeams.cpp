#include <iostream>
#include <vector>
#include <queue>

int n,m;
std::vector<int> groups;
std::vector<std::vector<int>> g;
std::vector<bool> visited;
bool invalid = false;

void bfs()
{
    for (int i = 1; i < n+1; i++)
    {
        if (!visited[i])
        {
            std::queue<int> q;
            q.push(i);
            visited[i] = true;
            groups[i] = 1;
            while (!q.empty())
            {
                int p1 = q.front();
                q.pop();
                
                for (int f : g[p1])
                {
                    if (!visited[f])
                    {
                        if (groups[p1] == 1)
                            groups[f] = 2;
                        else
                            groups[f] = 1;
                        visited[f] = true;
                        q.push(f);
                    }
                    else 
                    {
                        if (groups[f] == groups[p1])
                        {   
                            invalid = true;
                            return;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> n >> m;
    visited.resize(n+1, false); //1 based indexing
    groups.resize(n+1,0);
    g.resize(n+1);
    int p1, p2;
    for (int i = 0; i < m; i++)
    {
        std::cin >> p1 >> p2;
        g[p1].push_back(p2);
        g[p2].push_back(p1);
    }

    bfs();

    if (invalid)
    {
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
    }

    for (int i = 1; i < n+1; i++)
    {
        std::cout << groups[i] << " ";
    }
}