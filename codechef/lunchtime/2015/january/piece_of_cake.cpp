#include <algorithm>
#include <iostream>
#include <string>
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
        string sequence;
        cin >> sequence;

        vector<unsigned int> occurrences(26);

        for (auto letter : sequence)
        {
            ++occurrences[letter - 'a'];
        }

        auto maximum = *max_element(occurrences.cbegin(), occurrences.cend());

        cout << (2 * maximum == sequence.size() ? "YES" : "NO") << '\n';
    }

    return 0;
}
