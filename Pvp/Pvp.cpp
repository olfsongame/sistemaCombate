#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

struct Personaje { //Estructura de los personajes
    string nombre;
    int vida;
    int ataque;
    int defensa;
};

int calcularDanio(int ataque, int defensa) {  // Funcion para calcular daño

    int danio = ataque - defensa;
    return (danio > 0) ? danio : 0;
}

void mostrarEstado(const Personaje& p) { // Mostrar estado de jugadores el setw es para marcar un espaciado determinado para cada variable al momento de ejecutar
    cout << "Nombre: " << setw(2) << p.nombre << endl;
    cout << " | Vida: " << setw(2) << p.vida << endl;
    cout << " | Ataque: " << setw(2) << p.ataque << endl;
    cout << " | Defensa: " << setw(2) << p.defensa << endl;
}

int main() {
    srand(time(0)); // Semilla para números aleatorios

    Personaje p1, p2;

    // Ingreso de nombres
    cout << "Introduce el nombre del personaje 1: ";
    getline(cin, p1.nombre);
    cout << "Introduce el nombre del personaje 2: ";
    getline(cin, p2.nombre);

    // Asignación aleatoria de estadísticas (rango entre 50 y 100 para vida, 10 a 30 para ataque y de 10 a 20 de defensa)
    p1.vida = rand() % 51 + 50;
    p1.ataque = rand() % 31 + 10;
    p1.defensa = rand() % 21 + 10;

    p2.vida = rand() % 51 + 50;
    p2.ataque = rand() % 31 + 10;
    p2.defensa = rand() % 21 + 10;

    cout << "\n--- Estado Inicial ---\n";
    mostrarEstado(p1);
    mostrarEstado(p2);

    cout << "\n--- Combate ---\n";
    
    // P1 ataca a P2
    int danioP1 = calcularDanio(p1.ataque, p2.defensa);
    p2.vida -= danioP1;
    cout << p1.nombre << " ataca a " << p2.nombre << endl;
    cout << p2.nombre << " recibio  " << danioP1 << " de daño.\n";

    // P2 ataca a P1
    int danioP2 = calcularDanio(p2.ataque, p1.defensa);
    p1.vida -= danioP2;
    cout << p2.nombre << " ataca a " << p1.nombre << endl;
    cout << p1.nombre << " recibio " << danioP2 << " de daño.\n";

    // Asegurar que la vida no sea negativa
    if (p1.vida < 0) p1.vida = 0;
    if (p2.vida < 0) p2.vida = 0;

    cout << "\n--- ESTADO FINAL---\n";
    mostrarEstado(p1);
    mostrarEstado(p2);


    return 0;
}
