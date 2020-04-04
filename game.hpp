#ifndef GAME_HPP
#define GAME_HPP
#include "Sprite.hpp"


class CGame
{
public:
	CGame();

	void Init();
	void Run();
	void Quit();

private:
	void ProcessEvents();
	void handleEvent(SDL_Event*);

	bool menu;
	CSprite *m_pSpriteBackground;   // Sprite f�r den Hintergrund
	CSprite *m_pSpriteMenu;
	CSprite *m_pCurrentBackground;
	bool     m_bGameRun;            // L�uft das Spiel noch?

};

#endif
