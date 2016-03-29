/*
    ID:   gsshopo1
    PROG: skidesign
    LANG: C++11
*/

#include <algorithm>
#include <fstream>
#include <limits>
#include <vector>

using namespace std;

int main()
{
    ifstream fin  {"skidesign.in"};
    ofstream fout {"skidesign.out"};

    unsigned int hills;
    fin >> hills;

    vector<unsigned int> heights(hills);

    for (auto& height : heights)
    {
        fin >> height;
    }

    unsigned int min_cost {numeric_limits<unsigned int>::max()};

    for (unsigned int i {0}; i <= 83; ++i)
    {
        unsigned int cost {0};

        for (auto height : heights)
        {
            if (height < i)
            {
                cost += (i - height) * (i - height);
            }
            else if (i + 17 < height)
            {
                cost += (height - (i + 17)) * (height - (i + 17));
            }
        }

        min_cost = min(min_cost, cost);
    }

    fout << min_cost << '\n';

    return 0;
}
