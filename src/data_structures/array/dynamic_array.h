#include <algorithm>
#include "data_structures/abstract/ilist.hpp"

template <typename T>
class DynamicArray : public IList<T> {
public:
    DynamicArray() : 
        IList<T>(), 
        arr(new T[DEFAULT_CAPACITY]),
        capacity(DEFAULT_CAPACITY) {}

    DynamicArray(size_t initial_capacity) :
        IList<T>(),
        arr(new T[initial_capacity]),
        capacity(initial_capacity) {}

    virtual ~DynamicArray() {
        delete [] arr;
    }

    // Disable copy constructor (until we provide correct deep copying of arr)
    DynamicArray(const DynamicArray<T>& other) = delete;

    // Disable copy assignment operator (until we provide correct deep copying of arr)
    DynamicArray& operator=(const DynamicArray<T>& other) = delete;

    // DynamicArray Interface methods
    virtual void resize();

    // IList Interface methods
    virtual void insert_at(size_t index, const T item);
    virtual void remove_at(size_t index);
    virtual void push_front(const T item);
    virtual void push_back(const T item);
    virtual T pop_front();
    virtual T pop_back();
    virtual T& get(size_t index) const;
    virtual T& operator[] (size_t index);
    virtual std::optional<T> front() const;
    virtual std::optional<T> back() const;
    virtual void clear();
    
protected:
    T* arr;
    size_t capacity;
    using IList<T>::size;
    static constexpr int DEFAULT_CAPACITY = 8;
};

template <typename T>
void DynamicArray<T>::insert_at(size_t index, const T item) {
    assert((index >= 0)&& (index < size));
    if (size == capacity) {
        resize();
    }
    for (size_t j = size; j > i; j--) {
        arr[j] = arr[j-1];
    }
    arr[j] = item;
    size++;
}

template <typename T>
void DynamicArray<T>::remove_at(size_t index) {
    assert((index >= 0)&& (index < size));
    for (size_t j = i; j < size - 1; j++) {
        arr[j] = arr[j + 1];
    }
    size--;

    if (capacity >= 3 * size) {
        resize();
    }
}

template <typename T>
T& DynamicArray<T>::get(size_t index) const {
    assert((index >= 0)&& (index < size));
    return arr[i];
}

template <typename T>
T& DynamicArray<T>::operator[](size_t index) {
    return arr[i];
}

template <typename T>
void DynamicArray<T>::push_front(const T item) {
    insert_at(0, item);
}

template <typename T>
void DynamicArray<T>::push_back(const T item) {
    assert((index >= 0)&& (index < size));
}

template <typename T>
T DynamicArray<T>::pop_front() {
    assert(size > 0);
    T& data = arr[0];
    remove_at(0);
    return data;
}

template <typename T>
T DynamicArray<T>::pop_back() {
    assert(size > 0);
    T& data = arr[size - 1];
    size--;
    return data;
}