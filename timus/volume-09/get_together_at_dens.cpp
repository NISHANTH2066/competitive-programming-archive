#include <algorithm>
#include <iostream>
#include <numeric>
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

    unsigned int friends;
    cin >> friends;

    vector<unsigned int> amounts(friends);

    for (auto& amount : amounts)
    {
        cin >> amount;
    }

    auto total = accumulate(amounts.cbegin(), amounts.cend(), 0u);

    for (auto& amount : amounts)
    {
        amount = max(total, amount * (friends + 1)) - total;
    }

    total = accumulate(amounts.cbegin(), amounts.cend(), 0u);

    for (unsigned int i {0}; i < friends; ++i)
    {
        cout << 100 * amounts[i] / total << " \n"[i + 1 == friends];
    }

    return 0;
}
