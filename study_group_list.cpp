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
        Node *next;       // Store the address of the next node.
    }
    // TODO (Part C): Declare a Node *head data member for the first node address.
    node *head; // Store the first node address or nullptr.

    // TODO (Part C): Declare an int groupCount data member for the number of stored groups.
    int groupCount; // Store the number of stored groups.

public:
    // TODO (Part C): Write a constructor that creates an empty list and sets groupCount to zero.
struct StudyGroupList()
    {
        head = nullptr;  // A new list begins with no nodes.
        groupCount = 0;  // Initialize groupCount to zero.
    }
    // ===== Resolve these TODOs later (Part D) =====

    // TODO (Part D): Write addGroup. It receives a group code and room number, adds one node at the end, and updates groupCount.
    // TODO (Part D): Write displayGroups as a const member function.
    // TODO (Part D): Write size as a const member function that returns groupCount.

    // ===== Resolve these TODOs later (Part E) =====

    // TODO (Part E): Write containsGroup as a const member function that searches by group code.
};

int main()
{
    cout << boolalpha;

    // ===== Resolve these TODOs later (Part E) =====

    // TODO (Part E): Create a StudyGroupList object.
    // TODO (Part E): Add three dummy groups with different codes and room numbers.
    // TODO (Part E): Display every stored group and print the result of size().
    // TODO (Part E): Search for one stored group code and one missing group code; print both bool results.

    return 0;
}