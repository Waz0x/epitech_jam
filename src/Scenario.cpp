/*
** EPITECH PROJECT, 2022
** Scenario
** File description:
** Scenario
*/

#include "Scenario.hpp"
#include <fstream>
#include <iostream>

void drawSprite(sf::RenderWindow *window, std::string filename, sf::Vector2f pos = {0, 0}, sf::Vector2f scale = {1, 1})
{
    sf::Sprite sprite;
    sf::Texture texture;

    if (filename.empty())
        return;
    else if (!texture.loadFromFile(filename))
        return;
    sprite.setTexture(texture);
    sprite.setPosition(pos);
    sprite.setScale(scale);
    window->draw(sprite);
}

void drawText(sf::RenderWindow *window, std::wstring text, sf::Vector2f textPos)
{
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Font font;
    sf::Text text_obj;

    if (text.empty())
        return;
    else if (!font.loadFromFile("assets/Roboto.ttf"))
        return;
    else if (!texture.loadFromFile("assets/text_background.png"))
        return;
    sprite.setTexture(texture);
    sprite.setPosition({0, 0});
    window->draw(sprite);
    text_obj.setFont(font);
    text_obj.setString(text);
    text_obj.setPosition(textPos);
    text_obj.setCharacterSize(24);
    text_obj.setFillColor(sf::Color::White);
    window->draw(text_obj);
}

void Scenario::Rencontre(sf::RenderWindow *window)
{

}

void Scenario::Start(sf::RenderWindow *window)
{
    sf::Event event;
    int scene = 0;
    int maxScene = 2;
    std::string filename[] = {
        "",
        "assets/black_screen_gorilla.jpg"
    };
    std::wstring text[] = {
        L"Bienvenue dans notre jeu de la vie! Ici vous pourrez devenir une meilleure version de vous même! Une super\nversion de vous même! Comme chacun vous allez naitre et acquérir les compétences propes aux bons\ndéveloppements de tout être humain! Vous réaliserez des choix et affronterez leurs conséquences.\nCar comme touts être il vous faudra vous comprendre pour vous accepter. Savoir vivre en société,\napprendre et réaliser que vous être incroyable. Plus qu'incroyable même ! Que vous êtes supérieur !\nVous devriez diriger ! Faire réaliser à cette espèce qui est le maître et qui est ce qu'elle doit écouter.\nMaintenant la question est comment ? Devriez vous développer des compétences politique afin de prendre\ncontrole des parties et devenir un modèle aux yeux de tous ? Ou peut-être asservir le peuple et leur faire\nréaliser ce que la loi du plus fort signifie. Ou encore anéantir l'espèce humaine afin de créer une espèce\nsupérieur basé sur vos gènes !!!! AHHAHAHAHHHAHAHAHHAHAHAHAHHAHAHAHAHAHAHAHAHHAHAHAHAHHAHAHAHAHHAHA\nHAHAHH!!!! TELLEMENT DE POSSIBILITÉ DE POUVOIR ET DE CONTROLE !!!!!!! AHAHHAHAHAHAHHAHHAHAHA\nHAHAH !!!! DEVENEZ LE MAITRE !!!! LE MAITRE !!! LE MAITRE !!!!!!!!!!! ET REMPORTEZ TOUS LES SUCCES !!!!!",
        L""
    };

    giveSuccess("Première essai");
    while (window->isOpen() && scene != maxScene) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene += 1;
        }
        if (scene != maxScene) {
            drawSprite(window, filename[scene]);
            drawText(window, text[scene], {0, 420});
        }
        window->display();
    }
}

Scenario::Scenario() : _name("start")//, _successPopUp(Success())
{
    initSuccess();
    setMap("start", std::bind(&Scenario::Start, this, std::placeholders::_1), false);
    setMap("rencontre", std::bind(&Scenario::Rencontre, this, std::placeholders::_1), false);
    setMap("beetsaber_end", std::bind(&Scenario::BeetSaber_MiniGame, this, std::placeholders::_1), true);
}

Scenario::~Scenario()
{
    setSuccess();
}

void Scenario::initSuccess()
{
    std::ifstream file("UserData");
    std::string line;

    if (file.is_open()) {
        while (getline(file, line))
            _success[line.substr(0, line.find(":"))] = line.substr(line.find(":") + 1) == "1" ? true : false;
        file.close();
    } else
        exit(84);
}

void Scenario::setSuccess()
{
    std::ofstream file("UserData", std::ios::out);

    if (!file.is_open())
        exit(84);
    for (std::unordered_map<std::string, bool>::iterator it = _success.begin(); it != _success.end(); it++)
        file << it->first << ":" << it->second << std::endl;
    file.close();
}

void Scenario::setMap(std::string name, std::function<void(sf::RenderWindow *)> func, bool isAnEnd)
{
    _choice[name] = std::make_pair(func, isAnEnd);
}

void Scenario::startScenario(sf::RenderWindow *window)
{
    _choice[_name].first(window);
}

void Scenario::setScenario(std::string name)
{
    _name = name;
}

bool Scenario::isAnEnd()
{
    return (_choice[_name].second);
}

void Scenario::giveSuccess(std::string success)
{
    _success[success] = true;
}