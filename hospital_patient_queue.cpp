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
