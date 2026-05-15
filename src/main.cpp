#include <optional>
#include <vector>

#include "funciones.h"
#include "enemigos.h"

int main() {

    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "Juego"
    );

    sf::RectangleShape player1({50.f, 50.f});
    player1.setFillColor(sf::Color(49, 212, 146));
    player1.setPosition({50.f, 250.f}); 

    std::vector<sf::RectangleShape> paredes;
    paredes.push_back(sf::RectangleShape({30.f, 30.f}));
    paredes.back().setFillColor(sf::Color(245, 39, 118));

    sf::RectangleShape enemigo1({50.f, 50.f});
    enemigo1.setPosition({700.f, 250.f});
    enemigo1.setFillColor(sf::Color::Red);

    float playerSpeed = 2.0f;

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        sf::Vector2f ultimaPosicion = player1.getPosition();
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            player1.move({0.f, -playerSpeed});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            player1.move({0.f, playerSpeed});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            player1.move({playerSpeed, 0.f});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            player1.move({-playerSpeed, 0.f});
        }

        for (sf::RectangleShape& pared : paredes) {
            if (player1.getGlobalBounds().findIntersection(pared.getGlobalBounds())) {
                player1.setPosition(ultimaPosicion);
            }
        }


        window.clear();

        window.draw(player1);

        CrearParedes(paredes, {0.f, 0.f}, 'h', 27);
        CrearParedes(paredes, {0.f, 0.f}, 'v', 20);
        CrearParedes(paredes, {770.f, 0.f}, 'v', 20);
        CrearParedes(paredes, {0.f, 570.f}, 'h', 27);

        for (sf::RectangleShape& pared : paredes) {
            window.draw(pared);
        }

        window.draw(enemigo1);
        MoverEnemigo(enemigo1, paredes);

        window.display(); 
    }

    return 0;
}