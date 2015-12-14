#include <deque>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<unsigned int> topsort(const vector<vector<unsigned int>>& graph,
                             vector<unsigned int>& in_degrees)
{
    deque <unsigned int> remaining;
    vector<unsigned int> sorted;

    for (vector<unsigned int>::size_type i {1}; i < in_degrees.size(); ++i)
    {
        if (in_degrees[i] == 0)
        {
            remaining.push_back(i);
        }
    }

    while (!remaining.empty())
    {
        auto current = remaining.front();
        remaining.pop_front();

        sorted.push_back(current);

        for (auto adjacent : graph[current])
        {
            --in_degrees[adjacent];

            if (in_degrees[adjacent] == 0)
            {
                remaining.push_back(adjacent);
            }
        }
    }

    return sorted;
}

int main()
{
    use_io_optimizations();

    unsigned int members;
    cin >> members;

    vector<unsigned int> in_degrees(members + 1);
    vector<vector<unsigned int>> graph(members + 1);

    for (unsigned int i {1}; i <= members; ++i)
    {
        for (unsigned int child; cin >> child && child != 0; )
        {
            ++in_degrees[child];
            graph[i].push_back(child);
        }
    }

    auto sorted = topsort(graph, in_degrees);

    for (auto i = sorted.cbegin(); i != sorted.cend(); ++i)
    {
        cout << *i << " \n"[i + 1 == sorted.cend()];
    }

    return 0;
}
