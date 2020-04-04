#include "Framework.hpp"

// Konstruktor
//
// Aufgabe: Allgemeine Initialisierungen
//
CFramework::CFramework()
{
	m_pWindow = NULL;
	m_pRenderer = NULL;

} // Konstruktor


// Init
//
// Aufgabe: Framework initialisieren
//
bool CFramework::Init (int ScreenWidth, int ScreenHeight,
					   int ColorDepth, bool bFullscreen)
{
	// Alle Systeme der SDL initialisieren
	if (SDL_Init (SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1 ) //initialisiert video und timer der sdl
	{
		cout << "SDL konnte nicht initialisiert werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;

		Quit ();

		return (false);
	}

	Uint32 WindowFlags = 0;

	// Vollbild oder Fenstermodus?
	if (bFullscreen == true)
		WindowFlags = SDL_WINDOW_FULLSCREEN;
	else
		WindowFlags = SDL_WINDOW_SHOWN;

    m_pWindow = SDL_CreateWindow("SDL_Game", // name des fesnters
                                 SDL_WINDOWPOS_UNDEFINED, //wo dargestellt
                                 SDL_WINDOWPOS_UNDEFINED, // -"-
                                 ScreenWidth, //breite
                                 ScreenHeight, // höhe
								 WindowFlags); // wie oben entschieden

	// Prüfen ob alles funktioniert hat
	if (m_pWindow == NULL)
	{
		cout << "SDL-Fenster konnte nicht erzeugt werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;

		Quit ();

		return (false);
	}
	
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0); //zur darfstellung, regelt alles selbst

	// Prüfen ob alles funktioniert hat
	if (m_pRenderer == NULL)
	{
		cout << "SDL-Renderer konnte nicht erzeugt werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError() << endl;

		Quit();

		return (false);
	}
    
	// Zeiger auf internes Array für Tastaturstatus ermitteln
	m_pKeystate = SDL_GetKeyboardState (NULL);

	// Alles ging glatt, also true zurückliefern
	return (true);

} // Init


// Quit
//
// Aufgabe: Framework (SDL) beenden
//
void CFramework::Quit ()
{
	// Renderer und Fenster freigeben
	if (m_pRenderer != NULL)
	{
		SDL_DestroyRenderer(m_pRenderer);
	}

	if (m_pWindow != NULL)
	{
		SDL_DestroyWindow(m_pWindow);
	}
		
	// SDL beenden
	SDL_Quit ();

} // Quit


// Update
//
// Aufgabe: Timer und Keyboardstatus updaten
//
void CFramework::Update ()
{
	// Timer updaten
	g_pTimer->Update (); //g_pTimer ist singleton für erstellen eines Timers auf heap auf den gepointed wird

	// Tastaturstatus ermitteln
	SDL_PumpEvents ();

} // Update


// Keydown
//
// Aufgabe: Tastendruck abfragen
//
bool CFramework::KeyDown (int Key_ID) // ID übergeben und antwort erhalten ob gedrückt oder nicht
{
    // Prüfen ob Taste gedrückt ist
	return (m_pKeystate[Key_ID] ? true : false);

} // KeyDown


// Clear
//
// Aufgabe: Buffer löschen
//
void CFramework::Clear ()
{
	// Buffer (Surface) mit Hintergrundfarbe füllen
    SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(m_pRenderer);

} // Clear


// Render
//
// Aufgabe: Spiel rendern
//
void CFramework::Render ()
{
	// Rendern
    SDL_RenderPresent(m_pRenderer);

} // Flip

