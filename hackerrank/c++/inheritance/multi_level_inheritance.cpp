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
        cout<<"I am a triangle\n";
    }
};

class Isosceles: public Triangle
{
public:
    void isosceles()
    {
        cout<<"I am an isosceles triangle\n";
    }
};

class Equilateral: public Isosceles
{
public:
    void equilateral()
    {
        cout << "I am an equilateral triangle\n";
    }
};

int main()
{
    use_io_optimizations();

    Equilateral equilateral;

    equilateral.equilateral();
    equilateral.isosceles();
    equilateral.triangle();

    return 0;
}
