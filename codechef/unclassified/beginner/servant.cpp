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
        int number;
        cin >> number;

        if (number < 10)
        {
            cout << "What an obedient servant you are!";
        }
        else
        {
            cout << -1;
        }

        cout << '\n';
    }

    return 0;
}
