#include <cmath>
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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        double food;
        cin >> food;

        cout << ceil(log(food) / log(2)) << " dias\n";
    }

    return 0;
}
