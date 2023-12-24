#include "Asteroid.h"
#include "SpaceShip.h"
#include "Bullet.h"
using namespace std;

//Global Const Variables
//---------------------------------------------
const int screenWidth = 1400;
const int screenHeight = 800;
SpaceShip player(Point(450, 700), Point(500, 675), Point(550, 700), Gun(Point(475, 675), 3, 25, WHITE), Gun(Point(525, 675), 3, 25, WHITE), 400, 400, WHITE);

int numAsteroids = 10;
vector<Asteroid> asteroids(numAsteroids);

int score;
int oldHighScore;
int life;

int redGain = -1;
int orangeGain = 100;
int greenGain = 1;
int newAsteroidFrequency = 10;
int bulletFrequency = 50;

int numBullets = 0;
vector<Bullet> bullets(numBullets);
int bulletFreCounter;

//---------------------------------------------

Asteroid getNewAsteroid()
{
	int ran = rand() % 50;
	Color color = RED;
	string colorStr = "RED"; //lose health
	if (ran == 0)
	{
		color = ORANGE; //gain score
		colorStr = "ORANGE";
	}
	else if (ran == 1)
	{
		color = GREEN; //gain health
		colorStr = "GREEN";
	}
	return Asteroid(rand() % GetScreenWidth(), (rand() % 500) * -1, rand() % 200 - 100, rand() % 300 + 100 + score / 2, rand() % 40 + 5, color, colorStr);
}

void createBullets()
{
	numBullets += 2;
	bullets.push_back(Bullet(player.getLeftGun().getFirePoint().getX(), player.getLeftGun().getFirePoint().getY(), 5, 20, 1000, BLUE));
	bullets.push_back(Bullet(player.getRightGun().getFirePoint().getX(), player.getRightGun().getFirePoint().getY(), 5, 20, 1000, BLUE));
}

void SetUp()
{
	//Clear bullets for new game
	bullets.erase(bullets.begin(), bullets.begin() + numBullets);
	numBullets = 0;

	//Clear asteroids for new game
	asteroids.erase(asteroids.begin() + 10, asteroids.begin() + numAsteroids);
	numAsteroids = 10;

	score = 0;
	oldHighScore = -1;
	life = 5;
	bulletFreCounter = bulletFrequency + 1;
	for (int i = 0; i < numAsteroids; i++)
	{
		asteroids[i] = getNewAsteroid();
	}
	player = SpaceShip(Point(450, 700), Point(500, 675), Point(550, 700), Gun(Point(475, 675), 3, 25, WHITE), Gun(Point(525, 675), 3, 25, WHITE), 400, 400, WHITE);
}

void Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	if (life > 0)
	{
		player.Draw();
		for (int i = 0; i < asteroids.size(); i++)
			asteroids.at(i).Draw();
		for (int i = 0; i < bullets.size(); i++)
			bullets.at(i).Draw();
		DrawText(to_string(score).c_str(), 10, 10, 60, YELLOW);
		DrawText(to_string(life).c_str(), 10, GetScreenHeight() - 60, 60, YELLOW);
	}
	else
	{
		char message[50];

		//Get Highscore
		int textWidth;
		if (oldHighScore == -1)
		{
			ifstream fin;
			fin.open("HighScore.txt");
			fin >> oldHighScore;
			fin.close();
		}
		if (oldHighScore < score)
		{
			fstream fout;
			fout.open("HighScore.txt");
			fout << score;
			fout.close();
			textWidth = MeasureText("New High Score", 60);
			DrawText("New High Score", GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 - 120, 60, YELLOW);
		}
		else
		{
			strcpy_s(message, "High Score: ");
			strcat_s(message, to_string(oldHighScore).c_str());
			textWidth = MeasureText(message, 60);
			DrawText(message, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 - 120, 60, YELLOW);
		}

		//Gameover
		textWidth = MeasureText("Game over", 60);
		DrawText("Game over", GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 - 60, 60, YELLOW);
		
		//score
		strcpy_s(message, "Your Score: ");
		strcat_s(message, to_string(score).c_str());
		textWidth = MeasureText(message, 60);
		DrawText(message, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2, 60, YELLOW);

		if (IsKeyDown(KEY_SPACE))
		{
			SetUp();
		}

	}
	EndDrawing();
}

void Input()
{
	if (IsKeyDown(KEY_W)) player.moveUp();
	if (IsKeyDown(KEY_D)) player.moveRight();
	if (IsKeyDown(KEY_A)) player.moveLeft();
	if (IsKeyDown(KEY_S)) player.moveDown();
	if (IsKeyDown(KEY_F))
	{
		if (bulletFreCounter > bulletFrequency)
		{
			createBullets();
			bulletFreCounter = 0;
		}
	}
	bulletFreCounter++;
}

void Logic()
{
	//Asteroids
	for (int i = 0; i < asteroids.size(); i++)
	{
		asteroids.at(i).setX(asteroids.at(i).getX() + asteroids.at(i).getSpeedX() * GetFrameTime());
		asteroids.at(i).setY(asteroids.at(i).getY() + asteroids.at(i).getSpeedY() * GetFrameTime());

		//Asteroid leaves play area
		if (asteroids.at(i).getX() > GetScreenWidth() + 100 || asteroids.at(i).getX() < 0 - 100 || asteroids.at(i).getY() > GetScreenHeight() + 100)
		{
			if (asteroids.at(i).getColorStr() == "RED")
			{
				score++;
				if (score % newAsteroidFrequency == 0)
				{
					numAsteroids++;
					asteroids.push_back(getNewAsteroid());
				}
			}

			asteroids.at(i) = getNewAsteroid();
		}

		//Asteroid collide with SpaceShip
		if (CheckCollisionCircleRec({ asteroids.at(i).getX(), asteroids.at(i).getY() }, asteroids.at(i).getRadius(), player.getLowerHitBox().getRec()) || CheckCollisionCircleRec({ asteroids.at(i).getX(), asteroids.at(i).getY() }, asteroids.at(i).getRadius(), player.getUpperHitBox().getRec()))
		{
			if (asteroids.at(i).getColorStr() == "RED") life += redGain;
			else if (asteroids.at(i).getColorStr() == "ORANGE") score += orangeGain;
			else if (asteroids.at(i).getColorStr() == "GREEN") life += greenGain;

			asteroids.at(i) = getNewAsteroid();
		}
	}
	

	//Bullets
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets.at(i).setY(bullets.at(i).getY() - bullets.at(i).getSpeed() * GetFrameTime());

		//Bullet leaves play area
		if (bullets.at(i).getY() < -100)
		{
			bullets.erase(bullets.begin() + i);
			i--;
			numBullets--;
		}
		else
		{
			//Bullet collides with Asteroid
			for (int aster = 0; aster < numAsteroids; aster++)
			{
				if (CheckCollisionCircleRec({ asteroids[aster].getX(), asteroids[aster].getY() }, asteroids[aster].getRadius(), bullets[i].getRec()))
				{
					bullets.at(i).setY(-1000);
					if (asteroids.at(aster).getColorStr() == "RED")
					{
						score++;
						if (score % newAsteroidFrequency == 0)
						{
							numAsteroids++;
							asteroids.push_back(getNewAsteroid());
						}
					}
					asteroids[aster] = getNewAsteroid();	
				}
			}
		}
	}
	
}

int main()
{
	InitWindow(screenWidth, screenHeight, "Spaceship Shooter");
	SetWindowState(FLAG_VSYNC_HINT);
	srand(time(0));

	SetUp();
	while (!WindowShouldClose())
	{
		Draw();
		if (life > 0)
		{
			Input();
			Logic();
		}
	}
	CloseWindow();
	return 0;
}