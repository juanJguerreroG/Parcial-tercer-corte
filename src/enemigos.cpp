#include "enemigos.h"

float enemySpeedX = 4.0f;
float enemySpeedY = 4.0f;



void MoverEnemigo(sf::RectangleShape& enemigo1, const std::vector<sf::RectangleShape>& paredes) {
    enemigo1.move({enemySpeedX, enemySpeedY});
    for (const sf::RectangleShape& pared : paredes) {
        if (enemigo1.getGlobalBounds().findIntersection(pared.getGlobalBounds())) {
            if (enemigo1.getPosition().x <= 0.f || enemigo1.getPosition().x + enemigo1.getSize().x >= 800.f) {
                enemySpeedX = -enemySpeedX;
            } else if (enemigo1.getPosition().y <= 0.f || enemigo1.getPosition().y + enemigo1.getSize().y >= 600.f) {
                enemySpeedY = -enemySpeedY;
            } else if (enemigo1.getPosition().x < pared.getPosition().x || enemigo1.getPosition().x > pared.getPosition().x + pared.getSize().x) {
                enemySpeedX = -enemySpeedX;
            } else {
                enemySpeedY = -enemySpeedY;
            }
        }
    }
}