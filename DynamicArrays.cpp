#include <iostream>
class Arrays{
    public:
        int *arr;
        int getCapacity(){
            return capacity;
        }
        int getSize(){
            return size;
        }
        void resize(int *input){
            capacity = 2 * size;
            arr = new int[capacity];
            for(int i = 0; i < capacity; i++){
                if(i < size){
                    arr[i] = input[i];
                }
                else{
                    arr[i] = '\0';
                }
            }
        }
        void insert(int *input, int inputSize, int pos, int value){
            size = inputSize;
            if(size >= capacity){
                resize(input);
            }
            for(int i = size -1; i >= pos; i--){
                arr[i+1] = arr[i];
            }
            arr[pos] = value;
            size++;
        }
        void remove(int pos){
            for(int i = pos; i < capacity + 1; i++){
                arr[i] = arr[i+1];
            }
            size--;
        }
        int print(int *input, int inputSize){
            for(int i = 0; i < inputSize; i++){
                std::cout << input[i] << "\t";
            }
            std::cout << std::endl;
        }
    private:
        int capacity;
        int size;
};

int main(){
    Arrays arry;
    int size = 5;
    int *data = new int[size]{1,2,3,4,5};
    arry.print(data, size);
    arry.insert(data, size, 0, 999);
    arry.print(arry.arr, arry.getSize());
    arry.remove(0);
    arry.print(arry.arr, arry.getSize());


    return 0;
}