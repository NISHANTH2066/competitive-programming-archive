#include <algorithm>
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

    unsigned int days;
    cin >> days;

    unsigned int min_price   {101};
    unsigned int money_spent {0};

    for (unsigned int i {0}; i < days; ++i)
    {
        unsigned int killograms;
        unsigned int price;

        cin >> killograms >> price;

        min_price    = min(min_price, price);
        money_spent += killograms * min_price;
    }

    cout << money_spent << '\n';

    return 0;
}
