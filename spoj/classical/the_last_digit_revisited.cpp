#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int last_digit(unsigned int base, unsigned long long exponent)
{
    unsigned int digit        {1};
    unsigned int intermediate {base};

    for (auto i = exponent; i > 0; i /= 2)
    {
        if (i % 2)
        {
            digit = (digit * intermediate) % 10;
        }

        intermediate = (intermediate * intermediate) % 10;
    }

    return digit;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        string base;
        unsigned long long exponent;

        cin >> base >> exponent;

        cout << last_digit(base.back() - '0', exponent) << '\n';
    }

    return 0;
}
