#include "dnode.hpp"
#include "data_structures/abstract/ilist.hpp"

template <typename T>
class DoublyLinkedList : public IList<T> {
public:
    DoublyLinkedList() : IList<T>() {
        dummy = new DNode<T>();
        dummy->next = dummy;
        dummy->prev = dummy;
    }
    virtual ~DoublyLinkedList();

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
    DNode<T> *dummy;
    using IList<T>::size;
};

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T item) {
    DNode<T>* node = new DNode<T>(item);

    // Link the new node with the dummy node and the first node
    node->next = dummy->next;
    node->prev = dummy;
    dummy->next->prev = node;
    dummy->next = node;

    size++;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T item) {
    DNode<T>* node = new DNode<T>(item);

    // Link the new node with the last node and the dummy node
    node->next = dummy;
    node->prev = dummy->prev;
    dummy->prev->next = node;
    dummy->prev = node;

    size++;
}

template<typename T>
T DoublyLinkedList<T>::pop_front() {
    if(size == 0) {
        throw std::underflow_error("LinkList has no items.");
    }

    DNode<T>* temp = dummy->next;
    T data = temp->data;

    // Update dummy-next (head)
    dummy->next = temp->next;
    dummy->next->prev = dummy;

    delete temp;
    --size;
    return data;
}

template<typename T>
T DoublyLinkedList<T>::pop_back() {
    if(size == 0) {
        throw std::underflow_error("LinkList has no items.");
    }
    DNode<T>* temp = dummy->prev;
    T data = temp->data;

    // Update dummy->prev (tail)
    dummy->prev = temp->prev;
    dummy->prev->next = dummy;
    delete temp;
    --size;
    return data;

}

template<typename T>
T& DoublyLinkedList<T>::get(size_t index) const {
    assert((index >= 0)&& (index < size));
    DNode<T>* curr = dummy->next;
    for (size_t i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}

template<typename T>
T& DoublyLinkedList<T>::operator[] (size_t index) {
    return get(index);
}

template<typename T>
std::optional<T> DoublyLinkedList<T>::front() const {
    return (size > 0) ? std::optional<T>{get(0)} : std::nullopt;
}

template<typename T>
std::optional<T> DoublyLinkedList<T>::back() const {
    return (size > 0) ? std::optional<T>{get(size - 1)} : std::nullopt;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
    DNode<T>* curr = dummy->next;
    while (curr != dummy) {
        DNode<T>* next = curr->next;
        delete curr;
        curr = next;
        size--;
    }
}
