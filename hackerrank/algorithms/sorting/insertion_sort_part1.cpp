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

    vector<int> sequence;
    read_sequence(sequence);

    auto i   = sequence.rbegin() + 1;
    auto key = sequence.back();

    for (; i != sequence.rend() && *i > key; ++i)
    {
        *(i - 1) = *i;
        print_sequence(sequence);
    }

    *(i - 1) = key;
    print_sequence(sequence);

    return 0;
}
