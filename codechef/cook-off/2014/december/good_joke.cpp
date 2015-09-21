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
        unsigned int points;
        cin >> points;

        for (unsigned int i {0}; i < points; ++i)
        {
            int x;
            int y;

            cin >> x >> y;
        }

        unsigned int aggregate {0};

        for (unsigned int i {1}; i <= points; ++i)
        {
            aggregate ^= i;
        }

        cout << aggregate << '\n';
    }

    return 0;
}
