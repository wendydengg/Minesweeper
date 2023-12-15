# Minesweeper

For our C++ final project, we aim to develop a Minesweeper game, potentially incorporating a graphical user interface (GUI) if time allows. This project will use key libraries and features of C++. The Standard Template Library (STL) will be employed for efficient handling of vectors, sets, and maps, while the <random> library will assist in generating random mine placements. Input and output operations will be facilitated through the <iostream> library, and <cstdint> will be used to specify the size of integers. Templates will play a crucial role in various aspects, including grid representation, game settings, custom data types, and utility functions such as shuffling the grid for the next round, validating user input, and checking for mines in a given cell. 

The project will implement a class hierarchy to organize key components of the game. The "Cell" class will represent individual cells with different statuses (empty, numbered, mine, flagged, opened, unopened). The "Board" class will handle the game board, encompassing cell arrangements and game status (not started, in progress, lost, win). Lastly, the "Game" class will manage the game logic and user interactions. Additionally, we plan to incorporate exception handling to enhance the robustness of our application.

If time permits, we intend to integrate the Simple and Fast Multimedia Library (SFML) to create a GUI. This will introduce features like a timer and a smiley face reset button, enhancing the user experience. The rules of the game are aligned with classic Minesweeper conventions, including the termination of the game when no mines are opened, revealing the number of adjacent mines when clicking on a cell with adjacent mines, and automatically clearing adjacent cells with no mines.

The game will feature three difficulty levels: Beginner (9x9 board with 10 mines), Intermediate (16x16 board with 40 mines), and Advanced (24x24 board with 99 mines). In terms of the project timeline, we anticipate a total duration of three weeks, allocating two weeks for the development of game logic and dedicating the final week to GUI implementation if time permits. To ensure a balanced workload, we plan to split all work evenly.

Game rules can be found on [Wikipedia](https://en.wikipedia.org/wiki/Minesweeper_(video_game)#:~:text=To%20win%20a%20game%20of,starting%20with%20a%20larger%20grid.).
