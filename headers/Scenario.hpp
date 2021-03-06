/*
** EPITECH PROJECT, 2022
** SCENARIO
** File description:
** SCENARIO
*/

#ifndef SCENARIO
    #define SCENARIO

    #include <SFML/Graphics/RenderWindow.hpp>
    #include <string>
    #include <map>
    #include <vector>
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <functional>
    #include "achievement.hpp"
    #include <unordered_map>
    #include "marcolito.hpp"
    #include "ScriptChoice.hpp"
    #include "cake.hpp"
    #include "DodgeBottle.hpp"
    #include "SchoolPriorities.hpp"
    #include "Horse.hpp"
    #include "DefeatKFC.hpp"
    #include "Space.hpp"
    #include "laruelavrai.hpp"

    class Scenario {
        public:
            Scenario();
            ~Scenario();
            Scenario(const Scenario &scenario);

            void setMap(std::string, std::function<void(sf::RenderWindow *)>, bool isAnEnd);
            void startScenario(sf::RenderWindow *);
            void setScenario(std::string name);
            bool isAnEnd();
            void giveSuccess(std::string);

            void setInScenario(const bool value);
            const bool &getInScenario() const;

            void Start(sf::RenderWindow *window);

            void Fuir(sf::RenderWindow *window);
            void Matrice(sf::RenderWindow *window);
            void Rencontre(sf::RenderWindow *window);
            void Reel(sf::RenderWindow *window);
            void marcolito(sf::RenderWindow *win);

            void laruelavrai(sf::RenderWindow *win);
            void JulienLaFarge(sf::RenderWindow *window);
            void FightTheRock(sf::RenderWindow *window);

            void BeetSaber_MiniGame(sf::RenderWindow *window);

            void Psykoloke_MiniScene(sf::RenderWindow *window);
            void PsyJob(sf::RenderWindow *window);
            void Folie(sf::RenderWindow *window);

            void Jouer(sf::RenderWindow *window);

            void Rue(sf::RenderWindow *window);
            void Vente(sf::RenderWindow *window);
            void Recherche(sf::RenderWindow *window);
            void Maitre(sf::RenderWindow *window);
            void Soiree(sf::RenderWindow *window);

            void Sobre(sf::RenderWindow *window);

            void addSuccess(std::wstring text, std::string path, std::string audio="assets/baptiste.ogg");
            void displaySuccess(sf::RenderWindow *win);
            void checkSuccessDelete(sf::Event event, sf::RenderWindow *win);

            void Bill(sf::RenderWindow *window);
            void Marier(sf::RenderWindow *window);
            void Entreprise(sf::RenderWindow *window);

            void BAC(sf::RenderWindow *window);
            void Medecine(sf::RenderWindow *window);
            void Ens(sf::RenderWindow *window);
            void Supaero(sf::RenderWindow *window);
            void Epitech(sf::RenderWindow *window);

            void Ecole(sf::RenderWindow *window);
            void Rien(sf::RenderWindow *window);
            void Travailler(sf::RenderWindow *window);
            void Depression(sf::RenderWindow *window);

            void Entendre(sf::RenderWindow *window);
            void Suicide(sf::RenderWindow *window);
            void Puissant(sf::RenderWindow *window);
            void Johannisme(sf::RenderWindow *window);

            void Equitation(sf::RenderWindow *window);
            void EquitationGates(sf::RenderWindow *window);
            void Repartie(sf::RenderWindow *window);
            void Normale(sf::RenderWindow *window);
            void Chute(sf::RenderWindow *window);

            void Kfc(sf::RenderWindow *window);
            void Gaming(sf::RenderWindow *window);
            void Julien(sf::RenderWindow *window);
            void Remy(sf::RenderWindow *window);
        private:
            void initChoice();
            void initSuccess();
            void setSuccess();
            std::string _name;
            std::map<std::string, std::pair<std::function<void(sf::RenderWindow *)>, bool>> _choice;
            std::unordered_map<std::string, bool> _success;
            std::vector<success *> _successPopUp;
            bool _inScenario;
    };

#endif /* !SCENARIO */