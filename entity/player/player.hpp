#include <iostream>
//#include <string>
//#include <SDL2/SDL.h>
#include "../../sound/chunk/chunk.cpp"

class Player {
public:
  Player();
  ~Player();
  void setActiveScreen(World activeScreen);
  void handleInput(SDL_Event &event);
  void draw(SDL_Renderer *renderer);
  void move(int key);
  void stop(int key);
  void talk(int key);
  void pickup(int key);
  void enter(int key);
  void update();
  bool getVicinity(pos entityPosition);
  World screen;

private:
  SDL_Rect rect[3];
  int xVel;
  int yVel;
  int vel;
  string name;
  Chunk *beep;
};
