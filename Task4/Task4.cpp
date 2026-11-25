#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct Person {
    string name;
    int age;
};
int main()
{
    int n;
    cin >> n;
    ofstream out("persons.txt");
    for (int i = 0; i < n; i++) {
        Person p;
        cin >> p.name >> p.age;
        out << p.name << " " << p.age << "\n";
    }
    out.close();
    ifstream in("persons.txt");
    vector<Person> v;
    Person temp;
    while (in >> temp.name >> temp.age) {
        v.push_back(temp);
    }
    in.close();
    ofstream res("results.txt");
    if (!v.empty()) {
        Person younger = v[0], older = v[0];
        for (size_t i = 1; i < v.size(); i++) {
            if (v[i].age < younger.age) younger = v[i];
            if (v[i].age > older.age) older = v[i];
        }
        res << "Younger: " << younger.name << " " << younger.age << "\n";
        res << "Older: " << older.name << " " << older.age << "\n";
    }
    res.close();

    return 0;
}
