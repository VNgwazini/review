#include <iostream>
#include <string.h>

class LinkedList
{
    private:
        struct Node
        {
            public:
                int id;
                char name[25];
                struct Node *prev, *next;
        };
    public:
        struct Node *root = NULL;

        struct Node *makeNode(int id, char name[])
        {
            struct Node *temp = new Node;
            temp->id = id;
            strcpy(temp->name, name);
            temp->next = NULL;
            temp->prev = NULL;
            
        }
        void addFront(struct Node *aNode, int id, char name[])
        {
            if(root == NULL)
            {
                root = makeNode(id, name);
            }
            aNode = makeNode(id, name);
            aNode->next = root;
            root->prev = aNode;
            root = aNode;
        }
        struct Node *find(int id)
        {
            struct Node *itr = root;
            while(itr != NULL){
                if(itr->id == id){
                    std::cout << "Found: " << itr->id << std::endl;
                    return itr;
                }
                else{
                    itr = itr->next;
                }
            }
            return NULL;
        }
        void insertAt(int key, int id, char name[])
        {
            struct Node *itr = find(key);
            struct Node *temp = makeNode(id, name);
            temp->next = itr->next;
            temp->prev = itr;
            itr->next->prev = temp;
            itr->next = temp;
            itr = temp;
        }
        void remove(int id)
        {
            struct Node *itr = find(id);
            if(itr != NULL){
                itr->prev->next = itr->next;
                itr->next->prev = itr->prev;
                delete itr;
            }
        }
        void print(struct Node *aNode)
        {
            if(aNode == NULL){
                std::cout << "Empty!!!" << std::endl;
                return;
            }
            struct Node *itr = aNode;
            while(itr != NULL){
                std::cout << itr->id << ", " << itr->name << "   -->   ";
                itr = itr->next;
            }
            std::cout << "End of list!!!\n";
        }
};

int main()
{
    LinkedList listy;
    listy.addFront(NULL, 5, "Magic");
    listy.addFront(NULL, 4, "Kobe");
    listy.addFront(NULL, 3, "Lebron");
    listy.addFront(NULL, 2, "Larry");
    listy.addFront(NULL, 1, "Micheal");

    listy.print(listy.root);
    listy.remove(3);
    listy.print(listy.root);
    listy.insertAt(2,3, "Shaq");
    listy.print(listy.root);



    


    return 0;
}