#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream x("welcome.txt");
    x<<"Hello Everybody";
    x.close();
    x.open("welcome.txt",ios::trunc);
    x<<"Hello Everyone";
    x.close();
}