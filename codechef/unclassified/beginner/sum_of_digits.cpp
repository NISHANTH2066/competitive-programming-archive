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
        unsigned int number;
        cin >> number;

        unsigned int digits_sum {0};

        for (auto i = number; i > 0; i /= 10)
        {
            digits_sum += i % 10;
        }

        cout << digits_sum << '\n';
    }

    return 0;
}
