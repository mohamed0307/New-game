#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <SFML/Window/Keyboard.hpp>
using namespace sf;
class game
{	
	//Variables
	//window
	RenderWindow* window;
	Event ev;
	SoundBuffer end_B;
	SoundBuffer eat_B;
	SoundBuffer err_B;
	Sound end;
	Sound eat;
	Sound err;
	VideoMode videoMode;
	Vector2i MousePosition;
	Vector2f MousePositionF;
	Font font;
	std::string S;
	//Game logic
	int points;
	int Health_score;
	float spawnEnemyTimer;
	float spawnEnemyTimerMax;
	int spawnEnemySizeMax;
	int cat_number;
	bool mouseC;
	bool gameRun;
	bool exitFromGame;
	bool gameOption;
	bool gameInterface = true;
	bool selected;
	Text Play;
	Text cat_chosen;
	Text Options;
	Text ExitGame;
	Text text;
	Text Score;
	Text health;
	Text Start;
	Text Exit;
	Text go_back;
	Text Restart;
	Texture Text_start;
	Texture Text_exit;
	Texture img;
	Text text_health;
	Texture cat_text;
	Texture background_text;
	Texture dog_text;
	Texture cat1;
	Texture cat2;
	Texture cat3;
	//Game objects
	Sprite enemy;
	Sprite background;
	Sprite dog;
	Sprite cat;
	Sprite cat_img1;
	Sprite cat_img2;
	Sprite cat_img3;
	std::vector <Sprite> enemies;
	std::vector <Sprite> dogs;
	//Private functions
	void intvar();
	void initenemies();
	void initFont();
	void initialization();
public:
	game();
	~game();
	void setExit();
	bool getExit();
	//interface page
	void SetGameRun();
	bool PlayGame();
	void updateMousePosition();
	// the appearance of the enemy
	void spawnEnemy();
	//Change the position of the enemies
	void UpdateSpawnEnemies();
	// draw the enemy in the windows
	void RenderEnemy();
	void Render();
	void Update();
	const bool running() const;

};

