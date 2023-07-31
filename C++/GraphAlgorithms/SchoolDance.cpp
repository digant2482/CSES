#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>

int n, m, k;
std::vector<std::tuple<int,int,int>> g[1005];
bool visited[1005];
int dfs(int node, int flow)
{
    if (node == 1001)
        return flow;

    visited[node] = true;
    for (auto &[to, remaining_cap, residual_idx] : g[node])
    {
        if (remaining_cap >= 1 && !visited[to])
        {
            int bottle_neck = dfs(to, std::min(flow, 1));
            if (bottle_neck > 0)
            {
                remaining_cap -= bottle_neck;
                std::get<1>(g[to][residual_idx]) += bottle_neck;
                return bottle_neck;
            }
        }
    }
    
}

int main()
{
    std::cin >> n >> m >> k;
    int a, b;
    for (int i = 0; i < k; i++)
    {
        std::cin >> a >> b;
        int b_size = g[500+b].size();
        int a_size = g[a].size();
        g[a].push_back({500+b, 1, b_size});
        g[500+b].push_back({a, 0, a_size});
    }

    int start_node = 0;
    int end_node = 1001;
    for (int i = 1; i < 501; i++)
    {
        int i_size = g[i].size();
        int start_node_size = g[start_node].size();
        g[start_node].push_back({i, 1, i_size});
        g[i].push_back({start_node, 0, start_node_size});
        
        i_size = g[500 + i].size();
        int end_node_size = g[end_node].size();
        g[500 + i].push_back({end_node, 1, end_node_size});
        g[end_node].push_back({500+i, 0, i_size});
    }

    long long max_flow = 0;
   
    while(1)
    {
        memset(visited, false, sizeof(visited));        
        int f = dfs(0, 2e9);
        max_flow += f;
        if (f == 0)
            break;
    }
    
    std::cout << max_flow << "\n";
    for (int i = 1; i < 501; i++)
        for (auto &[to, rc, re] : g[i])
            if (rc == 0 && to > n)
                std::cout << i << " " << to << '\n';
}