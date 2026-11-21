#pragma once

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <optional>
#include <stdexcept>

template <typename T>
class DynamicArray {
public:
    DynamicArray() :
        arr(new T[DEFAULT_CAPACITY]),
        capacity(DEFAULT_CAPACITY),
        count(0) {}

    DynamicArray(size_t initial_capacity) :
        arr(new T[initial_capacity]),
        capacity(initial_capacity),
        count(0) {}

    ~DynamicArray() {
        delete [] arr;
    }

    // Disable copy constructor (until we provide correct deep copying of arr)
    DynamicArray(const DynamicArray<T>& other) = delete;

    // Disable copy assignment operator (until we provide correct deep copying of arr)
    DynamicArray& operator=(const DynamicArray<T>& other) = delete;

    size_t size() const { return count; }
    bool empty() const { return count == 0; }

    void resize();
    void insert_at(size_t index, const T item);
    void remove_at(size_t index);
    void push_front(const T item);
    void push_back(const T item);
    T pop_front();
    T pop_back();
    T& get(size_t index) const;
    T& operator[] (size_t index);
    std::optional<T> front() const;
    std::optional<T> back() const;
    void clear();

protected:
    T* arr;
    size_t capacity;
    size_t count;
    static constexpr int DEFAULT_CAPACITY = 8;
};

template <typename T>
void DynamicArray<T>::insert_at(size_t index, const T item) {
    assert(index <= count);
    if (count == capacity) {
        resize();
    }
    for (size_t j = count; j > index; j--) {
        arr[j] = arr[j-1];
    }
    arr[index] = item;
    count++;
}

template <typename T>
void DynamicArray<T>::remove_at(size_t index) {
    assert((index >= 0)&& (index < count));
    for (size_t j = index; j < count - 1; j++) {
        arr[j] = arr[j + 1];
    }
    count--;

    if (capacity >= 3 * count) {
        resize();
    }
}

template <typename T>
T& DynamicArray<T>::get(size_t index) const {
    assert((index >= 0)&& (index < count));
    return arr[index];
}

template <typename T>
T& DynamicArray<T>::operator[](size_t index) {
    return arr[index];
}

template <typename T>
void DynamicArray<T>::push_front(const T item) {
    insert_at(0, item);
}

template <typename T>
void DynamicArray<T>::push_back(const T item) {
    throw std::logic_error("DynamicArray::push_back not implemented");
}

template <typename T>
T DynamicArray<T>::pop_front() {
    if (count == 0) {
        throw std::underflow_error("DynamicArray has no items.");
    }
    T data = arr[0];
    remove_at(0);
    return data;
}

template <typename T>
T DynamicArray<T>::pop_back() {
    if (count == 0) {
        throw std::underflow_error("DynamicArray has no items.");
    }
    T data = arr[count - 1];
    count--;
    return data;
}

// TODO: not implemented yet
template <typename T>
void DynamicArray<T>::resize() {
    throw std::logic_error("DynamicArray::resize not implemented");
}

template <typename T>
std::optional<T> DynamicArray<T>::front() const {
    throw std::logic_error("DynamicArray::front not implemented");
}

template <typename T>
std::optional<T> DynamicArray<T>::back() const {
    throw std::logic_error("DynamicArray::back not implemented");
}

template <typename T>
void DynamicArray<T>::clear() {
    throw std::logic_error("DynamicArray::clear not implemented");
}
