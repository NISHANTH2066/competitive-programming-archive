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
        unsigned long long levels;
        cin >> levels;

        unsigned long long standing {levels * (levels + 1)};
        unsigned long long lying    {levels * (levels - 1) / 2};

        cout << (standing + lying) % 1000007 << '\n';
    }

    return 0;
}
