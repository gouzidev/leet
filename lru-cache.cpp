#include "helper.cpp"


struct DblList
{
    int key;
    int val;
    DblList *next;
    DblList *prev;
    DblList() : key(0), val(0), next(nullptr), prev(nullptr) {}
    DblList(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    void printList(DblList *head)
    {
        while (head)
        {
            cout << "(" << head->key << ") = " << head->val << "   -->  ";
            head = head->next;
        }
        cout << endl;
    }
    void printRev(DblList *tail)
    {
        while (tail)
        {
            cout << tail->val << " --> ";
            tail = tail->prev;
        }
        cout << endl;
    }
    void add_back(DblList *node)
    {
        if ((head) == NULL)
            head = node;
        else
        {
            (tail)->next = node;
            node->prev = tail;
        }
        tail = node;
    }
    
    void add_front(DblList *node)
    {
        if (head == NULL) // first time
        {
            head = node;
            tail = node;
        }
        else
        {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    bool    node_exists(int key)
    {
        return (hash.find(key) != hash.end());
    }
    void remove_node(DblList    *node)
    {
        if (!node)
            return ;
        if (node->next)
            (node->next)->prev = node->prev;
        if (node->prev)
            (node->prev)->next = node->next;
        if (node == head)
            head = node->next;
        if (node == tail)
            tail = node->prev;
    }
    
    int maxCapacity;  // Rename to avoid confusion
    DblList *tail = NULL;
    DblList *head = NULL;
    unordered_map<int, DblList*> hash;  // Simplified map

    LRUCache(int capacity)
    {
        maxCapacity = capacity;
    }
    int get(int key)
    {
        if (hash.find(key) == hash.end())
            return -1;
        DblList *node = hash.find(key)->second;
        remove_node(node);
        add_front(node);
        return node->val;
    }
    

    
    void put(int key, int value) {
        if (node_exists(key)) {
            DblList *node = hash[key];
            node->val = value;
            remove_node(node);
            add_front(node);
        } else {
            DblList *newNode = new DblList(key, value);
            if (hash.size() >= maxCapacity) {
                // Remove from hash first
                hash.erase(tail->key);
                remove_node(tail);
            }
            add_front(newNode);
            hash[key] = newNode;
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.put(5, 5);       // Cache: [(5,5)]
    cache.put(4, 4);       // Cache: [(4,4), (5,5)]
    cache.get(5);          // Moves 5 to front: [(5,5), (4,4)]
    cache.put(3, 3);       // Evicts 4. Hash marks 4 as -1.
    cout << cache.get(4) << endl;  // Expected: -1
    cache.put(4, 7);       // Evicts 3. Hash marks 3 as -1.
    cout << cache.get(3) << endl;  // Expected: -1
    cout << cache.get(4) << endl;  // Expected: 7
}

