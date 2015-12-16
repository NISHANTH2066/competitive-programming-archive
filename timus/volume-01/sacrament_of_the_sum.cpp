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

vector<int> read_sequence(unsigned int length)
{
    vector<int> sequence(length);

    for (auto& element : sequence)
    {
        cin >> element;
    }

    return sequence;
}

int main()
{
    use_io_optimizations();

    unsigned int first_length;
    cin >> first_length;

    auto first = read_sequence(first_length);

    unsigned int second_length;
    cin >> second_length;

    auto second = read_sequence(second_length);

    bool is_possible {false};

    for (auto element : second)
    {
        if (binary_search(first.cbegin(), first.cend(), 10000 - element))
        {
            is_possible = true;
        }
    }

    cout << (is_possible ? "YES" : "NO") << '\n';

    return 0;
}
