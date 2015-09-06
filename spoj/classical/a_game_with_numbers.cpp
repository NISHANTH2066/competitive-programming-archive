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

    unsigned int number;
    cin >> number;

    unsigned int last_digit {number % 10};

    if (last_digit != 0)
    {
        cout << 1          << '\n'
             << last_digit << '\n';
    }
    else
    {
        cout << 2 << '\n';
    }

    return 0;
}
