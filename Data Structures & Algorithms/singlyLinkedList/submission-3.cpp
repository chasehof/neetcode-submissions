class LinkedList {
public:
    LinkedList() : head(nullptr), tail(nullptr) {

    }

    int get(int index) {

        if(index >= size) {
            return -1;
        }

        Node* node{head};

        for(int i = 0; i < index; i++){
            node = node->next;
        }

        return node->val;

    }

    void insertHead(int val) {
        Node* new_head = new Node;
        if(size > 0){
            new_head->next = head;
        } 
        else{

            new_head->next = nullptr;
            tail = new_head;
        }

        new_head->val = val;

        head = new_head;
        size++;
        
    }
    
    void insertTail(int val) {
        Node* new_tail = new Node;
        if(size > 0){
            tail->next = new_tail;
            new_tail->next = nullptr;
        } 
        else{

            new_tail->next = nullptr;
            head = new_tail;
        }

        new_tail->val = val;

        tail = new_tail;
        size++;

    }

    bool remove(int index) {
if (index >= size) {
        return false;
    }

    // Edge Case: Removing the very first node
    if (index == 0) {
        Node* temp = head;    // Remember the old head address
        head = head->next;    // Move head down the line
        delete temp;          // Free the old head from the heap!
        
        if (size == 1) {      // If that was the only node, tail is now dead too
            tail = nullptr;
        }
        size--;
        return true;
    }

    // General Case: Find the node BEFORE the one we want to delete
    Node* node{head};
    for (int i = 0; i < index - 1; i++) {
        node = node->next;
    }

    Node* target = node->next;   // This is the actual node targeted for death
    node->next = target->next;   // Bypass it!
    
    // Edge Case: If we just deleted the tail node, update our tail pointer
    if (target == tail) {
        tail = node;
    }

    delete target;               // Free the targeted node from the heap!
    size--;
    return true;
    }

    vector<int> getValues() {
        if(size < 1){
            return std::vector<int>{};
        }
        Node* node{head};
        std::vector<int> ret{};
        while(node){
            ret.push_back(node->val);

            node = node->next;
        }

        return ret;
        
    }

    private:

    struct Node {
        Node* next; 
        int val;
    };

    Node* head;
    Node* tail;
    size_t size{0};
};
