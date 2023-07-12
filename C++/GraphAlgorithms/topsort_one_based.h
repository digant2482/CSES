#include <vector>
#include <deque>
std::vector<int> FindTopologicalOrder(std::vector<std::vector<int>>& g)
{
    int n = g.size()-1;

    std::vector<int> ordering(n+1);
    int index = 1;
    std::vector<int> in_degree(n+1,0);
    for (int i = 1; i < n+1; i++)
        for (int to : g[i])
            in_degree[to]++;

    std::deque<int> zero_in_degree;
    for (int i = 1; i < n+1; i++)
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
    if (index != n+1)
        return std::vector<int> ();
    return ordering;
}