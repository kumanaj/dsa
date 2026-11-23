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

    explicit DynamicArray(size_t initial_capacity) :
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

    void insert_at(size_t index, const T& item) {
        assert(index <= count);
        // Copy first: item may refer to an element of arr (e.g. insert_at(0, arr[2])),
        // which the shift below or resize() would overwrite or free.
        T value = item;
        if (count == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        for (size_t j = count; j > index; j--) {
            arr[j] = arr[j-1];
        }
        arr[index] = value;
        count++;
    }

    void remove_at(size_t index) {
        assert(index < count);
        for (size_t j = index; j < count - 1; j++) {
            arr[j] = arr[j + 1];
        }
        count--;

        // Halve when only a quarter full. Halving (not quartering) leaves room to grow again
        // without an immediate resize, and the floor keeps capacity from shrinking to 0.
        if (capacity > DEFAULT_CAPACITY && count <= capacity / 4) {
            resize(capacity / 2);
        }
    }

    void push_front(const T& item) {
        insert_at(0, item);
    }

    // TODO: not implemented yet
    void push_back(const T& item) {
        throw std::logic_error("DynamicArray::push_back not implemented");
    }

    T pop_front() {
        if (count == 0) {
            throw std::underflow_error("DynamicArray has no items.");
        }
        T data = arr[0];
        remove_at(0);
        return data;
    }

    T pop_back() {
        if (count == 0) {
            throw std::underflow_error("DynamicArray has no items.");
        }
        T data = arr[count - 1];
        remove_at(count - 1);   // goes through remove_at so it shrinks like pop_front
        return data;
    }

    T& get(size_t index) {
        assert(index < count);
        return arr[index];
    }

    const T& get(size_t index) const {
        assert(index < count);
        return arr[index];
    }

    T& operator[](size_t index) {
        return get(index);
    }

    const T& operator[](size_t index) const {
        return get(index);
    }

    // TODO: not implemented yet
    std::optional<T> front() const {
        throw std::logic_error("DynamicArray::front not implemented");
    }

    // TODO: not implemented yet
    std::optional<T> back() const {
        throw std::logic_error("DynamicArray::back not implemented");
    }

    // TODO: not implemented yet
    void clear() {
        throw std::logic_error("DynamicArray::clear not implemented");
    }

private:
    T* arr;
    size_t capacity;
    size_t count;
    static constexpr size_t DEFAULT_CAPACITY = 8;

    // TODO: not implemented yet
    // Allocate new_capacity slots, copy the elements over, free the old array.
    void resize(size_t new_capacity) {
        throw std::logic_error("DynamicArray::resize not implemented");
    }
};
