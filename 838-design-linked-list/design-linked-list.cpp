class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };

    Node* head;
    int size;

    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;

        Node* curr = head;
        for (int i = 0; i < index; i++)
            curr = curr->next;

        return curr->val;
    }

    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        size++;
    }

    void addAtTail(int val) {
        Node* node = new Node(val);

        if (head == nullptr) {
            head = node;
        } else {
            Node* curr = head;
            while (curr->next != nullptr)
                curr = curr->next;
            curr->next = node;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* node = new Node(val);
        Node* curr = head;

        for (int i = 0; i < index - 1; i++)
            curr = curr->next;

        node->next = curr->next;
        curr->next = node;

        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        Node* curr = head;
        for (int i = 0; i < index - 1; i++)
            curr = curr->next;

        Node* temp = curr->next;
        curr->next = temp->next;

        delete temp;
        size--;
    }
};
