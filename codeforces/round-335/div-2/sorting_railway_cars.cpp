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

class SortingRailwayCars
{
public:

    void read_input()
    {
        cin >> cars;

        numbers.resize(cars);
        lengths.resize(cars + 1);

        for (auto& number : numbers)
        {
            cin >> number;
        }
    }

    void solve()
    {
        for (auto number : numbers)
        {
            lengths[number] = lengths[number - 1] + 1;
        }
    }

    void write_output()
    {
        cout << cars - *max_element(lengths.cbegin(), lengths.cend()) << '\n';
    }

private:

    unsigned int cars;

    vector<unsigned int> numbers;
    vector<unsigned int> lengths;
};

int main()
{
    use_io_optimizations();

    SortingRailwayCars instance;

    instance.read_input();
    instance.solve();
    instance.write_output();

    return 0;
}
