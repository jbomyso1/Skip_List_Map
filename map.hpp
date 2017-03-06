#ifndef MAP_HPP_
#define MAP_HPP_

#include <iostream>
#include <vector>
#include <utility>

struct SNode {
  SNode *next, *prev;
};

template<typename Key_T, typename Mapped_T>
struct Node: SNode {
  Key_T key;
  Mapped_T map_val;
  std::vector<Node*> forward;

  Node (Key_T k, Mapped_T m, int level);
};

template <typename Key_T, typename Mapped_T>
Node<Key_T, Mapped_T>::Node(Key_T k, Mapped_T m, int level): key(k), map_val(m)
{
  for(int i = 0; i < level; i++) forward.emplace_back(nullptr);
}

template<typename Key_T, typename Mapped_T>
class Map
{
public:
  typedef std::pair<const Key_T, Mapped_T> ValueType;

  // empty constructor
  Map():head(nullptr), NIL(nullptr), maxLevel(8), probability(0.5){}

  // copy constructor
  Map(const Map &mp): head(mp.head), NIL(mp.NIL), maxLevel(mp.maxLevel), probability(mp.probability){}

  // copy assignment operator
  Map &operator=(const Map &mp) {
    if(this == mp)
      return *this;

    head = mp.head;
    NIL = mp.NIL;
    maxLevel = mp.maxLevel;
    probability = mp.probability;
    return *this;
  }

  // initializer list constructor
  Map(std::initializer_list<std::pair<const Key_T, Mapped_T> >) {
    
  }
        
private:
  //pointers to first and last nodes
  Node<Key_T, Mapped_T>* head;
  Node<Key_T, Mapped_T>* NIL;
  int maxLevel;
  float probability;
};

#endif
