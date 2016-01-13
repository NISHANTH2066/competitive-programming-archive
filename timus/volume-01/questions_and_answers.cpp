#include <algorithm>
#include <iostream>
#include <string>
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

    unsigned int database_size;
    cin >> database_size;

    vector<unsigned int> database(database_size);

    for (auto& number : database)
    {
        cin >> number;
    }

    sort(database.begin(), database.end());

    string delimiter;
    cin >> delimiter;

    unsigned int queries;
    cin >> queries;

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned int position;
        cin >> position;

        cout << database[position - 1] << '\n';
    }

    return 0;
}
