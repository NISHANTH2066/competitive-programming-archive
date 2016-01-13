#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

constexpr double pi {acos(-1)};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(6);

    unsigned int bottles;
    cin >> bottles;

    if (bottles == 1)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 1 / sin(pi / bottles) + 1 << '\n';
    }

    return 0;
}
