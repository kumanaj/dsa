/*#include "node.hpp"
#include "data_structures/abstract/ilist.hpp"

template <typename T>
class DoublyLinkedList : public IList<T> {
public:
    DoublyLinkedList() : IList<T>(), head(nullptr) { }
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
    Node<T> *head;
    using IList<T>::size;
};*/