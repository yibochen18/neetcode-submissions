class LRUCache {
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    Node* head;
    Node* tail;
    //map each key to its node
    unordered_map<int, Node*> cache;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }

    void insert(Node * node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

    void remove(Node * node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    int get(int key) {
        if (cache.contains(key)) {
            //make it most recently used
            remove(cache[key]);
            
            insert(cache[key]);
            return cache[key]->val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            remove(cache[key]);
            cache[key]->val = value;
            insert(cache[key]);
            return;
        }

        Node* newNode = new Node(key,value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > cap) {
            //remove lru
            Node* lru = head->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }

        return;
    }
};
