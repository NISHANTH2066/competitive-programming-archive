#include <iostream>
#include <utility>

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

    unsigned int sum {0};

    for (unsigned int current {2}, next {8}; current < 4000000; )
    {
        sum += current;

        current += 4 * next;
        swap(current, next);
    }

    cout << sum << '\n';

    return 0;
}
