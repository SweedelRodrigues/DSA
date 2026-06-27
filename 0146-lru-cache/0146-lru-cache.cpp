class LRUCache {
public:
    // Node of Doubly Linked List
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    // Dummy head and tail nodes
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    // key -> address of node in DLL
    unordered_map<int, Node*> m;

    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;

        // Initially:
        // head <-> tail
        head->next = tail;
        tail->prev = head;
    }

    // Insert node right after head
    // (Most Recently Used position)
    void addNode(Node* newNode) {

        Node* oldNext = head->next;

        head->next = newNode;
        newNode->prev = head;

        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    // Remove a node from DLL
    void deleteNode(Node* oldNode) {

        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    int get(int key) {

        // Key not present
        if (m.find(key) == m.end())
            return -1;

        // Node exists
        Node* resNode = m[key];
        int ans = resNode->val;

        // Since accessed, make it MRU
        deleteNode(resNode);
        addNode(resNode);

        return ans;
    }

    void put(int key, int value) {

        // Key already exists
        if (m.find(key) != m.end()) {

            Node* oldNode = m[key];

            deleteNode(oldNode);
            m.erase(key);
        }

        // Cache full
        if (m.size() == capacity) {

            // Node before tail is LRU
            Node* lru = tail->prev;

            m.erase(lru->key);
            deleteNode(lru);
        }

        // Create new node
        Node* newNode = new Node(key, value);

        // Insert at front (MRU position)
        addNode(newNode);

        // Store address in map
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */