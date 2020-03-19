/*******************************************************
 * 
 * Copyright (C) 2019 Francesco Pham (pham.francesco@gmail.com)
 * 
 *******************************************************/
#include <stdlib.h>
#include <JTypes.h>
#include <JRenderer.h>

class Polygon
{
private:
    JRenderer* mRenderer;
    float x;
    float y;
    float vx;
    float vy;
    int edges;
    PIXEL_TYPE color;
public:
    Polygon();
    void Render();
    void Update(float dt);
};