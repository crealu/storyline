#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

class World {
public:
  World();
  ~World();
  void draw(SDL_Renderer *renderer);

protected:
  int r;
  int g;
  int b;
};

World::World() {

}

World::~World() {}

void World::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 55, 0, 55);
  SDL_RenderClear(renderer);
}
