#include <iostream>
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

    for (int objects; cin >> objects && objects != -1; )
    {
        vector<unsigned int> permutations(objects + 1);
        permutations[0] = 1;

        for (unsigned int i {1}; i <= objects; ++i)
        {
            permutations[i] = permutations[i - 1] * i;
        }

        vector<vector<unsigned int>> groups(objects + 1,
                                            vector<unsigned int>(objects + 1));
        groups[1][1] = 1;

        for (unsigned int i {2}; i <= objects; ++i)
        {
            for (unsigned int j {1}; j <= objects; ++j)
            {
                groups[i][j] = groups[i - 1][j] * j + groups[i - 1][j - 1];
            }
        }

        unsigned int relations {0};

        for (unsigned int i {1}; i <= objects; ++i)
        {
            relations += groups[objects][i] * permutations[i];
        }

        cout << relations << '\n';
    }

    return 0;
}
