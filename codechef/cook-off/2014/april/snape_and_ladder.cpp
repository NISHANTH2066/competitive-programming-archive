#include <cmath>
#include <iomanip>
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

    cout << fixed << setprecision(2);

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int left;
        unsigned int distance;

        cin >> distance >> left;

        cout << sqrt(left * left - distance * distance) << ' '
             << sqrt(left * left + distance * distance) << '\n';
    }

    return 0;
}
