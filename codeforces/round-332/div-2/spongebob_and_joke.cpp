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
    unsigned int upper_limit;

    cin >> length >> upper_limit;

    vector<vector<unsigned int>> indices(length + 1);

    for (unsigned int i {0}; i < length; ++i)
    {
        unsigned int element;
        cin >> element;

        indices[element].push_back(i);
    }

    bool is_impossible {false};
    bool is_ambiguous  {false};

    vector<unsigned int> initial(upper_limit);

    for (unsigned int i {0}; i < upper_limit; ++i)
    {
        unsigned int element;
        cin >> element;

        if (indices[element].empty())
        {
            is_impossible = true;
        }
        else if (indices[element].size() > 1)
        {
            is_ambiguous = true;
        }
        else
        {
            initial[i] = indices[element].front();
        }
    }

    if (is_impossible)
    {
        cout << "Impossible\n";
    }
    else if (is_ambiguous)
    {
        cout << "Ambiguity\n";
    }
    else
    {
        cout << "Possible\n";

        for (unsigned int i {0}; i < upper_limit; ++i)
        {
            cout << initial[i] + 1 << " \n"[i + 1 == upper_limit];
        }
    }

    return 0;
}
