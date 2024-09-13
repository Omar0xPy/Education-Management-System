#include<bits/stdc++.h>
using namespace std;


vector<vector<string>> parse_csv(const string&filename) //parses data from csv
{
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening " << filename << endl;
        return {};
    }

    /* Handling the 3-byte Byte Order Mark (BOM -> 0xEF 0xBB 0xBF)
    character sequence (UTF-8 CSV format) */

    char BOM[3];
    file.read(BOM,3);
    if(!(BOM[0] == '\xEF' && BOM[1] == '\xBB' && BOM[2] == '\xBF'))
    {
        file.seekg(0);
    }

    vector<vector<string>>data;
    vector<string>row;
    string line,cell;

    while(getline(file,line))
    {
        row.clear();
        istringstream lineStream(line);

        while(getline(lineStream,cell,','))
        {
            row.push_back(cell);
        }

        data.push_back(row);
    }

    file.close();
    return data;
}

void show_data(vector<vector<string>>&data)
{
    for(auto&row:data)
    {
        bool first=true;
        for(auto&field:row)
        {
            if(!first)
            {
                cout<<" | ";
            }
            cout<<field;
            first= false;   // printing the full row
        }
        cout<<endl;
    }
}


/*int main()
{
    vector<vector<string>>data = parse_csv("courses_data.csv");

    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
}*/