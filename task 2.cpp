#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Patient {
    int patientID;
    string name;
    int age;
    string disease;
    int roomNumber;
    Patient* next;  
};
void addPatient(Patient*& head);
void searchPatient(Patient* head);
void displayPatients(Patient* head);
void saveToFile(Patient* head);
void loadFromFile(Patient*& head);
void deleteList(Patient* head);
int main() {
    Patient* patientList = nullptr;  
    loadFromFile(patientList);  
    int choice;
      while (true) {
        cout << "\nHospital Patient Management System\n";
        cout << "1. Add new patient\n";
        cout << "2. Search for a patient by Patient ID\n";
        cout << "3. Display all patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
       switch (choice) {
            case 1:
                addPatient(patientList);
                break;
            case 2:
                searchPatient(patientList);
                break;
            case 3:
                displayPatients(patientList);
                break;
            case 4:
                saveToFile(patientList);
                deleteList(patientList);  
                cout << "Exiting the system...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
void addPatient(Patient*& head) {
    int id, age, room;
    string name, disease;

    cout << "Enter Patient ID: ";
    cin >> id;
    cin.ignore(); 
cout << "Enter Patient Name: ";
    getline(cin, name);

    cout << "Enter Patient Age: ";
    cin >> age;
    cin.ignore();  
 cout << "Enter Disease: ";
    getline(cin, disease);
cout << "Enter Room Number: ";
    cin >> room;
    Patient* newPatient = new Patient;
    newPatient->patientID = id;
    newPatient->name = name;
    newPatient->age = age;
    newPatient->disease = disease;
    newPatient->roomNumber = room;
    newPatient->next = head;  
    head = newPatient;  
    cout << "Patient added successfully!\n";
}
void searchPatient(Patient* head) {
    int id;
    cout << "Enter Patient ID to search: ";
    cin >> id;
    bool found = false;
    Patient* current = head;
    while (current != nullptr) {
        if (current->patientID == id) {
            cout << "Patient found!\n";
            cout << "Patient ID: " << current->patientID << "\n";
            cout << "Name: " << current->name << "\n";
            cout << "Age: " << current->age << "\n";
            cout << "Disease: " << current->disease << "\n";
            cout << "Room Number: " << current->roomNumber << "\n";
            found = true;
            break;
        }
        current = current->next;
    }
   if (!found) {
        cout << "Patient with ID " << id << " not found.\n";
    }
}
void displayPatients(Patient* head) {
    if (head == nullptr) {
        cout << "No patients in the hospital.\n";
        return;
    }
 cout << "\nList of Patients in the Hospital:\n";
    Patient* current = head;
    while (current != nullptr) {
        cout << "Patient ID: " << current->patientID << "\n";
        cout << "Name: " << current->name << "\n";
        cout << "Age: " << current->age << "\n";
        cout << "Disease: " << current->disease << "\n";
        cout << "Room Number: " << current->roomNumber << "\n";
        cout << "-----------------------------------\n";
        current = current->next;
    }
}
void saveToFile(Patient* head) {
    ofstream outFile("patients.txt", ios::out);
    if (outFile) {
        Patient* current = head;
        while (current != nullptr) {
            outFile << current->patientID << "\n" << current->name << "\n" << current->age << "\n" << current->disease << "\n" << current->roomNumber << "\n";
            current = current->next;
        }
        cout << "Patient data saved successfully.\n";
    } else {
        cout << "Error saving data.\n";
    }
}
void loadFromFile(Patient*& head) {
    ifstream inFile("patients.txt", ios::in);
    if (inFile) {
        int id, age, room;
        string name, disease;

        while (inFile >> id) {
            inFile.ignore();  
            getline(inFile, name);
            inFile >> age;
            inFile.ignore(); 
            getline(inFile, disease);
            inFile >> room;
            inFile.ignore(); 
            Patient* newPatient = new Patient;
            newPatient->patientID = id;
            newPatient->name = name;
            newPatient->age = age;
            newPatient->disease = disease;
            newPatient->roomNumber = room;
            newPatient->next = head;
            head = newPatient;
        }
        cout << "Patient data loaded successfully.\n";
    } else {
        cout << "No existing patient data found. Starting fresh.\n";
    }
}
void deleteList(Patient* head) {
    Patient* current = head;
    Patient* nextPatient;

    while (current != nullptr) {
        nextPatient = current->next;
        delete current;
        current = nextPatient;
    }
}