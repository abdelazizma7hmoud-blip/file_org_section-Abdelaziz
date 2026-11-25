#include <iostream>
#include<fstream>

using namespace std;
int main()
{
    char name[20];
    int id;
    float grade;
    char choice='y';
    ofstream x("students.txt", ios::app);
    while(choice == 'y' || choice == 'Y') {
        cout<<"Enter your name: ";
        cin.getline(name,20);
        cout<<"Enter your id: ";
        cin>>id;
        cout<<"Enter your grade: ";
        cin>>grade;
        cout<<"Add another student? (y/n) : ";
        cin>>choice;
        cin.ignore();
    }
    x<<name<<" "<<id<<" "<<grade<<endl;
        x.close();
}