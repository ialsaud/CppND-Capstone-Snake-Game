#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  // read and write cool title from /data/title.txt
  std::string title;

  // Read from the text file
  std::cout << "The vicious ..";
  std::ifstream titleFile("../data/title.txt");
  while (getline (titleFile, title)) {std::cout << title << "\n";}
  titleFile.close();
  std::cout << "\t\t.. designed by Ibrahim\n";

  int s_count=0;
  int quit = 1;
  while(quit==1){
    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame);
    std::cout << "========================================\n";
    std::cout << "You Died! his";
    s_count = game.GetScore()/100;
    for(int i=0;i<s_count; i++){
      std::cout << "s";
    }
    s_count = 0;
    std::cout << "s!\n\n";
    std::cout << "Score: " << game.GetScore() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";
    std::cout << "\nWant to try again? (1:yes, 2:no) ";
    quit=2;
    std::cin >> quit;
    std::cout << "========================================\n";
    std::cout << "\n";
    
  }


  return 0;
}