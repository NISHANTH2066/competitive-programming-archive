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

    unsigned int vertical_count;
    unsigned int horizontal_count;

    cin >> vertical_count >> horizontal_count;

    vector<unsigned int> vertical(vertical_count);

    for (auto& popularity : vertical)
    {
        cin >> popularity;
    }

    vector<unsigned int> horizontal(horizontal_count);

    for (auto& popularity : horizontal)
    {
        cin >> popularity;
    }

    auto max_vertical   = *max_element(vertical.cbegin(),   vertical.cend());
    auto max_horizontal = *max_element(horizontal.cbegin(), horizontal.cend());

    cout << max({min({horizontal.front(), vertical.back()}),
                 min({vertical.front(),   horizontal.back()}),
                 min({horizontal.front(), horizontal.back(), max_vertical}),
                 min({vertical.front(),   vertical.back(),   max_horizontal})})
         << '\n';

    return 0;
}
