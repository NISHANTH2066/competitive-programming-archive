#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

template <typename T>
class Heap
{
public:

    Heap(unsigned int capacity):
        _size     {0},
        _capacity {capacity},
        _data     {new T[_capacity]}
    { }

    ~Heap()
    {
        delete[] _data;
    }

    void push(const T& element)
    {
        _data[_size++] = element;
        push_heap(_data, _data + _size);
    }

    const T& pop()
    {
        pop_heap(_data, _data + _size);
        return _data[--_size];
    }

    unsigned int size() const
    {
        return _size;
    }

private:

    unsigned int _size;
    unsigned int _capacity;

    T* _data;
};

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(1);

    unsigned int length;
    cin >> length;

    auto heap = Heap<unsigned int>(length / 2 + 2);

    for (unsigned int i {0}; i < length; ++i)
    {
        unsigned int element;
        cin >> element;

        heap.push(element);

        if (heap.size() > length / 2 + 1)
        {
            heap.pop();
        }
    }

    if (length % 2)
    {
        cout << heap.pop() << '\n';
    }
    else
    {
        cout << (heap.pop() + heap.pop()) / 2.0 << '\n';
    }

    return 0;
}
