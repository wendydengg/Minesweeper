#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>

#include "Cell.hpp"
#include "GameBoard.hpp"

int main() {
	unsigned holdbacktime = 0;
	 std::chrono::time_point<std::chrono::steady_clock> beforeTime;
	 sf::Event occurance;

	 sf::RenderWindow window(sf::VideoMode(16 * 8 * 5, 5 * (16 + 16 * 8)), "Minesweeper", sf::Style::Close);
	 window.setView(sf::View(sf::FloatRect(0, 0, 16 * 8, 16 + 16 * 8)));

	 GameBoard field;
	 beforeTime = std::chrono::steady_clock::now();

	while (1 == window.isOpen()) {
		unsigned changeTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - beforeTime).count();

		holdbacktime = holdbacktime + changeTime;
		beforeTime  = beforeTime + std::chrono::microseconds(changeTime);

		while (holdbacktime >= 16650)
		{
			unsigned char Cell_X_Mouse = static_cast<unsigned char>(std::max(0, std::min(static_cast<int>(floor(sf::Mouse::getPosition(window).x / static_cast<float>(16 * 5))), static_cast<int>(8 - 1))));
            unsigned char Cell_Y_Mouse = static_cast<unsigned char>(std::max(0, std::min(static_cast<int>(floor(sf::Mouse::getPosition(window).y / static_cast<float>(16 * 5))), static_cast<int>(8 - 1))));

			holdbacktime  = holdbacktime - 16650;

			while (window.pollEvent(occurance) == 1)
			{
				if (occurance.type == sf::Event::Closed) {
					window.close();
				} else if (occurance.type == sf::Event::KeyReleased) {
					if (occurance.key.code == sf::Keyboard::Enter) {
						// Restart if Enter is pressed
						field.restart();
					}
				} else if (occurance.type == sf::Event::MouseButtonReleased) {
					if (occurance.mouseButton.button == sf::Mouse::Left) {
						field.openCell(Cell_X_Mouse, Cell_Y_Mouse);
					} else if (occurance.mouseButton.button == sf::Mouse::Right) {
						// Flag under the cursor
						field.flag_cell(Cell_X_Mouse, Cell_Y_Mouse);
					}
				}

			}

			if (1 == sf::Mouse::isButtonPressed(sf::Mouse::Left) || 1 == sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				field.fieldMouseState(2, Cell_X_Mouse, Cell_Y_Mouse);
			}
			else {
				field.fieldMouseState(1, Cell_X_Mouse, Cell_Y_Mouse);
			}
			

			if (16650 > holdbacktime) {
				window.clear();
				field.draw(window);
				field.textDraw("Num Mines: " + std::to_string(14 - field.numFlags()), window, 0, 0, 16 * 8);
				window.display();
			}
		}
	}
}