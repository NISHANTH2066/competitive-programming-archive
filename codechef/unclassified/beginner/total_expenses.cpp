#include <iomanip>
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

    cout << fixed << setprecision(6);

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int quantity;
        unsigned int price;

        cin >> quantity >> price;

        if (quantity < 1000)
        {
            cout << 1.0 * quantity * price << '\n';
        }
        else
        {
            cout << 0.9 * quantity * price << '\n';
        }
    }

    return 0;
}
