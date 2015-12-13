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

    vector<unsigned int> own(3);
    vector<unsigned int> needed(3);

    cin >> own[0]    >> own[1]    >> own[2]
        >> needed[0] >> needed[1] >> needed[2];

    unsigned int lacking {0};
    unsigned int extra   {0};

    for (unsigned int i {0}; i < 3; ++i)
    {
        if (own[i] < needed[i])
        {
            lacking += needed[i] - own[i];
        }
        else
        {
            extra += (own[i] - needed[i]) / 2;
        }
    }

    cout << (lacking <= extra ? "Yes" : "No") << '\n';

    return 0;
}
