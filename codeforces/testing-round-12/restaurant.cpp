#include <algorithm>
#include <iostream>
#include <utility>
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

    unsigned int orders;
    cin >> orders;

    vector<pair<unsigned int, unsigned int>> intervals(orders);

    for (auto& interval : intervals)
    {
        cin >> interval.second >> interval.first;
    }

    sort(intervals.begin(), intervals.end());

    unsigned int accepted_orders {0};
    unsigned int previous_end    {0};

    for (const auto& interval : intervals)
    {
        if (interval.second > previous_end)
        {
            ++accepted_orders;
            previous_end = interval.first;
        }
    }

    cout << accepted_orders << '\n';

    return 0;
}
