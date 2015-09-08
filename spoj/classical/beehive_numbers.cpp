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

    for (int number; cin >> number && number != -1; )
    {
        for (unsigned int i {1}; number > 1; ++i)
        {
            number -= 6 * i;
        }

        cout << (number == 1 ? 'Y' : 'N') << '\n';
    }

    return 0;
}
