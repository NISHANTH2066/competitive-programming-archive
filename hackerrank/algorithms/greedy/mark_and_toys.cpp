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

    unsigned int toys;
    unsigned int money;

    cin >> toys >> money;

    vector<unsigned int> prices(toys);

    for (auto& price : prices)
    {
        cin >> price;
    }

    sort(prices.begin(), prices.end());

    unsigned int bought {0};

    while (bought < toys && prices[bought] <= money)
    {
        money -= prices[bought++];
    }

    cout << bought << '\n';

    return 0;
}
