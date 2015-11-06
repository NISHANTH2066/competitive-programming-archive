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

    unsigned int flowers;
    unsigned int buyers;

    cin >> flowers >> buyers;

    vector<unsigned int> prices(flowers);

    for (auto& price : prices)
    {
        cin >> price;
    }

    sort(prices.begin(), prices.end(), greater<unsigned int>());

    unsigned int money {0};

    for (unsigned int i {0}; i < flowers; ++i)
    {
        money += prices[i] * (i / buyers + 1);
    }

    cout << money << '\n';

    return 0;
}
