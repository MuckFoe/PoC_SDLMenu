#define SDL_MAIN_HANDLED

#include "Framework.hpp"
#include "Game.hpp"

int main (int argc, char *argv[])
{
	// Framework initialisieren (ist ein singleton)
	if (g_pFramework->Init (1408, 768, 16, false) == false) // ersten beiden auflösung, dritte farbtiefe, vierte ob fenster (false) oder vollbild (true)
		return (0);

	// Neue Instanz des Spiels
	CGame Game;

	// Spiel initialisieren
	Game.Init ();

	// Spiel laufen lassen. Diese Funktion läuft so lange,
	// bis das Fenster geschlossen oder die Escape-Taste
	// gedrückt wird
	Game.Run ();

	// Spiel beenden
	Game.Quit ();

	// Framework beenden
	g_pFramework->Quit ();
	g_pFramework->Del ();

	return (0);

}