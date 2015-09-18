#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<bool> eratosthenes_sieve(unsigned int up_to)
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

    unsigned int upper_limit;
    cin >> upper_limit;

    auto is_prime = eratosthenes_sieve(upper_limit);

    vector<unsigned int> questions;

    for (unsigned int i {0}; i <= upper_limit; ++i)
    {
        if (is_prime[i])
        {
            for (unsigned int j {i}; j <= upper_limit; j *= i)
            {
                questions.push_back(j);
            }
        }
    }

    cout << questions.size() << '\n';

    for (auto i = questions.cbegin(); i != questions.cend(); ++i)
    {
        cout << *i << " \n"[i + 1 == questions.cend()];
    }

    return 0;
}
