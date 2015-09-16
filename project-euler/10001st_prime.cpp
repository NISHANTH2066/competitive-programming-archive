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

    auto is_prime = sieve_of_eratosthenes(1000000);

    for (unsigned int i {0}, primes {0}; i < is_prime.size(); ++i)
    {
        if (is_prime[i])
        {
            ++primes;

            if (primes == 10001)
            {
                cout << i << '\n';
            }
        }
    }

    return 0;
}
