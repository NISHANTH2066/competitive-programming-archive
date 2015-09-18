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

    cout << fixed << setprecision(9);

    unsigned long long x;
    unsigned long long y;

    cin >> x >> y;

    if (x < y)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << min((x + y) / (2.0 * ((x + y) / (2 * y))),
                    (x - y) / (2.0 * ((x - y) / (2 * y))))
             << '\n';
    }

    return 0;
}
