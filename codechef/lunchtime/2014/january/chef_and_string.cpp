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

    string sequence;
    cin >> sequence;

    unsigned int c    {0};
    unsigned int ch   {0};
    unsigned int che  {0};
    unsigned int chef {0};

    for (auto symbol : sequence)
    {
        if (symbol == 'C')
        {
            ++c;
        }
        else if (symbol == 'H')
        {
            if (c > 0)
            {
                --c;
                ++ch;
            }
        }
        else if (symbol == 'E')
        {
            if (ch > 0)
            {
                --ch;
                ++che;
            }
        }
        else
        {
            if (che > 0)
            {
                --che;
                ++chef;
            }
        }
    }

    cout << chef << '\n';

    return 0;
}
