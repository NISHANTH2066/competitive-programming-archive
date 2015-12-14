#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned int modulo {1000000007};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int remixes;
    cin >> remixes;

    vector<unsigned int> lengths(2);
    cin >> lengths[0] >> lengths[1];

    vector<vector<unsigned int>> subtasks(remixes + 1, vector<unsigned int>(2));
    subtasks[0][0] = subtasks[0][1] = 1;

    for (unsigned int i {1}; i <= remixes; ++i)
    {
        for (unsigned int j {0}; j <= 1; ++j)
        {
            for (unsigned int k {1}; k <= min(lengths[j], i); ++k)
            {
                subtasks[i][j] += subtasks[i - k][1 - j];
                subtasks[i][j] %= modulo;
            }
        }
    }

    cout << (subtasks.back()[0] + subtasks.back()[1]) % modulo << '\n';

    return 0;
}
