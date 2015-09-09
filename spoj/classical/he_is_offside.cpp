#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read_sequence(vector<unsigned int>& sequence)
{
    for (auto& element : sequence)
    {
        cin >> element;
    }
}

int main()
{
    use_io_optimizations();

    unsigned int strikers;
    unsigned int deffenders;

    while (cin >> strikers >> deffenders && (strikers != 0 || deffenders != 0))
    {
        vector<unsigned int> attacking(strikers);
        vector<unsigned int> deffending(deffenders);

        read_sequence(attacking);
        read_sequence(deffending);

        sort(attacking .begin(), attacking .end());
        sort(deffending.begin(), deffending.end());

        cout << (attacking[0] < deffending[1] ? 'Y' : 'N') << '\n';
    }

    return 0;
}
