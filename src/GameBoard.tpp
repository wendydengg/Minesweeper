// // GameBoard.tpp - Template Implementation for GameBoard class

// template<typename T>
// GameBoard<T>::GameBoard() : over(1), rando(std::chrono::system_clock::now().time_since_epoch().count()) {
//     for (T a = 0; a < 8; a++) {
//         for (T b = 0; b < 8; b++) {
//             cells.push_back(Cell<T>(b, a));
//         }
//     }
//     restart();
// }

// template<typename T>
// void GameBoard<T>::textDraw(const std::string& text, sf::RenderWindow& wdw, bool blackColor, unsigned short x, unsigned short y) {
//     short yChar = y;
//     short xChar = x;
//     sf::Sprite charSprite;
//     unsigned char charWidth;


//     sf::Texture textureFont;
//     textureFont.loadFromFile("textType.png");

//     charWidth = textureFont.getSize().x / 96;
//     charSprite.setTexture(textureFont);

//     if (1 == blackColor) {
//         charSprite.setColor(sf::Color(0, 0, 0));
//     }

//     for (const char a : text) {
//         if (a == '\n') {
//             xChar = x;
//             yChar += textureFont.getSize().y;
//             continue;
//         }

//         charSprite.setPosition(xChar, yChar);
//         charSprite.setTextureRect(sf::IntRect(charWidth * (a - 32), 0, charWidth, textureFont.getSize().y));
//         xChar += charWidth;
//         wdw.draw(charSprite);
//     }
// }

// template<typename T>
// void GameBoard<T>::draw(sf::RenderWindow& i_window) {
// //draw cells
// 	sf::RectangleShape shapeOfCell(sf::Vector2f(15, 15));
// 	sf::Sprite sprite;

// 	sf::Texture texture;
// 	texture.loadFromFile("Nums" + std::to_string(16) + ".png");

// 	sprite.setTexture(texture);

// 	for (unsigned char a = 0; a < 8; a++) {
// 		for (unsigned char b = 0; b < 8; b++) {
// 			shapeOfCell.setPosition(static_cast<float>(16 * a), static_cast<float>(16 * b));

// 			if (1 == retCell(cells, a, b) -> retIsOpen())
// 			{
// 				//number of mines around
// 				unsigned char mines_around = retCell(cells, a, b) -> retMinesSurrounding();

// 				shapeOfCell.setFillColor(sf::Color(128, 0, 128));

// 				//draw cell
// 				wdw.draw(shapeOfCell);

// 				//check surrounding mines
// 				if (0 < mines_around)
// 				{
// 					sprite.setPosition(static_cast<float>(16 * a), static_cast<float>(16 * b));
// 					sprite.setTextureRect(sf::IntRect(16 * mines_around, 0, 16, 16));
// 					wdw.draw(sprite);
// 				}
// 			}
// 			else
// 			{
// 				shapeOfCell.setFillColor(sf::Color(0, 255, 0));

// 				if (0 == over && 0 != retCell(cells, a, b) -> mouseState()) {
// 					if (1 == retCell(cells, a, b) -> mouseState()) {
// 						shapeOfCell.setFillColor(sf::Color(36, 109, 255));
// 					} else if (2 == retCell(cells, a, b) -> mouseState()) {    
// 						shapeOfCell.setFillColor(sf::Color(0, 36, 255));
// 					}
// 				}


// 				wdw.draw(shapeOfCell);

// 				//If the cell is flagged
// 				if (1 == retCell(cells, a, b) -> retIsFlag()) {
// 					sprite.setPosition(static_cast<float>(16 * a), static_cast<float>(16 * b));
// 					sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));

// 					wdw.draw(sprite);
// 				}
// 			}

// 			//Reset the cell's mouse state
// 			retCell(cells, a, b) -> MouseStateSet(0);

// 		}
// }

// template<typename T>
// void GameBoard<T>::restart() {
//     // ... Implement restart method ...
// }

// template<typename T>
// unsigned short GameBoard<T>::numFlags() {
//     // ... Implement numFlags method ...
//     return 0; // placeholder
// }

// template<typename T>
// char GameBoard<T>::retOver() {
//     return over;
// }

// template<typename T>
// void GameBoard<T>::flag_cell(T flagx, T flagy) {
//     // ... Implement flag_cell method ...
// }

// template<typename T>
// void GameBoard<T>::openCell(T i_x, T i_y) {
//     // ... Implement openCell method ...
// }

// template<typename T>
// void GameBoard<T>::fieldMouseState(unsigned char i_mouse_state, T i_x, T i_y) {
//     // ... Implement fieldMouseState method ...
// }

// // Explicitly instantiate your GameBoard for the types you use
// template class GameBoard<unsigned char>;