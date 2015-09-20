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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int count;
        cin >> count;

        string gestures;
        cin >> gestures;

        if (gestures.find('Y') != string::npos)
        {
            cout << "NOT INDIAN\n";
        }
        else if (gestures.find('I') != string::npos)
        {
            cout << "INDIAN\n";
        }
        else
        {
            cout << "NOT SURE\n";
        }
    }

    return 0;
}
