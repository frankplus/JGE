#include "GameApp.h"
#include "Polygon.h"

#define NUM_POLYGONS 100

JRenderer* GameApp::mRenderer = NULL;

Polygon *polygons;

GameApp::GameApp()
{
    mRenderer = JRenderer::GetInstance();
    polygons = new Polygon[NUM_POLYGONS];
}

GameApp::~GameApp()
{

}

void GameApp::Create()
{
}

void GameApp::Destroy()
{

}

void GameApp::Update()
{
	JGE* engine = JGE::GetInstance();	
	float dt = engine->GetDelta();

    for(int i=0; i<NUM_POLYGONS; i++)
        polygons[i].Update(dt);
}

void GameApp::Render()
{
    mRenderer->ClearScreen(ARGB(255,255,255,255));

    for(int i=0; i<NUM_POLYGONS; i++)
        polygons[i].Render();
}

void GameApp::Pause()
{

}

void GameApp::Resume()
{
    
}