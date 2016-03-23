#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
public:

    virtual void getdata() = 0;
    virtual void putdata() = 0;

protected:

    string name;
    unsigned int age;
};

class Professor: public Person
{
public:

    Professor():
        id {current_id++}
    { }

    void getdata()
    {
        cin >> name >> age >> publications;
    }

    void putdata()
    {
        cout << name         << ' '
             << age          << ' '
             << publications << ' '
             << id           << '\n';
    }

private:

    unsigned int publications;
    unsigned int id;

    static unsigned int current_id;
};

unsigned int Professor::current_id {1u};

class Student: public Person
{
public:

    Student():
        marks(6),
        id {current_id++}
    { }

    void getdata()
    {
        cin >> name >> age;

        for (auto& mark : marks)
        {
            cin >> mark;
        }
    }

    void putdata()
    {
        cout << name                                         << ' '
             << age                                          << ' '
             << accumulate(marks.cbegin(), marks.cend(), 0u) << ' '
             << id                                           << '\n';
    }

private:

    vector<unsigned int> marks;
    unsigned int id;

    static unsigned int current_id;
};

unsigned int Student::current_id {1u};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

