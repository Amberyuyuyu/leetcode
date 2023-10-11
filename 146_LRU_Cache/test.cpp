class LRUCache {
public:
    struct Node {
        int key, val;
        Node* prev, * next;
        Node(int k, int v) :key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    unordered_map<int, Node*> mp;
    Node* L, * R;
    int n;
    LRUCache(int capacity) {
        n = capacity;
        L = new Node(-1, -1);
        R = new Node(-1, -1);
        L->next = R;
        R->prev = L;
    }

    int get(int key) {
        if (mp.count(key)) {
            Node* node = mp[key];
            remove(node);
            insert(node->key, node->val);
            return node->val;
        }
        else {
            return -1;
        }

    }

    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            remove(node);
            insert(key, value);
        }
        else {
            if (mp.size() == n) {
                Node* node = L->next;
                remove(node);
                insert(key, value);
            }
            else {
                insert(key, value);
            }
        }
    }
    void remove(Node* node) {
        auto pre = node->prev;
        auto nxt = node->next;
        pre->next = nxt;
        nxt->prev = pre;
        mp.erase(node->key);
    }
    void insert(int key, int val) {
        auto node = new Node(key, val);
        auto pre = R->prev;
        auto nxt = R;
        pre->next = node;
        node->next = nxt;
        nxt->prev = node;
        node->prev = pre;
        mp[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
