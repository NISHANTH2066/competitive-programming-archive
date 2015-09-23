#include <algorithm>
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

        unsigned int minimum {100000};

        for (unsigned int i {0}; i < numbers; ++i)
        {
            unsigned int number;
            cin >> number;

            minimum = min(minimum, number);
        }

        cout << minimum * static_cast<unsigned long long>(numbers - 1) << '\n';
    }

    return 0;
}
