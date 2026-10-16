#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Node
{
    int patientID;
    string patientName;
    Node* next;
};

Node* front = NULL;
Node* rear =NULL;

// Add a patient to the queue
void enqueue()
{
    Node* newNode = new Node;

    cout << "Enter Patient ID: ";
    if (!(cin >> newNode->patientID))
    {
        cout << "Invalid Patient ID.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        delete newNode;
        return;
    }

    cout << "Enter Patient Name: ";
    cin >> ws;
    getline(cin, newNode->patientName);

    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Patient added successfully!\n";
}

// Remove a patient from the front
void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is empty. No patient to remove.\n";
        return;
    }

    Node* temp = front;

    cout << "Patient removed: "
         << temp->patientID << " - "
         << temp->patientName << '\n';

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    delete temp;
}

// Display all patients
void display()
{
    if (front == NULL)
    {
        cout << "No patients in the waiting queue.\n";
        return;
    }

    Node* temp = front;

    cout << "\nHospital Patient Waiting Queue:\n";

    while (temp != NULL)
    {
        cout << "Patient ID: " << temp->patientID
             << ", Name: " << temp->patientName << '\n';

        temp = temp->next;
    }
}

// Release memory when the program ends
void clearQueue()
{
    while (front != NULL)
    {
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    rear = NULL;
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Hospital Patient Waiting Queue =====\n";
        cout << "1. Enqueue Patient\n";
        cout << "2. Dequeue Patient\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Program ended successfully.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    clearQueue();

    return 0;
}


New program....


#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int id, age;
    string name, address, gender;
    Node* next;
};

Node *front = NULL, *rear = NULL;

void enqueue()
{
    Node* temp = new Node;

    cout << "Enter Patient ID: ";
    cin >> temp->id;

    cout << "Enter Name: ";
    cin >> ws;
    getline(cin, temp->name);

    cout << "Enter Age: ";
    cin >> temp->age;

    cout << "Enter Address: ";
    cin >> ws;
    getline(cin, temp->address);

    cout << "Enter Gender: ";
    getline(cin, temp->gender);

    temp->next = NULL;

    if (rear == NULL)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }

    cout << "Patient added successfully!\n";
}

void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is empty!\n";
        return;
    }

    Node* temp = front;

    cout << "Removed Patient: " << temp->name << endl;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

void display()
{
    Node* temp = front;

    if (temp == NULL)
    {
        cout << "No patients in queue!\n";
        return;
    }

    while (temp != NULL)
    {
        cout << "\nPatient ID: " << temp->id;
        cout << "\nName: " << temp->name;
        cout << "\nAge: " << temp->age;
        cout << "\nAddress: " << temp->address;
        cout << "\nGender: " << temp->gender << endl;

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Add Patient";
        cout << "\n2. Remove Patient";
        cout << "\n3. Display Patients";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: cout << "Program ended."; break;
            default: cout << "Invalid choice!";
        }

    } while (choice != 4);

    return 0;
}