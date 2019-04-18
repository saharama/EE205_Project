#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
    public:
		Menu();
        Menu(float width, float height);
        ~Menu();

        void draw(sf::RenderWindow &window);
	    void MoveUp();
	    void MoveDown();
	    int GetPressedItem() { return selectedItemIndex; }

    protected:
	    int selectedItemIndex;
	    sf::Font font;
	    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};

class Instructions : public Menu
{
	public: 
		Instructions(float width, float height);
		~Instructions();


};
    
