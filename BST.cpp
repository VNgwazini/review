#include <iostream>
#include <string.h>

class BST
{
    public:
        struct Node
        {
            public:
                int id;
                char name[25];
                struct Node *left, *right;
        };
        struct Node *root = NULL;
        struct Node *makeNode(int id, char name[])
        {
            struct Node *temp = new Node;
            temp->id = id;
            strcpy(temp->name, name);
            temp->left = NULL;
            temp->right = NULL;
            return temp;
        }
        struct Node *findMin(struct Node *aNode)
        {
            if(aNode->left == NULL)
            {
                return aNode;
            }
            else
            {
                return findMin(aNode->left);
            }
        }
        struct Node *findByKey(struct Node *aNode, int id)
        {
            if(aNode->id == id)
            {
                std::cout << "Found: " << aNode->name << std::endl;
                return aNode;
            }
            else
            {
                if(id < aNode->id)
                {
                    findByKey(aNode->left, id);
                }
                else
                {
                    findByKey(aNode->right, id);
                }
            }
            return aNode;
        }
        struct Node *insert(struct Node *aNode, int id, char name[])
        {
            if(root == NULL)
            {
                return root = makeNode(id, name);
            }            
            else if(aNode == NULL)
            {
                return makeNode(id, name);
            }
            else{
                if(id < aNode->id)
                {
                    aNode->left = insert(aNode->left, id, name);
                }
                else{
                    aNode->right = insert(aNode->right, id, name);
                }
            }
            return aNode;
        }
        struct Node *removeByKey(struct Node *aNode, int id)
        {
            if(aNode == NULL)
            {
                return NULL;
            }
            else if(id < aNode->id)
            {
                aNode->left = removeByKey(aNode->left, id);
            }
            else if(id > aNode->id)
            {
                aNode->right = removeByKey(aNode->right, id);
            }
            else
            {
                if(aNode->left == NULL && aNode->right == NULL)
                {
                    aNode = NULL;
                }
                else if(aNode->left == NULL)
                {
                    struct Node *temp = aNode->right;
                    delete aNode;
                    aNode = temp;
                }
                else if(aNode->right == NULL)
                {
                    struct Node *temp = aNode->left;
                    delete aNode;
                    aNode = temp;
                }
                else
                {
                    struct Node *temp = findMin(aNode->right);
                    aNode->id = temp->id;
                    strcpy(aNode->name, temp->name);
                    aNode->right = removeByKey(aNode->right, aNode->id);
                }
            }
            return aNode;
        }
        void print(struct Node *aNode)
        {
            if(aNode == NULL)
            {
                return;
            }
            print(aNode->left);
            std::cout << aNode->id << ", " << aNode->name << "   -->   ";
            print(aNode->right);
        }
};

int main()
{
    BST tree;
    tree.insert(tree.root, 35, "Jesus Christ");
    tree.insert(tree.root, 30, "Vusumuzi Ngwazini");
    tree.insert(tree.root, 20, "Madison Ngwazini");
    tree.insert(tree.root, 10, "Nchima Chongwe");
    tree.insert(tree.root, 40, "Kwame Amponsah");
    tree.insert(tree.root, 50, "Malvin Chali");
    tree.insert(tree.root, 60, "Christine Ngwazini");
    tree.print(tree.root);
    std::cout << "End of list!!\n";
    std::cout << "Minimum is: " << tree.findMin(tree.root)->id << ", " << tree.findMin(tree.root)->name << std::endl;
    tree.findByKey(tree.root, 30);
    tree.removeByKey(tree.root, 30);
    tree.print(tree.root);

    return 0;
}