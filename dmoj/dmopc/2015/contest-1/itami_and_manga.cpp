#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Manga
{
    string name;
    double rating;
};

bool operator<(const Manga& left, const Manga& right)
{
    return left.rating < right.rating;
}

int main()
{
    use_io_optimizations();

    unsigned int mangas_count;
    cin >> mangas_count;

    vector<Manga> mangas(mangas_count);

    for (auto& manga : mangas)
    {
        cin >> manga.name >> manga.rating;
    }

    cout << max_element(mangas.cbegin(), mangas.cend())->name << '\n';

    return 0;
}
