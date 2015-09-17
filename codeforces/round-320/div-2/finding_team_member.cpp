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

struct Pair
{
    unsigned int first;
    unsigned int second;
    unsigned int strength;
};

bool operator>(const Pair& left, const Pair& right)
{
    return left.strength > right.strength;
}

int main()
{
    use_io_optimizations();

    unsigned int teams;
    cin >> teams;

    vector<Pair> pairs;

    for (unsigned int i {1}; i < 2 * teams; ++i)
    {
        for (unsigned int j {0}; j < i; ++j)
        {
            unsigned int strength;
            cin >> strength;

            pairs.push_back({i, j, strength});
        }
    }

    sort(pairs.begin(), pairs.end(), greater<Pair>());

    vector<unsigned int> mates(2 * teams);

    for (const auto& pair : pairs)
    {
        if (!mates[pair.first] && !mates[pair.second])
        {
            mates[pair.first]  = pair.second + 1;
            mates[pair.second] = pair.first  + 1;
        }
    }

    for (auto i = mates.cbegin(); i != mates.cend(); ++i)
    {
        cout << *i << " \n"[i + 1 == mates.cend()];
    }

    return 0;
}
