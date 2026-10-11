#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
};

int main() {
    vector<Patient> patients;
    map<int, string> records;
    queue<int> appointments;

    int choice, nextId = 101;

    do {
        cout << "\n1. Register Patient";
        cout << "\n2. Display Patients";
        cout << "\n3. Search Patient";
        cout << "\n4. Add Appointment";
        cout << "\n5. Call Next Patient";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            Patient p;
            p.id = nextId++;

            cout << "Enter name: ";
            cin >> p.name;

            cout << "Enter age: ";
            cin >> p.age;

            patients.push_back(p);
            records[p.id] = p.name;

            cout << "Patient registered. ID: "
                 << p.id << endl;
        }
        else if (choice == 2) {
            for (const auto &p : patients) {
                cout << "ID: " << p.id
                     << " Name: " << p.name
                     << " Age: " << p.age << endl;
            }
        }
        else if (choice == 3) {
            int id;
            cout << "Enter patient ID: ";
            cin >> id;

            auto it = records.find(id);

            if (it != records.end())
                cout << "Patient found: " << it->second << endl;
            else
                cout << "Patient not found.\n";
        }
        else if (choice == 4) {
            int id;
            cout << "Enter patient ID: ";
            cin >> id;

            if (records.count(id)) {
                appointments.push(id);
                cout << "Appointment added.\n";
            } else {
                cout << "Invalid patient ID.\n";
            }
        }
        else if (choice == 5) {
            if (!appointments.empty()) {
                int id = appointments.front();
                appointments.pop();

                cout << "Next patient: "
                     << records[id] << endl;
            } else {
                cout << "No appointments waiting.\n";
            }
        }

    } while (choice != 6);

    return 0;
}
