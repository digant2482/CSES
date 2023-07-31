#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

struct Edge
{
    int from, to, max_speed, residual_edge_index;
    int used_speed = 0;

    Edge(int from, int to, int max_speed, const int residual_edge_index) : 
        from(from), to(to), max_speed(max_speed), residual_edge_index(residual_edge_index) {}
};

int n, m;
std::vector<std::vector<Edge>> g;
std::vector<int> levels;

bool bfs()
{
    levels.resize(n+1, -1);
    std::queue<int> q;
    levels[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (Edge edge : g[node])
        {
            if ((edge.max_speed - edge.used_speed > 0) && levels[edge.to] == -1) //last condition to avoid residuals from interfering
            {
                levels[edge.to] = levels[node] + 1; 
                q.push(edge.to);               
            }
        }
        std::cout << q.empty() << " ";
    }
    return levels[n] != -1;    
}

std::vector<int> next;
int dfs(int node, int flow)
{
    if (node == n)
        return flow;
        
    int num_edges = g[node].size();
    while (next[node] < num_edges)
    {
        Edge& edge = g[node][next[node]];
        int cap = edge.max_speed - edge.used_speed;
        if (levels[edge.to] == levels[node] + 1 && cap > 0)
        {
            int bottleneck = dfs(edge.to, std::min(flow, cap));
            if (bottleneck > 0)
            {
                edge.used_speed += bottleneck;
                g[edge.to][edge.residual_edge_index].used_speed -= bottleneck; //Residual edge
                return bottleneck;
            }
        }
        next[node]++;
    }
    return 0;
}

int main()
{
    std::cin >> n >> m;
    g.resize(n+1);
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b >> c;
        Edge edge(a,b,c, g[b].size());
        Edge residual_edge(b,a,0, g[a].size());
        g[a].push_back(edge);
        g[b].push_back(residual_edge);
    }

    ll max_speed = 0;
    while(bfs() == true)
    {
        next.resize(n+1, 0);
        int flow = 1e9;
        while (true)
        {
            flow = dfs(1, flow);
            max_speed += flow;
            if (flow == 0)
                break;
        } 
    }
    std::cout << max_speed << std::endl;    
}