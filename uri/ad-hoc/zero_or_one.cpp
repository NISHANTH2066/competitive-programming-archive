#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    for (unsigned int alice, beto, clara; cin >> alice >> beto >> clara; )
    {
        if (alice != beto && alice != clara)
        {
            cout << 'A';
        }
        else if (beto != alice && beto != clara)
        {
            cout << 'B';
        }
        else if (clara != alice && clara != beto)
        {
            cout << 'C';
        }
        else
        {
            cout << '*';
        }

        cout << '\n';
    }

    return 0;
}
