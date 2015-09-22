#include <iostream>
#include <string>

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
        string first;
        string second;

        cin >> first >> second;

        bool are_matching {true};

        for (string::size_type i {0}; i < first.size(); ++i)
        {
            if (first[i] != '?' && second[i] != '?' && first[i] != second[i])
            {
                are_matching = false;
            }
        }

        cout << (are_matching ? "Yes" : "No") << '\n';
    }

    return 0;
}
