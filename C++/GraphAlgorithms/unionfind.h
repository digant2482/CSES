#include <vector>

class UnionFind
{
    int size;
    std::vector<int> parent_node;
    std::vector<int> sz;
    int num_components;
public:

    UnionFind(int n) : size(n)
    {
        num_components = size;
        parent_node.resize(size+1); //To create 1 indexed array (size+1)
        sz.resize(size+1);
        for (int i = 1; i < size+1; i++)
        {
            sz[i] = 1;
            parent_node[i] = i;
        }
    }
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
            if (sz[root_a] < sz[root_b])
            {
                sz[root_b] += sz[root_a];
                parent_node[root_a] = root_b;
            }
            else
            {
                sz[root_a] += sz[root_b];
                parent_node[root_b] = root_a;
            }
        }
        num_components--;
    }

    int size(int p)
    {
        return sz[find(p)];
    }

    bool connected(int a, int b)
    {
        return find(a) == find(b);
    }
    
    int components()
    {
        return num_components;
    }
};