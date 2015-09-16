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

    for (unsigned int i {1} ; i < 333; ++i)
    {
        if ((500000 - 1000 * i) % (1000 - i) == 0)
        {
            unsigned int j {(500000 - 1000 * i) / (1000 - i)};

            cout << i * j * (1000 - i - j) << '\n';
        }
    }

    return 0;
}
