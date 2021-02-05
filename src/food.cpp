#include "food.h"
#include <cmath>
#include <iostream>





// removes food from a food cell.
void Food::remove(int x, int y){

  Hashed_Tuple tempt(x,y);

  SDL_Point temp;
  temp.x = x;
  temp.y = y;
  // std::cout << "food count:" << cells.size() <<" at point ("<< x<<","<<y<<") being removed.\n";
  int i=0;
  for(auto cell: cells){
    if(cell.x == temp.x || cell.y == temp.y){
      // std::cout << "food #" << i <<" removed\n";

      cells.erase(cells.begin()+i);
      break;
    }
    i++;
  }
  cellMap.at(tempt).value = false;
}

// adds food to a random cell.
void Food::add(){
  SDL_Point temp;
  temp.x = random_w(engine);
  temp.y = random_h(engine);
  // std::cout << "food #" << count <<" added\n";

  cells.push_back(temp);
  Hashed_Tuple tempt(temp.x, temp.y);
  Bool_Default valuet;
  valuet.value = true;
  cellMap.emplace(tempt, valuet);
  return;
}

// void Food::add(int x, int y){
//   SDL_Point temp;
//   temp.x = x;
//   temp.y = y;
  
//   Hashed_Tuple tempt(temp.x, temp.y);
//   Bool_Default valuet;
//   valuet.value = true;
//   if (!foodCell(tempt)) {
//     cells.push_back(temp);
//     cellMap.emplace(tempt, valuet);
//     count++;
//   }

//   return;
// }

// returns if passed in cell has food.
bool Food::foodCell(int x, int y){
  Hashed_Tuple tempt(x, y);

  if (cellMap.find(tempt) == cellMap.end()){
    return false;
  }else{
    return true;
  }
}

bool Food::foodCell(Hashed_Tuple tempt){
  if (cellMap.find(tempt) == cellMap.end()){
    return false;
  }else{
    return true;
  }
}


// returns food count.
int Food::foodCount(){
  return cells.size();
}