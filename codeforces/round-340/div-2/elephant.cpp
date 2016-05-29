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

    unsigned int distance;
    cin >> distance;

    unsigned int steps {0};

    for (unsigned int i {5}; i >= 1; --i)
    {
        steps    += distance / i;
        distance %= i;
    }

    cout << steps << '\n';

    return 0;
}
