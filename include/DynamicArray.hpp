#pragma once
#include <stdlib.h>

template<typename T>
class DynamicArray {
private:
    T* data;
    size_t size;

public:
    DynamicArray()
        : data(nullptr)
        , size(0) {}

    DynamicArray(int size) {
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
        this->size = size;
    }

    DynamicArray(T* items, int count){
        data = new T[count];
        size = count;
        for (int i = 0; i < count; i++) {
            data[i] = items[i];
        }
    }

    DynamicArray(const DynamicArray<T>& other) {
        data = new T[other.size];
        size = other.size;
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    DynamicArray& operator=(const DynamicArray<T>& other) {
        if (this == &other) {
            return *this;
        }
        if (data) {
            delete []data;
        }

        data = new T[other.size];
        size = other.size;
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }

        return *this;
    }

    ~DynamicArray() {
        delete[] data;
    }

    void Resize(size_t new_size) {
        T* new_data = new T[new_size];
        if (!data) {
            data = new_data;
            size = new_size;
            return;
        }

        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        size = new_size;
    }
    int GetSize() const {
        return size;
    }
    void Set(size_t index, const T& object) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        data[index] = object;
    }
    
    T Get(size_t index) const{
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    DynamicArray<T>* GetSubArray(int start, int end) const{
        if (start < 0 || start >= size || end < start || end > size) {
            throw std::out_of_range("Index out of range");
        }
        DynamicArray<T>* result = new DynamicArray<T>(end - start + 1);
        for (int i = start; i <= end; i++) {
            result->Set(i - start, data[i]);
        }
        return result;
    }
    DynamicArray<T>* Concat(const DynamicArray<T> &other) const{
        DynamicArray<T> result(size + other.size);
        for (int i = 0; i < size; ++i)
            result.Set(i, data[i]);
        for (int i = 0; i < other.size; ++i)
            result.Set(size + i, other.data[i]);   
        return result;
    }

    class Iterator {
    public:
        Iterator(T* data, size_t index, size_t size)
            : data(data)
            , index(index)
            , size(size) {}

        T& operator*() {
            return data[index];
        }

        Iterator& operator++() {
            index++;
            return *this;
        }

        bool operator!=(const Iterator& other) {
            return index != other.index;
        }
        Iterator begin() {
        return Iterator(data, 0, size);
        }

        Iterator end() {
        return Iterator(data, index, size);
        }

    private:
        T* data;
        size_t index;
        size_t size;
    };
};