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

class Problem
{
public:
    void read_input()
    {
        cin >> length >> operations >> number;

        sequence.resize(length);

        for (auto& element : sequence)
        {
            cin >> element;
        }
    }

    void solve()
    {
        auto factor   = compute_factor();
        auto prefixes = compute_prefixes();
        auto suffixes = compute_suffixes();

        max_value = 0;

        for (unsigned int i {0}; i < length; ++i)
        {
            unsigned long long value {
                (sequence[i] * factor) | prefixes[i] | suffixes[i + 1]
            };

            max_value = max(max_value, value);
        }
    }

    void write_output()
    {
        cout << max_value << '\n';
    }

private:
    unsigned int length;
    unsigned int operations;
    unsigned int number;

    vector<unsigned int> sequence;

    unsigned long long max_value;

    unsigned long long compute_factor()
    {
        unsigned long long factor {1};

        for (unsigned int i {0}; i < operations; ++i)
        {
            factor *= number;
        }

        return factor;
    }

    vector<unsigned int> compute_prefixes()
    {
        vector<unsigned int> prefixes(length + 1);

        for (unsigned int i {0}; i < length; ++i)
        {
            prefixes[i + 1] = prefixes[i] | sequence[i];
        }

        return prefixes;
    }

    vector<unsigned int> compute_suffixes()
    {
        vector<unsigned int> suffixes(length + 1);

        for (unsigned int i {length}; i > 0; --i)
        {
            suffixes[i - 1] = suffixes[i] | sequence[i - 1];
        }

        return suffixes;
    }
};

int main()
{
    use_io_optimizations();

    Problem problem;

    problem.read_input();
    problem.solve();
    problem.write_output();

    return 0;
};
