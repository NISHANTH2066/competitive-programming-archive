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

    unsigned int buttons;
    unsigned int bulbs;

    cin >> buttons >> bulbs;

    vector<bool> is_on(bulbs);

    for (unsigned int i {0}; i < buttons; ++i)
    {
        unsigned int affected_bulbs;
        cin >> affected_bulbs;

        for (unsigned int j {0}; j < affected_bulbs; ++j)
        {
            unsigned int bulb;
            cin >> bulb;

            is_on[bulb - 1] = true;
        }
    }

    cout << (count(is_on.cbegin(), is_on.cend(), false) ? "NO" : "YES") << '\n';

    return 0;
}
