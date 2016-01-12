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
        unsigned int squares;
        cin >> squares;

        unsigned long long grains {0};

        for (unsigned int i {0}; i < squares; ++i)
        {
            grains += 1ull << i;
        }

        cout << grains / 12000 << " kg\n";
    }

    return 0;
}
