#include <cctype>
#include <iostream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read_input(unsigned int& trams, unsigned int& trolleybuses)
{
    string word;

    for (char symbol; cin.get(symbol); )
    {
        if (!isalpha(symbol))
        {
            if (word == "tram")
            {
                ++trams;
            }
            else if (word == "trolleybus")
            {
                ++trolleybuses;
            }

            word = "";
        }
        else
        {
            word += symbol;
        }
    }
}

int main()
{
    use_io_optimizations();

    unsigned int trams        {0};
    unsigned int trolleybuses {0};

    read_input(trams, trolleybuses);

    if (trams > trolleybuses)
    {
        cout << "Tram driver\n";
    }
    else if (trams < trolleybuses)
    {
        cout << "Trolleybus driver\n";
    }
    else
    {
        cout << "Bus driver\n";
    }

    return 0;
}
