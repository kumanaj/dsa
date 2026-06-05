#include <optional>

template <typename T>
class IList {
public:
        IList() : size(0) {}

        virtual size_t get_size() cost { 
            return size; 
        }

        virtual bool is_empty() const {
            return size == 0;
        }

        virtual void push_front(const T item) = 0;
        virtual void push_back(const T item) = 0;
        virtual T pop_front() = 0;
        virtual T pop_back() = 0;
        virtual T& get(size_t index) = 0;
        virtual void set(size_t index, const T item) = 0;
        virtual T& operator[] (size_t index) = 0;
        std::optional<T> front() const = 0;
        std::optional<T> back() const = 0;
        virtual void clear() = 0;

protected:
    size_t size;
};