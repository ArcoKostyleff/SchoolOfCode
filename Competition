#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <String>
#include <vector>
using namespace std;
class AimTrainer
  {
      enum Difficulty { Easy, Medium, Hard };
      Difficulty currentDifficulty;
public:
      AimTrainer() : window(sf::VideoMode(800, 600), "Aim Trainer"), font(), score(0), shotsFired(0), startTime(0), prod(30), maxRadius(25), minRadius(15), currentDifficulty(Easy), numTargets(3)
      {
          font.loadFromFile("ArialRegular.ttf");
          scoreText.setFont(font);
          scoreText.setCharacterSize(24);
          scoreText.setPosition(10, 10);
          shotsText.setFont(font);
          shotsText.setCharacterSize(24);
          shotsText.setPosition(10, 40);
          timeText.setFont(font);
          timeText.setCharacterSize(24);
          timeText.setPosition(10, 70);
          startTimer();
          if (!hitB.loadFromFile("hit.wav"))
          {
              cout << "ERROR" << endl;
          }
          hitS.setBuffer(hitB);
          if (!texture.loadFromFile("target_texture.png"))
          {
              cout << "ERROR" << endl;
          }
          targets.resize(numTargets, sf::CircleShape(20));
          for (auto& target : targets)
          {
              target.setTexture(&texture);
              target.setPosition(rand() % 760 + 20, rand() % 560 + 20);
          }
      }
      void setDifficulty(Difficulty difficulty)
      {
          currentDifficulty = difficulty;
          switch (currentDifficulty)
          {
            case Easy:
                prod = 30;
                maxRadius = 25;
                minRadius = 19;
                numTargets = 3;
                break;
            case Medium:
                prod = 20;
                maxRadius = 17;
                minRadius = 8;
                numTargets = 5;
                break;
            case Hard:
                prod = 10;
                maxRadius = 7;
                minRadius = 5;
                numTargets = 7;
                break;
            default:
                break;
          }
          targets.resize(numTargets, sf::CircleShape(20));
          for (auto& target : targets)
          {
              target.setTexture(&texture);
              target.setPosition(rand() % 760 + 20, rand() % 560 + 20);
          }

          startTimer();
        }

      void run()
      {
          showMenu();
          while (window.isOpen())
          {
              Events();
              update();
              render();
          }
      }

private:
      int readpreviousattempt()
      {
          ifstream file("result.txt");
          int previousattempt = 0;
          if (file.is_open())
          {
              string line;
              while (getline(file, line))
              {
                  if (line.find("Попадания:") == 0)
                  {
                      previousattempt = stoi(line.substr(line.find_last_of(' ') + 1));
                      break;
                  }
              }
              file.close();
          }
          else
          {
              cerr << "ERROR: Unable to open record file" << endl;
          }
          return previousattempt;
      }

      void showMenu()
      {
          if (!easyButtonTexture.loadFromFile("easy.png"))
          {
              cout << "ERROR" << endl;
          }
          if (!mediumButtonTexture.loadFromFile("Medium.png"))
          {
              cout << "ERROR" << endl;
          }
          if (!hardButtonTexture.loadFromFile("demon.png"))
          {
              cout << "ERROR" << endl;
          }
          if (!selectTexture.loadFromFile("select.png"))
          {
              cout << "ERROR" << endl;
          }
          sf::Text previousattemptText;
          previousattemptText.setFont(font);
          previousattemptText.setCharacterSize(25);
          previousattemptText.setPosition(10, 50);
          int previousattempt = readpreviousattempt();
          stringstream sspreviousattempt;
          sspreviousattempt << "previous attempt: " << previousattempt;
          previousattemptText.setString(sspreviousattempt.str());
          sf::RectangleShape selectRect(sf::Vector2f(250, 100));
          selectRect.setPosition(275, 50);
          selectRect.setTexture(&selectTexture);
          sf::RectangleShape easyRect(sf::Vector2f(100, 100));
          easyRect.setPosition(350, 200);
          easyRect.setTexture(&easyButtonTexture);
          sf::RectangleShape mediumRect(sf::Vector2f(100, 100));
          mediumRect.setPosition(350, 325);
          mediumRect.setTexture(&mediumButtonTexture);
          sf::RectangleShape hardRect(sf::Vector2f(100, 100));
          hardRect.setPosition(350, 450);
          hardRect.setTexture(&hardButtonTexture);
          sf::Font font;
          font.loadFromFile("ArialRegular.ttf");
          while (true)
          {
              sf::Event event;
              while (window.pollEvent(event))
              {
                  if (event.type == sf::Event::Closed)
                      window.close();
                  else if (event.type == sf::Event::MouseButtonPressed)
                  {
                      if (easyRect.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                      {
                          setDifficulty(Easy);
                          return;
                      }
                      else if (mediumRect.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                      {
                          setDifficulty(Medium);
                          return;
                      }
                      else if (hardRect.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                      {
                          setDifficulty(Hard);
                          return;
                      }
                  }
              }
              window.clear(sf::Color::Blue);
              window.draw(easyRect);
              window.draw(previousattemptText);
              window.draw(mediumRect);
              window.draw(hardRect);
              window.draw(selectRect);
              window.display();
          }
      }
      void Events()
      {
          sf::Event event;
          while (window.pollEvent(event))
          {
              if (event.type == sf::Event::Closed)
                  window.close();
              else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                  MouseClick(event.mouseButton.x, event.mouseButton.y);
          }
      }
      void update()
      {
          time_t currentTime = time(0);
          int remainingTime = prod - difftime(currentTime, startTime);
          if (remainingTime < 0)
          {
              remainingTime = 0;
              saveStatistics();
              window.close();
              return;
          }
          stringstream ss3;
          ss3 << "Time left: " << remainingTime;
          timeText.setString(ss3.str());
          for (auto& target : targets)
          {
              float scale = 1 + sin(time(0) * 0.5) * 0.5;
              target.setRadius(20 * scale);
          }
          stringstream ss;
          ss << "Score: " << score;
          scoreText.setString(ss.str());
          stringstream ss2;
          ss2 << "All shots: " << shotsFired;
          shotsText.setString(ss2.str());
      }
      void render()
      {
          window.clear(sf::Color::Blue);
          for (auto& target : targets)
          {
              window.draw(target);
          }
          window.draw(scoreText);
          window.draw(shotsText);
          window.draw(timeText);
          window.display();
      }
      void MouseClick(int x, int y)
      {
          shotsFired++;
          for (auto& target : targets)
          {
              if (target.getGlobalBounds().contains(x, y))
              {
                  score++;
                  target.setPosition(rand() % 760 + 20, rand() % 560 + 20);
                  target.move(rand() % 10 - 5, rand() % 10 - 5);
                  break;
              }
          }
          hitS.play();
      }
      void startTimer()
      {
          startTime = time(0);
      }
      void saveStatistics()
      {
          ofstream file("result.txt");
          if (file.is_open())
          {
              file << "Попадания: " << score << endl;
              file << "Всего выстрелов: " << shotsFired << endl;
              file.close();
          }
          else
          {
              cerr << "ERROR" << endl;
          }
      }
private:
        sf::RenderWindow window;
        sf::Font font;
        sf::Text scoreText;
        sf::Text shotsText;
        sf::Text timeText;
        sf::SoundBuffer hitB;
        sf::Sound hitS;
        int score;
        int shotsFired;
        time_t startTime;
        int prod;
        float maxRadius;
        float minRadius;
        int numTargets;
        vector<sf::CircleShape> targets;
        sf::Texture texture;
        sf::Texture easyButtonTexture;
        sf::Texture mediumButtonTexture;
        sf::Texture hardButtonTexture;
        sf::Texture selectTexture;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    AimTrainer aimTrainer;
    aimTrainer.run();
    return 0;
}
