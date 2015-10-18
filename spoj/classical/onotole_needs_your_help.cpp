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

    unsigned int count;
    cin >> count;

    unsigned int unique {0};

    for (unsigned int i {0}; i < count; ++i)
    {
        unsigned int number;
        cin >> number;

        unique ^= number;
    }

    cout << unique << '\n';

    return 0;
}
