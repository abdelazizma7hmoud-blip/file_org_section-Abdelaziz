#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fruits ("fruit.txt");
    fruits<<"Apple\nOrange\nBanana\n";
    fruits.close();
    fstream fr("fruit.txt",ios::out | ios::app);
    fr<<"Fresh Fruits\n";
    fr.close();
    return 0;
}