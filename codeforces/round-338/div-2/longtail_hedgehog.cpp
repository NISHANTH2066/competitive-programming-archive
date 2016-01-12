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

void read_input(unsigned int& points,
                unsigned int& segments,
                vector<vector<unsigned int>>& graph,
                vector<unsigned long long>& lengths)
{
    cin >> points >> segments;

    graph.resize(points);
    lengths.resize(points, 1);

    for (unsigned int i {0}; i < segments; ++i)
    {
        unsigned int from;
        unsigned int to;

        cin >> from >> to;

        graph[from - 1].push_back(to - 1);
        graph[to - 1].push_back(from - 1);
    }
}

int main()
{
    use_io_optimizations();

    unsigned int points;
    unsigned int segments;

    vector<vector<unsigned int>> graph;
    vector<unsigned long long> lengths;

    read_input(points, segments, graph, lengths);

    unsigned long long max_beauty {0};

    for (unsigned int i {0}; i < points; ++i)
    {
        for (auto adjacent : graph[i])
        {
            if (adjacent < i)
            {
                lengths[i] = max(lengths[i], lengths[adjacent] + 1);
            }
        }

        max_beauty = max(max_beauty, lengths[i] * graph[i].size());
    }

    cout << max_beauty << '\n';

    return 0;
}
