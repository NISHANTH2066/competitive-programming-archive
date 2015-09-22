#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_prime(unsigned int number)
{
    for (unsigned int i {2}; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return number > 1;
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

        if (is_prime(number))
        {
            cout << "yes";
        }
        else
        {
            cout << "no";
        }

        cout << '\n';
    }

    return 0;
}
