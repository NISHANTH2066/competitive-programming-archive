#include <algorithm>
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

    unsigned long long breakfasts;
    unsigned long long lunches;
    unsigned long long suppers;

    cin >> breakfasts >> lunches >> suppers;

    unsigned long long missed_meals {0};
    auto max_meals = max({breakfasts, lunches, suppers});

    for (auto meals : {breakfasts, lunches, suppers})
    {
        if (meals != max_meals)
        {
            missed_meals += max_meals - 1 - meals;
        }
    }

    cout << missed_meals << '\n';

    return 0;
}
