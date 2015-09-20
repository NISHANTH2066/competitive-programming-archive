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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int length;
        cin >> length;

        vector<unsigned int> sequence(length);

        for (auto& element : sequence)
        {
            cin >> element;
        }

        nth_element(sequence.begin(), sequence.begin() + 1, sequence.end());

        cout << sequence[0] + sequence[1] << '\n';
    }

    return 0;
}

