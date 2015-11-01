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
        unsigned long long counter;
        cin >> counter;

        if (__builtin_popcountll(counter - 1) % 2)
        {
            cout << "Louise";
        }
        else
        {
            cout << "Richard";
        }

        cout << '\n';
    }

    return 0;
}
