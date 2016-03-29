/*
    ID:   gsshopo1
    PROG: wormhole
    LANG: C++11
*/

#include <fstream>
#include <utility>
#include <vector>

using namespace std;

bool has_cycle(const vector<unsigned int>& next,
               const vector<unsigned int>& partners)
{
    for (unsigned int i {1}; i < next.size(); ++i)
    {
        unsigned int j {i};

        for (unsigned int k {1}; k < next.size(); ++k)
        {
            j = partners[next[j]];
        }

        if (j > 0)
        {
            return true;
        }
    }

    return false;
}

unsigned int pairings(const vector<unsigned int>& next,
                      vector<unsigned int>& partners)
{
    unsigned int i;

    for (i = 1; i < partners.size() && partners[i] > 0; ++i)
    { }

    if (i == partners.size())
    {
        return has_cycle(partners, next);
    }

    unsigned int result {0};

    for (unsigned int j {i + 1}; j < partners.size(); ++j)
    {
        if (partners[j] == 0)
        {
            partners[i] = j;
            partners[j] = i;

            result += pairings(next, partners);

            partners[i] = 0;
            partners[j] = 0;
        }
    }

    return result;
}

int main()
{
    ifstream fin  {"wormhole.in"};
    ofstream fout {"wormhole.out"};

    unsigned int wormholes;
    fin >> wormholes;

    vector<pair<unsigned int, unsigned int>> coordinates(wormholes + 1);

    for (unsigned int i {1}; i <= wormholes; ++i)
    {
        fin >> coordinates[i].first >> coordinates[i].second;
    }

    vector<unsigned int> next(wormholes + 1);
    vector<unsigned int> partners(wormholes + 1);

    for (unsigned int i {1}; i <= wormholes; ++i)
    {
        for (unsigned int j {1}; j <= wormholes; ++j)
        {
            if (coordinates[i].first   < coordinates[j].first &&
                coordinates[i].second == coordinates[j].second)
            {
                if (next[i] == 0 ||
                    coordinates[j].first < coordinates[next[i]].first)
                {
                    next[i] = j;
                }
            }
        }
    }

    fout << pairings(next, partners) << '\n';

    return 0;
}
