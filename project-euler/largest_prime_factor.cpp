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

    unsigned long long number {600851475143ll};
    unsigned long long factor {2};

    while (factor * factor <= number)
    {
        while (number % factor == 0)
        {
            number /= factor;
        }

        ++factor;
    }

    cout << max(number, factor) << '\n';

    return 0;
}
