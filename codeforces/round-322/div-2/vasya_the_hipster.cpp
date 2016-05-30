#include <algorithm>
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

    unsigned int red_socks;
    unsigned int blue_socks;

    cin >> red_socks >> blue_socks;

    auto minimum = min(red_socks, blue_socks);
    auto maximum = max(red_socks, blue_socks);

    cout << minimum << ' ' << (maximum - minimum) / 2 << '\n';

    return 0;
}
