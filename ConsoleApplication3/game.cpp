#include "game.h"
void game::intvar() {
	this->window = nullptr;
}

bool game::PlayGame() {
	bool option = false;
	this->selected = false;
	bool chosen = false;
	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				if (this->cat.getPosition().x < this->window->getSize().x - 100) {
					std::cout << this->cat.getPosition().x << std::endl;
					this->cat.move(40, 0);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				if (this->cat.getPosition().x > 13)
					this->cat.move(-40, 0);
			}
			break;
		case Event::MouseMoved:
			this->updateMousePosition();
			break;
		}
	}
	this->font.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\ConsoleApplication3\\Font\\TTF\\dogica.ttf");
	this->gameRun = false;
	this->gameOption = false;
	this->Play.setFont(this->font);
	this->Play.setPosition(100, 200);
	this->Play.setString("Start game");
	this->Play.setFillColor(Color::Black);
	this->Play.setCharacterSize(40);
	this->Options.setFont(this->font);
	this->Options.setPosition(150, 250);
	this->Options.setString("Options");
	this->Options.setFillColor(Color::Black);
	this->Options.setCharacterSize(40);
	this->ExitGame.setFont(this->font);
	this->ExitGame.setPosition(220, 300);
	this->ExitGame.setString("Exit");
	this->ExitGame.setFillColor(Color::Black);
	this->ExitGame.setCharacterSize(40);
	this->background_text.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\images_balls\\background.jpg");
	this->background.setTexture(this->background_text);
	this->background.setPosition(0, 0);
	this->window->clear(Color(118, 143, 59, 255));
	this->window->draw(this->Play);
	this->window->draw(this->Options);
	this->window->draw(this->ExitGame);
	this->window->display();
	this->MousePosition = Mouse::getPosition(*this->window);
	this->MousePositionF = this->window->mapPixelToCoords(this->MousePosition);
	if (this->Play.getGlobalBounds().contains(this->MousePositionF))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			return true;
	}
	if (this->ExitGame.getGlobalBounds().contains(this->MousePositionF)) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			this->window->close();
		}
	}
	if (this->Options.getGlobalBounds().contains(this->MousePositionF)) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			option = true;
			this->selected = true;
			while (option) {

				if (!Mouse::isButtonPressed(Mouse::Left))
					this->selected = false;
				bool cat_bool1 = false;
				bool cat_bool2 = false;
				bool cat_bool3 = false;
				this->cat1.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\images_balls\\cat1.png");
				this->cat2.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\images_balls\\cat2.png");
				this->cat3.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\images_balls\\cat3.png");
				this->cat_img1.setTexture(this->cat1);
				this->cat_img2.setTexture(this->cat2);
				this->cat_img3.setTexture(this->cat3);
				this->font.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\ConsoleApplication3\\Font\\TTF\\dogica.ttf");
				this->go_back.setFont(this->font);
				this->go_back.setFillColor(Color::Black);
				this->go_back.setString("Go back");
				this->go_back.setPosition(20, 560);
				this->go_back.setCharacterSize(20);
				this->cat_img1.setPosition(160, 250);
				this->cat_img2.setPosition(260, 250);
				this->cat_img3.setPosition(360, 250);
				this->window->clear(Color(118, 143, 59, 255));
				this->MousePosition = Mouse::getPosition(*this->window);
				this->MousePositionF = this->window->mapPixelToCoords(this->MousePosition);
				if (this->go_back.getGlobalBounds().contains(this->MousePositionF)) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						option = false;
					} 
				}
				if (this->cat_img1.getGlobalBounds().contains(this->MousePositionF)) {
					this->cat_img1.move(0, -30);
					this->window->draw(this->cat_img1);
					cat_bool1 = true;
					if (Mouse::isButtonPressed(Mouse::Left) and !this->selected) {
						this->cat_number = 1;
						this->cat_chosen.setFont(this->font);
						this->cat_chosen.setPosition(170, 347);
						this->cat_chosen.setString("You choose the first cat");
						this->cat_chosen.setFillColor(Color::Black);
						this->cat_chosen.setCharacterSize(13);
						chosen = true;
					}
  				}
				if (this->cat_img2.getGlobalBounds().contains(this->MousePositionF)) {
					this->cat_img2.move(0, -30);
					this->window->draw(this->cat_img2);
					cat_bool2 = true;
					if (Mouse::isButtonPressed(Mouse::Left) and !this->selected) {
						this->cat_number = 2;
						this->cat_chosen.setFont(this->font);
						this->cat_chosen.setPosition(170, 347);
						this->cat_chosen.setString("You choose the second cat");
						this->cat_chosen.setFillColor(Color::Black);
						this->cat_chosen.setCharacterSize(13);
						chosen = true;
					}
				}
				if (this->cat_img3.getGlobalBounds().contains(this->MousePositionF)) {
					this->cat_img3.move(0, -30);
					cat_bool3 = true;
					this->window->draw(this->cat_img3);
					if (Mouse::isButtonPressed(Mouse::Left) and !this->selected) {
						this->cat_number = 3;
						this->cat_chosen.setFont(this->font);
						this->cat_chosen.setPosition(170, 347);
						this->cat_chosen.setString("You choose the third cat");
						this->cat_chosen.setFillColor(Color::Black);
						this->cat_chosen.setCharacterSize(13);
						chosen = true;
					}
				}
				if (!cat_bool1)
					this->window->draw(this->cat_img1);
				if (!cat_bool2)
					this->window->draw(this->cat_img2);
				if (!cat_bool3)
					this->window->draw(this->cat_img3);
				if (chosen) {
					this->window->draw(this->cat_chosen);
				}
				this->window->draw(this->go_back);

				this->window->display();
			}

		}
	}
	if (this->cat_number == 1) {
		this->cat_text.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\images_balls\\cat1.png");
		this->cat.setTexture(this->cat_text);
	}
	else if (this->cat_number == 2) {
		this->cat_text.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\images_balls\\cat2.png");
		this->cat.setTexture(this->cat_text);
	}
	else if (this->cat_number == 3) {
		this->cat_text.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\images_balls\\cat3.png");
		this->cat.setTexture(this->cat_text);
	}
	return false;
}

void game::initenemies() {
	this->dog_text.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\images_balls\\dog.png");
	this->cat_text.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\images_balls\\cat1.png");
	this->background_text.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\images_balls\\background.jpg");
	this->background.setTexture(this->background_text);
	this->img.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\images_balls\\fish5.png");
	this->dog.setTexture(this->dog_text);
	this->cat_text.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\images_balls\\cat1.png");
	this->enemy.setTexture(this->img);
	this->cat.setTexture(this->cat_text);
	this->cat.setPosition(Vector2f(200, 500));
	this->background.setPosition(0, 0);
}

void game::initFont() {
	this->font.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\ConsoleApplication3\\Font\\TTF\\dogica.ttf");
	this->text.setFont(this->font);
	this->Start.setCharacterSize(40);
	this->text.setCharacterSize(20);
	this->text.setFillColor(Color::Black);
	this->text.setPosition(130, 10);
	this->Score.setFont(font);
	this->Score.setCharacterSize(20);
	this->Score.setFillColor(Color::Black);
	this->Score.setPosition(10, 10);
	this->Score.setString("Score: ");
	this->text.setString("0");
	this->health.setFont(font);
	this->health.setCharacterSize(20);
	this->health.setFillColor(Color::Black);
	this->health.setPosition(150, 40);
	this->health.setString("40");
	this->text_health.setFont(font);
	this->text_health.setCharacterSize(20);
	this->text_health.setFillColor(Color::Black);
	this->text_health.setPosition(10, 40);
	this->text_health.setString("Health: ");
	this->Exit.setFont(this->font);
	this->Exit.setPosition(170, 200);
	this->Exit.setString("Game Over");
	this->Exit.setFillColor(Color::Red);
	this->Exit.setCharacterSize(30);
	this->Restart.setFont(this->font);
	this->Restart.setString("Restart");
	this->Restart.setFillColor(Color::Blue);
	this->Restart.setCharacterSize(30);
	this->Restart.setPosition(200, 263);


}

void game::initialization() {
	this->end_B.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\images_balls\\game_over.ogg");
	this->eat_B.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\images_balls\\eat.ogg");
	this->err_B.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\images_balls\\fail.ogg");
	this->end.setBuffer(this->end_B);
	this->eat.setBuffer(this->eat_B);
	this->err.setBuffer(this->err_B);
	this->exitFromGame = false;
	this->videoMode.height = 600;
	this->videoMode.width = 600;
	this->window = new RenderWindow(this->videoMode, "New game");
	this->window->setFramerateLimit(70);
	this->points = 0;
	this->Health_score = 40;
	this->spawnEnemyTimer = 0;
	this->spawnEnemyTimerMax = 60;
	this->spawnEnemySizeMax = 60;
	this->mouseC = false;
}

game::game() {
	this->intvar();
	this->initFont();
	this->initialization();
	this->initenemies();
}
game::~game() {
	delete this->window;
}
const bool game::running() const{
	return this->window->isOpen();
}
void game::Update() {
	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case Event::Closed :
			this->window->close();
			break;
		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				if (this->cat.getPosition().x < 520) {
					this->cat.move(40, 0);
					}
			}
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				if (this->cat.getPosition().x > 13)
					this->cat.move(-40, 0);
			}
			break;
		case Event::MouseMoved :
			this->updateMousePosition();
			break;
		}
	}
	this->UpdateSpawnEnemies();
}
void game::setExit() {
	if (this->exitFromGame)
		this->exitFromGame = false;
	else
		this->exitFromGame = true;
}

bool game::getExit() {
	return this->exitFromGame;
}
void game::Render() {
	//while (this->PlayGame()) {}
	this->window->clear();
	this->window->draw(this->background);
	this->window->draw(this->cat);
	this->window->draw(this->Score);
	this->window->draw(this->text);
	this->window->draw(this->text_health);
	if (this->Health_score == 0) {
		this->end.play();
		this->health.setString("0");
		this->Score.setPosition(220, 240);
		this->text.setPosition(340, 240);
		this->ExitGame.setFont(this->font);
		this->ExitGame.setPosition(220, 300);
		this->ExitGame.setString("Exit");
		this->ExitGame.setFillColor(Color::Black);
		this->ExitGame.setCharacterSize(40);
		this->window->draw(this->text);
		this->window->draw(this->Score);
		this->window->draw(this->health);
		this->window->draw(this->Restart);
		this->window->draw(this->ExitGame);
		this->RenderEnemy();
		this->window->draw(this->Exit);
		this->window->display();
		bool healthDrawn = true;
		while (healthDrawn) {
			this->updateMousePosition();
			if (this->Restart.getGlobalBounds().contains(this->MousePositionF)) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					healthDrawn = false;
					this->text.setFont(this->font);
					this->Start.setCharacterSize(40);
					this->text.setCharacterSize(20);
					this->text.setFillColor(Color::Black);
					this->text.setPosition(130, 10);
					this->Score.setFont(font);
					this->Score.setCharacterSize(20);
					this->Score.setFillColor(Color::Black);
					this->Score.setPosition(10, 10);
					this->Score.setString("Score: ");
					this->text.setString("0");
					this->health.setFont(font);
					this->health.setCharacterSize(20);
					this->health.setFillColor(Color::Black);
					this->health.setPosition(150, 40);
					this->health.setString("40");
					this->text_health.setFont(font);
					this->text_health.setCharacterSize(20);
					this->text_health.setFillColor(Color::Black);
					this->text_health.setPosition(10, 40);
					this->text_health.setString("Health: ");
					this->points = 0;
					this->Health_score = 50;
					this->spawnEnemyTimerMax = 60;
					this->spawnEnemySizeMax = 60;
					this->window->setFramerateLimit(70);
					this->window->display();
				}
			}
			else if (this->ExitGame.getGlobalBounds().contains(this->MousePositionF)) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					this->window->close();
				}
			}
		}
	}
	else {
		this->window->draw(this->health);
	}
	this->RenderEnemy();
	this->window->display();
	
}
void game::updateMousePosition() {
	this->MousePosition = Mouse::getPosition(*this->window);
	this->MousePositionF = this->window->mapPixelToCoords(this->MousePosition);
}
void game::spawnEnemy() {
	float a = static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - 60));
	float b = static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - 90));
	if ((b >= a - 90) and (b <= a)) {
		b = b - 160;
	}
	else if ((b > a) and (b <= a + 90)) {
		b = b + 160;
	}
	if (b < 30) {
		b = 320;
	}
	else if (b > 530) {
		b = 70;
	}
	this->enemy.setPosition(a, 0.f);
	this->dog.setPosition(b, 0.f);
	this->enemies.push_back(this->enemy);
	this->dogs.push_back(this->dog);
}
void game::UpdateSpawnEnemies() {
	
	if (this->enemies.size() <= this->spawnEnemySizeMax) {
		if (this->spawnEnemyTimer >= this->spawnEnemyTimerMax) {
			this->spawnEnemy();
			this->spawnEnemyTimer = 0;
		}
		else {
			this->spawnEnemyTimer += 1.f;
		}
	}
	for (int i = 0; i < this->enemies.size(); i++) {
		this->enemies[i].move(0.f, 5.f);
		if (this->enemies[i].getPosition().y >= this->window->getSize().y) {
			this->enemies.erase(this->enemies.begin() + i);
		}
	}
	for (int i = 0; i < this->dogs.size(); i++) {
		this->dogs[i].move(0.f, 5.f);
		if (this->dogs[i].getPosition().y >= this->window->getSize().y) {
			this->dogs.erase(this->dogs.begin() + i);

		}
	}
}
void game::RenderEnemy() {
	for (int i = 0; i < this->enemies.size(); i++) {
		this->window->draw(this->enemies[i]);
		if (this->enemies[i].getGlobalBounds().intersects(this->cat.getGlobalBounds())) {
			this->enemies.erase(this->enemies.begin() + i);
			this->points += 10;
			this->eat.play();
			this->S = this->points;
			this->text.setString(std::to_string(this->points));
			if (this->points == 100) {
				this->window->setFramerateLimit(100);
				this->spawnEnemyTimerMax = 50;
			}
			if (this->points == 200) {
				this->window->setFramerateLimit(150);
				this->spawnEnemyTimerMax = 35;
			}
			if (this->points == 300) {
				this->window->setFramerateLimit(200);
				this->spawnEnemyTimerMax = 33;
			}
			if (this->points == 400) {
				this->spawnEnemyTimerMax = 30;
			}
			this->text.setString(std::to_string(this->points));
		}
	}
	bool deleted = false;
	for (int i = 0; i < this->dogs.size(); i++) {
		this->window->draw(this->dogs[i]);
		if (this->dogs[i].getGlobalBounds().intersects(this->cat.getGlobalBounds())) {
			this->Health_score -= 10;
			this->err.play();
			if (this->Health_score > 0) {
				this->dogs.erase(this->dogs.begin() + i);
			}
			this->health.setString(std::to_string(this->Health_score));

		}
	}
}
