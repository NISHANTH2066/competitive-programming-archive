#include <iostream>
#include <vector>

using namespace std;

const vector<unsigned int> mersenne_primes {
          2,       3,       5,       7,      13,      17,      19,      31,
         61,      89,     107,     127,     521,     607,    1279,    2203,
       2281,    3217,    4253,    4423,    9689,    9941,   11213,   19937,
      21701,   23209,   44497,   86243,  110503,  132049,  216091,  756839,
     859433, 1257787, 1398269, 2976221, 3021377, 6972593
};

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
        unsigned int index;
        cin >> index;

        cout << mersenne_primes[index - 1] << '\n';
    }

    return 0;
}
