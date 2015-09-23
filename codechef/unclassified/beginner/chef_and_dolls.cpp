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
        unsigned int dolls;
        cin >> dolls;

        unsigned int missing {0};

        for (unsigned int i {0}; i < dolls; ++i)
        {
            unsigned int doll;
            cin >> doll;

            missing ^= doll;
        }

        cout << missing << '\n';
    }

    return 0;
}
