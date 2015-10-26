#include <iomanip>
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

    cout << fixed << setprecision(4);
 
    unsigned int length;
    unsigned int speed_a;
    unsigned int speed_b;

    cin >> length >> speed_a >> speed_b;

    cout << static_cast<double>(length) * speed_a / (speed_a + speed_b) << '\n';

    return 0;
}
