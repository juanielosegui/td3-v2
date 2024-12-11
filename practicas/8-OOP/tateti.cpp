#include <iostream>
#include <vector>

enum class Casillero{circulo,cruz,vacio};
enum class Jugador{circulo,cruz};

class Tateti
{
    public:
        Tateti();
        Jugador a_quien_le_toca();
        Casillero observar_posicion(const int & fila, const int & columna);
        void hacer_jugada(const Jugador j, const int & fila, const int & columna);
        bool esta_terminado();
        bool hubo_empate();
        Jugador quien_gano();

    private:
        std::vector<std::vector<Casillero>> _tablero;
        Jugador _ultimoenjugar = Jugador::circulo;
        int _cantidad_de_cruces = 0;
        int _cantidad_de_circulos = 0;
        Jugador _ganador;
};

Tateti::Tateti()
{
    _tablero = std::vector<std::vector<Casillero>>(3, std::vector<Casillero>(3, Casillero::vacio));
}

Jugador Tateti::a_quien_le_toca()
{
    if(_ultimoenjugar == Jugador::circulo) return Jugador::cruz;
    else return Jugador::circulo;
}

Casillero Tateti::observar_posicion(const int & fila, const int & columna)
{
    return _tablero[fila][columna];
}

void Tateti::hacer_jugada(const Jugador j, const int & fila, const int & columna)
{
    if(_tablero[fila][columna] == Casillero::vacio)
    {
        if(j == Jugador::circulo)
        {
            _tablero[fila][columna] = Casillero::circulo;
            _cantidad_de_circulos++;
            _ultimoenjugar = Jugador::circulo;
        }
        if (j == Jugador::cruz)
        {
            _tablero[fila][columna] = Casillero::cruz;
            _cantidad_de_cruces++;
            _ultimoenjugar = Jugador::cruz;
        }
    }
    return;
}

bool Tateti::esta_terminado()
{
    //  Para que termine tienen que usarse todos los espacios
    if(_cantidad_de_circulos == 5 && _cantidad_de_cruces == 4) return true;
    if(_cantidad_de_circulos == 4 && _cantidad_de_cruces == 5) return true;
    return false;
}

bool Tateti::hubo_empate()
{
    //  FIXME: no se bien como hacer esto. Me debo estar comiendo una precondicion
    return false;
}

Jugador Tateti::quien_gano() {return _ganador;}

int main()
{
    Tateti juego;

    //  Prueba 1: A quién le toca al principio (debería ser cruz)
    std::cout << "Prueba 1 - A quién le toca: ";
    std::cout << (juego.a_quien_le_toca() == Jugador::cruz ? "Aprobada" : "Fallida") << std::endl;

    //  Prueba 2: Alternancia de turnos (turno 1: círculo, turno 2: cruz)
    juego.hacer_jugada(Jugador::cruz, 0, 0); // círculo juega en (0,0)
    std::cout << "Prueba 2 - Alternancia de turnos: ";
    std::cout << (juego.a_quien_le_toca() == Jugador::circulo ? "Aprobada" : "Fallida") << std::endl;

    //  Prueba 3: Ganar en una fila
    //      FIXME: fucker keeps failing for some reason
    Tateti juego_fila;
    juego_fila.hacer_jugada(Jugador::cruz, 0, 0);
    juego_fila.hacer_jugada(Jugador::circulo, 1, 0);
    juego_fila.hacer_jugada(Jugador::cruz, 0, 1);
    juego_fila.hacer_jugada(Jugador::circulo, 1, 1);
    juego_fila.hacer_jugada(Jugador::cruz, 0, 2); // cruz completa fila 0
    std::cout << "Prueba 3 - Ganar en fila: ";
    std::cout << (juego_fila.esta_terminado() && juego_fila.quien_gano() == Jugador::cruz ? "Aprobada" : "Fallida") << std::endl;

    //  Prueba 4: Ganar en una columna
    //      FIXME: fucker keeps failing for some reason
    Tateti juego_columna;
    juego_columna.hacer_jugada(Jugador::cruz, 0, 0);
    juego_columna.hacer_jugada(Jugador::circulo, 0, 1);
    juego_columna.hacer_jugada(Jugador::cruz, 1, 0);
    juego_columna.hacer_jugada(Jugador::circulo, 1, 1);
    juego_columna.hacer_jugada(Jugador::cruz, 2, 0); // cruz completa columna 0
    std::cout << "Prueba 4 - Ganar en columna: ";
    std::cout << (juego_columna.esta_terminado() && juego_columna.quien_gano() == Jugador::cruz ? "Aprobada" : "Fallida") << std::endl;

    //  Prueba 5: Ganar en diagonal
    //      FIXME: fucker keeps failing for some reason
    Tateti juego_diagonal;
    juego_diagonal.hacer_jugada(Jugador::cruz,1,0);
    juego_diagonal.hacer_jugada(Jugador::circulo, 0, 0);
    juego_diagonal.hacer_jugada(Jugador::cruz, 0, 1);
    juego_diagonal.hacer_jugada(Jugador::circulo, 1, 1);
    juego_diagonal.hacer_jugada(Jugador::cruz, 0, 2);
    juego_diagonal.hacer_jugada(Jugador::circulo, 2, 2); // círculo completa diagonal principal
    std::cout << "Prueba 5 - Ganar en diagonal: ";
    std::cout << (juego_diagonal.esta_terminado() && juego_diagonal.quien_gano() == Jugador::circulo ? "Aprobada" : "Fallida") << std::endl;

    //  Prueba 6: Empate (todo el tablero lleno sin ganador)
    //      FIXME: fucker keeps failing for some reason
    Tateti juego_empate;
    juego_empate.hacer_jugada(Jugador::cruz, 0, 0);
    juego_empate.hacer_jugada(Jugador::circulo, 0, 1);
    juego_empate.hacer_jugada(Jugador::cruz, 0, 2);
    juego_empate.hacer_jugada(Jugador::circulo, 1, 1);
    juego_empate.hacer_jugada(Jugador::cruz, 1, 0);
    juego_empate.hacer_jugada(Jugador::circulo, 1, 2);
    juego_empate.hacer_jugada(Jugador::cruz, 2, 1);
    juego_empate.hacer_jugada(Jugador::circulo, 2, 0);
    juego_empate.hacer_jugada(Jugador::cruz, 2, 2); // tablero completo sin ganador
    std::cout << "Prueba 6 - Empate: ";
    std::cout << (juego_empate.esta_terminado() && juego_empate.hubo_empate() ? "Aprobada" : "Fallida") << std::endl;

    return 0;
}
