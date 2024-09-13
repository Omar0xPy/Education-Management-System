#include<bits/stdc++.h>
#include"Courses.cpp"
#include"Students.cpp"
#include"Professors.cpp"
#include"CSV_parser.cpp"
using namespace std;


vector<vector<string>>data_records;
multimap<student,course>student_courselist;
multimap<course,student>course_takerlist;
multimap<professor,course>prof_course_list;


void LoadingScreen()
{
    string closed = "\x1b[31m_ _ _\x1b[0m";
    string open = "\x1b[32m* * *\x1b[0m";
    string nothing = "          ";
    int delay_time=400;


    cout << closed << flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_time));
    cout << "\x1b[2K\r"<<flush;

    cout << open << flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_time));
    cout << "\x1b[2K\r"<<flush;

    cout << nothing << flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_time));

    cout<<endl;
}


void displayLogoAnimation()
{
    string logoline1 = "  \x1b[32m ___________    _____________     __________   \x1b[0m\n";
    string logoline2 = "  \x1b[32m|   _______|   |             |   |   _______|  \x1b[0m\n";
    string logoline3 = "  \x1b[32m|   ________   |   ||   ||   |   |   |______   \x1b[0m\n";
    string logoline4 = "  \x1b[32m|   _______|   |   ||   ||   |   |_______   |  \x1b[0m\n";
    string logoline5 = "  \x1b[32m|   ________   |   ||   ||   |    ______|   |  \x1b[0m\n";
    string logoline6 = "  \x1b[32m|__________|   |___||___||___|   |__________|  \x1b[0m\n";

    vector<string>logo_lines= {logoline1,logoline2,logoline3,logoline4,logoline5,logoline6};

    for(const string&line: logo_lines)
    {
        cout << line << endl;
        cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}


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
        /*cout<<"Registered professors: "<<endl;

        for(auto&x: professors_list)
        {
            cout<<i<<"-"<<x.name<<endl;
            i++;
        }*/

        data_records.clear();
        data_records = parse_csv("professors_data.csv");
        show_data(data_records);
    }

    if(entry==2)
    {
        /*cout<<"Registered students : "<<endl;

        for(auto&x: student_list)
        {
            cout<<i<<"-"<<x.name<<" ID "<<x.id<<endl;
            i++;
        }*/

        data_records.clear();
        data_records = parse_csv("students_data.csv");
        show_data(data_records);
    }

    if(entry==3)
    {
        /*cout<<"Available courses: "<<endl;

        for(auto&x: course_list)
        {
            cout<<i<<"-"<<x.code<<" "<<x.name<<endl;
            i++;
        }*/

        data_records.clear();
        data_records = parse_csv("courses_data.csv");
        show_data(data_records);
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
    {
        cout<<"Sorry, Student not found !"<<endl;
        return;
    }


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
            course_takerlist.insert(pair<course,student>(*temp_course,*temp_student));
        }
        else
            cout<<"Sorry, the course you're looking for isn't available !"<<endl;
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
        LoadingScreen();

        displayLogoAnimation();

        cout << endl;
        cout << "\x1b[32m<< ------ EDUCATION MANAGEMENT SYSTEM ------ >>\x1b[0m" << flush <<endl << endl;
        cout << "\x1b[32m Made by Omar Mohammed, 2024\x1b[0m" << flush << endl;
        cout << "\x1b[32m Release version - v1.1\x1b[0m" << flush << endl << endl;

        cout << "Main Menu:" << endl;
        cout << "[1] Add students" << endl;
        cout << "[2] Add courses" << endl;
        cout << "[3] Add professors" << endl;
        cout << "[4] Show lists of --> " << endl << endl;

        cin >> input;

        if (input == 1) {
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

        else if (input == 2) {
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

        else if (input == 4) {
            show_lists();
        }
    }
    while(input!=0);

    cout<<"Exiting the program. Goodbye!"<<endl;
}