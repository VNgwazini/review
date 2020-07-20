#include <iostream>
#include <string.h>

class BinaryHeap
{
    public:
        int capacity;
        int size;
        int *heap = new int[capacity];
        BinaryHeap()
        {
            capacity = 4;
            size = 0;
        }        
        
        int leftChildIndex(int parentIndex)
        {return (2 * parentIndex) + 1;}
        int rightChildIndex(int parentIndex)
        {return (2 * parentIndex) + 2;}
        int parentIndex(int childIndex)
        {return (childIndex - 1) / 2;}
        
        bool hasLeftChild(int parentIndex)
        {return leftChildIndex(parentIndex) < size;}
        bool hasRightChild(int parentIndex)
        {return rightChildIndex(parentIndex) < size;}
        bool hasParent(int childIndex)
        {return parentIndex(childIndex) >= 0;}
        
        int leftChild(int parentIndex)
        {return heap[leftChildIndex(parentIndex)];}
        int rightChild(int parentIndex)
        {return heap[rightChildIndex(parentIndex)];}
        int parent(int childIndex)
        {return heap[parentIndex(childIndex)];}
        
        void heapifyUp()
        {
            int index = size - 1;
            while(hasParent(index) && parent(index) < heap[index])
            {
                swap(parentIndex(index), index);
                index = parentIndex(index);
            }
        }
        void heapifyDown()
        {
            int index = 0;
            while(hasLeftChild(index))
            {
                int biggestChildIndex = leftChildIndex(index);
                if(hasRightChild(index) && rightChild(index) > leftChild(index))
                {
                    biggestChildIndex = rightChildIndex(index);
                }
                if(heap[index] > heap[biggestChildIndex])
                {
                    break;
                }
                else
                {
                    swap(index,biggestChildIndex);
                }
                index = biggestChildIndex;
            }
        }

        void ensureCapacity()
        {
            if(size == capacity)
            {
                int *temp = new int[2 * capacity];
                for(int i = 0; i < capacity; i++)
                {
                    if(i < size)
                    {
                        temp[i] = heap[i];
                    }
                    else
                    {
                        temp[i] = '\000';
                    }
                }
                delete [] heap;
                heap = temp;
                capacity *= 2;
            }
        }

        void insert(int key)
        {
            ensureCapacity();
            int index = size;
            heap[index] = key;
            size++;
            heapifyUp();
        }
        void extractMax()
        {
            int max = heap[0];
            heap[0] = heap[size - 1];
            heap[size - 1] = 0;
            size--;
            heapifyDown();
        }
        void swap(int firstIndex, int secondIndex)
        {
            int temp = heap[firstIndex];
            heap[firstIndex] = heap[secondIndex];
            heap[secondIndex] = temp;
        }

        void printHeap(){
            for(int i = 0; i < capacity; i++){
                std::cout << i << "["<< heap[i] <<"]"<<std::endl;
            }
            std::cout << "========================" <<std::endl;
        }
        void printHorizontaly(){
            for(int i = 0; i < capacity; i++){
                std::cout << "["<< heap[i] <<"]";
            }
            std::cout << "\n";
        }
        void sort()
        {
            int index = capacity - 1;
            printHorizontaly();
            while(size >= 1)
            {
                swap(0,index);
                size--;
                heapifyDown();
                index--;
            }
            printHorizontaly();
        }
};

int main(){

    BinaryHeap myHeap;
    
    myHeap.insert(6);
    myHeap.insert(5);
    myHeap.insert(3);
    myHeap.insert(1);
    myHeap.insert(8);
    myHeap.insert(7);
    myHeap.insert(2);
    myHeap.insert(4);
    myHeap.printHeap();
    myHeap.sort();
    return 0;
}