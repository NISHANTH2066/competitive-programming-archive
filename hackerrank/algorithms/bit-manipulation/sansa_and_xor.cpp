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
        unsigned int numbers;
        cin >> numbers;

        unsigned int result {0};

        for (unsigned int i {0}; i < numbers; ++i)
        {
            unsigned int number;
            cin >> number;

            if ((i + 1) * (numbers - i) % 2)
            {
                result ^= number;
            }
        }

        cout << result << '\n';
    }

    return 0;
}
