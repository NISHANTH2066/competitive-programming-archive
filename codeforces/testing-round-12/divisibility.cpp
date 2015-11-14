#include <cstdlib>
#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(void)
{
    use_io_optimizations();

    long long divisor;
    long long lower;
    long long upper;

    cin >> divisor >> lower >> upper;

    if (lower > 0)
    {
        cout << upper / divisor - (lower - 1) / divisor << '\n';
    }
    else if (upper >= 0)
    {
        cout << upper / divisor + 1 + abs(lower) / divisor << '\n';
    }
    else
    {
        cout << abs(lower) / divisor - (abs(upper) - 1) / divisor << '\n';
    }

    return 0;
}
