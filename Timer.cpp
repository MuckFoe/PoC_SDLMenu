#include "Timer.hpp"

// Konstruktor
//
// Aufgabe: Initialisierung
//
CTimer::CTimer ()
{
	// Initialisierung  --> SDL getticks zählt milisekunden seit initialisierung der SDL /1000 um in sekunden
	m_fCurTime  = 0.0f; //aktuelle zeit
	m_fLastTime = SDL_GetTicks() / 1000.0f; // Zeit des letzten frames
	m_fElapsed  = 0.0f;		// Zeit vergangen seit dem letzten frame

}


// Update
//
// Aufgabe: Timer updaten
//
void CTimer::Update ()
{
	// Vergangene Zeit seit dem letzten Frame berechnen
	m_fCurTime = SDL_GetTicks() / 1000.0f; //zeit seit letztem aufruf update

	m_fElapsed = m_fCurTime - m_fLastTime; 
	m_fLastTime = m_fCurTime; //zeit des letzten frames updaten

} // Update
