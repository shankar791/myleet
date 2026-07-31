class Solution {
public:
    Node* add(Node* head, int i) {
        for (int j = 0; j < i; j++) {
            head = head->next;
        }
        return head;
    }

    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        Node* original[1000];
        int x = 0;

        Node* temp = head;
        while (temp != NULL) {
            original[x++] = temp;
            temp = temp->next;
        }

        Node* coppy = new Node(head->val);
        Node* firstcoppy = coppy;

        temp = head->next;

        while (temp != NULL) {
            coppy->next = new Node(temp->val);
            coppy = coppy->next;
            temp = temp->next;
        }

        coppy = firstcoppy;
        temp = head;

        while (temp != NULL) {
            coppy->random = temp->random;
            temp = temp->next;
            coppy = coppy->next;
        }

        coppy = firstcoppy;

        while (coppy != NULL) {
            if (coppy->random != NULL) {
                for (int i = 0; i < x; i++) {
                    if (coppy->random == original[i]) {
                        coppy->random = add(firstcoppy, i);
                        break;
                    }
                }
            }
            coppy = coppy->next;
        }

        return firstcoppy;
    }
};