//implement as doubly linked list
class LRUCache {
private:
    struct Node {
        pair<int,int> keyVal;
        Node* prev;
        Node* next;
        Node(pair<int,int> kv) : keyVal(kv), prev(nullptr), next(nullptr) {} 
    };

    int cap;
    unordered_map<int, Node*> cache;
    Node* head; //head is LRU
    Node* tail; //tail is MRU

    void insert(Node* node){
        node->prev = tail->prev; //put it at the back!
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node({0,0});
        tail = new Node({0,0});

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            // accessing it makes it the most recently used
            // remove node
            remove(cache[key]);
            // insert it again
            insert(cache[key]);
            return cache[key]->keyVal.second;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            //exists
            cache[key]->keyVal.second = value;
            //remove and insert again
            remove(cache[key]);
            insert(cache[key]);
            return; 
        }

        //add new node as the MRU
        Node *newNode = new Node({key, value});
        cache[key] = newNode;
        insert(newNode);

        //eviction if we exceeed capacity
        if (cache.size() > cap) {
            Node* lru = head->next;
            remove(lru);
            cache.erase(lru->keyVal.first);
            delete lru;
        }
    }
};
