#include<bits/stdc++.h>
#include"Courses.cpp"
#include"Students.cpp"
#include"Professors.cpp"
using namespace std;

multimap<student,course>student_courselist;
multimap<professor,course>prof_course_list;

void show_lists()
{
    int i=1;
    int entry;

    cout << "Enter 1 to show registered professors" << endl;
    cout << "Enter 2 to show registered students" << endl;
    cout << "Enter 3 to show available courses" << endl;


    cin>>entry;

    if(entry==1)
    {
        cout<<"Registered professors: "<<endl;

        for(auto x: professors_list)
        {
            cout<<i<<"-"<<x.name<<endl;
            i++;
        }
    }

    if(entry==2)
    {
        cout<<"Registered students : "<<endl;

        for(auto x: student_list)
        {
            cout<<i<<"-"<<x.name<<" ID "<<x.id<<endl;
            i++;
        }
    }

    if(entry==3)
    {
        cout<<"Available courses: "<<endl;

        for(auto x: course_list)
        {
            cout<<i<<"-"<<x.code<<" "<<x.name<<endl;
            i++;
        }
    }
}


void add_courses_to_student()
{
    int n;
    int id;
    string course_code;
    bool found=false;
    course*temp_course= nullptr;
    student*temp_student= nullptr;

    cout << "Student ID please ! : " << endl;
    cin>>id;

    for(auto&x: student_list)
    {
        if (id == x.id)
        {
            found = true;
            temp_student=&x;
            break;
        }
    }

    if(found==true)
        cout<<"Student found"<<endl;
    else
        cout<<"Sorry, Student not found !"<<endl;


    cout << "No. of courses to register: " << endl;
    cin >> n;

    found=false;

    while(n--)
    {
        for (auto&x: course_list)
        {
            cout<<"Enter course code: "<<endl;
            cin>>course_code;

            if(course_code==x.code)
            {
                found=true;
                temp_course=&x;
                break;
            }
        }

        if(found==true)
        {
            cout<<"Course found and it will be added for you !"<<endl;
            student_courselist.insert(pair<student,course>(*temp_student,*temp_course));
        }
        else
            cout<<"Sorry, the course you're looking for isn't available !"<<endl;;
    }
}


int main()
{
    int records;

    int input;

    int id;
    long phone_num;
    string code;
    string name;

    do
    {
        cout<<endl<<endl;
        cout << "    _________    ___       ___    _________  " << endl;
        cout << "   | _______/   |   |_   _|   |  / _______/  " << endl;
        cout << "   | |_______   | |_  |_|  _| |  | |_______  " << endl;
        cout << "   | _______/   | | |_   _| | |  |_______  | " << endl;
        cout << "   | |_______   | |   |_|   | |   _______/ | " << endl;
        cout << "   |________/   |_|         |_|  |________/  " << endl << endl;

        cout << "<< ------ EDUCATION MANAGEMENT SYSTEM ------ >>" << endl << endl;

        cout << "Main Menu:" << endl;
        cout << "1-Add students" << endl;
        cout << "2-Add courses" << endl;
        cout << "3-Add professors" << endl;
        cout << "4-Show lists of --> " << endl << endl;

        cin >> input;

        if (input == 2) {
            cout << "No. of courses to add: " << endl;
            cin >> records;
            while (records--) {
                cout << "Course name: " << endl;
                cin.ignore();
                getline(cin,name);
                cout << "Course code: " << endl;
                cin >> code;

                add_course(code, name);
                cout << endl;
            }
        }

        else if (input == 3) {
            cout << "No. of professors to add: " << endl;
            cin >> records;
            while (records--) {
                cout << "Professor name: " << endl;
                cin.ignore();
                getline(cin,name);
                cout << "Professor phone number: " << endl;
                cin >> phone_num;

                add_professor(name, phone_num);
                cout << endl;
            }
        }

        else if (input == 1) {
            cout << "No. of students to add: " << endl;
            cin >> records;
            while (records--) {
                cout << "Student name: " << endl;
                cin.ignore();
                getline(cin,name);
                cout << "Student ID: " << endl;
                cin >> id;
                cout << "Student phone number: " << endl;
                cin >> phone_num;

                add_student(id, name, phone_num);
                cout << endl;
            }
        }

        else if (input == 4) {
            show_lists();
        }

    }
    while(input!=0);

    cout<<"Exiting the program. Goodbye!"<<endl;
    cout<<"Made by: Omar Mohammed, 2024"<<endl;
    cout<<"Release version - v1.0"<<endl;

}