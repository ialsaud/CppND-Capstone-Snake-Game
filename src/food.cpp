#include "food.h"
#include <cmath>
#include <iostream>





// removes food from a food cell.
void Food::remove(int x, int y){
  SDL_Point temp;
  temp.x = x;
  temp.y = y;

  for(int i=0; i++; i<count){
    if(cells[i].x == x && cells[i].y == y){
      cells.erase(cells.begin()+i);
      break;
    }
  }

  Hashed_Tuple tempt(x,y);

  cellMap.at(tempt) = false;
  count--;
}

// adds food to a random cell.
void Food::add(){
  SDL_Point temp;
  temp.x = random_w(engine);
  temp.y = random_h(engine);
  cells.push_back(temp);
  Hashed_Tuple tempt(temp.x, temp.y);
  cellMap.emplace(tempt, true);
  count++;
  return;
}

// returns if passed in cell has food.
bool Food::foodCell(int x, int y){
  Hashed_Tuple tempt(x, y);
  return cellMap.at(tempt);
}

// returns food count.
int Food::foodCount(){
  return count;
}