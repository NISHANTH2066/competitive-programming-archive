#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

template <typename T>
map<T, T> inverse(const map<T, T>& relation)
{
    map<T, T> inversed;

    for (const auto& link : relation)
    {
        inversed[link.second] = link.first;
    }

    return inversed;
}

int main()
{
    use_io_optimizations();

    unsigned int name_length;
    unsigned int designers;
    string name;

    cin >> name_length >> designers >> name;

    map<char, char> replacements;

    for (char letter {'a'}; letter <= 'z'; ++letter)
    {
        replacements[letter] = letter;
    }

    for (unsigned int i {0}; i < designers; ++i)
    {
        char first;
        char second;

        cin >> first >> second;

        swap(replacements[first], replacements[second]);
    }

    replacements = inverse(replacements);

    for (auto letter : name)
    {
        cout << replacements[letter];
    }

    cout << '\n';

    return 0;
}
