#include <iostream>

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
        char id;
        cin >> id;

        if (id == 'b' || id == 'B')
        {
            cout << "BattleShip";
        }
        else if (id == 'c' || id == 'C')
        {
            cout << "Cruiser";
        }
        else if (id == 'd' || id == 'D')
        {
            cout << "Destroyer";
        }
        else
        {
            cout << "Frigate";
        }

        cout << '\n';
    }

    return 0;
}
