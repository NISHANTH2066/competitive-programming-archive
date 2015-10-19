#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read_sequence(vector<int>& sequence)
{
    unsigned int length;
    cin >> length;

    sequence.resize(length);

    for (auto& element : sequence)
    {
        cin >> element;
    }
}

int main()
{
    use_io_optimizations();

    vector<int> first;
    read_sequence(first);

    vector<int> second;
    read_sequence(second);

    for (unsigned int i {0}; i < min(first.size(), second.size()); ++i)
    {
        if (first[i] == second[i])
        {
            cout << i + 1 << ' ';
        }
    }

    cout << '\n';

    return 0;
}
