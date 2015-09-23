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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int buckets;
        unsigned int divisor;

        cin >> buckets >> divisor;

        unsigned long long operations {0};

        for (unsigned int i {0}; i < buckets; ++i)
        {
            unsigned int grapes;
            cin >> grapes;

            if (grapes < divisor)
            {
                operations += divisor - grapes;
            }
            else
            {
                operations += min(grapes % divisor,
                                  divisor - grapes % divisor);
            }
        }

        cout << operations << '\n';
    }

    return 0;
}
