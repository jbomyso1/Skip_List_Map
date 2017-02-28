#ifndef MAP_HPP_
#define MAP_HPP_

#include <iostream>
#include <vector>
#include <utility>

template<typename Key_T, typename Mapped_T>
class Map
{
    public:
        typedef std::pair<const Key_T, Mapped_T> value_type;
        struct SNode {
            SNode *next, *prev;
        };
  
        struct Node: public SNode {
            Node(value_type);
            std::vector<Node> forward;
        };
  
        // create empty map
        Map(): numElements(0), node(nullptr) {};
  
        // Copy Constructor
        Map(const Map &mp) {
            Node ptr = new Node;
            *ptr = *mp.node;
        };
       
        // Copy assignment operator 
        Map &operator=(const Map &mp) {
            if(&mp == this)
                return *this;

            std::copy(
        };


        Map(std::initializer_list<std::pair<const Key_T, Mapped_T> >);
        ~Map();
        size_t size() const;
        bool empty() const;
        
    private:
        Node* node;
        size_t numElements;
};

#endif
