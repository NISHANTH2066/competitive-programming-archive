#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned int infinity {1000000};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int min_unhappiness(unsigned int horses,
                             unsigned int stables,
                             const vector<unsigned int>& white,
                             const vector<unsigned int>& black)
{
    vector<vector<unsigned int>> subtasks;
    subtasks.resize(horses + 1, vector<unsigned int>(stables + 1, infinity));
    subtasks[0][0] = 0;

    for (unsigned int i {1}; i <= horses; ++i)
    {
        for (unsigned int j {1}; j <= stables; ++j)
        {
            for (unsigned int k {j - 1}; k <= i - 1; ++k)
            {
                auto white_horses = white[i] - white[k];
                auto black_horses = black[i] - black[k];

                subtasks[i][j] = min(
                    subtasks[i][j],
                    white_horses * black_horses + subtasks[k][j - 1]
                );
            }
        }
    }

    return subtasks[horses][stables];
}

int main()
{
    use_io_optimizations();

    unsigned int horses;
    unsigned int stables;

    cin >> horses >> stables;

    vector<unsigned int> white(horses + 1);
    vector<unsigned int> black(horses + 1);

    for (unsigned int i {0}; i < horses; ++i)
    {
        unsigned int color;
        cin >> color;

        white[i + 1] = white[i] + (color == 0);
        black[i + 1] = black[i] + (color == 1);
    }

    cout << min_unhappiness(horses, stables, white, black) << '\n';

    return 0;
}
