#include <iostream>
#include <string.h>

struct LinkedList
{
    public:
        int id;
        char name[25];
        struct LinkedList *next = NULL;
};

class HashTable
{
    static const int SIZE = 5;
    public:
        struct LinkedList *buckets[SIZE]{NULL};
        int hashFunction(int key)
        {
            return key % SIZE;
        }
        struct LinkedList *makeEntry(int id, char name[])
        {
            struct LinkedList *temp = new LinkedList;
            temp->id = id;
            strcpy(temp->name, name);
            temp->next = NULL;
            return temp;
        }
        void insert(int id, char name[])
        {
            int bucketIndex = hashFunction(id);
            if(buckets[bucketIndex] == NULL)
            {
                buckets[bucketIndex] = makeEntry(id, name);

            }
            else
            {
                struct LinkedList *itr = buckets[bucketIndex];
                while(itr != NULL)
                {
                    if(itr->next == NULL)
                    {
                        itr->next = makeEntry(id, name);
                        break;
                    }
                    else
                    {
                        itr = itr->next;
                    }
                }
            }
        }
        struct LinkedList *find(int key)
        {
            for(int i = 0; i < SIZE;i++)
            {
                if(buckets[i] == NULL)
                {
                    continue;
                }
                else
                {
                    struct LinkedList *itr = buckets[i];
                    while(itr != NULL)
                    {
                        if(key == itr->id)
                        {
                            std::cout << "Found [" <<itr->id<<"-"<<itr->name<<"]\n";
                            return itr;
                        }
                        else
                        {
                            itr = itr->next;
                        }
                    }
                }
            }
            std::cout << "Not Found";
            return NULL;
        }
        void print()
        {
            for(int i = 0; i < SIZE; i++)
            {
                struct LinkedList *itr = buckets[i];
                while(itr != NULL)
                {
                    std::cout << "[" <<itr->id<<"-"<<itr->name<<"]\t--->\t";
                    itr = itr->next; 
                }
                std::cout << "\n";
            }
            std::cout << "======================================'Print Finshed'============================================\n";
        }

};

int main()
{
    HashTable hashy;
    hashy.insert(1000, "Trey");
    hashy.insert(1001, "Magic");
    hashy.insert(1006, "Lebron");
    hashy.insert(1002, "Larry");
    hashy.insert(1003, "Micheal");
    hashy.insert(1004, "Shaq");
    hashy.insert(1011, "Jerry");
    hashy.insert(1009, "Giannis");
    hashy.insert(1005, "Luka");
    hashy.insert(1016, "Kyrie");
    hashy.insert(1014, "Carmelo");
    hashy.insert(1008, "Reggie");
    hashy.print();

    return 0;
}