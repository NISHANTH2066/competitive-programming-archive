#include <algorithm>
#include <functional>
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
    for (auto& element : sequence)
    {
        cin >> element;
    }
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int length;
        unsigned int lower_bound;

        cin >> length >> lower_bound;

        vector<unsigned int> first(length);
        vector<unsigned int> second(length);

        read_sequence(first);
        read_sequence(second);

        sort(first.begin(), first.end());
        sort(second.begin(), second.end(), greater<unsigned int>());

        bool is_possible {true};

        for (unsigned int i {0}; i < length; ++i)
        {
            if (first[i] + second[i] < lower_bound)
            {
                is_possible = false;
            }
        }

        cout << (is_possible ? "YES" : "NO") << '\n';
    }

    return 0;
}
