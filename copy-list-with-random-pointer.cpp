#include "helper.cpp"
#include <iomanip> // For std::hex and std::showbase

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
  
//     Node* copyRandomList(Node* head)
//     {
//         map<Node*, Node*> hash; // old node -> new node
//         Node* curr = head;
//         Node* copy = nullptr;
//         Node* last = nullptr;

//         cout << "Starting to copy the list..." << endl;

//         while (curr)
//         {
//             cout << "\nProcessing Node: " << static_cast<const void*>(curr) 
//                 << " { Val: " << curr->val << " }" << endl;

//             // Create a new node with the same value as the current node
//             Node* newNode = new Node(curr->val);
//             cout << "Created new node: " << static_cast<const void*>(newNode) 
//                 << " { Val: " << newNode->val << " }" << endl;

//             // Handle the random pointer
//             if (curr->random == nullptr) {
//                 newNode->random = nullptr;
//                 cout << "Random pointer is NULL for new node." << endl;
//             } else if (has(hash, curr->random)) { // Random node already exists in the hash map
//                 newNode->random = hash[curr->random];
//                 cout << "Random pointer set to existing node: " 
//                     << static_cast<const void*>(newNode->random) 
//                     << " { Val: " << newNode->random->val << " }" << endl;
//             } else { // Random node is seen for the first time
//                 hash[curr->random] = new Node(curr->random->val);
//                 newNode->random = hash[curr->random];
//                 cout << "Created new random node: " 
//                     << static_cast<const void*>(newNode->random) 
//                     << " { Val: " << newNode->random->val << " }" << endl;
//             }

//             // Add the current node to the hash map if it doesn't exist
//             if (!has(hash, curr))
//             {
//                 hash[curr] = newNode;
//                 cout << "Added current node to hash map: " 
//                     << static_cast<const void*>(curr) << " -> " 
//                     << static_cast<const void*>(newNode) << endl;
//             }

//             // Add the new node to the copied list
//             add_back(&copy, &last, newNode);
//             cout << "Added new node to the copied list." << endl;

//             // Move to the next node
//             curr = curr->next;
//         }

//     cout << "\nFinished copying the list." << endl;
//     return copy;
// }



class Solution {
public:
    bool    has(map<Node *, Node *> m,  Node *node)
    {
        return (m.find(node) != m.end());
    }
    void add_back(Node **head, Node **last, Node *node)
    {
        if ((*head) == NULL)
            *head = node;
        else
            (*last)->next = node;
        *last = node;
    }

    void printList(Node *head)
    {
        while (head)
        {
            std::cout << "Node " << static_cast<const void*>(head) << " { "
                    << "Val: " << head->val << ", "
                    << "Next: ";

            if (head->next) {
                std::cout << static_cast<const void*>(head->next) 
                        << " (" << head->next->val << ")";
            } else {
                std::cout << "NULL";
            }

            std::cout << ", Random: ";

            if (head->random) {
                std::cout << static_cast<const void*>(head->random) 
                        << " (" << head->random->val << ")";
            } else {
                std::cout << "NULL";
            }

            std::cout << " }" << std::endl;
            head = head->next;
        }
    std::cout << std::endl;
    }
    
    Node* copyRandomList(Node* head)
    {
        map<Node*, Node*> hash; // old node -> new node
        Node* curr1 = head;
        Node* curr2 = nullptr;
        Node* copy = nullptr;
        Node* last = nullptr;

        while (curr1)
        {
            Node* newNode = new Node(curr1->val);
            newNode->random = NULL;
            if (!has(hash, curr1))
                hash[curr1] = newNode;
            add_back(&copy, &last, newNode);
            curr1 = curr1->next;
        }
        curr1 = head;
        curr2 = copy;
        while (curr1)
        {
             if (curr1->random == nullptr)
                curr2->random = nullptr;
            else
                curr2->random = hash[curr1->random];
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return copy;
    }

    Node* copyRandomList2(Node* head) {
        map <Node *, Node *> hash; // old node -> new node
        Node *curr = head;
        Node *copy = NULL;
        Node *last = NULL;
        while (curr)
        {
            
            Node *newNode = new Node(curr->val);
            if (!has(hash, curr))
            {
                hash[curr] = newNode;
            }
            if (curr->random == NULL)
                newNode->random = NULL;
            else if (has(hash, curr->random)) // seen this random;
            {
                newNode->random = hash[curr->random];
            }
            else // first time see this random
            {
                hash[curr->random] = new Node(curr->random->val);
                newNode->random = hash[curr->random];
            }
            add_back(&copy, &last, newNode);
            curr = curr->next;
            
        }
        return copy;
    }
};

int main() {
    // Create test cases
    Solution solution;
    Node *h1 = new Node(1);
    Node *h2 = new Node(2);
    Node *h3 = new Node(3);
    h1->next = h2;
    h1->random = NULL;
    h2->next = h3;
    h2->random = h2;
    h3->next = NULL;
    h3->random = h2;
    Node *new_lst = solution.copyRandomList(h1);
    solution.printList(new_lst);
    solution.printList(h1);
    return 0;
}
