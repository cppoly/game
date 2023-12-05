#include "RentCards.h"

void drawRentStreetCard(sf::RenderWindow &window, ProfitableField *field, sf::Sprite &rentCardSprite, float x,
                                    float y, float scaleX,
                                    float scaleY, sf::Font& font2) {
    auto street = dynamic_cast<Street *>(field);
    rentCardSprite.setPosition(x, y);
    rentCardSprite.setScale(scaleX, 1.2 * scaleY);
    window.draw(rentCardSprite);

    std::string name = field->get_name();
    std::string rent = "Rent:  " + std::to_string(field->get_rent());
    std::string rentWith1House = "Rent with 1 house:   " + std::to_string(field->get_rent_vector()[0]);
    std::string rentWith2House = "Rent with 2 houses:  " + std::to_string(field->get_rent_vector()[1]);
    std::string rentWith3House = "Rent with 3 houses:  " + std::to_string(field->get_rent_vector()[2]);
    std::string rentWith4House = "Rent with 4 houses:  " + std::to_string(field->get_rent_vector()[3]);
    std::string rentWith1Hotel = "Rent with 1 hotel:   " + std::to_string(field->get_rent_vector()[4]);
    std::string mortgageValue = "Mortgage value:       " + std::to_string(field->get_mortgage_price());
    std::string redemptionValue = "Redemption value:     " + std::to_string(field->get_redemption_price());

    std::string price1House = std::to_string(street->get_house_price());
    std::string price1Hotel = std::to_string(street->get_hotel_price());

    sf::Text nameText;
    sf::Text rentText;
    sf::Text rentWith1HouseText;
    sf::Text rentWith2HouseText;
    sf::Text rentWith3HouseText;
    sf::Text rentWith4HouseText;
    sf::Text rentWith1HotelText;
    sf::Text mortgageValueText;
    sf::Text redemptionValueText;
    sf::Text price1HouseText;
    sf::Text price1HotelText;

    set_text(nameText, font2, name, (int) (15 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (100 * scaleY * 1.1));
    set_text(rentText, font2, rent, (int) (15 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (130 * scaleY * 1.1));
    set_text(rentWith1HouseText, font2, rentWith1House, (int) (15 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (160 * scaleY * 1.1));
    set_text(rentWith2HouseText, font2, rentWith2House, (int) (15 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (190 * scaleY * 1.1));
    set_text(rentWith3HouseText, font2, rentWith3House, (int) (15 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (220 * scaleY * 1.1));
    set_text(rentWith4HouseText, font2, rentWith4House, (int) (15 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (250 * scaleY * 1.1));
    set_text(rentWith1HotelText, font2, rentWith1Hotel, (int) (15 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (280 * scaleY * 1.1));
    set_text(mortgageValueText, font2, mortgageValue, (int) (15 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (310 * scaleY * 1.1));
    set_text(redemptionValueText, font2, redemptionValue, (int) (15 * scaleX), sf::Color::Black,
             sf::Text::Style::Regular,
             x + 20, y + (340 * scaleY * 1.1));
    set_text(price1HouseText, font2, price1House, (int) (25 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 100 * scaleX, y + (350 * scaleY * 1.2));
    set_text(price1HotelText, font2, price1Hotel, (int) (25 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 100 * scaleX, y + (400 * scaleY * 1.2));

    window.draw(nameText);
    window.draw(rentText);
    window.draw(rentWith1HouseText);
    window.draw(rentWith2HouseText);
    window.draw(rentWith3HouseText);
    window.draw(rentWith4HouseText);
    window.draw(rentWith1HotelText);
    window.draw(mortgageValueText);
    window.draw(redemptionValueText);
    window.draw(price1HouseText);
    window.draw(price1HotelText);
}

void drawRentStationCard(sf::RenderWindow &window, ProfitableField *field, sf::Sprite& rentCardSprite, float x, float y, float scaleX,
                                     float scaleY, sf::Font& font2) {
    rentCardSprite.setPosition(x, y);
    rentCardSprite.setScale(scaleX, 1.2 * scaleY);
    window.draw(rentCardSprite);
    auto station = dynamic_cast<Station *>(field);

    std::string name = station->get_name();
    std::string rentWith1Station = "Rent:   " + std::to_string(station->get_rent_vector()[0]);
    std::string rentWith2Station = "If 2 are owned:  " + std::to_string(station->get_rent_vector()[1]);
    std::string rentWith3Station = "If 3 are owned:  " + std::to_string(station->get_rent_vector()[2]);
    std::string rentWith4Station = "If 4 are owned:  " + std::to_string(station->get_rent_vector()[3]);
    std::string mortgageValue = "Mortgage value:       " + std::to_string(station->get_mortgage_price());
    std::string redemptionValue = "Redemption value:     " + std::to_string(station->get_redemption_price());

    sf::Text nameText;
    sf::Text rentWith1StationText;
    sf::Text rentWith2StationText;
    sf::Text rentWith3StationText;
    sf::Text rentWith4StationText;
    sf::Text mortgageValueText;
    sf::Text redemptionValueText;

    set_text(rentWith1StationText, font2, rentWith1Station, (int) (15 * scaleX), sf::Color::Black,
             sf::Text::Style::Regular,
             x + 20, y + (scaleY * 100 * 1.1));
    set_text(rentWith1StationText, font2, rentWith1Station, (int) (15 * scaleX), sf::Color::Black,
             sf::Text::Style::Regular,
             x + 20, y + (scaleY * 130 * 1.1));
    set_text(rentWith2StationText, font2, rentWith2Station, (int) (scaleX * 15), sf::Color::Black,
             sf::Text::Style::Regular,
             x + 20, y + (scaleY * 160 * 1.1));
    set_text(rentWith3StationText, font2, rentWith3Station, (int) (scaleX * 15), sf::Color::Black,
             sf::Text::Style::Regular,
             x + 20, y + (scaleY * 190 * 1.1));
    set_text(rentWith4StationText, font2, rentWith4Station, (int) (scaleX * 15), sf::Color::Black,
             sf::Text::Style::Regular,
             x + 20, y + (scaleY * 220 * 1.1));
    set_text(mortgageValueText, font2, mortgageValue, (int) (scaleX * 15), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (scaleY * 250 * 1.1));
    set_text(redemptionValueText, font2, redemptionValue, (int) (scaleX * 15), sf::Color::Black,
             sf::Text::Style::Regular,
             x + 20, y + (scaleY * 280 * 1.1));

    window.draw(rentWith1StationText);
    window.draw(rentWith2StationText);
    window.draw(rentWith3StationText);
    window.draw(rentWith4StationText);
    window.draw(mortgageValueText);
    window.draw(redemptionValueText);
}

void drawRentUtilityCard(sf::RenderWindow &window, ProfitableField *field, sf::Sprite& rentCardSprite, float x, float y, float scaleX,
                                     float scaleY, sf::Font& font2) {
    rentCardSprite.setPosition(x, y);
    rentCardSprite.setScale(scaleX, 1.2f * scaleY);
    window.draw(rentCardSprite);
    auto utility = dynamic_cast<Utility *>(field);

    std::string name = field->get_name();
    std::string utility1 = "If one \"Utility\" is owned,\nrent is 4 times amount\nshown on dice";
    std::string utility2 = "If both \"Utilities\" are\nowned, rent is 10\ntimes the amount\nshown on dice";
    std::string mortgageValue = "Mortgage value:       " + std::to_string(utility->get_mortgage_price());
    std::string redemptionValue = "Redemption value:     " + std::to_string(utility->get_redemption_price());

    sf::Text nameText;
    sf::Text utility1Text;
    sf::Text utility2Text;
    sf::Text mortgageValueText;
    sf::Text redemptionValueText;

    set_text(nameText, font2, name, (int) (scaleX * 15), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (scaleY * 100 * 1.1));
    set_text(utility1Text, font2, utility1, (int) (scaleX * 15), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (scaleY * 130 * 1.1));
    set_text(utility2Text, font2, utility2, (int) (scaleX * 15), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (scaleY * 220 * 1.1));
    set_text(mortgageValueText, font2, mortgageValue, (int) (scaleX * 15), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (scaleY * 300 * 1.1));
    set_text(redemptionValueText, font2, redemptionValue, (int) (scaleX * 15), sf::Color::Black,
             sf::Text::Style::Regular,
             x + 20, y + (scaleY * 330 * 1.1));

    window.draw(nameText);
    window.draw(utility1Text);
    window.draw(utility2Text);
    window.draw(mortgageValueText);
    window.draw(redemptionValueText);
}