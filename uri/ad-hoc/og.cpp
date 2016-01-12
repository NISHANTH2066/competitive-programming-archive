#include <iostream>

using namespace std;

inline
void use_oi_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_oi_optimizations();

    unsigned int sons;
    unsigned int daughters;

    while (cin >> sons >> daughters && !(sons == 0 && daughters == 0))
    {
        cout << sons + daughters << '\n';
    }

    return 0;
}
