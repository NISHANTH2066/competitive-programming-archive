#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read_sequence(vector<unsigned int>& sequence)
{
    unsigned int length;
    cin >> length;

    sequence.resize(length);

    for (auto& element : sequence)
    {
        cin >> element;
    }
}

bool is_subsequence(const vector<unsigned int>& first,
                    const vector<unsigned int>& second)
{
    auto j = second.cbegin();

    for (auto i = first.cbegin(); i != first.cend() && j != second.cend(); ++i)
    {
        if (*i == *j)
        {
            ++j;
        }
    }

    return j == second.cend();
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        vector<unsigned int> first;
        read_sequence(first);

        vector<unsigned int> second;
        read_sequence(second);

        if (is_subsequence(first, second))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
