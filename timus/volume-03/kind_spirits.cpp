#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int levels;
    cin >> levels;

    vector<vector<int>> subtasks;
    subtasks.resize(30, vector<int>(31, numeric_limits<int>::max()));
    subtasks[0][1] = 0;

    for (unsigned int i {1}; i <= levels; ++i)
    {
        if (i > 1)
        {
            char delimiter;
            cin >> delimiter;
        }

        unsigned int planets;
        cin >> planets;

        for (unsigned int j {1}; j <= planets; ++j)
        {
            unsigned int parent;
            int cost;

            while (cin >> parent && parent != 0 && cin >> cost)
            {
                subtasks[i][j] = min(subtasks[i][j],
                                     subtasks[i - 1][parent] + cost);
            }
        }
    }

    cout << *min_element(subtasks[levels].cbegin(), subtasks[levels].cend())
         << '\n';

    return 0;
}
