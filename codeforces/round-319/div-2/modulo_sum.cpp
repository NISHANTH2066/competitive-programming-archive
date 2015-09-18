#include <iostream>
#include <set>
#include <vector>

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
    unsigned int modulus;

    cin >> length >> modulus;

    vector<unsigned int> sequence(length);

    for (auto& element : sequence)
    {
        cin >> element;
        element %= modulus;
    }

    set<unsigned int> remainders;

    for (unsigned int i {0}; i < min(length, modulus); ++i)
    {
        auto new_remainders = remainders;
        new_remainders.insert(sequence[i]);

        for (auto remainder : remainders)
        {
            new_remainders.insert((sequence[i] + remainder) % modulus);
        }

        remainders = new_remainders;
    }

    cout << (remainders.count(0) ? "YES" : "NO") << '\n';

    return 0;
}
