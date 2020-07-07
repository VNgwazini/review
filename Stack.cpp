#include <iostream>
#include <string.h>

class Stack
{
    private:
        struct Node
        {
            public:
                int id;
                char name[25];
                struct Node *next;
        };

        struct Node *head = NULL;
    public:
        struct Node *makeNode(int id, char name[])
        {
            struct Node *temp = new Node;
            temp->id = id;
            strcpy(temp->name, name);
            temp->next = NULL;
            return temp;
        }

        void push(int id, char name[])
        {
            struct Node *temp = makeNode(id, name);
            if(head == NULL)
            {
                head = temp;
                return;
            }
            else 
            {
                temp->next = head;
                head = temp;
                return;
            }
        }

        void pop()
        {
            if(head == NULL)
            {
                std::cout << "============End of List!==============\n";
                return;
            }
            else
            {
                struct Node *temp = head;
                delete head;
                head = temp->next;
            }
        }

        void print()
        {
            if(head == NULL)
            {
                std::cout << "============End of List!==============\n";
                return;
            }
            else
            {
                struct Node *itr = head;
                while(itr != NULL)
                {
                    std::cout << itr->name << "\n\t|\n\t|\n\tV\n";    
                    itr = itr->next;
                }
                std::cout << "============End of List!==============\n";
                return;
            }
        }

};

int main()
{
    Stack stacky;
    stacky.push(1, "Magic Johnson");
    stacky.push(2, "Kobe Bryant");
    stacky.push(3, "Lebron James");
    stacky.push(4, "Larry Bird");
    stacky.push(5, "Micheal Jordan");
    stacky.print();
    stacky.pop();
    stacky.print();    
    stacky.pop();
    stacky.print();    
    stacky.pop();
    stacky.print();    
    stacky.pop();
    stacky.print();    

    return 0;
}