#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "sources/player.h"
#include "sources/game.h"

//class Figure {
//public:
//    Figure(std::string &filePath) : file_path(filePath) {
//
//    }
//
//    std::pair<float, float> getPosition() {
//        return {this->positionX, this->positionY};
//    }
//
//    std::string getFilePath() {
//        return this->file_path;
//    }
//
//    int getPositionField() {
//        return this->positionField;
//    }
//
//    void stepRight(int countStep) {
//        this->positionX = this->positionX * countStep;
//    }
//
//    void setIsActive() {
//        this->isActive = !this->isActive;
//    }
//
//    void setPosition(float x, float y) {
//        this->positionX = x;
//        this->positionY = y;
//    }
//
//private:
//    bool isActive = false;
//    float positionX = 900;
//    float positionY = 850;
//    std::string file_path;
//    int positionField = 1;
//};

int main() {
    sf::RenderWindow window(sf::VideoMode({1024, 1024}), "Monopoly");

    std::vector<sf::Texture> playersTexture(3);
    std::vector<sf::Sprite> playersSprite;
    std::vector<Player> players;



    for (int i = 0; i < playersTexture.size(); i++) {
        if (!playersTexture[i].loadFromFile("assets/Player" + std::to_string(i+1) + ".png")) {
            return EXIT_FAILURE;
        }
        sf::Sprite sprite1(playersTexture[i]);
        if (i == 2) {
            Player player(sprite1, "Alyona", 1500, 11, 0);
            players.push_back(player);
            playersSprite.push_back(sprite1);
            continue;
        }
        Player player(sprite1, "Alyona", 1500, 1, 0);
        players.push_back(player);
        playersSprite.push_back(sprite1);

    }

//    Player player1(file_path1, "Alyona", 1500, 1, 0);
//    Player player2(file_path2, "Max", 1500, 1, 0);
//    Player player3(file_path3, "Evgeny", 1500, 1, 0);

    Game game(1500, -1, 200, 0, true, 50, 0, players);

    sf::View view1;
    view1.reset(sf::FloatRect(724.f, 724.f, 300.f, 300.f));

    while (window.isOpen()) {
        sf::Event event;
        sf::Texture texture;
        if (!texture.loadFromFile("assets/playing_field-Recovered.png")) {
            return EXIT_FAILURE;
        }

        sf::Sprite sprite(texture);

        for (int i = 0; i < playersSprite.size(); i++) {
            sf::Vector2f position;
            if (players[i].get_position() % 10 == 1) {
                sf::Vector2f p(930 + players[i].get_position() * 10 ,850);
                position = p;

                playersSprite[i].setPosition(930 ,850);
            } else {
                playersSprite[i].setPosition(100, 100);
            }
//            playersSprite[i].set
        }
        players[0].get_sprite().setPosition(500, 500);

//        player1Sprite.setPosition(player1.getPosition().first, player1.getPosition().second);
//
//        player2Sprite.setPosition(930, 850);


//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//            player1.setPosition(player1.getPosition().first - 70, 850);
//            view1.move(-50.f, 0);
//        }

        while (window.pollEvent(event))  {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.draw(sprite);
        for (int i = 0; i < playersSprite.size(); i++) {
            window.draw(playersSprite[i]);
        }
//        window.setView(view1);
        window.display();
    }
    return 0;
}
