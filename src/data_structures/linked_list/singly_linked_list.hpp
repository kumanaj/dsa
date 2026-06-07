#include "node.hpp"
#include "data_structures/abstract/ilist.hpp"


template <typename T>
class SinglyLinkedList : public IList<T> {
public:
    SinglyLinkedList() : IList<T>(), head(nullptr) { }
     virtual ~SinglyLinkedList();

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
    Node<T> *head;
    using IList<T>::size;
};

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

template<typename T>
void SinglyLinkedList<T>::push_front(const T item) {
    Node<T>* node = new Node<T>(item); //We can use Node<T>(std::move(item)) here...
    node->next = head;
    head = node;
    size++;
}

template<typename T>
void SinglyLinkedList<T>::push_back(const T item) {
    Node<T>* node = new Node<T>(item);
    if (!head) {
        head = node;
    } else {
        Node<T>* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = node;
    }
    size++;
}

template<typename T>
T SinglyLinkedList<T>::pop_front() {
    if(!head || (size == 0)) {
        throw std::underflow_error("LinkList has no items.");
    }
    Node<T>* temp = head;
    head = head->next;
    T data = temp->data;
    delete temp;
    --size;
    return data;
}

template<typename T>
T SinglyLinkedList<T>::pop_back() {
    assert(head && (size > 0));
    T data;
    if (head->next == nullptr) {
        data = head->data;
        delete head;
        head = nullptr;
    } else {
        Node<T>* curr = head;
        while (curr->next->next) {
            curr = curr->next;
        }
        data = curr->next->data;
        delete curr->next;
        curr->next = nullptr;
    }
    size--;
    return data;

}

template<typename T>
T& SinglyLinkedList<T>::get(size_t index) const {
    assert((index >= 0)&& (index < size));
    Node<T>* curr = head;
    for (size_t i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}

template<typename T>
T& SinglyLinkedList<T>::operator[] (size_t index) {
    return get(index);
}

template<typename T>
std::optional<T> SinglyLinkedList<T>::front() const {
    return (size > 0) ? std::optional<T>{get(0)} : std::nullopt;
}

template<typename T>
std::optional<T> SinglyLinkedList<T>::back() const {
    return (size > 0) ? std::optional<T>{get(size - 1)} : std::nullopt;
}

template<typename T>
void SinglyLinkedList<T>::clear() {
    Node<T>* curr = head;
    while (curr != nullptr) {
        Node<T>* next = curr->next;
        delete curr;
        curr = next;
        size--;
    }
    head = nullptr;
}

