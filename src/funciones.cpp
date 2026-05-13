#include "funciones.h"

void CrearParedes(std::vector<sf::RectangleShape>& paredes,
                  sf::Vector2f posicionInicial,
                  char direccion,
                  int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        sf::RectangleShape pared({30.f, 30.f});

        pared.setPosition(posicionInicial);

        paredes.push_back(pared);

        if (direccion == 'v')
            posicionInicial.y += 30.f;

        else if (direccion == 'h')
            posicionInicial.x += 30.f;
    }
}