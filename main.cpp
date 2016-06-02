#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

typedef struct{
	char x;
	char y;
} Vector;

typedef struct{
	// name of the chess piece
	char pion_type[10];
	
	// player that once piece
	bool player_one;
	
	// boolean to check if this piece is moved during the game
	bool moved;
	
} Chess_piece;

typedef struct{
	bool used;
	Chess_piece piece;
} Tile;

bool string_equal( const char * s, const char * t ) {
	
	// start var
	int i = 0;
	
	// increment i till string parameters are not equal
	while(s[i] == t[i]) {
		
		// if both values are the same and its a zero terminator, life is good
		if(s[i] == '\0') {
			return true;
		}
		
		i++;
		
	}
	
	return false;
}

// function will only check if the given vectors are possible with the selected piece
bool can_piece_make_dir_vector(const Chess_piece piece, const Vector vector, const Tile tile, bool player_one) {
	
	const char pion_check[10] = "pion";
	
	if(string_equal(piece.pion_type, pion_check)) {
		
		// pion for walking player one/ bottom
		if(string_equal(piece.pion_type, pion_check) && piece.player_one == true) {
			
			if(vector.x == 0 && vector.y == 1) {
				return true;
			}
		}
		
		// pion for walking player two / top
		if(string_equal(piece.pion_type, pion_check) && piece.player_one == false) {
			
			if(vector.x == 0 && vector.y == -1) {
				return true;
			}
		}
	
		// when the pion is never used, he can walk 2 tiles forwards
		if(piece.moved == false) {
			
			// when he does not want to move in x
			if(vector.x == 0) {
				
				// taking two steps as direction
				if(player_one == true && vector.y == 2) {
					return true;
				}
				
				if(player_one == false && vector.y == -2) {
					return true;
				}
			}
		}
		
		// extra check for pion. Pion can move other move when hitting enemy piece.
		// check if the destination tile is used
		if(tile.used == true) {
			
			// if the current player is NOT equal on the player that used the tile
			if(tile.piece.player_one != player_one) {
				
				// vector validation player 1 for hitting the enemy
				if(player_one == true) {
						
					if(vector.y == 1 & vector.x == 1 || vector.x == -1) {
						
						return true;
					}
				}
				
				// vector validation player 2 for hitting the enemy
				if(player_one == false) {
						
					if(vector.y == -1 & vector.x == 1 || vector.x == -1) {
						
						return true;
					}
				}
				
			}
		}
		
		return false;
		
	}
	
	const char tower_check[10] = "tower";
	
	// tower
	if(string_equal(piece.pion_type, tower_check)) {
		
		if(vector.x == 0 && vector.y != 0 || vector.x != 0 && vector.y == 0) {
				return true;
		}
		
		return false;
	}
	
	const char walker_check[10] = "walker";
	
	// walker
	if(string_equal(piece.pion_type, walker_check)) {
		
		if(vector.x == vector.y || vector.x == abs(vector.y) || abs(vector.x) == vector.y) {
			return true;
		}
		
		return false;
	}
	
	const char horse_check[10] = "horse";
	
	// horse
	if(string_equal(piece.pion_type, horse_check)) {
		
		// L move with the x
		if(vector.x == 2 || vector.x == -2 && vector.y == 1 || vector.y == -1) {
			return true;
		}
		
		// L move with the y
		if(vector.x == 1 || vector.x == -1 && vector.y == 2 || vector.y == -2) {
			return true;
		}

		return false;
	}
	
	const char queen_check[10] = "queen";
	
	if(string_equal(piece.pion_type, queen_check)) {
		
		// walker move
		if(vector.x == vector.y || vector.x == abs(vector.y) || abs(vector.x) == vector.y) {
			return true;
		}
		
		// tower move
		if(vector.x == 0 && vector.y != 0 || vector.x != 0 && vector.y == 0) {
			return true;
		}
		
		return false;
	}
	
	const char king_check[10] = "king";
	
	if(string_equal(piece.pion_type, king_check)) {
		
		// walker move with one move
		if(vector.x == vector.y || vector.x == abs(vector.y) || abs(vector.x) == vector.y && vector.x < 2 && vector.y < 2) {
			return true;
		}
		
		// tower move with one step!
		if(vector.x == 0 && vector.y == 1 || vector.x == 1 && vector.y == 0) {
			return true;
		}
		
		return false;
	}
	
	return false;
}

// check if any piece is on the tile
bool chess_piece_on_tile(const Tile tile) {

		// is there any piece on the tile
		if(tile.used == true) {
			return true;
		} 
		
		// nothing is on this tile
		return false;
}

// check if the piece of the player in parameter is on tile
bool my_piece_on_tile(bool player_one, const Tile tile) {
		
	// check if there is any piece on tile
	if(chess_piece_on_tile(tile)) {
	
		if(tile.piece.player_one == player_one) {
			return true;
		}
	}
	
	return false;
}

// print chess board on the c console
void print_board( Tile tiles[][8]) {
	
	printf("\n");
	printf("\n");
	
	int i = 8;
	int j = 0;
	int z = 0;
	
	for(int z = 0; z < 8; z++) {
		printf("|.%d.|", z);
	}
	printf("\n");
	
	for(i = 7; i >= 0; i-- ) {
		
		for(j = 0; j < 8; j++ ) {
			
			if(tiles[i][j].used == true) {
				printf("|.%c.|", tiles[i][j].piece.pion_type[0], tiles[i][j].piece.player_one);
			} else {
				printf("|...|");
			}
		}
		printf("|.%d.|", i);
		printf("\n");
	}
	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	
}

// initialise playground from start
void playground_init(Tile tiles[][8]) {
	int i = 0;
	int j = 0;
	
	// setting up pions for player one, bottom
	
	for(i = 0; i < 8; i++ ) {
		
		tiles[1][i] = {true, Chess_piece{"pion", true, false}};
		
	}
	
	// setting up other chess pieces for player one, bottom
	tiles[0][0] = {true, Chess_piece{"tower", true, false}};
	tiles[0][1] = {true, Chess_piece{"horse", true, false}};
	tiles[0][2] = {true, Chess_piece{"walker", true, false}};
	tiles[0][3] = {true, Chess_piece{"king", true, false}};
	tiles[0][4] = {true, Chess_piece{"queen", true, false}};
	tiles[0][5] = {true, Chess_piece{"walker", true, false}};
	tiles[0][6] = {true, Chess_piece{"horse", true, false}};
	tiles[0][7] = {true, Chess_piece{"tower", true, false}};
	

	
	// setting up pions for player two, up
	j = 0;
	
	for(j = 0; j < 8; j++ ) {
		
		tiles[6][j] = {true, Chess_piece{"pion", false, false}};
	}
	
	// setting up other chess pieces for player two, top
	tiles[7][0] = {true, Chess_piece{"tower", false, false}};
	tiles[7][1] = {true, Chess_piece{"horse", false, false}};
	tiles[7][2] = {true, Chess_piece{"walker", false, false}};
	tiles[7][3] = {true, Chess_piece{"king", false, false}};
	tiles[7][4] = {true, Chess_piece{"queen", false, false}};
	tiles[7][5] = {true, Chess_piece{"walker", false, false}};
	tiles[7][6] = {true, Chess_piece{"horse", false, false}};
	tiles[7][7] = {true, Chess_piece{"tower", false, false}};
	
	
	i = 0;
	j = 0;
	
	// init other tiles
	for(i = 2; i < 6;i++) {
		
		for(j = 0; j < 8; j++) {
			tiles[i][j] = {false, Chess_piece{".", false, false}};
		}
	}
}

// recursive function for valid moves
bool check_destination_left(char start_x, char end_x, char current_y, const Tile tiles[][8], bool player_one) {
	
	// made it to the end
	if(start_x == end_x) {
		
		return my_piece_on_tile(player_one, tiles[current_y][end_x]) ?  false :  true;
	}
	
	// something is on direction path
	if(tiles[current_y][start_x - 1].used == true && (start_x - 1) != end_x) {
		return false;
	}
	
	start_x--;
	
	return check_destination_left(start_x, end_x, current_y, tiles, player_one);
}

bool check_destination_right(char start_x, char end_x, char current_y, const Tile tiles[][8], bool player_one) {
	
	// made it to the end
	if(start_x == end_x) {
		
		return my_piece_on_tile(player_one, tiles[current_y][start_x]) ?  false : true;
	}
	
	// something is on direction path
	if(tiles[current_y][start_x + 1].used == true && (start_x + 1) != end_x) {
		return false;
	}
	
	start_x++;
	
	return check_destination_right(start_x, end_x, current_y, tiles, player_one);
}

bool check_destination_up(char start_y, char end_y, char current_x, const Tile tiles[][8], bool player_one) {
	
	// made it to the end
	if(start_y == end_y) {
		
		return my_piece_on_tile(player_one, tiles[start_y][current_x]) ? false : true;
		
	}
	
	// something is on direction path
	if(tiles[start_y + 1][current_x].used == true && (start_y + 1) != end_y) {
		return false;
	}
	
	start_y++;
	
	return check_destination_up(start_y, end_y, current_x, tiles, player_one);
}

bool check_destination_down(char start_y, char end_y, char current_x, const Tile tiles[][8], bool player_one) {
	
	// made it to the end
	if(start_y == end_y) {
		
		return my_piece_on_tile(player_one, tiles[start_y][current_x]) ? false : true;
	}
	
	// something is on direction path and it is not the destination
	if(tiles[start_y - 1][current_x].used == true && (start_y - 1) != end_y) {
		return false;
	}
	
	start_y--;
	
	return check_destination_down(start_y, end_y, current_x, tiles, player_one);
}

bool check_destination_oblique_left_up(char start_x, char start_y, char end_x, char end_y, const Tile tiles[][8], bool player_one) {
	
	// made it to the end
	if(start_x == end_x && start_y == end_y) {
		
		return my_piece_on_tile(player_one, tiles[start_y][start_x]) ? false : true;
	}
	
	// something is on direction path and it is not the destination
	if(tiles[start_y + 1][start_x - 1].used == true && (start_y + 1) != end_y && (start_x - 1) != end_x) {
		return false;
	}
	
	start_x--;
	start_y++;
	
	return check_destination_oblique_left_up(start_x, start_y, end_x, end_y, tiles, player_one);
}

bool check_destination_oblique_right_up(char start_x, char start_y, char end_x, char end_y, const Tile tiles[][8], bool player_one) {
	
	// made it to the end
	if(start_x == end_x && start_y == end_y) {
		
		return my_piece_on_tile(player_one, tiles[start_y][start_x]) ? false : true;
	}
	
	// something is on direction path and it is not the destination
	if(tiles[start_y + 1][start_x + 1].used == true && (start_y + 1) != end_y && (start_x + 1) != end_x) {
		return false;
	}
	
	start_x++;
	start_y++;
	
	return check_destination_oblique_right_up(start_x, start_y, end_x, end_y, tiles, player_one);
}

bool check_destination_oblique_left_down(char start_x, char start_y, char end_x, char end_y, const Tile tiles[][8], bool player_one) {
	
	// made it to the end
	if(start_x == end_x && start_y == end_y) {
		
		return my_piece_on_tile(player_one, tiles[start_y][start_x]) ? false : true;
	}
	
	// something is on direction path and it is not the destination
	if(tiles[start_y - 1][start_x - 1].used == true && (start_y - 1) != end_y && (start_x - 1) != end_x) {
		return false;
	}
	
	start_x--;
	start_y--;
	
	return check_destination_oblique_left_down(start_x, start_y, end_x, end_y, tiles, player_one);
}

bool check_destination_oblique_right_down(char start_x, char start_y, char end_x, char end_y, const Tile tiles[][8], bool player_one) {
	
	// made it to the end
	if(start_x == end_x && start_y == end_y) {
		
		return my_piece_on_tile(player_one, tiles[start_y][start_x]) ? false : true;
	}
	
	// something is on direction path and it is not the destination
	if(tiles[start_y - 1][start_x + 1].used == true && (start_y - 1) != end_y && (start_x + 1) != end_x) {
		return false;
	}
	
	start_x++;
	start_y--;
	
	return check_destination_oblique_right_down(start_x, start_y, end_x, end_y, tiles, player_one);
}

// check if the move could enter the destination in real game. Are there any own pieces on the way?
bool valid_move(const Tile tiles[][8], bool player_one, char start_x, char start_y, char end_x, char end_y) {
	
	// direction coordinates
	int x = end_x - start_x;
	int y = end_y - start_y;
	
	// TOWER CHECK
	if(string_equal(tiles[start_y][start_x].piece.pion_type, "tower")) {
		
		if(x == 0)
			return y > 0 ? check_destination_up(start_y, end_y, start_x, tiles, player_one) : check_destination_down(start_y, end_y, start_x, tiles, player_one);
		
		return x > 0 ? check_destination_right(start_x, end_x, start_y, tiles, player_one) : check_destination_left(start_x, end_x, start_y, tiles, player_one);
	}
	
	// PION CHECK
	if(string_equal(tiles[start_y][start_x].piece.pion_type, "pion")) {
		
		return y > 0 ? check_destination_up(start_y, end_y, start_x, tiles, player_one) : check_destination_down(start_y, end_y, start_x, tiles, player_one);
	}
	
	// KING and QUEEN have same direction vectors. Afource, the queen can have larger direction vectors. Lenght vector is already calculated in previous function.
	// We can check the same types in one expresson.
	if(string_equal(tiles[start_y][start_x].piece.pion_type, "king") || string_equal(tiles[start_y][start_x].piece.pion_type, "queen")) {
			
		// want to make straight move
		
		// go up
		if(y > 0 && x == 0) {
			return check_destination_up(start_y, end_y, start_x, tiles, player_one);
		}
		
		// go down
		if(y < 0 && x == 0) {
			return check_destination_down(start_y, end_y, start_x, tiles, player_one);
		}
		
		// go right
		if(x > 0 && y == 0) {
			return check_destination_right(start_x, end_x, start_y, tiles, player_one);
		}
		
		// go left
		if(x < 0 && y == 0) {
			return check_destination_left(start_x, end_x, start_y, tiles, player_one);
		}
		
		// for checking oblique moves
		if( x > 0)
			return y > 0 ? check_destination_oblique_right_up(start_x, start_y, end_x, end_y, tiles, player_one) : check_destination_oblique_right_down(start_x, start_y, end_x, end_y, tiles, player_one);

			
		return y > 0 ? check_destination_oblique_left_up(start_x, start_y, end_x, end_y, tiles, player_one) : check_destination_oblique_left_down(start_x, start_y, end_x, end_y, tiles, player_one);
	}
	
	// WALKER
	if(string_equal(tiles[start_y][start_x].piece.pion_type, "walker")) {
		
		// for checking obluque moves
		if( x > 0)
			return y > 0 ? check_destination_oblique_right_up(start_x, start_y, end_x, end_y, tiles, player_one) : check_destination_oblique_right_down(start_x, start_y, end_x, end_y, tiles, player_one);

		return y > 0 ? check_destination_oblique_left_up(start_x, start_y, end_x, end_y, tiles, player_one) : check_destination_oblique_left_down(start_x, start_y, end_x, end_y, tiles, player_one);
			
	}
	
	// HORSE
	if(string_equal(tiles[start_y][start_x].piece.pion_type, "horse")) {
		
		// just only check if the end position is legid.
		if(tiles[end_y][end_x].used == true && tiles[end_y][end_x].piece.player_one == player_one) {
			return false;
		}
		
		return true;
			
	}
	
	// default, return false
	return false;
}

// remove the chess piece to 'graveyard'
Tile remove_enemy_from_tile(Tile tiles[][8], char x, char y) {
	
	// current piece remove from board with engine
		// calculate path for engine.....
	
	// return empty tile back
	return Tile{false, Chess_piece{0}};
}

// function will validate if the chess move is complete legid.
bool move_piece_validation(bool player_one, const Tile tiles[][8], char start_x, char start_y, char end_x, char end_y) {

	// check if the start tile contains a piece of current player AND
	// check if the end tile contains NOT a piece of the current player
	if(my_piece_on_tile(player_one, tiles[start_y][start_x]) == true && my_piece_on_tile(player_one, tiles[end_y][end_x]) == false) {
		
		// direction vector
		Vector direction_vector = {end_x - start_x,  end_y - start_y};
		
		// check if the chess piece can make the direction vector
		if(can_piece_make_dir_vector(tiles[start_y][start_x].piece, direction_vector, tiles[end_y][end_x], player_one)) {
					
			//valid move?
			if(valid_move(tiles, player_one, start_x, start_y, end_x, end_y)) {
				
				// wen can move now
					return true;
			}
		}
	}
	
	return false;
}


// check if the king can be hit from the oblique left up line
bool king_check_oblique_left_up(const Tile tiles[][8], char current_x, char current_y, bool king_player_one, char original_x, char original_y) {
	
	// king is in no danger from this line
	if((current_x -1) < 0 && (current_y + 1) > 7) {
		return false;
	}

	// when chess piece is spotted
	if(chess_piece_on_tile(tiles[current_y + 1][current_x - 1])) {
		
		// if it is chess piece from the king, no danger
		if(my_piece_on_tile(king_player_one, tiles[current_y + 1][current_x - 1])) {
			return false;
		}
		
		// check if the enemy can make dir vector till king reach
		if(can_piece_make_dir_vector(tiles[current_y + 1][current_x - 1].piece, Vector{original_x - (current_x - 1), original_y - (current_y + 1)}, tiles[original_y][original_x], king_player_one)) {
			return true;
		}
			
	}
	
	return king_check_oblique_left_up(tiles, current_x - 1, current_y + 1, king_player_one, original_x, original_y);

}

// check if the king can be hit from the oblique left up line
bool king_check_oblique_left_down(const Tile tiles[][8], char current_x, char current_y, bool king_player_one, char original_x, char original_y) {
	
	// king is in no danger from this line
	if((current_x -1) < 0 && (current_y -1) > 0) {
		return false;
	}

	// when chess piece is spotted
	if(chess_piece_on_tile(tiles[current_y - 1][current_x - 1])) {
		
		// if it is chess piece from the king, no danger
		if(my_piece_on_tile(king_player_one, tiles[current_y - 1][current_x - 1])) {
			return false;
		}
		
		// check if the enemy can make dir vector till king reach
		if(can_piece_make_dir_vector(tiles[current_y - 1][current_x - 1].piece, Vector{original_x - (current_x - 1), original_y -(current_y - 1)}, tiles[original_y][original_x], king_player_one)) {
			return true;
		}
		
	}
	
	return king_check_oblique_left_down(tiles, current_x - 1, current_y + 1, king_player_one, original_x, original_y);

}

// check if the king can be hit from the oblique left up line
bool king_check_oblique_right_up(const Tile tiles[][8], char current_x, char current_y, bool king_player_one, char original_x, char original_y) {
	
	// king is in no danger from this line
	if((current_x + 1)> 7 && (current_y +1) > 7) {
		return false;
	}

	// when chess piece is spotted
	if(chess_piece_on_tile(tiles[current_y + 1][current_x + 1])) {
		
		// if it is chess piece from the king, no danger
		if(my_piece_on_tile(king_player_one, tiles[current_y + 1][current_x + 1])) {
			return false;
		}
			
		// check if the enemy can make dir vector till king reach
		if(can_piece_make_dir_vector(tiles[current_y + 1][current_x + 1].piece, Vector{  original_x - (current_x + 1) , original_y - (current_y + 1)}, tiles[original_y][original_x], king_player_one)) {
			return true;
		}
			
	}
	
	return king_check_oblique_left_down(tiles, current_x - 1, current_y + 1, king_player_one, original_x, original_y);

}

// check if the king can be hit from the oblique left up line
bool king_check_oblique_right_down(const Tile tiles[][8], char current_x, char current_y, bool king_player_one, char original_x, char original_y) {
	
	// king is in no danger from this line
	if((current_x  + 1) > 7 && (current_y - 1) < 0 ) {
		return false;
	}

	// when chess piece is spotted
	if(chess_piece_on_tile(tiles[current_y - 1][current_x + 1])) {
		
		// if it is chess piece from the king, no danger
		if(my_piece_on_tile(king_player_one, tiles[current_y - 1][current_x + 1])) {
			return false;
		}
		
		// check if the enemy can make dir vector till king reach
		if(can_piece_make_dir_vector(tiles[current_y - 1][current_x + 1].piece, Vector{  original_x - (current_x + 1) , original_y - (current_y - 1)}, tiles[original_y][original_x], king_player_one)) {
			return true;
		}
		
	}
	
	return king_check_oblique_left_down(tiles, current_x - 1, current_y - 1, king_player_one, original_x, original_y);

}


// check if the king can be hit from left
bool king_check_left(const Tile tiles[][8], char current_x, char current_y, bool king_player_one, char original_x, char original_y) {
	
	// king is in no danger from this line
	if((current_x  - 1) < 0 ) {
		return false;
	}

	// when chess piece is spotted
	if(chess_piece_on_tile(tiles[current_y][current_x - 1])) {
		
		// if it is chess piece from the king, no danger
		if(my_piece_on_tile(king_player_one, tiles[current_y][current_x - 1])) {
			return false;
		}
		
		// check if the enemy can make dir vector till king reach
		if(can_piece_make_dir_vector(tiles[current_y][current_x - 1].piece, Vector{  original_x - (current_x - 1) , original_y - current_y}, tiles[original_y][original_x], king_player_one)) {
			return true;
		}
		
	}
	
	return king_check_left(tiles, current_x - 1, current_y , king_player_one, original_x, original_y);

}

// check if the king can be hit from right
bool king_check_right(const Tile tiles[][8], char current_x, char current_y, bool king_player_one, char original_x, char original_y) {
	
	// king is in no danger from this line
	if((current_x  + 1) > 7 ) {
		return false;
	}

	// when chess piece is spotted
	if(chess_piece_on_tile(tiles[current_y][current_x + 1])) {
		
		// if it is chess piece from the king, no danger
		if(my_piece_on_tile(king_player_one, tiles[current_y][current_x + 1])) {
			return false;
		}

		// check if the enemy can make dir vector till king reach
		if(can_piece_make_dir_vector(tiles[current_y][current_x + 1].piece, Vector{  original_x - (current_x + 1) , original_y - current_y}, tiles[original_y][original_x], king_player_one)) {
			return true;
		}
			
	}
	
	return king_check_right(tiles, current_x + 1, current_y , king_player_one, original_x, original_y);

}

// check if the king can be hit from up
bool king_check_up(const Tile tiles[][8], char current_x, char current_y, bool king_player_one, char original_x, char original_y) {
	
	// king is in no danger from this line
	if((current_y  + 1) > 7 ) {
		return false;
	}

	// when chess piece is spotted
	if(chess_piece_on_tile(tiles[current_y + 1][current_x])) {
		
		// if it is chess piece from the king, no danger
		if(my_piece_on_tile(king_player_one, tiles[current_y + 1][current_x])) {
			return false;
		}
		
		// check if the enemy can make dir vector till king reach
		if(can_piece_make_dir_vector(tiles[current_y + 1][current_x].piece, Vector{  original_x  - current_x, original_y - (current_y + 1)}, tiles[original_y][original_x], king_player_one)) {
			return true;
		}
		
	}
	
	return king_check_up(tiles, current_x, current_y + 1 , king_player_one, original_x, original_y);

}

// check if the king can be hit from down
bool king_check_down(const Tile tiles[][8], char current_x, char current_y, bool king_player_one, char original_x, char original_y) {
	
	// king is in no danger from this line
	if((current_y  - 1) < 0 ) {
		return false;
	}

	// when chess piece is spotted
	if(chess_piece_on_tile(tiles[current_y - 1][current_x])) {
		
		// if it is chess piece from the king, no danger
		if(my_piece_on_tile(king_player_one, tiles[current_y - 1][current_x])) {
			return false;
		}
			
		// check if the enemy can make dir vector till king reach
		if(can_piece_make_dir_vector(tiles[current_y - 1][current_x].piece, Vector{  original_x  - current_x, original_y - (current_y - 1)}, tiles[original_y][original_x], king_player_one)) {
			return true;
		}

	}
	
	return king_check_down(tiles, current_x, current_y - 1 , king_player_one, original_x, original_y);

}


// check if any king is check
char king_check(const Tile tiles[][8]) {
	
	// find the first king location
	int y = 0;
	int x = 0;
	
	for(y = 0; y < 8; y++) {
		
		for(x = 0; x < 8; x++) {
			
			// if any king is found
			if(tiles[y][x].used == true && string_equal(tiles[y][x].piece.pion_type, "king") ) {
				
				bool king_player_one = tiles[y][x].piece.player_one;
				
				
				// check if any horse can beat him down
				
				// check if other pieces on oblique lines can beat him down
				if(king_check_oblique_left_down(tiles, x, y, king_player_one, x, y) || king_check_oblique_left_up(tiles, x, y, king_player_one, x, y) ||
				king_check_oblique_right_up(tiles, x, y, king_player_one, x, y) || king_check_oblique_right_down(tiles, x, y, king_player_one, x, y) ||
				king_check_left(tiles, x, y, king_player_one, x, y) || king_check_right(tiles, x, y, king_player_one, x, y) || 
				king_check_down(tiles, x, y, king_player_one, x, y) || king_check_up(tiles, x, y, king_player_one, x, y)) {
					
					// who is it ?
					 // 1. player one
					 // 2. player two
					return king_player_one? 1 : 2;

				}
				
			}
		}
	}
	
	// nobody is checked
	return 0;
}

// check if the king is checkmate
bool king_checkmate() {
	
}


int main(int argc, char **argv)
{
	// define all tiles
	Tile tiles[8][8];
	
	// player turn
	bool player_one = true;
	
	// playground initiliase
	playground_init(tiles);
	print_board(tiles);
	
	while(1) {
		
		int input_x;
		int input_y;
		int input_x_destination;
		int input_y_destination;
		
		scanf("%d", &input_y);
		scanf("%d", &input_x);

		scanf("%d", &input_y_destination);
		scanf("%d", &input_x_destination);
	
		bool validation_move = move_piece_validation(player_one,tiles, input_x, input_y, input_x_destination, input_y_destination);
		
		// can the chess piece make the step in the real chess game?
		if(validation_move) {
			printf("valid move");
			
			// piece is moved true
			tiles[input_y][input_x].piece.moved = true;
 
			// set the chess piece to the final destination
			tiles[input_y_destination][input_x_destination].piece = tiles[input_y][input_x].piece;
			tiles[input_y_destination][input_x_destination].used = true;
			
			// clean the start position
			tiles[input_y][input_x] = Tile{ false, {0}};
			
			// check if any king is check
			if(king_check(tiles) == 1) {
				printf("player 1 is check!");
			}
			
			// check if any king is check
			if(king_check(tiles) == 2) {
				printf("player 2 is check!");
			}
		}
		
		print_board(tiles);
		
	}
	

	return 0;
}
