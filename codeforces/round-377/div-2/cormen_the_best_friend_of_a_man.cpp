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

    unsigned int days;
    unsigned int min_walks;

    cin >> days >> min_walks;

    unsigned int additional_walks {0};
    vector<unsigned int> walks(days);

    for (unsigned int i {0}; i < days; ++i)
    {
        cin >> walks[i];

        if (i > 0 && walks[i - 1] + walks[i] < min_walks)
        {
            additional_walks += min_walks - (walks[i - 1] + walks[i]);
            walks[i]         += min_walks - (walks[i - 1] + walks[i]);
        }
    }

    cout << additional_walks << '\n';

    for (unsigned int i {0}; i < days; ++i)
    {
        cout << walks[i] << " \n"[i == days - 1];
    }

    return 0;
}
