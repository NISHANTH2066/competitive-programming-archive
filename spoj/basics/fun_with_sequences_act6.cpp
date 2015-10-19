#include <iostream>
#include <numeric>
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

void print_sequence(const vector<int>& sequence)
{
    for (auto i = sequence.cbegin(); i != sequence.cend(); ++i)
    {
        cout << *i << " \n"[i + 1 == sequence.cend()];
    }
}

int main()
{
    use_io_optimizations();

    vector<int> first;
    read_sequence(first);

    vector<int> second;
    read_sequence(second);

    if (accumulate(first.cbegin(),  first.cend(),  0) >
        accumulate(second.cbegin(), second.cend(), 0))
    {
        print_sequence(first);
    }
    else
    {
        print_sequence(second);
    }

    return 0;
}
