/*
    ID:   gsshopo1
    PROG: ariprog
    LANG: C++11
*/

#include <algorithm>
#include <fstream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

void precalculate_bisquares(vector<unsigned int>& bisquares,
                            vector<bool>& is_available,
                            unsigned int upper_limit)
{
    for (unsigned int i {0}; i <= upper_limit; ++i)
    {
        for (unsigned int j {i}; j <= upper_limit; ++j)
        {
            unsigned int bisquare {i * i + j * j};

            if (!is_available[bisquare])
            {
                is_available[bisquare] = true;
                bisquares.push_back(bisquare);
            }
        }
    }

    sort(bisquares.begin(), bisquares.end());
}

void find_progressions(vector<pair<unsigned int, unsigned int>>& progressions,
                       const vector<unsigned int>& bisquares,
                       const vector<bool>& is_available,
                       unsigned int length)
{
    for (unsigned int i {0}; i < bisquares.size(); ++i)
    {
        for (unsigned int j {i + 1}; j < bisquares.size(); ++j)
        {
            unsigned int difference {bisquares[j] - bisquares[i]};

            if (bisquares[i] + (length - 1) * difference > bisquares.back())
            {
                break;
            }

            bool found {true};

            for (unsigned int k {0}; k < length && found; ++k)
            {
                if (!is_available[bisquares[i] + k * difference])
                {
                    found = false;
                }
            }

            if (found)
            {
                progressions.emplace_back(difference, bisquares[i]);
            }
        }
    }

    sort(progressions.begin(), progressions.end());
}

int main()
{
    ifstream fin  {"ariprog.in"};
    ofstream fout {"ariprog.out"};

    unsigned int length;
    unsigned int upper_limit;
    fin >> length >> upper_limit;

    vector<unsigned int> bisquares;
    vector<bool> is_available(125001);
    precalculate_bisquares(bisquares, is_available, upper_limit);

    vector<pair<unsigned int, unsigned int>> progressions;
    find_progressions(progressions, bisquares, is_available, length);

    if (progressions.empty())
    {
        fout << "NONE\n";
    }

    for (const auto& progression : progressions)
    {
        fout << progression.second << ' ' << progression.first << '\n';
    }

    return 0;
}
