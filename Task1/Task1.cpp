#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string Fullname;
    int id;
    float Grade;
    cout<<"Fullname: \n";
    getline(cin,Fullname);
     cout<<"ID\n";
    cin>>id;
    cout<<"Grade\n";
    cin>>Grade;
    ofstream x("Student.txt");
    x<<"Fullname: "<<Fullname<<"\n";
    x<<"iD: "<<id<<"\n";
    x<<"Grade: "<<Grade<<"\n";
    x.close();
    return 0;
}
