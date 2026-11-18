#include <optional>

template <typename N, typename T>
class ITree {
    virtual ITree() {}
    virtual ~ITree() {}

    virtual bool insert(const T) = 0;
    virtual bool remove(const T) = 0;
    virtual N* getRoot() const = 0;
    virtual N* find(const T) const = 0;
    virtual void traverse() const = 0;
    virtual void depth(N *node) const = 0;
    virtual void height() const = 0;
    virtual void size() const = 0;
    virtual void clear() = 0;
};