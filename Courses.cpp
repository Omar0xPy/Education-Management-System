#include<bits/stdc++.h>
using namespace std;

struct course
{
    string code;
    string name;

    course(string c,string n)
    {
        code=c;
        name=n;
    }

    bool operator<(const course& other) const
    {
        return code<other.code;
    };

    bool operator<(const course& other) const
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