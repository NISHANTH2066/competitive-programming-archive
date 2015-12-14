#include <algorithm>
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
        parents(items),
        ranks(items)
    {
        for (unsigned int i {0}; i < items; ++i)
        {
            parents[i] = i;
        }
    }

    void link(unsigned int left, unsigned int right)
    {
        auto left_root  = find(left);
        auto right_root = find(right);

        if (left_root == right_root)
        {
            return;
        }

        if (ranks[left_root] < ranks[right_root])
        {
            parents[left_root] = right_root;
        }
        else
        {
            parents[right_root] = left_root;

            if (ranks[left_root] == ranks[right_root])
            {
                ++ranks[left_root];
            }
        }
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

    bool connected(unsigned int left, unsigned int right)
    {
        return find(left) == find(right);
    }

private:

    vector<unsigned int> parents;
    vector<unsigned int> ranks;
};

struct Edge
{
    unsigned int source;
    unsigned int destination;
    unsigned int cost;

    Edge(unsigned int source, unsigned int destination, unsigned int cost):
        source      {source},
        destination {destination},
        cost        {cost}
    { }
};

bool operator<(const Edge& left, const Edge& right)
{
    return left.cost < right.cost;
}

unsigned int minimum_spanning_tree_cost(vector<Edge>& edges, unsigned int nodes)
{
    UnionFind forest(nodes);

    unsigned int mst_cost  {0};
    unsigned int mst_nodes {0};

    sort(edges.begin(), edges.end());

    for (unsigned int i {0}; mst_nodes < nodes - 1; ++i)
    {
        if (!forest.connected(edges[i].source, edges[i].destination))
        {
            ++mst_nodes;
            mst_cost += edges[i].cost;
            forest.link(edges[i].source, edges[i].destination);
        }
    }

    return mst_cost;
}

int main()
{
    use_io_optimizations();

    unsigned int cities;
    unsigned int powered;

    cin >> cities >> powered;

    vector<bool> is_powered(cities);

    for (unsigned int i {0}; i < powered; ++i)
    {
        unsigned int city;
        cin >> city;

        is_powered[city - 1] = true;
    }

    vector<Edge> lines;

    for (unsigned int i {0}; i < cities; ++i)
    {
        for (unsigned int j {0}; j < cities; ++j)
        {
            unsigned int cost;
            cin >> cost;

            if (is_powered[i] && is_powered[j])
            {
                lines.emplace_back(i, j, 0);
            }
            else
            {
                lines.emplace_back(i, j, cost);
            }
        }
    }

    cout << minimum_spanning_tree_cost(lines, cities) << '\n';

    return 0;
}
