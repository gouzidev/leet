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
    int capacity = 0;
    void printList(DblList *head)
    {
        while (head)
        {
            cout << head->val << " --> ";
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

    DblList *tail = NULL;
    DblList *head = NULL;
    map <int, pair<int, DblList *>> hash;

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

    void remove_node(DblList    *node)
    {
        if (!node)
            return ;
        if (node && !node->prev)
            head = node->next;
        if (node && !node->next)
            tail = node->prev;
        if (node->prev)
            node->prev->next = node->next;
        if (node->next)
            node->next->prev = node->prev;
    }
    
    LRUCache(int capacity)
    {
        this->capacity = capacity;   
    }
    
    int get(int key)
    {
        if (hash.find(key) == hash.end())
            return -1;
        DblList *oldNode = hash.find(key)->second.second;
        add_front(new DblList(key, oldNode->val));
        remove_node(oldNode);
        return head->val;
    }
    
    void put(int key, int value)
    {
        if (capacity)
        {
            if (hash.find(key) != hash.end()) // if node exists // remove and add it to top
            {
                DblList *oldNode = hash.find(key)->second.second;
                DblList *newNode = new DblList(key, oldNode->val);
                add_front(newNode);
                remove_node(oldNode);
                hash[key] = {value, newNode};
            }
            else
            {
                DblList *oldNode = hash.find(key)->second.second;
                DblList *newNode = new DblList(key, value);
                add_front(new DblList(key, value));
                hash[key] = {value, newNode};
            }
            capacity--;
        }
        else
        {
            DblList *oldNode = hash.find(key)->second.second;
            hash[tail->key] = {-1, 0};
            remove_node(tail);
            add_front(new DblList(key, value));
        }
    }
};

int main()
{
    LRUCache lRUCache = LRUCache(2);
    lRUCache.put(1, 1);
    lRUCache.put(2, 2);
    lRUCache.put(3, 3);
    cout << " -> " << lRUCache.get(1) << endl;
    cout << " -> " << lRUCache.get(2) << endl;
    cout << " -> " << lRUCache.get(3) << endl;
    cout << " -> " << lRUCache.get(4) << endl;
    lRUCache.put(4, 4);
    cout << " -> " << lRUCache.get(1) << endl;
    cout << " -> " << lRUCache.get(2) << endl;
    cout << " -> " << lRUCache.get(3) << endl;
    cout << " -> " << lRUCache.get(4) << endl;
    return 0;
}
