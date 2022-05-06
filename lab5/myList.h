#ifndef ZAD5MYLISTANDSORTING_DLASTUDENTOW_MYLIST_H
#define ZAD5MYLISTANDSORTING_DLASTUDENTOW_MYLIST_H

#include <memory>
#include <stdexcept>


template<typename T>
class MyList {
public:
    class Node {
        public:
            explicit Node(T);
            ~Node();
        public:
            T data{};
            std::unique_ptr<MyList::Node> next = nullptr;
    };

    class Iterator: public std::iterator<std::random_access_iterator_tag, T>{
        public:
            Iterator() noexcept: current_node(nullptr){};
            explicit Iterator(const std::unique_ptr<MyList::Node> &node) noexcept : current_node(node.get()){};
            ~Iterator() = default;
            Iterator &operator++() noexcept;
            Iterator operator++(int) noexcept;
            bool operator!=(const Iterator &other) const noexcept;
            T operator*() const noexcept;
            Iterator begin() const noexcept;
            Iterator end() const noexcept;
        private:
            const Node *previous_node = nullptr;
            const Node *current_node = nullptr;
    };

    std::unique_ptr<MyList::Node> head = nullptr;
public:
    MyList();
    MyList(const MyList<T> &other) noexcept;
    MyList(MyList<T> &&other) noexcept;
    ~MyList();
    void clear() noexcept;
    [[nodiscard]] std::size_t size() const;
    void push_front(T value);
    auto & pop_front();
    auto & front();
    MyList<T> &operator=(const MyList &other) noexcept;
    MyList<T> &operator=(MyList &&other) noexcept;
    Iterator begin() const noexcept;
    Iterator end() const noexcept;
private:
    std::size_t size_ = 0;
};

template<typename T>
typename MyList<T>::Iterator &MyList<T>::Iterator::operator++() noexcept {
    if (current_node != nullptr)
    {
        previous_node = current_node;
        current_node = current_node->next.get();
    }
    return *this;
}

template<typename T>
typename MyList<T>::Iterator MyList<T>::Iterator::operator++(int) noexcept {
    Iterator tempIter = *this;
    ++*this;
    return tempIter;
}

template<typename T>
bool MyList<T>::Iterator::operator!=(const MyList::Iterator &other) const noexcept {
    return this->current_node != other.current_node;
}

template<typename T>
T MyList<T>::Iterator::operator*() const noexcept {
    return this->current_node->data;
}

template<typename T>
typename MyList<T>::Iterator MyList<T>::Iterator::begin() const noexcept {
    return Iterator(this->head);
}

template<typename T>
typename MyList<T>::Iterator MyList<T>::Iterator::end() const noexcept {
    return MyList::Iterator();
}

template<typename T>
MyList<T>::Node::Node(const T data): data(data) {}

template<typename T>
MyList<T>::Node::~Node() = default;

template<typename T>
MyList<T>::MyList() {
    head = nullptr;
    size_ = 0;
}

template<typename T>
MyList<T>::~MyList() = default;

template<typename T>
size_t MyList<T>::size() const{
    return size_;
}

template<typename T>
void MyList<T>::push_front(const T value) {
    if (size_ == 0) {
        head = std::make_unique<Node>(value, nullptr);
    }
    else {
        std::unique_ptr<MyList::Node> new_node = std::make_unique<Node>(value, nullptr);
        new_node->next = std::move(head);
        head = std::move(new_node);
    }
    size_++;
}

template<typename T>
auto & MyList<T>::pop_front() {
    if (head == NULL) throw std::out_of_range("No elements in list");
    std::unique_ptr<MyList::Node> old_head = head;
    head = std::move(head->next);
    size_--;
    return old_head;
}

template<typename T>
auto &MyList<T>::front() {
    return head;
}

template<typename T>
MyList<T>::MyList(const MyList<T> &other) noexcept {
    if (other.head == nullptr)
        return;

    head = std::make_unique<Node>(other.head->data);
    Node *current = head.get();
    size_ = 1;

    Node *otherCurrent = other.head->next.get();
    while (otherCurrent != nullptr)
    {
        current->next = std::make_unique<Node>(otherCurrent->data);
        otherCurrent = otherCurrent->next.get();
        current = current->next.get();
        size_++;
    }
}

template<typename T>
MyList<T> &MyList<T>::operator=(const MyList &other) noexcept {
    MyList<T> tempList(other);
    head.swap(tempList.head);
    std::swap(size_, tempList.size_);
    return *this;
}

template<typename T>
MyList<T>::MyList(MyList<T> &&other) noexcept {
    head.swap(other.head);
    size_ = other.size_;

    other.head = nullptr;
    other.size = 0;
}

template<typename T>
MyList<T> &MyList<T>::operator=(MyList &&other) noexcept {
    this->clear();

    head.swap(other.head);
    size_ = other.size_;

    other.head = nullptr;
}

template<typename T>
void MyList<T>::clear() noexcept {
    if (size_ > 0)
    {
        Node *current = head.get();
        while (current != nullptr)
        {
            Node *temp = current;
            temp = nullptr;
            current = current->next.get();
        }
        head = nullptr;
        size_ = 0;
    }
}

template<typename T>
typename MyList<T>::Iterator MyList<T>::begin() const noexcept {
    return MyList::Iterator(this->head);
}

template<typename T>
typename MyList<T>::Iterator MyList<T>::end() const noexcept {
    return MyList::Iterator();
}


#endif //ZAD5MYLISTANDSORTING_DLASTUDENTOW_MYLIST_H
