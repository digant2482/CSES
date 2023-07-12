#include <iostream>
#include <vector>
#include <set>

std::vector<int> parent_node;
std::vector<int> component_size;

int find(int p)
{
    int root = p;
    while (parent_node[root] != root)
        root = parent_node[root];

    //Path Compression
    while (p != root)
    {
        int prev = parent_node[p];
        parent_node[p] = root;
        p = prev;
    }
    return root;  
}

void unify(int node_a, int node_b)
{
    int root_a = find(node_a);
    int root_b = find(node_b);

    if (root_a != root_b)
    {
        if (component_size[root_a] < component_size[root_b])
        {
            component_size[root_b] += component_size[root_a];
            parent_node[root_a] = root_b;
        }
        else
        {
            component_size[root_a] += component_size[root_b];
            parent_node[root_b] = root_a;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    parent_node.push_back(0); //To create 1 based indexing in the vector
    component_size.push_back(0); //To create 1 based indexing in the vector
    for (int i = 1; i < n+1; i++)
    {
        parent_node.push_back(i);
        component_size.push_back(1);
    }

    int city1, city2;
    for (int i = 0; i < m; i++)
    {
        std::cin >> city1 >> city2;
        unify(city1, city2);
    }


    std::set<int> root_nodes_all_cmpts;
    for (int i = 1; i < n+1; i++)
    {
        root_nodes_all_cmpts.insert(find(i));
    }

    std::cout << root_nodes_all_cmpts.size()-1 << '\n';


    auto itr = root_nodes_all_cmpts.begin();
    int city_from = *itr;
    for (int i = 0; i < root_nodes_all_cmpts.size()-1; i++)
        std::cout << city_from << " " << *++itr << '\n';
}