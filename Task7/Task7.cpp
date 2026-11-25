#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    ofstream file("student.txt");
    if (!file) {
        cout << "Error opening student.txt for writing!" << endl;
        return 1;
    }

    file << "Hadeer Mahmoud" << endl;
    file << "Youssef Ali" << endl;
    file << "Ahmed Mostafa" << endl;
    file << "Esraa Ebrahim" << endl;
    file.close();

    ifstream inFile("student.txt");
    if (!inFile) {
        cout << "Error opening student.txt for reading!" << endl;
        return 1;
    }

    string names[4];
    int count = 0;
    while (count < 4 && getline(inFile, names[count])) {
        if (!names[count].empty()) {
            count++;
        }
    }
    inFile.close();

    sort(names, names + count);

    cout << "Sorted student names (ascending):" << endl;
    for (int i = 0; i < count; i++) {
        cout << names[i] << endl;
    }

    return 0;
}
