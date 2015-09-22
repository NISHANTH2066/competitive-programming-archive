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
        unsigned int salary;
        cin >> salary;

        if (salary < 1500)
        {
            cout << 2 * salary << '\n';
        }
        else
        {
            cout << salary + 500 + 0.98 * salary << '\n';
        }
    }

    return 0;
}
