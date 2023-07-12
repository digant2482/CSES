#include <iostream>
#include <stack>
#include <vector>

int n, m;
std::vector<std::vector<int>> g;
std::vector<bool> visited;
std::vector<bool> contained_in_s;
std::vector<int> s;

bool dfs(int node)
{
    s.push_back(node);
    visited[node] = true;
    contained_in_s[node] = true;
    int curr_node = s.back();
    for (int child:g[curr_node])
    {
        if (!visited[child])
        {
            if (dfs(child))
                return true;
                //No more dfs, cycle already found
        }
        if (contained_in_s[child])
        {
            s.push_back(child);
            return true;
            //No more dfs, cycle found here
        }               
    }
    contained_in_s[curr_node] = false;
    s.pop_back();
    return false;
    //No cycle detected
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> n >> m;
    g.resize(n+1);
    visited.resize(n+1, false);
    contained_in_s.resize(n+1, false);
    int c1,c2;
    for (int i = 0; i < m; i++)
    {
        std::cin >> c1 >> c2;
        g[c1].push_back(c2);
    }

    for (int i = 1; i < n+1; i++) 
        if (!visited[i])
            if (dfs(i))
                break;

    if (s.empty())
    {
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
    }
    
    int temp = s.back();
    int idx = 0;
    while(temp != s[idx])
        idx++;
    
    std::cout << s.size() - idx << '\n';
    for (int i = idx; i < s.size(); i++)
        std::cout << s[i] << " ";
}