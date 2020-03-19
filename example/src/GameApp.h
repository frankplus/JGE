#ifndef _GAMEAPP_H_
#define _GAMEAPP_H_

#include <JApp.h>
#include <JGE.h>
#include <JRenderer.h>


class GameApp:	public JApp
{
private:
	static JRenderer* mRenderer;

public:
	GameApp();
	virtual ~GameApp();
	virtual void Create();
	virtual void Destroy();
	virtual void Update();
	virtual void Render();
	virtual void Pause();
	virtual void Resume();
};

#endif
