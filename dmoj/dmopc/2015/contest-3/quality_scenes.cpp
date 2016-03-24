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

    unsigned int first_lower;
    unsigned int first_upper;

    unsigned int second_lower;
    unsigned int second_upper;

    cin >> first_lower  >> first_upper
        >> second_lower >> second_upper;

    if (first_lower >= second_upper || second_lower >= first_upper)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }

    cout << '\n';

    return 0;
}
