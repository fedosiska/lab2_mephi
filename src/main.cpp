#include <iostream>
#include "../include/MutableArraySequence.hpp"
#include "../include/ListSequence.hpp"

int main() {
    int a[6] = {0, 1, 2, 3, 4, 5};
    MutableArraySequence<int> arr(a , 6);

    ListSequence<double> list;
    list.Append(4.5);
    list.Prepend(3.1);
    std::cout << "First: " << arr.GetFirst() << "\n";
    std::cout << "Last: " << arr.GetLast() << "\n";
    std::cout << "Length: " << arr.GetLength() << "\n";
    std::cout << list.GetFirst()<<"\n";
    std::cout<< list.GetLast()<<"\n";

    for(int i=0; i<arr.GetLength();i++){
        std::cout<<arr.Get(i)<<" ";
    }
}