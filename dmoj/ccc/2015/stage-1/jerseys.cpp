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

    unsigned int jerseys;
    unsigned int athletes;

    cin >> jerseys >> athletes;

    vector<char> sizes(jerseys);

    for (auto& size : sizes)
    {
        cin >> size;
    }

    for (unsigned int i {0}; i < athletes; ++i)
    {
        char size;
        unsigned int number;

        cin >> size >> number;

        if (size >= sizes[number - 1])
        {
            sizes[number - 1] = 'A';
        }
    }

    cout << count(sizes.cbegin(), sizes.cend(), 'A') << '\n';

    return 0;
}
