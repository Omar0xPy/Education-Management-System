#include<bits/stdc++.h>
using namespace std;

struct student
{
    int id;
    string name;
    long phone_num;

    student(int id,string n,long p)
    {
        this->id=id;
        this->name=n;
        this->phone_num=p;
    }

    bool operator<(const student& other) const
    {
        return id<other.id;
    };

    bool operator=(const student& other) const
    {
        return id==other.id;
    };
};

vector<student>student_list;

student add_student(int id,string n,long p)
{
    student new_student(id,n,p);
    student_list.push_back(new_student);

    return new_student;
}