#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int i,n,grades[5]={50,66,70,80,95};
    ofstream f("grades.txt");
    if (!f) {
        cout << "Error creating grades.txt!" << endl;
        return 1;
    }
    for (i=0;i<5;i++) {
        f<<grades[i]<<endl;
    }
    f.close();
    ifstream t("grades.txt");
    if (!t) {
        cout << "Error opening grades.txt!" << endl;
        return 1;
    }

    int grade;
    cout << "Grades before deletion" << endl;
    while (t >> grade) {
        cout << grade << endl;
    }
    t.close();
    cout << "\nEnter grade to delete: ";
    cin >> n;

    ifstream readGrades("grades.txt");
    ofstream tempFile("temp.txt");
    if (!readGrades || !tempFile) {
        cout << "Error opening files during deletion!" << endl;
        return 1;
    }
    bool found = false;
    while (readGrades >> grade) {
        if (grade != n) {
            tempFile << grade << endl;
        } else {
            found = true;
        }
    }
    readGrades.close();
    tempFile.close();
    ofstream outTrunc("grades.txt", ios::trunc);
    ifstream readTemp("temp.txt");
    if (!outTrunc || !readTemp) {
        cout << "Error updating grades.txt with trunc!" << endl;
        return 1;
    }

    while (readTemp >> grade) {
        outTrunc << grade << endl;
    }
    readTemp.close();
    outTrunc.close();

    if (found) {
        cout << "Grade " << n << " deleted successfully and grades.txt updated." << endl;
    } else {
        cout << "Grade " << n << " not found, grades.txt updated." << endl;
    }
    ifstream afterDelete("grades.txt");
    if (afterDelete) {
        cout << "\nGrades after deletion" << endl;
        while (afterDelete >> grade) {
            cout << grade << endl;
        }
        afterDelete.close();
    }

    return 0;
}