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

vector<unsigned int> read_sequence(unsigned int length)
{
    vector<unsigned int> sequence(length);

    for (auto& element : sequence)
    {
        cin >> element;
    }

    return sequence;
}

int main()
{
    use_io_optimizations();

    unsigned int girls;
    unsigned int boys;

    cin >> girls >> boys;

    auto girls_units = read_sequence(girls);
    auto boys_units  = read_sequence(boys);

    sort(girls_units.begin(), girls_units.end(), greater<unsigned int>());
    sort(boys_units.begin(),  boys_units.end(),  greater<unsigned int>());

    auto min_upsets = accumulate(girls_units.cbegin(), girls_units.cend(), 0u);

    for (unsigned int i {1}; i <= min(girls, boys); ++i)
    {
        auto girls_upsets = accumulate(girls_units.cbegin() + i,
                                       girls_units.cend(),
                                       0u);

        auto boys_upsets  = accumulate(boys_units.cbegin() + i,
                                       boys_units.cend(),
                                       0u);

        min_upsets = min(min_upsets, girls_upsets + boys_upsets * i);
    }

    cout << min_upsets << '\n';

    return 0;
}
