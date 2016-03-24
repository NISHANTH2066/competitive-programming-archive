#include <iostream>
#include <map>
#include <utility>

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

    unsigned int watchmen;
    cin >> watchmen;

    unsigned long long pairs {0};

    map<pair<int, int>, unsigned int> point_count;
    map<int, unsigned int> x_count;
    map<int, unsigned int> y_count;

    for (unsigned int i {0}; i < watchmen; ++i)
    {
        int x;
        int y;

        cin >> x >> y;

        pairs -= point_count[make_pair(x, y)];
        pairs += x_count[x];
        pairs += y_count[y];

        ++point_count[make_pair(x, y)];
        ++x_count[x];
        ++y_count[y];
    }

    cout << pairs << '\n';

    return 0;
}
