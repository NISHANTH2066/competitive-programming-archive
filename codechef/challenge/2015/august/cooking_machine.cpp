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
        unsigned int initial;
        unsigned int target;

        cin >> initial >> target;

        unsigned int operations {0};

        while (initial != target)
        {
            if (initial < target)
            {
                target /= 2;
            }
            else
            {
                initial /= 2;
            }

            ++operations;
        }

        cout << operations << '\n';
    }

    return 0;
}
