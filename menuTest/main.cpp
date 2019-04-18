//Final project

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include "menu.hpp"


int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Dating Sim Game");
    Menu menu(window.getSize().x, window.getSize().y);

    sf::Music menumusic;
    
	//load in menu music
    if(!menumusic.openFromFile("MainMenuMusic.ogg")){

        std::cout << "No Music File: Main Menu" << std::endl;

    }
    menumusic.setLoop(true);
    menumusic.setVolume(15.f);
    menumusic.play();
	
//	bool GameStart = false;
//	bool OptionsOpen = false;
	
	while (window.isOpen())
	{
		sf::Event event;

		//menu music
        sf::SoundBuffer buffer;
        sf::Sound MenuSound;
        
		//loading menu music
        if(!buffer.loadFromFile("MenuSelectionClick.wav")){

        std::cout << "No Sound File: Menu Selection" << std::endl;

        }

		//adjusting menu sounds
        MenuSound.setBuffer(buffer);
        MenuSound.setPitch(3.2f);

		

		while (window.pollEvent(event))
		{

				switch (event.type)
				{
				case sf::Event::KeyReleased:
					switch (event.key.code){
						case sf::Keyboard::Up:
                    		MenuSound.play();
							menu.MoveUp();
							break;

						case sf::Keyboard::Down:
                    		MenuSound.play();
							menu.MoveDown();
							break;

						case sf::Keyboard::Return:
							switch (menu.GetPressedItem())
							{
								case 0:
									std::cout << "Play button has been pressed" << std::endl;
									//GameStart = true;
									
									break;
								case 1:
									std::cout << "Option button has been pressed" << std::endl;
								//	OptionsOpen = true;
									break;
								case 2:
									std::cout << "Good Bye" << std::endl;
									window.close();
									break;
							}

							break;
					}

				break;
			

				case sf::Event::Closed:
					window.close();

				break;
				}

			window.clear();

			menu.draw(window);

			window.display();
		
		}

	}




    menumusic.stop();
}
