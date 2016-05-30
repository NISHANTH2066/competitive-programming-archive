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

    unsigned int length;
    unsigned int divisor;

    cin >> length >> divisor;

    if (length == 1 && divisor == 10)
    {
        cout << -1;
    }
    else
    {
        cout << divisor << string(length - 1 - (divisor == 10), '0');
    }

    cout << '\n';

    return 0;
}
