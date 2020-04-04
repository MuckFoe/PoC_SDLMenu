#include "Game.hpp"
#include <stack> 

// Konstruktor
//
// Aufgabe: Allgemeine Initialisierungen
//
CGame::CGame()
{
	m_pSpriteBackground = NULL;
	m_pSpriteMenu = NULL;
	m_pCurrentBackground = NULL;

} // Konstruktor


// Init
//
// Aufgabe: Spieler, Hintergrund und Asteroid initialisieren
//
void CGame::Init()
{
	// Hintergrundbild (Sprite) laden
	m_pSpriteBackground = new CSprite;
	m_pSpriteBackground->Load("Data/Background.bmp");

	m_pSpriteMenu = new CSprite();
	m_pSpriteMenu->Load("Data/Menu.bmp");

	m_pCurrentBackground = new CSprite();
	m_pCurrentBackground = m_pSpriteMenu;
	// Spiel läuft
	m_bGameRun = true;
} // Init


// Quit
//
// Aufgabe: Instanzen freigeben
//
void CGame::Quit()
{

	// Hintergrundsprite freigeben
	if (m_pSpriteBackground != NULL)
	{
		delete (m_pSpriteBackground);
		m_pSpriteBackground = NULL;
	}
	if (m_pSpriteMenu != NULL)
	{
		delete(m_pSpriteMenu);
		m_pSpriteMenu = NULL;
	}
} // Quit


// Run
//
// Aufgabe: Hauptschleife des Spiels
//
void CGame::Run()
{
	// Hauptschleife des Spiels durchlaufen
	//

	while (m_bGameRun == true)
	{
		// Events bearbeiten
		ProcessEvents();

		// Framework updaten und Buffer löschen
		g_pFramework->Update();
		g_pFramework->Clear();

		// Hintergrundbild rendern
		m_pCurrentBackground->Render();

		// Spiel darstellen
		g_pFramework->Render();

	}

} // Run

const int BUTTON_WIDTH = 270;
const int BUTTON_HEIGHT = 120;

const int butx = 0;
const int buty = 380;

const int butEndX = 700;
const int butEndY = 280;

const int butStartX = 410;
const int butStartY = 285;


void CGame::handleEvent(SDL_Event* e)
{
	//Get mouse position
	int x, y;
	SDL_GetMouseState(&x, &y);

	//Check if mouse is in button
	bool insideExit = true;
	bool insideStart = true;
	printf("x: %i\n", x);
	printf("y: %i\n", y);


	//Mouse is left of the button
	if (x < butEndX)
	{
		printf("left\n");
		insideExit = false;
	}
	//Mouse is right of the button
	else if (x > butEndX + BUTTON_WIDTH)
	{
		printf("right\n");
		insideExit = false;
	}
	//Mouse above the button
	else if (y < butEndY)
	{
		printf("above\n");
		insideExit = false;
	}
	//Mouse below the button
	else if (y > butEndY + BUTTON_HEIGHT)
	{
		printf("below\n");
		insideExit = false;
	}
	//Mouse is left of the button
	if (x < butStartX)
	{
		printf("left\n");
		insideStart = false;
	}
	//Mouse is right of the button
	else if (x > butStartX + BUTTON_WIDTH)
	{
		printf("right\n");
		insideStart = false;
	}
	//Mouse above the button
	else if (y < butStartY)
	{
		printf("above\n");
		insideStart = false;
	}
	//Mouse below the button
	else if (y > butStartY + BUTTON_HEIGHT)
	{
		printf("below\n");
		insideStart = false;
	}

	if (insideExit) {
		m_bGameRun = false;
	}
	if (insideStart) {
		m_pCurrentBackground = m_pSpriteBackground;
	}

}


// ProcessEvents
//
// Aufgabe: Events bearbeiten
//
void CGame::ProcessEvents()
{
	SDL_Event Event;
	// Gab es ein Event?
	if (SDL_PollEvent(&Event))
	{
		// Ja, also schauen welches
		switch (Event.type)
		{
			// Beenden?
		case (SDL_QUIT):
		{
			m_bGameRun = false;

		} break;


		// Wurde eine Taste gedrückt?
		case (SDL_KEYDOWN):
		{
			switch (Event.key.keysym.sym)
			{
			case (SDLK_ESCAPE):
			{
				// Ja, also Spiel beenden
				m_bGameRun = false;

			} break;

			default:
				break;
			}
		} break;
		case(SDL_MOUSEBUTTONDOWN):
		{
			handleEvent(&Event);
		}break;
		}
	}
}