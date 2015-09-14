#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class Triangle
{
public:
    void triangle()
    {
        cout << "I am a triangle\n";
    }
};

class Isosceles: public Triangle
{
public:
    void isosceles()
    {
        cout << "I am an isosceles triangle\n";
    }

    void description()
    {
        cout << "In an isosceles triangle two sides are equal\n";
    }
};

int main()
{
    use_io_optimizations();

    Isosceles isosceles;

    isosceles.isosceles();
    isosceles.description();
    isosceles.triangle();

    return 0;
}
