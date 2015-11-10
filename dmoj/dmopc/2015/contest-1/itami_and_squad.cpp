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

int main()
{
    use_io_optimizations();

    unsigned int soldiers;
    unsigned int leaders;
    unsigned int itami_rank;

    cin >> soldiers >> leaders >> itami_rank;

    vector<unsigned int> strengths(soldiers);

    for (auto& strength : strengths)
    {
        cin >> strength;
    }

    sort(strengths.begin(), strengths.end(), greater<unsigned int>());

    unsigned int itami_squad_strength {0};

    for (unsigned int i {itami_rank - 1}; i < soldiers; i += leaders)
    {
        itami_squad_strength += strengths[i];
    }

    cout << itami_squad_strength << '\n';

    return 0;
}
