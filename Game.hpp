//1. first click is always safe (lands on number or blank)
//2. if clicked on bomb, game ends
//2.a when game ends, player cant do any further move, only restart button is clickable
//3. else, if clicked on number or a blank tile, all adjacent cells will automatically be opened
//3.a chain reaction: any blank tiles opened by other blank tiles open the surrounding tiles too
//to win, all non-mine cells must be open without opening a mine
