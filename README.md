# Queue-Using-Linked-List
Repository DescriptionQueue Using Linked List is a C++ program that implements a queue data structure using a singly linked list. It demonstrates basic queue operations such as Enqueue, Dequeue, and Display following the FIFO (First In, First Out) principle.



1.problem statement:
Hospitals face significant challenges in managing patient queues efficiently. Static data structures (like standard fixed-size arrays) lead to memory waste or queue overflow when patient intake spikes suddenly. Traditional manual or fixed systems fail to handle real-time queue additions, processing patients on a First-In, First-Out (FIFO) basis, and dynamic cancellations effectively.
This project implements a dynamic Hospital Patient Waiting Queue Management System using a Singly Linked List in C/C++. It dynamically allocates memory for each patient, ensuring zero memory overflow and optimal dynamic space management.

2. Objectives
Dynamic Memory Allocation: Store patient details without fixed queue size restrictions using pointers.
FIFO Processing: Ensure fairness by serving patients in the exact order of their arrival.
Real-time Queue Operations: Allow registration, appointment discharge, search, and queue display seamlessly.
Time & Space Efficiency: Achieve O(1) constant time complexity for enqueuing and dequeuing operations using front and rear pointers.

3. Data Structure Design
Node Structure
Each node represents an individual patient in the queue:
struct PatientNode 
{
    int patientID;
    string name;
    int age;
    string condition;
    PatientNode* next; // Pointer to the next patient in line
};

4. Key Queue Operations

A.Objectives
1. Implement dynamic memory allocation with zero queue overflow.
2. Achieve efficient $O(1)$ Enqueue and Dequeue operations.
3. Serve patients in strict order of arrival (FIFO basis).
4. Provide real-time patient registration and consultation processing.
5. Search patient status in line using a unique Patient ID.
6. Display current waiting queue status in real time.

5. System Algorithms

Step 1: Start the program.

Step 2: Initialize front and rear pointers to NULL.

Step 3: Display the menu with the following options:
Step 4: Accept the user's choice.

Step 5: If the choice is 1 (Enqueue):

A) Create a new node using dynamic memory allocation.

B) Accept the patient ID and patient name.

C) Set the new node's next pointer to NULL.

D) If the queue is empty, set both front and rear to the new node.

E) Otherwise, connect the new node to the current rear node and update rear.

F) Display a success message.

Step 6: If the choice is 2 (Dequeue):
Check whether front is NULL.
If the queue is empty, display an appropriate message.
Otherwise, store the front node in a temporary pointer.
Display the removed patient's details.
Move front to the next node.
If the queue becomes empty, set rear to NULL.
Free the memory of the removed node.

Step 7: If the choice is 3 (Display):
Check whether the queue is empty.
If empty, display a message.
Otherwise, start from front.
Traverse each node until NULL is reached.
Display each patient's ID and name.

Step 8: If the choice is 4, display the exit message and terminate the program.

Step 9: If the choice is invalid, display an error message.

Step 10: Repeat Steps 3–9 until the user selects Exit.

Step 11: Stop the program.


