#ifndef MAP_HPP_
#define MAP_HPP_

#include <iostream>
#include <vector>
#include <utility>

template<typename Key_T, typename Mapped_T>
class Map
{
    public:
        Map();
        Map(const Map&);
        Map &operator=(const Map &);
        Map(std::initializer_list<std::pair<const Key_T, Mapped_T> >);
        ~Map();
        size_t size() const;
        bool empty() const;
        
    private:
        struct Node {
            Key_T key;
            Mapped_T val;

            std::vector<Node> nextNode;
        };
        size_t numElements;
};

#endif
