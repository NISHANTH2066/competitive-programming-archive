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
        double hardness;
        double carbon;
        double tensile;

        cin >> hardness >> carbon >> tensile;

        if (hardness > 50 && carbon < 0.7 && tensile > 5600)
        {
            cout << "10\n";
        }
        else if (hardness > 50 && carbon < 0.7)
        {
            cout << "9\n";
        }
        else if (carbon < 0.7 && tensile > 5600)
        {
            cout << "8\n";
        }
        else if (hardness > 50 && tensile > 5600)
        {
            cout << "7\n";
        }
        else if (hardness > 50 || carbon < 0.7 || tensile > 5600)
        {
            cout << "6\n";
        }
        else
        {
            cout << "5\n";
        }
    }

    return 0;
}
