#include <iostream>
#include <vector>
#include <deque>

std::vector<int> FindTopologicalOrder(std::vector<std::vector<int>>& g)
{
    int n = g.size();

    std::vector<int> ordering(n);
    int index = 0;
    std::vector<int> in_degree(n,0);
    for (int i = 0; i < n; i++)
        for (int to : g[i])
            in_degree[to]++;

    std::deque<int> zero_in_degree;
    for (int i = 0; i < n; i++)
        if (in_degree[i] == 0)
            zero_in_degree.push_back(i);

    while (!zero_in_degree.empty())
    {
        int curr_node = zero_in_degree.front();
        ordering[index++] = curr_node;
        zero_in_degree.pop_front();

        for (int child : g[curr_node])
            if (--in_degree[child] == 0)
                zero_in_degree.push_back(child);
    }
    if (index != n)
        return std::vector<int> ();
    return ordering;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b;
        g[a-1].push_back(b-1);
    }

    std::vector<int> answer = FindTopologicalOrder(g);
    if (answer.empty())
    {
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
        std::cout << answer[i] + 1 << " ";
}