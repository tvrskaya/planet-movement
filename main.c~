#include <stdio.h>

#include "raylib.h"
#include "calculator.h"
#include "objects.h"

float normalizeCoordinates(float x0, float prevSystem, float newSystem)
{
  float newCoord = x0/prevSystem;
  newCoord *= newSystem;
  return newCoord;
}

int main(void)
{
  const float xWorld = 1e+7;
  const float yWorld = 1e+7;
  
  struct planet p1;
  struct planet p2;
  initPlanet(&p1, 2e+23f, 0, 0);
  initPlanet(&p2, 2e+23f, 3e+6f, 3e+6f);

  struct floatObject obj;
  initObject(&obj, 4.8e+6f, 6.4e+6f, 1.2e+3f, 0);

  const int screenWidth = 800;
  const int screenHeight = 450;
  InitWindow(screenWidth, screenHeight, "window");

  float dt = 0.01f;
  
  float p1X = normalizeCoordinates(p1.x, xWorld, screenWidth);
  float p1Y = normalizeCoordinates(p1.y, yWorld, screenHeight);
  float p2X = normalizeCoordinates(p2.x, xWorld, screenWidth);
  float p2Y = normalizeCoordinates(p2.y, yWorld, screenHeight);

  while(!WindowShouldClose())
  {
    calculatePosition(&p1, &obj, dt);
    calculatePosition(&p2, &obj, dt);
    float objX = normalizeCoordinates(obj.x, xWorld, screenWidth);
    float objY = normalizeCoordinates(obj.y, yWorld, screenHeight);
    
    BeginDrawing();
    
    ClearBackground(RAYWHITE);
    
    DrawCircle(p1X, p1Y, 10, RED);
    DrawCircle(p2X, p2Y, 10, BLUE);
    DrawCircle(objX, objY, 10, GREEN);
    
    EndDrawing();
  }
  
  CloseWindow();

  return 0;
}
