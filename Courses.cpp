#include<bits/stdc++.h>
using namespace std;

class course
{
    string code;
    string name;

public:
    course(string c,string n)
    {
        this->code=c;
        this->name=n;
    }

    bool operator<(const course& other) const
    {
        return code<other.code;
    };

    bool operator=(const course& other) const
    {
        return code==other.code;
    };
};

vector<course>course_list;

course add_course(string c,string n)
{
    course new_course(c,n);
    course_list.push_back(new_course);

    return new_course;
}