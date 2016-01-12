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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {1}; test <= test_cases; ++test)
    {
        unsigned int team_members;
        cin >> team_members;

        vector<unsigned int> ages(team_members);

        for (auto& age : ages)
        {
            cin >> age;
        }

        cout << "Case " << test << ": " << ages[team_members / 2] << '\n';
    }

    return 0;
}
