#include <algorithm>
#include <iostream>
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

    unsigned int paintings;
    cin >> paintings;

    vector<unsigned int> frequencies(1001);

    for (unsigned int i {0}; i < paintings; ++i)
    {
        unsigned int beauty;
        cin >> beauty;

        ++frequencies[beauty];
    }

    cout << paintings - *max_element(frequencies.cbegin(), frequencies.cend())
         << '\n';

    return 0;
}
