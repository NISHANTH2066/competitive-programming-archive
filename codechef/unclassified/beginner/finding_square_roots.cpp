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

        unsigned int square_root {0};

        while (square_root * square_root <= number)
        {
            ++square_root;
        }

        cout << square_root - 1 << '\n';
    }

    return 0;
}
