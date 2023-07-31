#include <iostream>
int parent[100005];
int size[100005];

int find(int node)
{
    int root = node;
    while (parent[root] != root)
        root = parent[root];    
    return root;
}

void unify(int a, int b, int& num_components, int& largest_component)
{
    int root_a = find(a);
    int root_b = find(b);

    if (root_a == root_b)
        return;

    if (size[root_a] > size[root_b])
    {
        size[root_a] += size[root_b];
        parent[root_b] = root_a;
        largest_component = std::max(largest_component, size[root_a]);
    }
    else
    {
        size[root_b] += size[root_a];
        parent[root_a] = root_b; 
        largest_component = std::max(largest_component, size[root_b]);
    }
    num_components--;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    int num_components = n;
    int largest_component = 1;
    for (int i = 1; i < n+1; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }

    int c1, c2;
    for (int i = 0; i < m; i++)
    {
        std::cin >> c1 >> c2;
        unify(c1, c2, num_components, largest_component);
        std::cout << num_components << " " << largest_component << '\n';
    }
}