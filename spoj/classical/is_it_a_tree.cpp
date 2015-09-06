#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class UnionFind
{
public:
    UnionFind(unsigned int items):
        components(items),
        parents(items),
        ranks(items)
    {
        for (unsigned int i {0}; i < components; ++i)
        {
            parents[i] = i;
        }
    }

    void link(unsigned int item, unsigned int another_item)
    {
        auto root_i = find(item);
        auto root_j = find(another_item);

        if (root_i == root_j)
        {
            return;
        }

        if (ranks[root_i] < ranks[root_j])
        {
            parents[root_i] = root_j;
        }
        else
        {
            parents[root_j] = root_i;

            if (ranks[root_i] == ranks[root_j])
            {
                ++ranks[root_i];
            }
        }

        --components;
    }

    unsigned int find(unsigned int item)
    {
        auto root = item;

        while (root != parents[root])
        {
            root = parents[root];
        }

        while (item != root)
        {
            auto parent = parents[item];

            parents[item] = root;
            item          = parent;
        }

        return root;
    }

    unsigned int size() const
    {
        return components;
    }

private:
    unsigned int components;

    vector<unsigned int> parents;
    vector<unsigned int> ranks;
};

int main()
{
    use_io_optimizations();

    unsigned int nodes;
    unsigned int edges;

    cin >> nodes >> edges;

    UnionFind graph(nodes);

    for (unsigned int i {0}; i < edges; ++i)
    {
        unsigned int source;
        unsigned int destination;

        cin >> source >> destination;

        graph.link(source - 1, destination - 1);
    }

    if (nodes == edges + 1 && graph.size() == 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
