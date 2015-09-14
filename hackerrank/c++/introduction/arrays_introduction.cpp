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

    unsigned int length;
    cin >> length;

    vector<unsigned int> sequence(length);

    for (auto& element : sequence)
    {
        cin >> element;
    }

    for (auto i = sequence.crbegin(); i != sequence.crend(); ++i)
    {
        cout << *i << " \n"[i + 1 == sequence.crend()];
    }

    return 0;
}
