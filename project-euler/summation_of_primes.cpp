#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<bool> sieve_of_eratosthenes(unsigned int up_to)
{
    vector<bool> is_prime(up_to + 1, true);

    is_prime[0] = false;

    if (up_to > 0)
    {
        is_prime[1] = false;
    }

    for (unsigned int i {2}; i * i <= up_to; ++i)
    {
        if (is_prime[i])
        {
            for (unsigned int j {i * i}; j <= up_to; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    return is_prime;
}

int main()
{
    use_io_optimizations();

    auto is_prime = sieve_of_eratosthenes(2000000);

    unsigned long long sum {0};

    for (unsigned int i {0}; i <= 2000000; ++i)
    {
        if (is_prime[i])
        {
            sum += i;
        }
    }

    cout << sum << '\n';

    return 0;
}
