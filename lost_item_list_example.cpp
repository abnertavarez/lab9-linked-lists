/*
 * Course: COEN 2220 - Programming 2
 * Name: [Your Name]
 * Lab: Lab 9 - Linked Lists
 * Description: Guided example - a linked list of lost-item codes
 * Due date: [Date]
 */

#include <iostream>
#include <string>
using namespace std;

class LostItemList
{
private:
    struct Node
    {
        string itemCode; // Store one lost-item code.
        Node *next;      // Store the address of the next node.
    };

    Node *head;          // Store the first node address or nullptr.

public:
    LostItemList()
    {
        head = nullptr;  // A new list begins with no nodes.
    }

    bool isEmpty() const
    {
        return head == nullptr; // No first node means the list is empty.
    }

    // --- STEP B2: Add one item at the end ---
    
    void addItem(const string& newItemCode)
    {
        Node *newNode = new Node;
        newNode->itemCode = newItemCode;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *currentNode = head;

        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }

        currentNode->next = newNode;
    }
    

    // --- STEP B3: Traverse and search the list ---
    
    void display() const
    {
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            cout << "Lost item: " << currentNode->itemCode << endl;
            currentNode = currentNode->next;
        }
    }

    bool contains(const string& targetItemCode) const
    {
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            if (currentNode->itemCode == targetItemCode)
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
    cout << boolalpha; // Print bool results as true or false.

    LostItemList lostItems;

    cout << "List starts empty: " << lostItems.isEmpty() << endl;

    // --- STEP B2: Add dummy lost-item codes ---
    
    lostItems.addItem("LF-104");
    lostItems.addItem("LF-215");
    lostItems.addItem("LF-330");

    cout << "List starts empty after additions: "
         << lostItems.isEmpty() << endl;
    

    // --- STEP B3: Display and search stored codes ---
    
    lostItems.display();
    cout << "Contains LF-215: " << lostItems.contains("LF-215") << endl;
    cout << "Contains LF-999: " << lostItems.contains("LF-999") << endl;
    

    return 0;
}

/*
 * Analysis Answers
 *
 * B4 — Appending LF-330
 * When addItem("LF-330") reaches its final assignment, which node does head point to,
 * which node does currentNode point to, and what link is created? Explain why head does
 * not change in this case.
 * Answer: When adding LF-330, head points to the first node (LF-104), currentNode points to the last node (LF-215), and a link is created from LF-215 to LF-330.
 * Head does not change because it always points to the first node in the list, while currentNode traverses to the end of the list to add the new item.
 *
 * B5 — Traversal and linear search
 * What traversal step do display and contains have in common? What is different about
 * the action each function performs at a node, and why may contains stop earlier?
 * Answer: When traversing the list, both display and contains use a while loop to iterate through each node. The difference is that display prints the item code of each node, while contains checks if the item code matches the target.
 *  Contains may stop earlier if it finds a match before reaching the end of the list, while display will always go through all nodes to print their codes.
 *
 */