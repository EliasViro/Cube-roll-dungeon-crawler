#include <SFML/Graphics.hpp>

class SpriteContainer {
public:
    static sf::Sprite ai_aggressive() {
        sf::Texture t;
        t.loadFromFile("../src/Graphics/CharacterSprites/AI_Aggressive.png");
        return sf::Sprite(t);
    }
};