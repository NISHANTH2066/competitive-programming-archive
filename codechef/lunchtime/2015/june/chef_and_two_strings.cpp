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

    unsigned int test_case;
    cin >> test_case;

    for (unsigned int test {0}; test < test_case; ++test)
    {
        string first;
        string second;

        cin >> first >> second;

        unsigned int min_difference {0};
        unsigned int max_difference {0};

        for (string::size_type i {0}; i < first.size(); ++i)
        {
            if (first[i] == '?' || second[i] == '?')
            {
                ++max_difference;
            }
            else if (first[i] != second[i])
            {
                ++min_difference;
                ++max_difference;
            }
        }

        cout << min_difference << ' '
             << max_difference << '\n';
    }

    return 0;
}
