#include <iostream>
#include <vector>
#include <stack>
 
int UNVISITED = -1;
bool on_stack[100005];
std::vector<int> ids(100005, UNVISITED);
int low_link[100005];
std::vector<std::vector<int>> g;
std::stack<int> s;
std::vector<int> unreachable_cities;
 
int scc = 0;
int id = 0;
int elements_in_scc;
void dfs(int node)
{
    if (scc > 1)
        return;
    ids[node] = low_link[node] = id++; 
    s.push(node);
    on_stack[node] = true;
 
    for (int child : g[node])
    {
        if (ids[child] == UNVISITED)
            dfs(child);
        if (on_stack[child])
            low_link[node] = std::min(low_link[node], low_link[child]);
    }
    
    if (ids[node] == low_link[node])
    {
        elements_in_scc = s.size();
        scc++;
        unreachable_cities.push_back(node);
        int s_node = -1;
        while (s_node != node)
        {
            s_node = s.top();
            on_stack[s_node] = false;
            s.pop();
        }
    }       
}
 
int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    g.resize(n+1);
    int c1, c2;
    for (int i = 0; i < m; i++)
    {
        std::cin >> c1 >> c2;
        g[c1].push_back(c2);
    }
 
    for (int i = 1; i < n+1; i++)
        if (ids[i] == UNVISITED)
            dfs(i);

    if (scc != 1 || elements_in_scc != n)
    {
        std::cout << "NO" << '\n';
        if (s.size())
        {
            unreachable_cities.push_back(s.top());
            s.pop();
        }
        if (s.size())
            unreachable_cities.push_back(s.top());
        c1 = unreachable_cities[0];
        c2 = unreachable_cities[1];
        std::cout << c1 << " " << c2;
        return 0;
    }
    std::cout << "YES" << std::endl;
}