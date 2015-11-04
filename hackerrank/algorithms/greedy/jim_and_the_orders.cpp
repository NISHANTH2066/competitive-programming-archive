#include <algorithm>
#include <iostream>
#include <utility>
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

    unsigned int fans;
    cin >> fans;

    vector<pair<unsigned int, unsigned int>> endings(fans);

    for (unsigned int i {0}; i < fans; ++i)
    {
        unsigned int start;
        unsigned int duration;

        cin >> start >> duration;

        endings[i] = make_pair(start + duration, i + 1);
    }

    sort(endings.begin(), endings.end());

    for (unsigned int i {0}; i < fans; ++i)
    {
        cout << endings[i].second << " \n"[i + 1 == fans];
    }

    return 0;
}
