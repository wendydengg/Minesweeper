#include <random>
#include <SFML/Graphics.hpp>
#include <chrono>

#include "Cell.hpp"
#include "GameBoard.hpp"
#include "retCell.hpp"


void GameBoard::textDraw(const std::string& text, sf::RenderWindow& wdw, bool blackColor, unsigned short x, unsigned short y) {
	short yChar = y;
	short xChar = x;
	sf::Sprite charSprite;
	unsigned char charWidth;


	sf::Texture textureFont;
	textureFont.loadFromFile("textType.png");

	charWidth = textureFont.getSize().x / 96;

	charSprite.setTexture(textureFont);

	if (1 == blackColor) {
		charSprite.setColor(sf::Color(0, 0, 0));
	}

	for (const char a : text) {
		if ('\n' == a) {
			xChar = x;
			yChar = yChar + textureFont.getSize().y;
			continue;
		}

		charSprite.setPosition(xChar, yChar);
	
		charSprite.setTextureRect(sf::IntRect(charWidth * (a - 32), 0, charWidth, textureFont.getSize().y));

		//Increase the x-coordinate
		xChar = xChar + charWidth;

		//Draw the character
		wdw.draw(charSprite);
	}
}

GameBoard::GameBoard() :
	over(1),
	rando(std::chrono::system_clock::now().time_since_epoch().count()) {
	for (unsigned char a = 0; a < 8; a++) {
		for (unsigned char b = 0; b < 8; b++) {
			cells.push_back(std::unique_ptr<Cell<int>>(new Cell<int>(b, a)));
		}
	}

	restart();
}

unsigned short GameBoard::numFlags() {
	//number of flagged cells
	unsigned short flagNum = 0;

	for (const auto& cellPtr : cells) {
        flagNum += cellPtr->retIsFlag();
	}     
	return flagNum;
}

char GameBoard::retOver() {
	return over;
}

void GameBoard::openCell(unsigned char ix, unsigned char iy) {
	//first cell opened?
	if (0 == click) {
		std::uniform_int_distribution<unsigned short> x_distribution(0, 8 - 1);
		std::uniform_int_distribution<unsigned short> y_distribution(0, 8 - 1);

		click = 1;

		//mine generation
		for (unsigned short a = 0; a < 14; a++) {
			unsigned char mine_x = static_cast<unsigned char>(x_distribution(rando));
			unsigned char mine_y = static_cast<unsigned char>(y_distribution(rando));

			//if cell has mine or player wants to open it
			if ((ix == mine_x && iy == mine_y) || retCell(cells, mine_x, mine_y) -> retIsMine() == 1) {
				a--;
			}
			else {
				retCell(cells, mine_x, mine_y)->mineSet();
			}
		}

		//after mine generation, minecount for each cell
		for (auto& cellPtr : cells) {
        cellPtr->numMinesSurrounding(cells);
    	}
	}

	//game over of flagged cell
	if (0 == over && 0 == retCell(cells, ix, iy)->retIsFlag()) {
		if (1 == retCell(cells, ix, iy) -> open(cells)) {
			over = -1;
		}
		else {
			unsigned short closedCellCount = 0;

			//how many cells closed?
			for (auto& cellPtr : cells) {
                closedCellCount += !cellPtr->retIsOpen();
			}

			//closed cells equals mine num
			if (closedCellCount == 14) {
				over = 1;
			}
		}
	}
}

void GameBoard::draw(sf::RenderWindow& wdw) {
	//draw cells
	sf::RectangleShape shapeOfCell(sf::Vector2f(15, 15));
	sf::Sprite sprite;

	sf::Texture texture;
	texture.loadFromFile("Nums" + std::to_string(16) + ".png");

	sprite.setTexture(texture);

	for (unsigned char a = 0; a < 8; a++) {
		for (unsigned char b = 0; b < 8; b++) {
			shapeOfCell.setPosition(static_cast<float>(16 * a), static_cast<float>(16 * b));

			if (1 == retCell(cells, a, b) -> retIsOpen())
			{
				//number of mines around
				unsigned char mines_around = retCell(cells, a, b) -> retMinesSurrounding();

				shapeOfCell.setFillColor(sf::Color(128, 0, 128));

				//draw cell
				wdw.draw(shapeOfCell);

				//check surrounding mines
				if (0 < mines_around)
				{
					sprite.setPosition(static_cast<float>(16 * a), static_cast<float>(16 * b));
					sprite.setTextureRect(sf::IntRect(16 * mines_around, 0, 16, 16));
					wdw.draw(sprite);
				}
			}
			else
			{
				shapeOfCell.setFillColor(sf::Color(0, 255, 0));

				if (0 == over && 0 != retCell(cells, a, b) -> mouseState()) {
					if (1 == retCell(cells, a, b) -> mouseState()) {
						shapeOfCell.setFillColor(sf::Color(36, 109, 255));
					} else if (2 == retCell(cells, a, b) -> mouseState()) {    
						shapeOfCell.setFillColor(sf::Color(0, 36, 255));
					}
				}


				wdw.draw(shapeOfCell);

				//If the cell is flagged
				if (1 == retCell(cells, a, b) -> retIsFlag()) {
					sprite.setPosition(static_cast<float>(16 * a), static_cast<float>(16 * b));
					sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));

					wdw.draw(sprite);
				}
			}

			//Reset the cell's mouse state
			retCell(cells, a, b) -> MouseStateSet(0);

		}
	}

	// Check if the game is won or lost
    if (over == -1 || over == 1) {
        // Draw a red screen
        sf::RectangleShape redScreen(sf::Vector2f(16 * 8, 16 * 8));
        redScreen.setFillColor(sf::Color(255, 0, 0, 150)); // Red with some transparency
        wdw.draw(redScreen);

        // Display the text
        if (1 == over) {
            textDraw("VICTORY!", wdw, 1, static_cast<unsigned short>(round(0.5f * (16 * 8 - 8 * 8))),
                      static_cast<unsigned short>(round(0.5f * (16 * 8 - 16))));
        }
        else {
            textDraw("GAME OVER", wdw, 1, static_cast<unsigned short>(round(0.5f * (16 * 8 - 4 * 8))),
                      static_cast<unsigned short>(round(0.5f * (16 * 8 - 2 * 16))));
        }
    }
}

void GameBoard::flag_cell(unsigned char flagx, unsigned char flagy) {
	if (over == 0) {
		retCell(cells, flagx, flagy) -> flag();
	}
}

void GameBoard::fieldMouseState(unsigned char isMouse, unsigned char ix, unsigned char iy) {
	retCell(cells, ix, iy) -> MouseStateSet(isMouse);
}

void GameBoard::restart() {
	if (0 != over) {
        over = 0;
		click = 0;
		for (auto& cellPtr : cells) {
            cellPtr->reset();
		}
	}
}
