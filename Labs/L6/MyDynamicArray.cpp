#include <iostream>

using namespace std;

class MyDynamicArray {
    private:
        int size, capacity, error;
        int *a;
    public:
         MyDynamicArray() {
            /* Your code goes here */
            size = 0;
            capacity = 2;
            a = new int[capacity];
            // ERROR? //
            error = 0;
        }
        MyDynamicArray(int s) {
            /* Your code goes here */
            capacity = s;
            size = s;
            a = new int[s];
            error = 0;

        }
        int& operator[](int i){
            /* Your code goes here */
            if (i>size)
            {
                cout << "Out of bounds reference :" << i << endl;
                return error;
            } else {
                return a[i];
            }
            
        }
        void add(int v) {
            /* Your code goes here */
            if(size<capacity)
            {
                a[size] = v;
                size++;
                return;
            }
                cout << "Doubling to : " << capacity * 2 << endl;
                int* temp = new int[capacity*2];
                for (int i = 0;i<capacity;i++)
                {
                    temp[i] = a[i];
                }
                capacity *=2;
                temp[size] = v;
                size++;

                delete[] a;

                a = temp;

        }
        void del() {
            /* Your code goes here */
            size--;
         
           if ( size <= (.25) * capacity )
           {
           
             int new_capacity = (.5) * capacity;
           
             cout << "Reducing to :" << new_capacity << endl;

             int *temp = new int[ new_capacity ];
           
             for ( int i = 0 ; i < size ; i++ )
              *(temp + i) = *(a + i);
            
            capacity = new_capacity;
          
            free(a);
            a = temp;
           }
        }
        int length() {
            return size;
        }
        void clear() {
            delete[] a;
            capacity = 2;
            size = 0;
            a = new int[capacity];
        }
        ~MyDynamicArray() {
            cout << "In the destructor" << endl;
            delete[] a;
        }
        MyDynamicArray& operator=(const MyDynamicArray& src) {
           /* Your code goes here */
           cout << "In the copy assignment operator" << endl;
          capacity= src.capacity;
          size = src.size;
          error = src.error;
          free(a);
          
          a = new int[capacity];
          
          for (int i=0;i<size;i++)
            a[i] = src.a[i];
        }
        
        MyDynamicArray(const MyDynamicArray & src) {
           /* Your code goes here */
           cout << "In the copy constructor" << endl;
           size = src.size; 
           error = src.error;
           capacity = src.capacity;

           int *temp = new int[capacity];
           for(int i=0;i<size;i++)
           {
               temp[i] = src.a[i];
           }
           a = temp;

        }
};

