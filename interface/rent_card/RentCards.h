#include "SFML/Graphics.hpp"
#include "../../sources/game.h"
#include "../text/text.h"

void drawRentStreetCard(sf::RenderWindow& window, ProfitableField * field, sf::Sprite& rentCardSprite, float x, float y, float scaleX, float ScaleY, sf::Font& font);

void drawRentStationCard(sf::RenderWindow& window, ProfitableField* field, sf::Sprite& rentCardSprite, float x, float y, float scaleX, float ScaleY, sf::Font& font);

void drawRentUtilityCard(sf::RenderWindow& window, ProfitableField* field, sf::Sprite& rentCardSprite, float x, float y, float scaleX, float ScaleY, sf::Font& font);
