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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        // In order to get this ACed you should use int and let it overflow.
        // Seems like the test data is completely bollocksed.

        unsigned int first;
        unsigned int second;

        cin >> first >> second;

        auto gcd = __gcd(first, second);
        auto lcm = static_cast<unsigned long long>(first) * second / gcd;

        cout << gcd << ' '
             << lcm << '\n';
    }

    return 0;
}
