#include <iostream>

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

    unsigned int diggers;
    unsigned int period_a;
    unsigned int period_b;

    cin >> diggers >> period_a >> period_b;

    auto for_one_day = diggers * period_a;

    auto lower = for_one_day / period_b;
    auto upper = (for_one_day + period_b - 1) / period_b;

    auto upper_count = for_one_day % period_b;
    auto lower_count = period_b - upper_count;

    for (unsigned int i {0}; i < upper_count; ++i)
    {
        cout << upper << ' ';
    }

    for (unsigned int i {0}; i < lower_count; ++i)
    {
        cout << lower << " \n"[i + 1 == lower_count];
    }

    return 0;
}
