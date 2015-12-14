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

    unsigned int cars;
    cin >> cars;

    vector<unsigned int> lengths(cars + 1);

    for (unsigned int i {0}; i < cars; ++i)
    {
        unsigned int number;
        cin >> number;

        lengths[number] = lengths[number - 1] + 1;
    }

    cout << cars - *max_element(lengths.cbegin(), lengths.cend()) << '\n';

    return 0;
}
