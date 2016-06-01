#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    int duration;
    int records;

    double down_payment;
    double loan;

    while (cin >> duration >> down_payment >> loan >> records && duration >= 0)
    {
        vector<double> depreciations(duration + 1, -1);

        for (int i {0}; i < records; ++i)
        {
            int month;
            cin >> month;
            cin >> depreciations[month];
        }

        double depreciation    {depreciations.front()};
        double car_worth       {(loan + down_payment) * (1.0 - depreciation)};
        double monthly_payment {loan / duration};

        int month;

        for (month = 0; month < duration && car_worth <= loan; ++month)
        {
            if (depreciations[month + 1] != -1)
            {
                depreciation = depreciations[month + 1];
            }

            car_worth *= 1.0 - depreciation;
            loan      -= monthly_payment;
        }

        cout << month << ' ' << (month == 1 ? "month" : "months") << '\n';
    }

    return 0;
}
