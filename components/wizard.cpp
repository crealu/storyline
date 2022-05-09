#include <iostream>
#include <string>
#include <SDL2/SDL.h>
using namespace std;

class WizardHat {
public:
  WizardHat();
  ~WizardHat();
  void draw(SDL_Renderer *renderer);

protected:
  SDL_Point point1;
  SDL_Point point2;
  SDL_Point point3;
  SDL_Color *color;
};

WizardHat::WizardHat(SDL_Color color) {
  SDL_Point p1 = {400, 150};
  SDL_Point p2 = {415, 125};
  SDL_Point p3 = {430, 150};

  point1 = p1;
  point2 = p2;
  point3 = p3;

  color = color;
}

WizardHat::~WizardHat() {}

void WizardHat::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
  SDL_RenderDrawLine(renderer, point1.x, point1.y, point2.x, point2.y);
  SDL_RenderDrawLine(renderer, point2.x, point2.y, point3.x, point3.y);
  SDL_RenderDrawLine(renderer, point3.x, point3.y, point1.x, point1.y);
}

class Wizard {
public:
  Wizard();
  ~Wizard();
  void draw(SDL_Renderer *renderer);
  int getX();
  int getY();

protected:
  WizardHat *wizardHat;
  SDL_Rect pRect;
  string name;
  SDL_Color *color;
};

Wizard::Wizard(SDL_Color color) {
  SDL_Rect rect = {400, 150, 30, 30};
  pRect = rect;
  wizardHat = new WizardHat(color);
  color = color;
  name = "Wizard";
};

Wizard::~Wizard() {}

void Wizard::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
  SDL_RenderFillRect(renderer, &pRect);
  wizardHat->draw(renderer);
}

int Wizard::getX() {
  return pRect.x;
}

int Wizard::getY() {
  return pRect.y;
}
