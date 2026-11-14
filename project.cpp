#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

void chess_game ();

void rook_moves_white ( char*, int row, int, bool& );

void knight_moves_white ( char*, int row, int, bool& );

void bishop_moves_white ( char*, int row, int, bool& );

void king_moves_white ( char*, int row, int, bool& );

void queen_moves_white ( char*, int row, int, bool& );

void rook_moves_black ( char*, int row, int, bool& );

void knight_moves_black ( char*, int row, int, bool& );

void bishop_moves_black ( char*, int row, int, bool& );

void king_moves_black ( char*, int row, int, bool& );

void queen_moves_black ( char*, int row, int, bool& );

int main () {
    chess_game ();
    return 0;
}

void chess_game () {
    char chess_board[8][8], col;
    bool white = 0, black = 0;  // to differentiate the winner and loser
    int row = 0, turn = 0;
    // assigning initial positions to each piece and leaving the rest of the
    // board blank
    for ( int i = 0; i < 8; i++ ) {
        for ( int j = 0; j < 8; j++ ) {
            // assigning pieces to the top-most row
            if ( i == 0 ) {
                switch ( j ) {
                    case 0:
                        chess_board[i][j] = 'R';
                        break;
                    case 1:
                        chess_board[i][j] = 'N';
                        break;
                    case 2:
                        chess_board[i][j] = 'B';
                        break;
                    case 3:
                        chess_board[i][j] = 'Q';
                        break;
                    case 4:
                        chess_board[i][j] = 'K';
                        break;
                    case 5:
                        chess_board[i][j] = 'B';
                        break;
                    case 6:
                        chess_board[i][j] = 'N';
                        break;
                    case 7:
                        chess_board[i][j] = 'R';
                        break;
                }
            }
            // assigning pieces to the bottom-most row
            else if ( i == 7 ) {
                switch ( j ) {
                    case 0:
                        chess_board[i][j] = 'r';
                        break;
                    case 1:
                        chess_board[i][j] = 'n';
                        break;
                    case 2:
                        chess_board[i][j] = 'b';
                        break;
                    case 3:
                        chess_board[i][j] = 'q';
                        break;
                    case 4:
                        chess_board[i][j] = 'k';
                        break;
                    case 5:
                        chess_board[i][j] = 'b';
                        break;
                    case 6:
                        chess_board[i][j] = 'n';
                        break;
                    case 7:
                        chess_board[i][j] = 'r';
                        break;
                }
            }
            // assigning blank space to the rest of positions
            else
                chess_board[i][j] = ' ';
        }
    }
    // initial output
    do {
        cout << endl;
        for ( int i = -1; i < 9; i++ ) {
            for ( int j = -1; j < 9; j++ ) {
                if ( ( j == -1 || j == 8 ) ) {
                    if ( i == -1 || i == 8 )
                        cout << ' ';
                    else
                        cout << ( 8 - i ) << ' ';
                } else if ( i == -1 || i == 8 )
                    cout << ' ' << static_cast<char> ( 97 + j );
                else
                    cout << chess_board[i][j] << ' ';
            }
            cout << endl;
        }
        // code for white
        if ( turn % 2 == 0 ) {
            // outputting turn
            cout << setw ( 19 ) << "\n<-- White's Turn -->\n";
            // prompting to select a piece to move
            cout << "\nPostion of piece you would like to move:\nRow # ";
            cin >> row;
            while ( !( row >= 1 && row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> row;
            }
            cout << "Column: ";
            cin >> col;
            while ( !( col >= 'a' && col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> col;
            }
            // check for selected position
            while ( !( chess_board[8 - row][col - 97] == 'r' ||
                       chess_board[8 - row][col - 97] == 'n' ||
                       chess_board[8 - row][col - 97] == 'b' ||
                       chess_board[8 - row][col - 97] == 'q' ||
                       chess_board[8 - row][col - 97] == 'k' ) ) {
                cout << "\nInvalid Selection.\nYou do not have any of your "
                        "pieces at that position.\n\nPlease enter another "
                        "position:\nRow # ";
                cin >> row;
                while ( !( row >= 1 && row <= 8 ) ) {
                    cout << "Invalid Input. Please enter a valid row number "
                            "(1-8): ";
                    cin >> row;
                }
                cout << "Column: ";
                cin >> col;
                while ( !( col >= 'a' && col <= 'h' ) ) {
                    cout
                        << "Invalid Input. Please enter a valid column (a-h): ";
                    cin >> col;
                }
            }
            // swtich statement to run game according to selected piece
            switch ( chess_board[8 - row][col - 97] ) {
                case 'R':
                    rook_moves_black (
                        &chess_board[0][0], ( 8 - row ), ( col - 97 ),
                        black );  // passing row and column number w.r.t array
                                  // to respective function
                    break;
                case 'r':
                    rook_moves_white ( &chess_board[0][0], ( 8 - row ),
                                       ( col - 97 ), white );
                    break;
                case 'N':
                    knight_moves_black ( &chess_board[0][0], ( 8 - row ),
                                         ( col - 97 ), black );
                    break;
                case 'n':
                    knight_moves_white ( &chess_board[0][0], ( 8 - row ),
                                         ( col - 97 ), white );
                    break;
                case 'B':
                    bishop_moves_black ( &chess_board[0][0], ( 8 - row ),
                                         ( col - 97 ), black );
                    break;
                case 'b':
                    bishop_moves_white ( &chess_board[0][0], ( 8 - row ),
                                         ( col - 97 ), white );
                    break;
                case 'Q':
                    queen_moves_black ( &chess_board[0][0], ( 8 - row ),
                                        ( col - 97 ), black );
                    break;
                case 'q':
                    queen_moves_white ( &chess_board[0][0], ( 8 - row ),
                                        ( col - 97 ), white );
                    break;
                case 'K':
                    king_moves_black ( &chess_board[0][0], ( 8 - row ),
                                       ( col - 97 ), black );
                    break;
                case 'k':
                    king_moves_white ( &chess_board[0][0], ( 8 - row ),
                                       ( col - 97 ), white );
                    break;
            }
        } else {
            cout << setw ( 19 ) << "\n<-- Black's Turn -->\n";
            // prompting to select a piece to move
            cout << "\nPostion of piece you would like to move:\nRow # ";
            cin >> row;
            while ( !( row >= 1 && row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> row;
            }
            cout << "Column: ";
            cin >> col;
            while ( !( col >= 'a' && col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> col;
            }
            // check for selected position
            while ( !( chess_board[8 - row][col - 97] == 'R' ||
                       chess_board[8 - row][col - 97] == 'N' ||
                       chess_board[8 - row][col - 97] == 'B' ||
                       chess_board[8 - row][col - 97] == 'Q' ||
                       chess_board[8 - row][col - 97] == 'K' ) ) {
                cout << "\nInvalid Selection.\nYou do not have any of your "
                        "pieces at that position.\n\nPlease enter another "
                        "position:\nRow # ";
                cin >> row;
                while ( !( row >= 1 && row <= 8 ) ) {
                    cout << "Invalid Input. Please enter a valid row number "
                            "(1-8): ";
                    cin >> row;
                }
                cout << "Column: ";
                cin >> col;
                while ( !( col >= 'a' && col <= 'h' ) ) {
                    cout
                        << "Invalid Input. Please enter a valid column (a-h): ";
                    cin >> col;
                }
            }
            // swtich statement to run game according to selected piece
            switch ( chess_board[8 - row][col - 97] ) {
                case 'R':
                    rook_moves_black (
                        &chess_board[0][0], ( 8 - row ), ( col - 97 ),
                        black );  // passing row and column number w.r.t array
                                  // to respective function
                    break;
                case 'r':
                    rook_moves_white ( &chess_board[0][0], ( 8 - row ),
                                       ( col - 97 ), white );
                    break;
                case 'N':
                    knight_moves_black ( &chess_board[0][0], ( 8 - row ),
                                         ( col - 97 ), black );
                    break;
                case 'n':
                    knight_moves_white ( &chess_board[0][0], ( 8 - row ),
                                         ( col - 97 ), white );
                    break;
                case 'B':
                    bishop_moves_black ( &chess_board[0][0], ( 8 - row ),
                                         ( col - 97 ), black );
                    break;
                case 'b':
                    bishop_moves_white ( &chess_board[0][0], ( 8 - row ),
                                         ( col - 97 ), white );
                    break;
                case 'Q':
                    queen_moves_black ( &chess_board[0][0], ( 8 - row ),
                                        ( col - 97 ), black );
                    break;
                case 'q':
                    queen_moves_white ( &chess_board[0][0], ( 8 - row ),
                                        ( col - 97 ), white );
                    break;
                case 'K':
                    king_moves_black ( &chess_board[0][0], ( 8 - row ),
                                       ( col - 97 ), black );
                    break;
                case 'k':
                    king_moves_white ( &chess_board[0][0], ( 8 - row ),
                                       ( col - 97 ), white );
                    break;
            }
        }
        turn++;
    } while ( !( white == 1 || black == 1 ) );
    if ( white == 1 ) {
        cout << "\nWhite Wins!\n";
    } else if ( black == 1 )
        cout << "\nBlack Wins!\n";
}

void rook_moves_white ( char* chess_board_ptr, int row, int col, bool& white ) {
    int new_row, i, j;
    char new_col;
    // displaying possible moves
    cout << endl;
    for ( int i = -1; i < 9; i++ ) {
        for ( int j = -1; j < 9; j++ ) {
            if ( ( j == -1 || j == 8 ) ) {
                // corners
                if ( i == -1 || i == 8 ) cout << ' ';
                // row numbers
                else
                    cout << ( 8 - i );
            }
            // column alphabets
            else if ( i == -1 || i == 8 )
                cout << static_cast<char> ( 97 + j );
            // possible moves
            // for white
            else if ( !( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) &&
                      ( i == row || j == col ) ) {
                if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) {
                    cout << '*';
                } else {
                    cout << '.';
                }
            } else
                cout << *( chess_board_ptr + ( i * 8 + j ) );
            cout << ' ';
        }
        cout << endl;
    }
    // verifying and changing position of selected peice
    // assigning blank space to the initial position (from which the peice is
    // being moved)
    *( chess_board_ptr + ( row * 8 + col ) ) = ' ';
    // prompting new position of selected piece
    cout << "\nWhere would you like to move it\? ";
    cout << "\nRow # ";
    cin >> new_row;
    while ( !( new_row >= 1 && new_row <= 8 ) ) {
        cout << "Invalid Input. Please enter a valid row number (1-8): ";
        cin >> new_row;
    }
    cout << "Column: ";
    cin >> new_col;
    while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
        cout << "Invalid Input. Please enter a valid column (a-h): ";
        cin >> new_col;
    }
    // assigning row and column number w.r.t chess_board array to i and j
    // respectively
    i = ( 8 - new_row );
    j = ( new_col - 97 );
    // check for new position
    // for white
    while ( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ||
            ( !( ( 8 - new_row ) == row || ( new_col - 97 ) == col ) ) ) {
        if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) {
            cout << "\nInvalid Move.\nYou already have a piece placed at that "
                    "position.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        } else if ( ( !( i == row || j == col ) ) ) {
            cout << "\nInvalid Move.\nRook cannot be moved in such a "
                    "manner.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
            if ( *( chess_board_ptr + i * 8 + j ) == 'q' || 'Q' ) {
            }
        }
    }
    if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) white = 1;
    // assigning new position to array
    *( chess_board_ptr + ( i * 8 + j ) ) = 'r';
}

void rook_moves_black ( char* chess_board_ptr, int row, int col, bool& black ) {
    int new_row, i, j;
    char new_col;
    // displaying possible moves
    cout << endl;
    for ( int i = -1; i < 9; i++ ) {
        for ( int j = -1; j < 9; j++ ) {
            if ( ( j == -1 || j == 8 ) ) {
                // corners
                if ( i == -1 || i == 8 ) cout << ' ';
                // row numbers
                else
                    cout << ( 8 - i );
            }
            // column alphabets
            else if ( i == -1 || i == 8 )
                cout << static_cast<char> ( 97 + j );
            // possible moves
            // for black
            else if ( !( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) &&
                      ( i == row || j == col ) ) {
                if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) {
                    cout << '*';
                } else
                    cout << '.';
            } else
                cout << *( chess_board_ptr + ( i * 8 + j ) );
            cout << ' ';
        }
        cout << endl;
    }
    // verifying and changing position of selected peice
    // assigning blank space to the initial position (from which the peice is
    // being moved)
    *( chess_board_ptr + ( row * 8 + col ) ) = ' ';
    // prompting new position of selected piece
    cout << "\nWhere would you like to move it\? ";
    cout << "\nRow # ";
    cin >> new_row;
    while ( !( new_row >= 1 && new_row <= 8 ) ) {
        cout << "Invalid Input. Please enter a valid row number (1-8): ";
        cin >> new_row;
    }
    cout << "Column: ";
    cin >> new_col;
    while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
        cout << "Invalid Input. Please enter a valid column (a-h): ";
        cin >> new_col;
    }
    i = ( 8 - new_row );
    j = ( new_col - 97 );
    // check for new position
    // for black
    while ( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ||
            ( !( ( 8 - new_row ) == row || ( new_col - 97 ) == col ) ) ) {
        if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) {
            cout << "\nInvalid Move.\nYou already have a piece placed at that "
                    "position.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        } else if ( ( !( i == row || j == col ) ) ) {
            cout << "\nInvalid Move.\nRook cannot be moved in such a "
                    "manner.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        }
    }
    if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) black = 1;
    // assigning new position to array
    *( chess_board_ptr + ( i * 8 + j ) ) = 'R';
}

void knight_moves_white ( char* chess_board_ptr, int row, int col,
                          bool& white ) {
    int new_row, i, j;
    char new_col;

    // displaying possible moves
    cout << endl;
    for ( int i = -1; i < 9; i++ ) {
        for ( int j = -1; j < 9; j++ ) {
            if ( ( j == -1 || j == 8 ) ) {
                // corners
                if ( i == -1 || i == 8 ) cout << ' ';
                // row numbers
                else
                    cout << ( 8 - i );
            } else if ( i == -1 || i == 8 )
                cout << static_cast<char> ( 97 + j );
            // possible moves
            // for white
            else if ( !( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) &&
                      ( ( i == row + 2 &&
                              ( ( j == col + 1 ) || ( ( j == col - 1 ) ) ) ||
                          ( i == row - 2 &&
                            ( ( j == col + 1 ) || ( j == col - 1 ) ) ) ||
                          ( j == col + 2 &&
                            ( ( i == row + 1 ) || ( i == row - 1 ) ) ) ||
                          ( j == col - 2 &&
                            ( ( i == row + 1 ) || ( i == row - 1 ) ) ) ) ) ) {
                if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) {
                    cout << '*';
                } else
                    cout << '.';
            } else
                cout << *( chess_board_ptr + ( i * 8 + j ) );
            cout << ' ';
        }
        cout << endl;
    }

    // assigning blank space to the initial position (from which the peice is
    // being moved)
    *( chess_board_ptr + ( row * 8 + col ) ) = ' ';

    // prompting new position of selected piece
    cout << "\nWhere would you like to move it\? ";
    cout << "\nRow # ";
    cin >> new_row;
    while ( !( new_row >= 1 && new_row <= 8 ) ) {
        cout << "Invalid Input. Please enter a valid row number (1-8): ";
        cin >> new_row;
    }
    cout << "Column: ";
    cin >> new_col;
    while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
        cout << "Invalid Input. Please enter a valid column (a-h): ";
        cin >> new_col;
    }
    i = ( 8 - new_row );
    j = ( new_col - 97 );
    // validating new position
    while (
        *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
        *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
        *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
        *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
        *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ||
        ( !( ( i == row + 2 && ( ( j == col + 1 ) || ( j == col - 1 ) ) ) ||
             ( i == row - 2 && ( ( j == col + 1 ) || ( j == col - 1 ) ) ) ||
             ( j == col + 2 && ( ( i == row + 1 ) || ( i == row - 1 ) ) ) ||
             ( ( ( i == row + 1 ) ||
                 ( i == row - 1 ) ) ) ) )  // verfying valid moves for knight
    ) {
        if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) {
            cout << "\nInvalid Move.\nYou already have a piece placed at that "
                    "position.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        } else if ( !( ( i == row + 2 &&
                         ( ( j == col + 1 ) || ( j == col - 1 ) ) ) ||
                       ( i == row - 2 &&
                         ( ( j == col + 1 ) || ( j == col - 1 ) ) ) ||
                       ( j == col + 2 &&
                         ( ( i == row + 1 ) || ( i == row - 1 ) ) ) ||
                       ( j == col - 2 &&
                         ( ( i == row + 1 ) || ( i == row - 1 ) ) ) ) ) {
            cout << "\nInvalid Move.\nKnight cannot be moved in such a "
                    "manner.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        }
    }
    if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) white = 1;
    // assigning new position to array
    *( chess_board_ptr + ( i * 8 + j ) ) = 'n';
}

void knight_moves_black ( char* chess_board_ptr, int row, int col,
                          bool& black ) {
    int new_row, i, j;
    char new_col;
    // displaying possible moves
    cout << endl;
    for ( int i = -1; i < 9; i++ ) {
        for ( int j = -1; j < 9; j++ ) {
            if ( ( j == -1 || j == 8 ) ) {
                // corners
                if ( i == -1 || i == 8 ) cout << ' ';
                // row numbers
                else
                    cout << ( 8 - i );
            } else if ( i == -1 || i == 8 )
                cout << static_cast<char> ( 97 + j );
            // possible moves
            // for white
            else if ( !( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) &&
                      ( ( i == row + 2 &&
                              ( ( j == col + 1 ) || ( ( j == col - 1 ) ) ) ||
                          ( i == row - 2 &&
                            ( ( j == col + 1 ) || ( j == col - 1 ) ) ) ||
                          ( j == col + 2 &&
                            ( ( i == row + 1 ) || ( i == row - 1 ) ) ) ||
                          ( j == col - 2 &&
                            ( ( i == row + 1 ) || ( i == row - 1 ) ) ) ) ) ) {
                if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) {
                    cout << '*';
                } else
                    cout << '.';
            } else
                cout << *( chess_board_ptr + ( i * 8 + j ) );
            cout << ' ';
        }
        cout << endl;
    }
    // assigning blank space to the initial position (from which the peice is
    // being moved)
    *( chess_board_ptr + ( row * 8 + col ) ) = ' ';
    // prompting new position of selected piece
    cout << "\nWhere would you like to move it\? ";
    cout << "\nRow # ";
    cin >> new_row;
    while ( !( new_row >= 1 && new_row <= 8 ) ) {
        cout << "Invalid Input. Please enter a valid row number (1-8): ";
        cin >> new_row;
    }
    cout << "Column: ";
    cin >> new_col;
    while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
        cout << "Invalid Input. Please enter a valid column (a-h): ";
        cin >> new_col;
    }
    i = ( 8 - new_row );
    j = ( new_col - 97 );
    // validating new position
    while (
        *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
        *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
        *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
        *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
        *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ||
        ( !( ( i == row + 2 && ( ( j == col + 1 ) || ( j == col - 1 ) ) ) ||
             ( i == row - 2 && ( ( j == col + 1 ) || ( j == col - 1 ) ) ) ||
             ( j == col + 2 && ( ( i == row + 1 ) || ( i == row - 1 ) ) ) ||
             ( ( ( i == row + 1 ) ||
                 ( i == row - 1 ) ) ) ) )  // verfying valid moves for knight
    ) {
        if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) {
            cout << "\nInvalid Move.\nYou already have a piece placed at that "
                    "position.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        } else if ( !( ( i == row + 2 &&
                         ( ( j == col + 1 ) || ( j == col - 1 ) ) ) ||
                       ( i == row - 2 &&
                         ( ( j == col + 1 ) || ( j == col - 1 ) ) ) ||
                       ( j == col + 2 &&
                         ( ( i == row + 1 ) || ( i == row - 1 ) ) ) ||
                       ( j == col - 2 &&
                         ( ( i == row + 1 ) || ( i == row - 1 ) ) ) ) ) {
            cout << "\nInvalid Move.\nKnight cannot be moved in such a "
                    "manner.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        }
    }
    if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) black = 1;
    // assigning new position to array
    *( chess_board_ptr + ( i * 8 + j ) ) = 'N';
}

void bishop_moves_white ( char* chess_board_ptr, int row, int col,
                          bool& white ) {
    int new_row, i, j;
    char new_col;
    // displaying possible moves
    cout << endl;
    for ( int i = -1; i < 9; i++ ) {
        for ( int j = -1; j < 9; j++ ) {
            if ( ( j == -1 || j == 8 ) ) {
                // corners
                if ( i == -1 || i == 8 ) cout << ' ';
                // row numbers
                else if ( j == -1 || j == 8 )
                    cout << ( 8 - i );
            }

            // column alphabets
            else if ( i == -1 || i == 8 )
                cout << static_cast<char> ( 97 + j );
            // possible moves
            // for white
            else if ( !( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) &&
                      ( ( ( i - j ) == ( row - col ) ) ||
                        ( ( i + j ) == ( row + col ) ) ) ) {
                if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) {
                    cout << '*';
                } else
                    cout << '.';
            } else
                cout << *( chess_board_ptr + ( i * 8 + j ) );
            cout << ' ';
        }
        cout << endl;
    }
    // verifying and changing position of selected peice
    // assigning blank space to the initial position (from which the peice is
    // being moved)
    *( chess_board_ptr + ( row * 8 + col ) ) = ' ';
    // prompting new position of selected piece
    cout << "\nWhere would you like to move it\? ";
    cout << "\nRow # ";
    cin >> new_row;
    while ( !( new_row >= 1 && new_row <= 8 ) ) {
        cout << "Invalid Input. Please enter a valid row number (1-8): ";
        cin >> new_row;
    }
    cout << "Column: ";
    cin >> new_col;
    while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
        cout << "Invalid Input. Please enter a valid column (a-h): ";
        cin >> new_col;
    }

    i = ( 8 - new_row );
    j = ( new_col - 97 );

    // check for new position
    while ( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ||
            !( ( ( i - j ) == ( row - col ) ) ||
               ( ( i + j ) == ( row + col ) ) ) ) {
        if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) {
            cout << "\nInvalid Move.\nYou already have a piece placed at that "
                    "position.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        } else if ( ( !( ( i - j ) == ( row - col ) ) ||
                      ( ( i + j ) == ( row + col ) ) ) ) {
            cout << "\nInvalid Move.\nBishop cannot be moved in such a "
                    "manner.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        }
    }
    if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) white = 1;
    // assigning new position to array
    *( chess_board_ptr + ( i * 8 + j ) ) = 'b';
}

void bishop_moves_black ( char* chess_board_ptr, int row, int col,
                          bool& black ) {
    int new_row, i, j;
    char new_col;
    // displaying possible moves
    cout << endl;
    for ( int i = -1; i < 9; i++ ) {
        for ( int j = -1; j < 9; j++ ) {
            if ( ( j == -1 || j == 8 ) ) {
                // corners
                if ( i == -1 || i == 8 ) cout << ' ';
                // row numbers
                else if ( j == -1 || j == 8 )
                    cout << ( 8 - i );
            }

            // column alphabets
            else if ( i == -1 || i == 8 )
                cout << static_cast<char> ( 97 + j );
            // possible moves
            // for black
            else if ( !( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) &&
                      ( ( ( i - j ) == ( row - col ) ) ||
                        ( ( i + j ) == ( row + col ) ) ) ) {
                if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) {
                    cout << '*';
                } else
                    cout << '.';
            } else
                cout << *( chess_board_ptr + ( i * 8 + j ) );
            cout << ' ';
        }
        cout << endl;
    }

    // verifying and changing position of selected peice

    // assigning blank space to the initial position (from which the peice is
    // being moved)
    *( chess_board_ptr + ( row * 8 + col ) ) = ' ';
    // prompting new position of selected piece
    cout << "\nWhere would you like to move it\? ";
    cout << "\nRow # ";
    cin >> new_row;
    while ( !( new_row >= 1 && new_row <= 8 ) ) {
        cout << "Invalid Input. Please enter a valid row number (1-8): ";
        cin >> new_row;
    }
    cout << "Column: ";
    cin >> new_col;
    while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
        cout << "Invalid Input. Please enter a valid column (a-h): ";
        cin >> new_col;
    }

    i = ( 8 - new_row );
    j = ( new_col - 97 );

    // check for new position
    while ( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ||
            !( ( ( i - j ) == ( row - col ) ) ||
               ( ( i + j ) == ( row + col ) ) ) ) {
        if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) {
            cout << "\nInvalid Move.\nYou already have a piece placed at that "
                    "position.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        } else if ( ( !( ( i - j ) == ( row - col ) ) ||
                      ( ( i + j ) == ( row + col ) ) ) ) {
            cout << "\nInvalid Move.\nBishop cannot be moved in such a "
                    "manner.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        }
    }
    if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) black = 1;
    // assigning new position to array
    *( chess_board_ptr + ( i * 8 + j ) ) = 'B';
}

void queen_moves_white ( char* chess_board_ptr, int row, int col,
                         bool& white ) {
    int new_row, i, j;
    char new_col;
    // displaying possible moves
    cout << endl;
    for ( int i = -1; i < 9; i++ ) {
        for ( int j = -1; j < 9; j++ ) {
            if ( ( j == -1 || j == 8 ) ) {
                // corners
                if ( i == -1 || i == 8 ) cout << ' ';
                // row numbers
                else
                    cout << ( 8 - i );
            }
            // column alphabets
            else if ( i == -1 || i == 8 )
                cout << static_cast<char> ( 97 + j );
            // possible moves
            // for white
            else if ( !( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) &&
                      ( ( ( i == row ) || ( j == col ) ||
                          ( ( i - j ) == ( row - col ) ) ||
                          ( ( i + j ) == ( row + col ) ) ) ) ) {
                if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) {
                    cout << '*';
                } else
                    cout << '.';
            } else
                cout << *( chess_board_ptr + ( i * 8 + j ) );
            cout << ' ';
        }
        cout << endl;
    }
    // verifying and changing position of selected peice
    // assigning blank space to the initial position (from which the peice is
    // being moved)
    *( chess_board_ptr + ( row * 8 + col ) ) = ' ';
    // prompting new position of selected piece
    cout << "\nWhere would you like to move it\? ";
    cout << "\nRow # ";
    cin >> new_row;
    while ( !( new_row >= 1 && new_row <= 8 ) ) {
        cout << "Invalid Input. Please enter a valid row number (1-8): ";
        cin >> new_row;
    }
    cout << "Column: ";
    cin >> new_col;
    while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
        cout << "Invalid Input. Please enter a valid column (a-h): ";
        cin >> new_col;
    }
    i = ( 8 - new_row );
    j = ( new_col - 97 );
    // check for new position
    while ( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ||
            !( ( i == row ) || ( j == col ) || ( ( i - j ) == ( row - col ) ) ||
               ( ( i + j ) == ( row + col ) ) ) ) {
        if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) {
            cout << "\nInvalid Move.\nYou already have a piece placed at that "
                    "position.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        } else if ( !( ( i == row ) || ( j == col ) ||
                       ( ( i - j ) == ( row - col ) ) ||
                       ( ( i + j ) == ( row + col ) ) ) ) {
            cout << "\nInvalid Move.\nQueen cannot be moved in such a "
                    "manner.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        }
    }
    if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) white = 1;
    // assigning new position to array
    *( chess_board_ptr + ( i * 8 + j ) ) = 'q';
}

void queen_moves_black ( char* chess_board_ptr, int row, int col,
                         bool& black ) {
    int new_row, i, j;
    char new_col;
    // displaying possible moves
    cout << endl;
    for ( int i = -1; i < 9; i++ ) {
        for ( int j = -1; j < 9; j++ ) {
            if ( ( j == -1 || j == 8 ) ) {
                // corners
                if ( i == -1 || i == 8 ) cout << ' ';
                // row numbers
                else
                    cout << ( 8 - i );
            }
            // column alphabets
            else if ( i == -1 || i == 8 )
                cout << static_cast<char> ( 97 + j );
            // possible moves
            // for black
            else if ( !( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) &&
                      ( ( ( i == row ) || ( j == col ) ||
                          ( ( i - j ) == ( row - col ) ) ||
                          ( ( i + j ) == ( row + col ) ) ) ) ) {
                if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) {
                    cout << '*';
                } else
                    cout << '.';
            } else
                cout << *( chess_board_ptr + ( i * 8 + j ) );
            cout << ' ';
        }
        cout << endl;
    }
    // verifying and changing position of selected peice
    // assigning blank space to the initial position (from which the peice is
    // being moved)
    *( chess_board_ptr + ( row * 8 + col ) ) = ' ';
    // prompting new position of selected piece
    cout << "\nWhere would you like to move it\? ";
    cout << "\nRow # ";
    cin >> new_row;
    while ( !( new_row >= 1 && new_row <= 8 ) ) {
        cout << "Invalid Input. Please enter a valid row number (1-8): ";
        cin >> new_row;
    }
    cout << "Column: ";
    cin >> new_col;
    while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
        cout << "Invalid Input. Please enter a valid column (a-h): ";
        cin >> new_col;
    }
    i = ( 8 - new_row );
    j = ( new_col - 97 );
    // check for new position
    while ( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ||
            !( ( i == row ) || ( j == col ) || ( ( i - j ) == ( row - col ) ) ||
               ( ( i + j ) == ( row + col ) ) ) ) {
        if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) {
            cout << "\nInvalid Move.\nYou already have a piece placed at that "
                    "position.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        } else if ( !( ( i == row ) || ( j == col ) ||
                       ( ( i - j ) == ( row - col ) ) ||
                       ( ( i + j ) == ( row + col ) ) ) ) {
            cout << "\nInvalid Move.\nQueen cannot be moved in such a "
                    "manner.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        }
    }
    if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) black = 1;
    // assigning new position to array
    *( chess_board_ptr + ( i * 8 + j ) ) = 'Q';
}

void king_moves_white ( char* chess_board_ptr, int row, int col, bool& white ) {
    int new_row, i, j;
    char new_col;
    // displaying possible moves
    cout << endl;
    for ( int i = -1; i < 9; i++ ) {
        for ( int j = -1; j < 9; j++ ) {
            if ( ( j == -1 || j == 8 ) ) {
                // corners
                if ( i == -1 || i == 8 ) cout << ' ';
                // row numbers
                else
                    cout << ( 8 - i );
            }
            // column alphabets
            else if ( i == -1 || i == 8 )
                cout << static_cast<char> ( 97 + j );
            // possible moves
            // for white
            else if ( !( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) &&
                      ( ( i == row + 1 && ( ( j == col - 1 ) || ( j == col ) ||
                                            ( j == col + 1 ) ) ) ||
                        ( i == row &&
                          ( ( j == col - 1 ) || ( j == col + 1 ) ) ) ||
                        ( i == row - 1 && ( ( j == col - 1 ) || ( j == col ) ||
                                            ( j == col + 1 ) ) ) ) ) {
                if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) {
                    cout << '*';
                } else
                    cout << '.';
            } else
                cout << *( chess_board_ptr + ( i * 8 + j ) );
            cout << ' ';
        }
        cout << endl;
    }
    // verifying and changing position of selected peice
    // assigning blank space to the initial position (from which the peice is
    // being moved)
    *( chess_board_ptr + ( row * 8 + col ) ) = ' ';
    // prompting new position of selected piece
    cout << "\nWhere would you like to move it\? ";
    cout << "\nRow # ";
    cin >> new_row;
    while ( !( new_row >= 1 && new_row <= 8 ) ) {
        cout << "Invalid Input. Please enter a valid row number (1-8): ";
        cin >> new_row;
    }
    cout << "Column: ";
    cin >> new_col;
    while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
        cout << "Invalid Input. Please enter a valid column (a-h): ";
        cin >> new_col;
    }
    i = ( 8 - new_row );
    j = ( new_col - 97 );
    // check for new position
    while ( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ||
            !( ( i == row + 1 &&
                 ( ( j == col - 1 ) || ( j == col ) || ( j == col + 1 ) ) ) ||
               ( i == row && ( ( j == col - 1 ) || ( j == col + 1 ) ) ) ||
               ( i == row - 1 && ( ( j == col - 1 ) || ( j == col ) ||
                                   ( j == col + 1 ) ) ) ) ) {
        if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) {
            cout << "\nInvalid Move.\nYou already have a piece placed at that "
                    "position.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        } else if ( !( ( i == row + 1 && ( ( j == col - 1 ) || ( j == col ) ||
                                           ( j == col + 1 ) ) ) ||
                       ( i == row &&
                         ( ( j == col - 1 ) || ( j == col + 1 ) ) ) ||
                       ( i == row - 1 && ( ( j == col - 1 ) || ( j == col ) ||
                                           ( j == col + 1 ) ) ) ) ) {
            cout << "\nInvalid Move.\nKing cannot be moved in such a "
                    "manner.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        }
    }
    if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) white = 1;
    // assigning new position to array
    *( chess_board_ptr + ( i * 8 + j ) ) = 'k';
}

void king_moves_black ( char* chess_board_ptr, int row, int col, bool& black ) {
    int new_row, i, j;
    char new_col;
    // displaying possible moves
    cout << endl;
    for ( int i = -1; i < 9; i++ ) {
        for ( int j = -1; j < 9; j++ ) {
            if ( ( j == -1 || j == 8 ) ) {
                // corners
                if ( i == -1 || i == 8 ) cout << ' ';
                // row numbers
                else
                    cout << ( 8 - i );
            }
            // column alphabets
            else if ( i == -1 || i == 8 )
                cout << static_cast<char> ( 97 + j );
            // possible moves
            // for black
            else if ( !( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
                         *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) &&
                      ( ( i == row + 1 && ( ( j == col - 1 ) || ( j == col ) ||
                                            ( j == col + 1 ) ) ) ||
                        ( i == row &&
                          ( ( j == col - 1 ) || ( j == col + 1 ) ) ) ||
                        ( i == row - 1 && ( ( j == col - 1 ) || ( j == col ) ||
                                            ( j == col + 1 ) ) ) ) ) {
                if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'r' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'n' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'b' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'q' ||
                     *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) {
                    cout << '*';
                } else
                    cout << '.';
            } else
                cout << *( chess_board_ptr + ( i * 8 + j ) );
            cout << ' ';
        }
        cout << endl;
    }
    // verifying and changing position of selected peice
    // assigning blank space to the initial position (from which the peice is
    // being moved)
    *( chess_board_ptr + ( row * 8 + col ) ) = ' ';
    // prompting new position of selected piece
    cout << "\nWhere would you like to move it\? ";
    cout << "\nRow # ";
    cin >> new_row;
    while ( !( new_row >= 1 && new_row <= 8 ) ) {
        cout << "Invalid Input. Please enter a valid row number (1-8): ";
        cin >> new_row;
    }
    cout << "Column: ";
    cin >> new_col;
    while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
        cout << "Invalid Input. Please enter a valid column (a-h): ";
        cin >> new_col;
    }
    i = ( 8 - new_row );
    j = ( new_col - 97 );
    // check for new position
    while ( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
            *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ||
            !( ( i == row + 1 &&
                 ( ( j == col - 1 ) || ( j == col ) || ( j == col + 1 ) ) ) ||
               ( i == row && ( ( j == col - 1 ) || ( j == col + 1 ) ) ) ||
               ( i == row - 1 && ( ( j == col - 1 ) || ( j == col ) ||
                                   ( j == col + 1 ) ) ) ) ) {
        if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'R' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'N' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'B' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'Q' ||
             *( chess_board_ptr + ( i * 8 + j ) ) == 'K' ) {
            cout << "\nInvalid Move.\nYou already have a piece placed at that "
                    "position.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        } else if ( !( ( i == row + 1 && ( ( j == col - 1 ) || ( j == col ) ||
                                           ( j == col + 1 ) ) ) ||
                       ( i == row &&
                         ( ( j == col - 1 ) || ( j == col + 1 ) ) ) ||
                       ( i == row - 1 && ( ( j == col - 1 ) || ( j == col ) ||
                                           ( j == col + 1 ) ) ) ) ) {
            cout << "\nInvalid Move.\nKing cannot be moved in such a "
                    "manner.\n\nPlease select another position:\nRow # ";
            cin >> new_row;
            while ( !( new_row >= 1 && new_row <= 8 ) ) {
                cout
                    << "Invalid Input. Please enter a valid row number (1-8): ";
                cin >> new_row;
            }
            cout << "Column: ";
            cin >> new_col;
            while ( !( new_col >= 'a' && new_col <= 'h' ) ) {
                cout << "Invalid Input. Please enter a valid column (a-h): ";
                cin >> new_col;
            }
            i = ( 8 - new_row );
            j = ( new_col - 97 );
        }
    }
    if ( *( chess_board_ptr + ( i * 8 + j ) ) == 'k' ) black = 1;
    // assigning new position to array
    *( chess_board_ptr + ( i * 8 + j ) ) = 'K';
}