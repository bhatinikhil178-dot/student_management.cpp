#include <iostream> 
using namespace std;

class Student
{
public:
    int rollNo;
    string name;
    float marks;
};

Student s[100];
int countStudent = 0;

// Add Student
void addStudent()
{
    cout << "\nEnter Roll Number: ";
    cin >> s[countStudent].rollNo;

    cout << "Enter Name: ";
    cin >> s[countStudent].name;

    cout << "Enter Marks: ";
    cin >> s[countStudent].marks;

    countStudent++;

    cout << "\nStudent Added Successfully!\n";
}

// Display Students
void displayStudents()
{
    if (countStudent == 0)
    {
        cout << "\nNo Student Records Found!\n";
        return;
    }

    cout << "\n===== Student Records =====\n";

    for (int i = 0; i < countStudent; i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Roll Number : " << s[i].rollNo << endl;
        cout << "Name        : " << s[i].name << endl;
        cout << "Marks       : " << s[i].marks << endl;
        cout << "--------------------------\n";
    }
}

// Search Student
void searchStudent()
{
    int roll;
    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    for (int i = 0; i < countStudent; i++)
    {
        if (s[i].rollNo == roll)
        {
            cout << "\nStudent Found!\n";
            cout << "Roll Number : " << s[i].rollNo << endl;
            cout << "Name        : " << s[i].name << endl;
            cout << "Marks       : " << s[i].marks << endl;
            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

// Delete Student
void deleteStudent()
{
    int roll;
    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;

    for (int i = 0; i < countStudent; i++)
    {
        if (s[i].rollNo == roll)
        {
            for (int j = i; j < countStudent - 1; j++)
            {
                s[j] = s[j + 1];
            }

            countStudent--;

            cout << "\nStudent Deleted Successfully!\n";
            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            deleteStudent();
            break;

        case 5:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while (choice != 5);

    return 0;
}