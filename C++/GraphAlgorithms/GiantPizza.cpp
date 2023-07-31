#include <iostream>
#include <vector>
#include <stack>

std::vector<std::vector<int>> g;
int ids[200005];
int low_link[200005];
int UNVISITED = -1;
bool on_stack[200005];
bool visited[200005];
std::stack<int> s;

std::vector<int> v;
void dfs(int node)
{
    visited[node] = true;
    for (int child : g[node])
        if (!visited[child])
            dfs(child);
    v.push_back(node);
}

int id = 1;
void dfs2(int node)
{
    ids[node] = low_link[node] = id++;
    s.push(node);
    on_stack[node] = true;
    for (int child : g[node])
    {
        if (ids[child] == UNVISITED)
            dfs2(child);
        if (on_stack[child])
            low_link[node] = std::min(low_link[node], low_link[child]);
    }

    if (ids[node] == low_link[node])
    {
        int s_node = -1;
        while (s_node != node)
        {
            s_node = s.top();
            s.pop();
            on_stack[s_node] = false;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    g.resize(2*m+1);
    char x, y;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x >> a >> y >> b;
        if (x == '-' && y == '-')
        {
            g[m+a].push_back(b);
            g[m+b].push_back(a);
        }
        if (x == '-' && y == '+')
        {
            g[m + a].push_back(m + b);
            g[b].push_back(a);
        }
        if (x == '+' && y == '-')
        {
            g[a].push_back(b);
            g[m + b].push_back(m + a);
        }
        if (x == '+' && y == '+')
        {
            g[a].push_back(m + b);
            g[b].push_back(m + a);
        }
    }

    for (int i = 1; i < 2*m + 1; i++)
    {
        ids[i] = UNVISITED;
        on_stack[i] = false;
        visited[i] = false;
    }

    //Find topological order
    for (int i = 1; i < 2*m + 1; i++)
        if (!visited[i])
            dfs(i);

    //Process in topological order because we want set low_link according to topological order
    //And in Tarjan's algorithms this depends on from which elements you start your dfs
    for (auto i = 1; i <= 2*m; i++)
    {
        if (ids[v[i]] == UNVISITED)
            dfs2(v[i]);
    }

    std::vector<bool> answer(m+1);
    for (int i = 1; i <= m; i++)
    {
        if (low_link[i] == low_link[m + i]) //a and not a belongs to same scc
        {
            std::cout << "IMPOSSIBLE" << std::endl;
            return 0;
        }
        answer[i] = (low_link[i+m] < low_link[i]); //Values in one SCC should have same truth values, and oppsite will form another SCC symmetry
    }

    for (int i = 1; i <= m; i++)
        std::cout << (answer[i] ? '+' : '-') << " ";
}