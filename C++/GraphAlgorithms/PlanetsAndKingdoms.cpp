#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
 
int UNVISITED = -1;
bool on_stack[100005];
std::vector<int> ids(100005, UNVISITED);
int low_link[100005];
std::vector<std::vector<int>> g;
std::stack<int> s;
std::unordered_map<int, std::vector<int>> size_map;
 
int scc = 0;
int id = 1;
void dfs(int node)
{
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
        int s_node = -1;
        while (s_node != node)
        {
            s_node = s.top();
            size_map[node].push_back(s_node);
            s.pop();
            on_stack[s_node] = false;
        }
        scc++;
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

    std::cout << scc << '\n';
    std::vector<int> values(n+1);
    int answer = 1;
    for (auto key : size_map)
    {
        for (auto element : key.second)
            values[element] = answer;
        answer++;
    }
    for (int i = 1; i < n+1; i++)
        std::cout << values[i] << " ";
}