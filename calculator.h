#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <math.h>
#include "objects.h"

const float Gravitation = 6.674e-11;

void calculatePosition(const struct planet *p, struct floatObject *obj, const float dt)
{
  float r  = pow(pow(obj->x - p->x, 2) + pow(obj->y - p->y, 2), 0.5f);
  //printf("r: %f\n", r);
  obj->vx -= Gravitation*p->m*(obj->x - p->x)*dt/pow(r, 3);
  //printf("vx: %f\n", obj->vx);
  obj->vy -= Gravitation*p->m*(obj->y - p->y)*dt/pow(r, 3);
  //printf("vy: %f\n", obj->vy);
  obj->x  += obj->vx*dt;
  //printf("x: %f\n", obj->x);
  obj->y  += obj->vy*dt;
  //printf("y: %f\n", obj->y);
}
#endif