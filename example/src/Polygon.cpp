#include "Polygon.h"

float RandomFloat(float min, float max)
{
	if(max>min){
		float temp = min;
		min = max;
		max = temp;
	}
    float random = ((float) rand()) / (float) RAND_MAX;

    float range = max - min;  
    return (random*range) + min;
}

Polygon::Polygon()
{
    mRenderer = JRenderer::GetInstance();

    x = RandomFloat(0, SCREEN_WIDTH_F);
    y = RandomFloat(0, SCREEN_HEIGHT_F);
    vx = RandomFloat(-50, 50);
    vy = RandomFloat(-50, 50);

    edges = 1+rand()%8;
    color = ARGB(255, rand()%255, rand()%255, rand()%255);
}

void Polygon::Render()
{
    mRenderer->FillPolygon(x, y, 20, edges, 0, color);
}

void Polygon::Update(float dt)
{
    x += dt*vx;
    y += dt*vy;

    if(x > SCREEN_WIDTH_F) vx = -abs(vx);
    if(y > SCREEN_HEIGHT_F) vy = -abs(vy);
    if(x < 0) vx = abs(vx);
    if(y < 0) vy = abs(vy);
}