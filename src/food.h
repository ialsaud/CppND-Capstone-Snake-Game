#ifndef FOOD_H
#define FOOD_H

#include <vector>
#include <random>
#include <unordered_map>
#include "SDL.h"

// custom tuple 
// ref:https://stackoverflow.com/questions/17016175/c-unordered-map-using-a-custom-class-type-as-the-key
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

// overrides default functions for the custom tuple
// ref:https://stackoverflow.com/questions/17016175/c-unordered-map-using-a-custom-class-type-as-the-key
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

struct Bool_Default{
  bool value = false;
};


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
  // void add(int x, int y);
  bool foodCell(int x, int y);
  bool foodCell(Hashed_Tuple tempt);

  int foodCount();
  std::size_t operator()(const std::tuple<int, int>& k) const;
  std::vector<SDL_Point> cells;

 private:
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  
  std::unordered_map<Hashed_Tuple, Bool_Default> cellMap;

  int grid_width;
  int grid_height;
};

#endif