/*
    ID:   gsshopo1
    PROB: milk3
    LANG: C++11
 */

#include <algorithm>
#include <fstream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct Node
{
    vector<unsigned int> amounts;

    Node(unsigned int a, unsigned int b, unsigned int c):
        amounts {a, b, c}
    { }
};

bool operator<(const Node& left, const Node& right)
{
    return left.amounts < right.amounts;
}

Node pour(const Node& current,
          unsigned int from,
          unsigned int to,
          const vector<unsigned int>& capacities)
{
    unsigned int amount {min(current.amounts[from],
                             capacities[to] - current.amounts[to])};

    Node result {current};
    result.amounts[from] -= amount;
    result.amounts[to]   += amount;

    return result;
}

set<unsigned int> traverse(const vector<unsigned int>& capacities)
{
    set<unsigned int> amounts;
    amounts.insert(capacities[2]);

    set<Node> visited;
    visited.insert(Node{0, 0, capacities[2]});

    queue<Node> level;
    level.push(Node{0, 0, capacities[2]});

    while (!level.empty())
    {
        auto current = level.front();
        level.pop();

        for (unsigned int i {0}; i < 3; ++i)
        {
            for (unsigned int j {0}; j < 3; ++j)
            {
                auto adjacent = pour(current, i, j, capacities);

                if (!visited.count(adjacent))
                {
                    visited.insert(adjacent);
                    level.push(adjacent);

                    if (adjacent.amounts[0] == 0)
                    {
                        amounts.insert(adjacent.amounts[2]);
                    }
                }
            }
        }
    }

    return amounts;
}

int main()
{
    ifstream fin  {"milk3.in"};
    ofstream fout {"milk3.out"};

    vector<unsigned int> capacities(3);
    fin >> capacities[0] >> capacities[1] >> capacities[2];

    auto amounts = traverse(capacities);

    for (auto i = amounts.cbegin(); i != amounts.cend(); ++i)
    {
        if (i != amounts.cbegin())
        {
            fout << ' ';
        }

        fout << *i;
    }

    fout << '\n';

    return 0;
}
