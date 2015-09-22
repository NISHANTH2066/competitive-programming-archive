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
        unsigned int alpha;
        unsigned int beta;
        unsigned int gamma;

        cin >> alpha >> beta >> gamma;

        if (alpha + beta + gamma == 180)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }

        cout << '\n';
    }

    return 0;
}
