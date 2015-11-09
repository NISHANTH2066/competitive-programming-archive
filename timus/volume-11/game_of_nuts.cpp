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

    unsigned int heaps;
    cin >> heaps;

    bool daenerys_wins {true};

    for (unsigned int i {0}; i < heaps; ++i)
    {
        unsigned int nuts;
        cin >> nuts;

        if (nuts / 2 % 2 == 0)
        {
            daenerys_wins = !daenerys_wins;
        }
    }

    cout << (daenerys_wins ? "Daenerys" : "Stannis") << '\n';

    return 0;
}
