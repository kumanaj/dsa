#include "singly_linked_list.hpp"

template <typename T>
class SinglyLinkedListTailed : public SinglyLinkedList<T> {
public:
    SinglyLinkedListTailed() : SinglyLinkedList<T>(), tail(nullptr) { }
    virtual ~SinglyLinkedListTailed();

    virtual void push_front(const T item);
    virtual void push_back(const T item);
    virtual T pop_front();
    virtual T pop_back();
    virtual std::optional<T> back() const;
    virtual void clear();
protected:
    Node<T>* tail;
    using SinglyLinkedList<T>::head;
    using SinglyLinkedList<T>::size;
};

template<typename T>
SinglyLinkedListTailed<T>::~SinglyLinkedListTailed() {
    // is tail = nullptr; sufficient here?!!! since it will call base destructor to clear?!
    clear();
}

template<typename T>
void SinglyLinkedListTailed<T>::push_front(const T item) {
    SinglyLinkedList<T>::push_front(item);
    if (tail == nullptr) {
        tail = head;
    }
}

template<typename T>
void SinglyLinkedListTailed<T>::push_back(const T item) {
    Node<T>* node = new Node<T>(item);
    if (!head) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
    size++;
}

template<typename T>
T SinglyLinkedListTailed<T>::pop_front() {
    T data = SinglyLinkedList<T>::pop_front();
    if (head == nullptr) {
        tail = nullptr;
    }
    return data;
}

template<typename T>
T SinglyLinkedListTailed<T>::pop_back() {
    assert(head && (size > 0));
    T data;
    if (head->next == nullptr) {
        data = head->data;
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node<T>* curr = head;
        while (curr->next->next) { // Traverse to the second-to-last node.
            curr = curr->next;
        }
        data = curr->next->data;
        delete curr->next;
        curr->next = nullptr;
        tail = curr;
    }
    size--;
    return data;

}

template<typename T>
std::optional<T> SinglyLinkedListTailed<T>::back() const {
    if (tail) return tail->data;
    return std::nullopt;
}

template<typename T>
void SinglyLinkedListTailed<T>::clear() {
    SinglyLinkedList<T>::clear();
    tail = nullptr;
}