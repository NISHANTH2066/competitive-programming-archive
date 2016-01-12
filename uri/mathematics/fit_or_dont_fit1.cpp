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

    for (unsigned int test; test < test_cases; ++test)
    {
        string first;
        string second;

        cin >> first >> second;

        if (first.size() < second.size() ||
            first.substr(first.size() - second.size()) != second)
        {
            cout << "nao encaixa\n";
        }
        else
        {
            cout << "encaixa\n";
        }
    }

    return 0;
}
