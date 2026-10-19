/*
 * Course: COEN 2220 - Programming 2
 * Name: [Your Name]
 * Lab: Lab 9 - Linked Lists
 * Description: Practice - a linked list of study groups
 * Due date: [Date]
 */

#include <iostream>
#include <string>
using namespace std;

class StudyGroupList
{
private:
    // ===== Resolve these TODOs now (Part C) =====

    // TODO (Part C): Define a Node with string groupCode, int meetingRoom, and Node *next.
    struct node 
    {
        string groupCode; // Store one study group code.
        int meetingRoom;  // Store the meeting room number.
        node *next;       // Store the address of the next node.
    }; // <-- Faltaba este punto y coma aquí

    // TODO (Part C): Declare a Node *head data member for the first node address.
    node *head; // Store the first node address or nullptr.

    // TODO (Part C): Declare an int groupCount data member for the number of stored groups.
    int groupCount; // Store the number of stored groups.

public:
    // TODO (Part C): Write a constructor that creates an empty list and sets groupCount to zero.
    StudyGroupList() // <-- Se quitó "struct"
    {
        head = nullptr;  // A new list begins with no nodes.
        groupCount = 0;  // Initialize groupCount to zero.
    }

    // ===== Resolve these TODOs later (Part D) =====

    // TODO (Part D): Write addGroup. It receives a group code and room number, adds one node at the end, and updates groupCount.
    void addGroup(const string& newGroupCode, int newMeetingRoom)
    {
        node *newNode = new node; // <-- Cambiado de Node a node (minúscula)
        newNode->groupCode = newGroupCode;
        newNode->meetingRoom = newMeetingRoom;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            groupCount++;
            return;
        }

        node *currentNode = head;

        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }

        currentNode->next = newNode;
        groupCount++;
    }

    // TODO (Part D): Write displayGroups as a const member function.
    void displayGroups() const
    {
        node *currentNode = head;

        while (currentNode != nullptr)
        {
            cout << "Study group: " << currentNode->groupCode 
                 << " | Room: " << currentNode->meetingRoom << endl;
            currentNode = currentNode->next;
        }
    }

    // TODO (Part D): Write size as a const member function that returns groupCount.
    int size() const
    {
        return groupCount;
    }

    // ===== Resolve these TODOs later (Part E) =====

    // TODO (Part E): Write containsGroup as a const member function that searches by group code.
    bool containsGroup(const string& targetGroupCode) const
    {
        node *currentNode = head;

        while (currentNode != nullptr)
        {
            if (currentNode->groupCode == targetGroupCode)
            {
                return true;
            }

            currentNode = currentNode->next;
        }

        return false;
    }
};

int main()
{
    cout << boolalpha;

    // ===== Resolve these TODOs later (Part E) =====

    // TODO (Part E): Create a StudyGroupList object.
    StudyGroupList myStudyGroups; // <-- StudyGroupList con S mayúscula

    // TODO (Part E): Add three dummy groups with different codes and room numbers.
    myStudyGroups.addGroup("SG-101", 201);
    myStudyGroups.addGroup("SG-102", 202);
    myStudyGroups.addGroup("SG-103", 203);

    // TODO (Part E): Display every stored group and print the result of size().
    myStudyGroups.displayGroups();
    cout << "Number of study groups: " << myStudyGroups.size() << endl;

    // TODO (Part E): Search for one stored group code and one missing group code; print both bool results.
    cout << "Contains SG-102: " << myStudyGroups.containsGroup("SG-102") << endl;
    cout << "Contains SG-999: " << myStudyGroups.containsGroup("SG-999") << endl;

    return 0;
}