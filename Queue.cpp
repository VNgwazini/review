#include <iostream>
#include <string.h>

class Queue
{
    private:
        struct Node
        {
            public:
                int id;
                char name[25];
                struct Node *next;
        };

        struct Node *head = NULL, *tail = NULL;

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
        {   struct Node *temp = makeNode(id, name);
            if(head == NULL)
            {
                head = temp;
            }
            else if(tail == NULL)
            {
                head->next = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }
        void pop()
        {
            if(head != NULL)
            {
                struct Node *temp = head;
                delete head;
                head = temp->next;
            }
            else
            {
                std::cout << "End of queue!\n";
                return;
            }
        }

        void print()
        {
            struct Node *itr = head;

            if(itr != NULL)
            {
                while(itr != NULL)
                {
                    std::cout << itr->name << " ---> ";
                    itr = itr->next;
                }
            }
            std::cout << "End of queue!\n";
            return;
        }
};

int main()
{
    Queue queuey;
    queuey.push(1, "Magic Johnson");
    queuey.push(2, "Kobe Bryant");
    queuey.push(3, "Lebron James");
    queuey.push(4, "Larry Bird");
    queuey.push(5, "Micheal Jordan");
    queuey.print();
    queuey.pop();
    queuey.print();    
    queuey.pop();
    queuey.print();    
    queuey.pop();
    queuey.print();    
    queuey.pop();
    queuey.print();      
    queuey.pop();
    queuey.print();  

    return 0;
}