#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

// Function to validate email format
bool Emailcheck(const string &email) {
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}

class Student {
private:
    string name, roll_no, course, address, email_id;
    long long contact_no;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleteRecord();

private:
    void validateEmail(string &email);
    void validateContact(long long &contact);
};

// Function to validate email input
void Student::validateEmail(string &email) {
    while (true) {
        cout << "\t\t\tEnter Email Id (name@gmail.com): ";
        cin >> email;
        if (Emailcheck(email)) {
            cout << "\t\t\tYour Email-Id is Valid\n";
            break;
        } else {
            cout << "\t\t\tInvalid Email-Id. Please Try Again.\n";
        }
    }
}

// Function to validate contact number input
void Student::validateContact(long long &contact) {
    while (true) {
        cout << "\t\t\tEnter Contact No (10 digits): ";
        cin >> contact;
        if (contact >= 1000000000 && contact <= 9999999999) {
            break;
        } else {
            cout << "\t\t\tInvalid Contact Number. Please Enter Exactly 10 Digits.\n";
        }
    }
}

// Menu function
void Student::menu() {
    while (true) {
        system("cls");
        int choice;
        cout << "\t\t\t-----------------------------\n";
        cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |\n";
        cout << "\t\t\t-----------------------------\n";
        cout << "\t\t\t1. Enter New Record\n";
        cout << "\t\t\t2. Display Records\n";
        cout << "\t\t\t3. Modify Record\n";
        cout << "\t\t\t4. Search Record\n";
        cout << "\t\t\t5. Delete Record\n";
        cout << "\t\t\t6. Exit\n";
        cout << "Choose Option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                modify();
                break;
            case 4:
                search();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                cout << "\n\t\t\tExiting Program...\n";
                return;
            default:
                cout << "\n\t\t\tInvalid Choice. Please Try Again.\n";
        }
        system("pause");
    }
}

// Insert new record
void Student::insert() {
    system("cls");
    fstream file;
    cout << "\n------------------------------------- Add Student Details ---------------------------------------------\n";
    cin.ignore();
    cout << "\t\t\tEnter Name: ";
    getline(cin, name);
    cout << "\t\t\tEnter Roll No.: ";
    cin >> roll_no;
    cout << "\t\t\tEnter Course: ";
    cin >> course;
    validateEmail(email_id);
    validateContact(contact_no);
    cin.ignore();
    cout << "\t\t\tEnter Address: ";
    getline(cin, address);

    file.open("studentRecord.txt", ios::app);
    file << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
    file.close();

    cout << "\n\t\t\tStudent Record Added Successfully.\n";
}

// Display all records
void Student::display() {
    system("cls");
    fstream file;
    cout << "\n------------------------------------- Student Record Table --------------------------------------------\n";
    file.open("studentRecord.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\tNo Data is Present.\n";
    } else {
        int total = 0;
        while (file >> name >> roll_no >> course >> email_id >> contact_no >> address) {
            cout << "\n\t\t\tStudent No.: " << ++total << "\n";
            cout << "\t\t\tName: " << name << "\n";
            cout << "\t\t\tRoll No.: " << roll_no << "\n";
            cout << "\t\t\tCourse: " << course << "\n";
            cout << "\t\t\tEmail Id: " << email_id << "\n";
            cout << "\t\t\tContact No.: " << contact_no << "\n";
            cout << "\t\t\tAddress: " << address << "\n";
        }
        if (total == 0) {
            cout << "\n\t\t\tNo Data is Present.\n";
        }
    }
    file.close();
}

// Modify a record
void Student::modify() {
    system("cls");
    fstream file, tempFile;
    string rollno;
    int found = 0;
    cout << "\n------------------------------------- Modify Student Details ------------------------------------------\n";
    file.open("studentRecord.txt", ios::in);
    tempFile.open("temp.txt", ios::out);
    if (!file) {
        cout << "\n\t\t\tNo Data is Present.\n";
    } else {
        cout << "\t\t\tEnter Roll No. of Student to Modify: ";
        cin >> rollno;
        while (file >> name >> roll_no >> course >> email_id >> contact_no >> address) {
            if (rollno == roll_no) {
                found = 1;
                cin.ignore();
                cout << "\t\t\tEnter New Name: ";
                getline(cin, name);
                cout << "\t\t\tEnter New Roll No.: ";
                cin >> roll_no;
                cout << "\t\t\tEnter New Course: ";
                cin >> course;
                validateEmail(email_id);
                validateContact(contact_no);
                cin.ignore();
                cout << "\t\t\tEnter New Address: ";
                getline(cin, address);

                tempFile << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
                cout << "\n\t\t\tRecord Modified Successfully.\n";
            } else {
                tempFile << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
        }
        if (!found) {
            cout << "\n\t\t\tStudent Roll No. Not Found.\n";
        }
    }
    file.close();
    tempFile.close();
    remove("studentRecord.txt");
    rename("temp.txt", "studentRecord.txt");
}

// Search a record
void Student::search() {
    system("cls");
    fstream file;
    string rollno;
    int found = 0;
    cout << "\n------------------------------------- Search Student Details -------------------------------------------\n";
    file.open("studentRecord.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\tNo Data is Present.\n";
    } else {
        cout << "\t\t\tEnter Roll No. to Search: ";
        cin >> rollno;
        while (file >> name >> roll_no >> course >> email_id >> contact_no >> address) {
            if (rollno == roll_no) {
                cout << "\n\t\t\tName: " << name << "\n";
                cout << "\t\t\tRoll No.: " << roll_no << "\n";
                cout << "\t\t\tCourse: " << course << "\n";
                cout << "\t\t\tEmail Id: " << email_id << "\n";
                cout << "\t\t\tContact No.: " << contact_no << "\n";
                cout << "\t\t\tAddress: " << address << "\n";
                found = 1;
                break;
            }
        }
        if (!found) {
            cout << "\n\t\t\tStudent Roll No. Not Found.\n";
        }
    }
    file.close();
}

// Delete a record
void Student::deleteRecord() {
    system("cls");
    fstream file, tempFile;
    string rollno;
    int found = 0;
    cout << "\n------------------------------------- Delete Student Details ------------------------------------------\n";
    file.open("studentRecord.txt", ios::in);
    tempFile.open("temp.txt", ios::out);
    if (!file) {
        cout << "\n\t\t\tNo Data is Present.\n";
    } else {
        cout << "\t\t\tEnter Roll No. of Student to Delete: ";
        cin >> rollno;
        while (file >> name >> roll_no >> course >> email_id >> contact_no >> address) {
            if (rollno == roll_no) {
                found = 1;
                cout << "\n\t\t\tRecord Deleted Successfully.\n";
            } else {
                tempFile << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
        }
        if (!found) {
            cout << "\n\t\t\tStudent Roll No. Not Found.\n";
        }
    }
    file.close();
    tempFile.close();
    remove("studentRecord.txt");
    rename("temp.txt", "studentRecord.txt");
}

// Main function
int main() {
    Student project;
    project.menu();
    return 0;
}
