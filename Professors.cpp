#include<bits/stdc++.h>
using namespace std;

struct professor
{
    string name;
    long phone_num;

public:
    professor(){}

    professor(string n,long p)
    {
        this->name=n;
        this->phone_num=p;
    }

    bool operator<(const professor& other) const
    {
        return name<other.name;
    };

    bool operator=(const professor& other) const
    {
        return name==other.name;
    };
};

vector<professor>professors_list;

professor add_professor(string n,long p)
{
    professor new_professor(n,p);
    professors_list.push_back(new_professor);

    return new_professor;
}