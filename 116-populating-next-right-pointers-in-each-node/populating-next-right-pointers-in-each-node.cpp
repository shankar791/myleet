class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            Node* prev = NULL;

            for (int i = 0; i < n; i++) {
                Node* temp = q.front();
                q.pop();

                if (prev != NULL)
                    prev->next = temp;

                prev = temp;

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }

            prev->next = NULL;
        }

        return root;
    }
};