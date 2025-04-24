#include <iostream>
#include <string>
using namespace std;

class jugador 
{
	private:
		string nombreJugador;
		int vidaJugador;
		int dañoJugador;
		int defensaJugador;

	public:

		jugador() 
		{
			vidaJugador = rand() % 51;
			dañoJugador = rand() % 51;
			defensaJugador = rand() % 10;
		}


		

};


int main()
{

}