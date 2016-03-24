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

    unsigned int bars;
    unsigned int rate;

    cin >> bars >> rate;

    unsigned int swords {bars};

    while (bars >= rate)
    {
        unsigned int new_bars {bars / rate};

        swords += new_bars;
        bars    = new_bars + bars % rate;
    }

    cout << swords << '\n';

    return 0;
}
