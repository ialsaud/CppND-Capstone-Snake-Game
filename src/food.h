#ifndef FOOD_H
#define FOOD_H

#include <vector>
#include <random>
#include <unordered_map>
#include "SDL.h"

class Hashed_Tuple {
  public:
  Hashed_Tuple(int x, int y) : _x(x), _y(y){}
  bool operator==(const Hashed_Tuple &other) const
  { 
    return (_x == other._x
          && _y == other._y);
  }
  int _x;
  int _y;
};

namespace std {

  template <>
  struct hash<Hashed_Tuple>
  {
    std::size_t operator()(const Hashed_Tuple& k) const
    {
      // Compute individual hash values for first,
      // second and third and combine them using XOR
      // and bit shifting:

      return ((std::hash<int>()(k._x)
               ^ (std::hash<int>()(k._y) << 1)) >> 1);
    }
  };

}

class Food {
 public:
  Food(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        engine(dev()),
        random_w(0, static_cast<int>(grid_width)),
        random_h(0, static_cast<int>(grid_height)){}

  void remove(int x, int y);
  void add();
  bool foodCell(int x, int y);
  int foodCount();
  std::size_t operator()(const std::tuple<int, int>& k) const;


 private:
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int count=0;
  std::vector<SDL_Point> cells;
  std::unordered_map<Hashed_Tuple, bool> cellMap;

  int grid_width;
  int grid_height;
};

#endif