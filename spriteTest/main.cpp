//Final project

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>

#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 800



int main()
{	
	//Clear the Screen
	std::system("clear");

	//initialize variables
	bool Start_Game = false;
	char instructions;
	char choice;
	//Do you want to start the game?
	std::cout << "Welcome! Do you want to play Nick's Dating Adventure? (y/n)" << std::endl;
	
	std::cin >> choice;
	if(choice == 'y'){
		
		std::system("clear");
		std::cout << "Game is starting" << std::endl;
		std::cout << "Do you want instructions on how to play? (y/n)" << std::endl;
		
		std::cin >> instructions;
		if(instructions == 'y'){
			std::system("clear");
			std::cout << "INSTRUCTIONS:" << std::endl;
			std::cout <<"Move character with arrow keys. You can interact with enter key." << std::endl;
			std::cout <<"Do you still want to play? (y/n)" << std::endl;
			std::cin >> choice;

			if(choice == 'y'){
				std::system("clear");
				Start_Game = true;
			}
			else if(choice == 'n'){
				std::system("clear");
				std::cout << "Good Bye" << std::endl;
				return 0;
			}
	
		
		}
		else if (instructions == 'n'){
			Start_Game = true;
			std::system("clear");
		}
		else std::cin >> instructions;

	}
	else if(choice == 'n'){
		//clear screen
		std::system("clear");
		std::cout << "Good Bye" << std::endl;
		return 0;
	}
	else std::cin >> choice;

	if(Start_Game == true){

   		sf::Music menumusic;
    
		//load in happy song 
		if(!menumusic.openFromFile("MainMenuMusic.ogg")){

			std::cout << "No Music File: Main Menu" << std::endl;

		}

		//adjust song volume
		menumusic.setLoop(true);
		menumusic.setVolume(15.f);
		//menumusic.play();

		//interaction sound 
		sf::SoundBuffer buffer;
		sf::Sound MenuSound;
				
		//loading interaction sound
		if(!buffer.loadFromFile("MenuSelectionClick.wav")){

			std::cout << "No Sound File: Menu Selection" << std::endl;

		}

		//adjusting interaction sound
		MenuSound.setBuffer(buffer);
		MenuSound.setPitch(3.2f);

		//create window
		sf::RenderWindow Window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Nick's Dating Adventure");
		sf::FloatRect windowBounds({0.f, 0.f}, Window.getDefaultView().getSize());
			
		//Directions of character for moving
		int Up = 8;
		int Left = 9;
		int Down = 10;
		int Right = 11;



		sf::Vector2i source(1,Down);

		//control timing of the animations
		float frameCounter = 0, switchFrame = 50, frameSpeed = 500;
		sf::Clock clock;
		bool notMoving;

		//creating characters
		sf::Texture pTexture;
		sf::Sprite playerImage;

		//load in player image
		if(!pTexture.loadFromFile("player.png"))
			std::cout << "Error could not load player image" << std::endl;
		
		playerImage.setTexture(pTexture);
		playerImage.setPosition((SCREEN_WIDTH/2)-32,300);
		
		//creating status box
		sf::RectangleShape rect(sf::Vector2f(SCREEN_WIDTH,200));
		rect.setFillColor(sf::Color(209,199,171));
		rect.setPosition(0,SCREEN_HEIGHT - 200);

		while(Window.isOpen())
		{
			sf::Event event;

			while(Window.pollEvent(event))
			{

				
				switch(event.type)
				{
					//if window is closed, exit the program
					case sf::Event::Closed:
						Window.close();
						std::cout << "Good Bye" << std::endl;
						menumusic.stop();
						break;
					
				}
								
			}
			

			//controls the movement of the character
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
					source.y = Up;
					notMoving = false;
					playerImage.move(0,-.20);
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				source.y = Down;
				playerImage.move(0,.20);
				notMoving = false;
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				source.y = Right;
				playerImage.move(.20,0);
				notMoving = false;
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				source.y = Left;
				playerImage.move(-.20,0);
				notMoving = false;
			}
			else
			{
					notMoving = true;
			}
			
			
			//control the speed of the animation
			frameCounter += frameSpeed * clock.restart().asSeconds();

			if(frameCounter >= switchFrame)
			{
				//check if standing still
				if(notMoving == true)
					source.x = 0;
				//if moving, animate the sprite
				else
				{
					frameCounter = 0;
					source.x++;
					if(source.x *64 >= 576)
						source.x=0;
				}
			}

			//adapt the position of the player if going off the screen
			sf::Vector2f position = playerImage.getPosition();
        	position.x = std::max(position.x, windowBounds.left);
        	position.x = std::min(position.x, windowBounds.left + windowBounds.width - 64);
        	position.y = std::max(position.y, windowBounds.top);
			position.y = std::min(position.y, windowBounds.top + windowBounds.height - 64 - 200);
			playerImage.setPosition(position);

			playerImage.setTextureRect(sf::IntRect(source.x*64, source.y*64,64,64));
			Window.draw(playerImage);
			Window.draw(rect);
			Window.display();
			Window.clear();
		}

	}
	
}
