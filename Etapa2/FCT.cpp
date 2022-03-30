#include "FCT.h"

Game game;
string engine_color = "Black";

//  functie pentru citire/trimitere xboard:
void initial() {   
    //  sir in care stocam comenzile primite de la xboard:
    char command[256];

    //  bucla in care citim inputul de la stdin pentru
    //  verificarea comenzilor primite de la xboard:
    while(1) {
        fflush(stdout);

        if (!fgets(command, 256, stdin)) {
            cout << "NU a putut fi citita comanda!" << endl;
            exit(0);
        }

        if (!strcmp(command, "xboard\n"))
            cout << endl;
        //  optionalele pentru protover 2 cu feature-urile
        //  asociate pt nume si semnale:
        else if (!strcmp(command, "protover 2\n")) {
            cout << "feature done=0" << endl;
            cout << "feature myname=Ocult_Records" << endl;
            cout << "feature sigint=0" << endl;
            cout << "feature san=0" << endl;
            cout << "feature done=1" << endl;
        }
        else if (!strcmp(command, "new\n")) {
            //  reinitializeaza matricea de joc si
            //  seteaza culoarea engine-ului cu negru:
            game.update();
            engine_color = "Black";
        }
        else if (!strcmp(command, "force\n")) {
            //  Atribuie o culoare diferita de alb sau
            //  negru pentru engine pentru ca acesta sa
            //  nu fie nevoit sa mute in continuare:
            engine_color = "Neither";
        }
        else if (!strcmp(command, "go\n")) {
            //  in functie de culoarea actuala a engine-ului,
            //  acesta genereaza o mutare de pion:
            string mutare(command);

            if (!engine_color.compare("White"))
                cout<<"move "<<move(mutare, false);
            else
                if(!engine_color.compare("Black"))
                    cout<<"move "<<move(mutare, false);
        }
        else if (!strcmp(command, "white\n")) {
            //  setezam culoarea engine-ului alb:
            engine_color = "White";
        }
        else if (!strcmp(command, "black\n")) {
            //  setezam culoarea engine-ului negru:
            engine_color = "Black";
        }

        //  verificam daca se solicita inchiderea jocului:
        if (!strcmp(command, "quit\n")) {
            break;
        }
		//  verificam daca primim o mutare de tipul caracterNUMARcaracterNUMAR:
        else if (command[0] >= 'a' && command[0] <= 'h')
            if (command[1] >= '1' && command[1] <= '8') {
                string mutare(command);
                string final_action(move(mutare, true));

                if (!final_action.compare("resign\n"))
                    //  se cedeaza partida de joc:
                    cout<<final_action;
                else
                    //  se transmite mutarea engine-ului:
                    cout<<"move "<<final_action;
			}
    }
}

//  functie care intoarce mutarea pe care o
//  va genera engine-ul:
string move(string mutare, bool flag) {

    // DACA PIESA PRIMIM MUTARE CA INPUT:
        // engine-ul joaca cu culoarea negru:
    if(flag && !engine_color.compare("Black")) {
        //coordonate --> de unde mut --> unde mut
        int x_start, y_start, x_final, y_final;
        Empty empty;

        //  convertirea mutarii de tip caracterNUMARcaracterNUMAR
        //  in indici pentru tabla de joc:
        //  pozitia de unde pleaca:
        x_start = 9 - (mutare.at(1) - '0');
        y_start = (int)(mutare.at(0) - 96);
        //  pozitia in care ajunge:
        x_final = 9 - (mutare.at(3) - '0');
        y_final = (int)(mutare.at(2) - 96);

        //  mutarea pe tabla interna de joc a piesei si "eliberarea"
        //  patratului din care a plecat:
        game.Board[x_final][y_final].piece = game.Board[x_start][y_start].piece;
        game.Board[x_start][y_start].piece = empty;

        //  obtinerea culorii piesei care a fost mutata:
        string color = game.Board[x_start][y_start].piece.get_color();
        
        //  generarea mutarii pionului pe care o va face engine-ul
        //  in functie de culoarea pe care o reprezinta acesta:


        if(color == "White") {
            if(generate_bishop_moves("Black") != "resign")
                return generate_bishop_moves("Black");
            else if(generate_rook_moves("Black") != "resign")
                return generate_rook_moves("Black");
            else if(generate_queen_moves("Black") != "resign")
                return generate_queen_moves("Black");
            else if(generate_knight_moves("Black") != "resign")
                return generate_knight_moves("Black");
            else if(generate_pawn_moves("Black") != "resign")
                return generate_pawn_moves("Black");
            else if(generate_king_moves("Black") != "resign")
                return generate_king_moves("Black"); 
        }
        else {
            if(generate_bishop_moves("White") != "resign")
                return generate_bishop_moves("White");
            else if(generate_rook_moves("White") != "resign")
                return generate_rook_moves("White");
            else if(generate_queen_moves("White") != "resign")
                return generate_queen_moves("White");
            else if(generate_knight_moves("White") != "resign")
                return generate_knight_moves("White");
            else if(generate_pawn_moves("White") != "resign")
                return generate_pawn_moves("White");
            else if(generate_king_moves("White") != "resign")
                return generate_king_moves("White"); 
        }
    }
    else {
        //  engine-ul joaca cu culoarea alb:
        //  functionalitate similara cu cea a cazului
        //  in care engine-ul joaca cu negru;
        if(flag && !engine_color.compare("White")) {
            int x_start, y_start, x_final, y_final;
            Empty empty;

            x_start = 9 - (mutare.at(1) - '0');
            y_start = (int)(mutare.at(0) - 96);
            x_final = 9 - (mutare.at(3) - '0');
            y_final = (int)(mutare.at(2) - 96);

            game.Board[x_final][y_final].piece = game.Board[x_start][y_start].piece;
            game.Board[x_start][y_start].piece = empty;

            string color = game.Board[x_start][y_start].piece.get_color();
            
            if(color == "White") {
                if(generate_bishop_moves("Black") != "resign")
                    return generate_bishop_moves("Black");
                else if(generate_rook_moves("Black") != "resign")
                    return generate_rook_moves("Black");
                else if(generate_queen_moves("Black") != "resign")
                    return generate_queen_moves("Black");
                else if(generate_knight_moves("Black") != "resign")
                    return generate_knight_moves("Black");
                else if(generate_pawn_moves("Black") != "resign")
                    return generate_pawn_moves("Black");
                else if(generate_king_moves("Black") != "resign")
                    return generate_king_moves("Black"); 
        }
        else {
                if(generate_bishop_moves("White") != "resign")
                    return generate_bishop_moves("White");
                else if(generate_rook_moves("White") != "resign")
                    return generate_rook_moves("White");
                else if(generate_queen_moves("White") != "resign")
                    return generate_queen_moves("White");
                else if(generate_knight_moves("White") != "resign")
                    return generate_knight_moves("White");
                else if(generate_pawn_moves("White") != "resign")
                    return generate_pawn_moves("White");
                else if(generate_king_moves("White") != "resign")
                    return generate_king_moves("White"); 
            }
        }
    }

    // DACA TREBUIE GENERATA O MUTARE LA GO:
    if (!engine_color.compare("White")) {
        if(generate_bishop_moves("Black") != "resign")
            return generate_bishop_moves("Black");
        else if(generate_rook_moves("Black") != "resign")
            return generate_rook_moves("Black");
        else if(generate_queen_moves("Black") != "resign")
            return generate_queen_moves("Black");
        else if(generate_knight_moves("Black") != "resign")
            return generate_knight_moves("Black");
        else if(generate_pawn_moves("Black") != "resign")
            return generate_pawn_moves("Black");
        else if(generate_king_moves("Black") != "resign")
            return generate_king_moves("Black"); 
    }
    else {
        if(!engine_color.compare("Black")) {
            if(generate_bishop_moves("White") != "resign")
                return generate_bishop_moves("White");
            else if(generate_rook_moves("White") != "resign")
                return generate_rook_moves("White");
            else if(generate_queen_moves("White") != "resign")
                return generate_queen_moves("White");
            else if(generate_knight_moves("White") != "resign")
                return generate_knight_moves("White");
            else if(generate_pawn_moves("White") != "resign")
                return generate_pawn_moves("White");
            else if(generate_king_moves("White") != "resign")
                return generate_king_moves("White");
        }
    }

    return "resign\n";
}

//  functie care intoarce o mutare valida
//  de pion in functie de culoarea opusa:
string generate_pawn_moves(string color){
    point result;
    Empty empty;
    Queen queen1("Black");
    Queen queen2("White");
    string final_move;

    //  Se va muta un pion negru:
    if(color == "White") {
        //  se parcurge matricea interna de joc pana la identificarea
        //  primului pion pe coloana:
        for(int j = 1; j<=8; j++)
            for(int i = 1; i<=8; i++) {
                if(game.Board[i][j].piece.get_name() == "Pawn" 
                    && game.Board[i][j].piece.get_color() == "Black") {
                        //  generarea pozitiei pe care se va muta pionul:
                        result = pawn_valid_move(i,j,"Black");
                        
                        //  daca s-a generat o mutare valida se face update
                        //  pentru pozitia piesei pe tabla interna:
                        if(result.x != -1 && result.y != -1) {
                            game.Board[result.x][result.y] = game.Board[i][j];
                            game.Board[i][j].piece = empty;
                            
                            //  daca a ajuns in capatul opus al tablei de joc
                            //  se face promote la Regina:
                            if(result.x == 8)
                                game.Board[result.x][result.y].piece = queen1;

                            //  se genereaza string-ul de tip caracterNUMARcaracterNUMAR
                            //  cu mutarea finala:
                            final_move.push_back((char)(j+96));
                            final_move.push_back((char)(57-i));
                            final_move.push_back((char)(result.y+96));
                            final_move.push_back((char)(57-result.x));
                            final_move.push_back('\n');

                            return final_move;
                        }
                        else {
                            //  daca pionul nu mai poate avansa se declara resign:
                            return "resign\n";
                        }
                }
            }
    }
    //  se va muta un pion alb:
    //  functionalitate similara cu cea in cazul
    //  in care se va muta un pion negru:
    else {
        for(int j = 8; j >= 1; j--)
            for(int i = 1; i <= 8; i++) {
                if(game.Board[i][j].piece.get_name() == "Pawn" 
                    && game.Board[i][j].piece.get_color() == "White") {
                        result = pawn_valid_move(i,j,"White");

                        if(result.x != -1 && result.y != -1) {
                            game.Board[result.x][result.y] = game.Board[i][j];
                            game.Board[i][j].piece = empty;
                            
                            if(result.x == 1)
                                game.Board[result.x][result.y].piece = queen2;

                            final_move.push_back((char)(j+96));
                            final_move.push_back((char)(57-i));
                            final_move.push_back((char)(result.y+96));
                            final_move.push_back((char)(57-result.x));
                            final_move.push_back('\n');

                            return final_move;
                        }
                        else {
                            return "resign\n";
                        }
                }
            }
    }
    
    return "resign";
}

//  functie ce genereaza pozitia mutarii valide a
//  pionului in functie de culoarea sa:
point pawn_valid_move(int x, int y, string color) {
    point solution = {
        .x = -1,            //  initializarea pozitiei in care va ajunge
        .y = -1,            //  cu coordonate pentru o mutare invalida:
    };

    if(color == "Black") {
        //  se verifica posibilitatea capturarii in stanga:
        if(isOntable(x+1,y-1))
            if(game.Board[x+1][y-1].piece.get_name() != "Empty" 
                && game.Board[x+1][y-1].piece.get_color() == "White") {
                    solution.x = x+1;
                    solution.y = y-1;
                    return solution;
            }

        //  se verifica posibilitatea capturarii in dreapta:
        if(isOntable(x+1,y+1))
            if(game.Board[x+1][y+1].piece.get_name() != "Empty" 
                && game.Board[x+1][y+1].piece.get_color() == "White"){
                    solution.x = x+1;
                    solution.y = y+1;
                    return solution;
            }

        //  se verifica posibilitatea inaintarii pionului:
        if(isOntable(x+1,y)) {
            //  daca se afla pe prima linie de pioni va muta inainte
            //  2 patrate daca acea pozitie este libera, iar daca nu,
            //  va muta unul singur daca este posibil:
            if(x == 2) {
                if(game.Board[x+2][y].piece.get_name() == "Empty") {
                    solution.x = x+2;
                    solution.y = y;
                    return solution;
                }
                else 
                    if(game.Board[x+1][y].piece.get_name() == "Empty"){
                        solution.x = x+1;
                        solution.y = y;
                        return solution;
                    }
            }
            else 
                //  va inainta un patrat daca este posibil:
                if(game.Board[x+1][y].piece.get_name() == "Empty"){
                        solution.x = x+1;
                        solution.y = y;
                        return solution;
                    }
        }
    }
    //  daca pionul este alb:
    else {
        //  se verifica posibilitatea capturarii in stanga:
        if(isOntable(x-1,y-1))
            if(game.Board[x-1][y-1].piece.get_name() != "Empty" 
                && game.Board[x-1][y-1].piece.get_color() == "Black") {
                    solution.x = x-1;
                    solution.y = y-1;
                    return solution;
            }

        //  se verifica posibilitatea capturarii in dreapta:
        if(isOntable(x-1,y+1))
            if(game.Board[x-1][y+1].piece.get_name() != "Empty" 
                && game.Board[x-1][y+1].piece.get_color() == "Black") {
                    solution.x = x-1;
                    solution.y = y+1;
                    return solution;
            }
        
        //  se verifica posibilitatea inaintarii pionului,
        //  tiand cont de conditiile cazului in care pionul este negru:
        if(isOntable(x-1,y)) {
            if(x == 7) {
                if(game.Board[x-2][y].piece.get_name() == "Empty") {
                    solution.x = x-2;
                    solution.y = y;
                    return solution;
                } 
                else 
                    if(game.Board[x-1][y].piece.get_name() == "Empty") {
                        solution.x = x-1;
                        solution.y = y;
                        return solution;
                    }
            }
            else 
                if(game.Board[x-1][y].piece.get_name() == "Empty") {
                    solution.x = x-1;
                    solution.y = y;
                    return solution;
                }
        }
    }

    return solution;
}

//  functie ce verifica daca doua coordonate apartin
//  tablei de joc:
bool isOntable(int x, int y){
    if(x>8 || y>8 || x<1 || y<1)
        return false;
    return true;
}

string generate_rook_moves(string color){
    point result;
    Empty empty;
    string final_move;

    if(color == "White"){

        for(int j = 1; j <= 8; j++)
            for(int i = 1; i<=8; i++){
                if(game.Board[i][j].piece.get_name() == "Rook"
                   && game.Board[i][j].piece.get_color() == "Black"){

                       result = rook_valid_move(i,j,"Black");

                       if(result.x != -1 && result.y != -1) {

                            game.Board[result.x][result.y] = game.Board[i][j];
                            game.Board[i][j].piece = empty;

                            final_move.push_back((char)(j+96));
                            final_move.push_back((char)(57-i));
                            final_move.push_back((char)(result.y+96));
                            final_move.push_back((char)(57-result.x));
                            final_move.push_back('\n');

                            return final_move;
                       }
                       else{
                           return "resign\n";
                       }
                   }
            }
    }
    else{
        for(int j = 8; j >= 1; j--)
            for(int i = 8; i >= 1; i--){
                if(game.Board[i][j].piece.get_name() == "Rook"
                   && game.Board[i][j].piece.get_color() == "White"){

                       result = rook_valid_move(i,j,"White");

                       if(result.x != -1 && result.y != -1) {

                            game.Board[result.x][result.y] = game.Board[i][j];
                            game.Board[i][j].piece = empty;

                            final_move.push_back((char)(j+96));
                            final_move.push_back((char)(57-i));
                            final_move.push_back((char)(result.y+96));
                            final_move.push_back((char)(57-result.x));
                            final_move.push_back('\n');

                            return final_move;
                       }
                       else{
                           return "resign\n";
                       }
                   }
            }
    }

    return final_move;
}

point rook_valid_move(int x, int y, string color){
    point solution = {
        .x = -1,            //  initializarea pozitiei in care va ajunge
        .y = -1,            //  cu coordonate pentru o mutare invalida:
    };

    if(color == "Black"){

        if(game.Board[x+1][y].piece.get_color() != "Black"){ 
            for(int i = x+1; i <= 8; i++){         
                    if(game.Board[i][y].piece.get_name() == "Empty"){
                            solution.x++;
                        }
                    if(game.Board[i][y].piece.get_color() == "White"){
                        solution.x++;
                        return solution;
                    }

                    if(game.Board[i][y].piece.get_color() == "Black")
                        return solution;
            }
        }
        
        if(game.Board[x-1][y].piece.get_color() != "Black"){ 
            for(int i = x-1; i >= 1; i--){
                    if(game.Board[i][y].piece.get_name() == "Empty"){
                            solution.x--;
                        }
                    if(game.Board[i][y].piece.get_color() == "White"){
                        solution.x--;
                        return solution;
                    }

                    if(game.Board[i][y].piece.get_color() == "Black")
                        return solution;
            }
        }
        if(game.Board[x][y+1].piece.get_color() != "Black"){ 
            for(int j = y+1; j <= 8; j++){
                if(game.Board[x][j].piece.get_name() == "Empty"){
                            solution.y++;
                        }
                    if(game.Board[x][j].piece.get_color() == "White"){
                        solution.y++;
                        return solution;
                    }

                    if(game.Board[x][j].piece.get_color() == "Black")
                        return solution;
            }
        }
        if(game.Board[x][y-1].piece.get_color() != "Black"){ 
            for(int j = y-1; j >= 1; j--){
                if(game.Board[x][j].piece.get_name() == "Empty"){
                            solution.y--;
                        }
                    if(game.Board[x][j].piece.get_color() == "White"){
                        solution.y--;
                        return solution;
                    }

                    if(game.Board[x][j].piece.get_color() == "Black")
                        return solution;
            }
        }
    }
    else{

         if(game.Board[x+1][y].piece.get_color() != "White"){ 
            for(int i = x+1; i <= 8; i++){         
                    if(game.Board[i][y].piece.get_name() == "Empty"){
                            solution.x++;
                        }
                    if(game.Board[i][y].piece.get_color() == "Black"){
                        solution.x++;
                        return solution;
                    }

                    if(game.Board[i][y].piece.get_color() == "White")
                        return solution;
            }
        }
        
        if(game.Board[x-1][y].piece.get_color() != "White"){ 
            for(int i = x-1; i >= 1; i--){
                    if(game.Board[i][y].piece.get_name() == "Empty"){
                            solution.x--;
                        }
                    if(game.Board[i][y].piece.get_color() == "Black"){
                        solution.x--;
                        return solution;
                    }

                    if(game.Board[i][y].piece.get_color() == "White")
                        return solution;
            }
        }
        if(game.Board[x][y+1].piece.get_color() != "White"){ 
            for(int j = y+1; j <= 8; j++){
                if(game.Board[x][j].piece.get_name() == "Empty"){
                            solution.y++;
                        }
                    if(game.Board[x][j].piece.get_color() == "Black"){
                        solution.y++;
                        return solution;
                    }

                    if(game.Board[x][j].piece.get_color() == "White")
                        return solution;
            }
        }
        if(game.Board[x][y-1].piece.get_color() != "White"){ 
            for(int j = y-1; j >= 1; j--){
                if(game.Board[x][j].piece.get_name() == "Empty"){
                            solution.y--;
                        }
                    if(game.Board[x][j].piece.get_color() == "Black"){
                        solution.y--;
                        return solution;
                    }

                    if(game.Board[x][j].piece.get_color() == "White")
                        return solution;
            }
        }

    }
    return solution;
}

string generate_bishop_moves(string color){
    point result;
    Empty empty;
    string final_move;

    if(color == "White"){

        for(int j = 1; j <= 8; j++)
            for(int i = 1; i<=8; i++){
                if(game.Board[i][j].piece.get_name() == "Bishop"
                   && game.Board[i][j].piece.get_color() == "Black"){

                       result = bishop_valid_move(i,j,"Black");

                       if(result.x != -1 && result.y != -1) {

                            game.Board[result.x][result.y] = game.Board[i][j];
                            game.Board[i][j].piece = empty;

                            final_move.push_back((char)(j+96));
                            final_move.push_back((char)(57-i));
                            final_move.push_back((char)(result.y+96));
                            final_move.push_back((char)(57-result.x));
                            final_move.push_back('\n');

                            return final_move;
                       }
                       else{
                           return "resign\n";
                       }
                   }
            }
    }
    else{
        for(int j = 8; j >= 1; j--)
            for(int i = 8; i >= 1; i--){
                if(game.Board[i][j].piece.get_name() == "Bishop"
                   && game.Board[i][j].piece.get_color() == "White"){

                       result = bishop_valid_move(i,j,"White");

                       if(result.x != -1 && result.y != -1) {

                            game.Board[result.x][result.y] = game.Board[i][j];
                            game.Board[i][j].piece = empty;

                            final_move.push_back((char)(j+96));
                            final_move.push_back((char)(57-i));
                            final_move.push_back((char)(result.y+96));
                            final_move.push_back((char)(57-result.x));
                            final_move.push_back('\n');

                            return final_move;
                       }
                       else{
                           return "resign\n";
                       }
                   }
            }
    }

    return final_move;

}

point bishop_valid_move(int x, int y, string color){
    point solution = {
        .x = -1,            //  initializarea pozitiei in care va ajunge
        .y = -1,            //  cu coordonate pentru o mutare invalida:
    };

    //solution.x = x;
    //solution.y = y;

    int i,j;
    if(color == "Black"){
        
        if(game.Board[x+1][y+1].piece.get_color() == "Black"){
            for(i = x + 1, j = y + 1;  i<=8 && j<=8; i++, j++){
                if(game.Board[i][j].piece.get_name() == "Empty"){
                    solution.x++;
                    solution.y++;
                }
                else if(game.Board[i][j].piece.get_color() == "White"){
                    solution.x++;
                    solution.y++;
                    return solution;
                }
                else return solution;
            }
        }

        if(game.Board[x+1][y-1].piece.get_color() == "Black"){
            for(i = x + 1, j = y - 1; i<=8 && j>=1; i++, j--){
                if(game.Board[i][j].piece.get_name() == "Empty"){
                    solution.x++;
                    solution.y++;
                }
                else if(game.Board[i][j].piece.get_color() == "White"){
                    solution.x++;
                    solution.y++;
                    return solution;
                }
                else return solution;
            }
        }

        if(game.Board[x-1][y+1].piece.get_color() == "Black"){
            for(i = x - 1, j = y + 1; i<=1 && j<=8; i--, j++){
                if(game.Board[i][j].piece.get_name() == "Empty"){
                    solution.x++;
                    solution.y++;
                }
                else if(game.Board[i][j].piece.get_color() == "White"){
                    solution.x++;
                    solution.y++;
                    return solution;
                }
                else return solution;
            }
        }
    
        if(game.Board[x-1][y-1].piece.get_color() == "Black"){
            for(i = x - 1, j = y - 1; i>=8 && j >= 8; i--, j--){
                if(game.Board[i][j].piece.get_name() == "Empty"){
                    solution.x++;
                    solution.y++;
                }
                else if(game.Board[i][j].piece.get_color() == "White"){
                    solution.x++;
                    solution.y++;
                    return solution;
                }
                else return solution;
            }
        }
    }
    else{

        if(game.Board[x+1][y+1].piece.get_color() == "White"){
            for(i = x + 1, j = y + 1; i<=8 && j<=8; i++, j++){
                if(game.Board[i][j].piece.get_name() == "Empty"){
                    solution.x++;
                    solution.y++;
                }
                else if(game.Board[i][j].piece.get_color() == "Black"){
                    solution.x++;
                    solution.y++;
                    return solution;
                }
                else return solution;
            }
        }

        if(game.Board[x+1][y-1].piece.get_color() == "White"){
            for(i = x + 1, j = y - 1; i<=8 && j>=1; i++, j--){
                if(game.Board[i][j].piece.get_name() == "Empty"){
                    solution.x++;
                    solution.y++;
                }
                else if(game.Board[i][j].piece.get_color() == "Black"){
                    solution.x++;
                    solution.y++;
                    return solution;
                }
                else return solution;
            }
        }

        if(game.Board[x-1][y+1].piece.get_color() == "White"){
            for(i = x - 1, j = y + 1; i<=1 && j<=8; i--, j++){
                if(game.Board[i][j].piece.get_name() == "Empty"){
                    solution.x++;
                    solution.y++;
                }
                else if(game.Board[i][j].piece.get_color() == "Black"){
                    solution.x++;
                    solution.y++;
                    return solution;
                }
                else return solution;
            }
        }
    
        if(game.Board[x-1][y-1].piece.get_color() == "White"){
            for(i = x - 1, j = y - 1; i>=8 && j >= 8; i--, j--){
                if(game.Board[i][j].piece.get_name() == "Empty"){
                    solution.x++;
                    solution.y++;
                }
                else if(game.Board[i][j].piece.get_color() == "Black"){
                    solution.x++;
                    solution.y++;
                    return solution;
                }
                else return solution;
            }
        }
    }
    return solution;
}

string generate_knight_moves(string color){
    point result;
    Empty empty;
    string final_move;

    if(color == "White"){

        for(int j = 1; j <= 8; j++)
            for(int i = 1; i<=8; i++){
                if(game.Board[i][j].piece.get_name() == "Knight"
                   && game.Board[i][j].piece.get_color() == "Black"){

                       result = knight_valid_move(i,j,"Black");

                       if(result.x != -1 && result.y != -1) {

                            game.Board[result.x][result.y] = game.Board[i][j];
                            game.Board[i][j].piece = empty;

                            final_move.push_back((char)(j+96));
                            final_move.push_back((char)(57-i));
                            final_move.push_back((char)(result.y+96));
                            final_move.push_back((char)(57-result.x));
                            final_move.push_back('\n');

                            return final_move;
                       }
                       else{
                           return "resign\n";
                       }
                   }
            }
    }
    else{
        for(int j = 8; j >= 1; j--)
            for(int i = 8; i >= 1; i--){
                if(game.Board[i][j].piece.get_name() == "Knight"
                   && game.Board[i][j].piece.get_color() == "White"){

                       result = knight_valid_move(i,j,"White");

                       if(result.x != -1 && result.y != -1) {

                            game.Board[result.x][result.y] = game.Board[i][j];
                            game.Board[i][j].piece = empty;

                            final_move.push_back((char)(j+96));
                            final_move.push_back((char)(57-i));
                            final_move.push_back((char)(result.y+96));
                            final_move.push_back((char)(57-result.x));
                            final_move.push_back('\n');

                            return final_move;
                       }
                       else{
                           return "resign\n";
                       }
                   }
            }
    }
    return final_move;
}

point knight_valid_move(int x, int y, string color){
    point solution = {
        .x = -1,            //  initializarea pozitiei in care va ajunge
        .y = -1,            //  cu coordonate pentru o mutare invalida:
    };

    

    if(isOntable(x+2,y+1))
        if(game.Board[x+2][y+1].piece.get_name() == "Empty" || 
            game.Board[x+2][y+1].piece.get_color() != color){
                solution.x = x+2;
                solution.y = y+1;
                return solution;
        }
    
    if(isOntable(x+2,y-1))
        if(game.Board[x+2][y-1].piece.get_name() == "Empty" || 
            game.Board[x+2][y-1].piece.get_color() != color){
                solution.x = x+2;
                solution.y = y-1;
                return solution;
        }
    
    if(isOntable(x+1,y-2))
        if(game.Board[x+1][y-2].piece.get_name() == "Empty" || 
            game.Board[x+1][y-2].piece.get_color() != color){
                solution.x = x+1;
                solution.y = y-2;
                return solution;
        }
    if(isOntable(x+1,y+2))
        if(game.Board[x+1][y+2].piece.get_name() == "Empty" || 
            game.Board[x+1][y+2].piece.get_color() != color){
                solution.x = x+1;
                solution.y = y+2;
                return solution;
        }

    if(isOntable(x-1,y-2))
        if(game.Board[x-1][y-2].piece.get_name() == "Empty" || 
            game.Board[x-1][y-2].piece.get_color() != color){
                solution.x = x-1;
                solution.y = y-2;
                return solution;
            }
            
    if(isOntable(x-1,y+2))
        if(game.Board[x-1][y+2].piece.get_name() == "Empty" || 
            game.Board[x-1][y+2].piece.get_color() != color){
                solution.x = x-1;
                solution.y = y+2;
                return solution;
        }
    
    if(isOntable(x-2,y+1))
        if(game.Board[x-2][y+1].piece.get_name() == "Empty" || 
            game.Board[x-2][y+1].piece.get_color() != color){
                solution.x = x-2;
                solution.y = y+1;
                return solution;
        }
    
    if(isOntable(x-2,y+1))
        if(game.Board[x-2][y+1].piece.get_name() == "Empty" || 
            game.Board[x-2][y+1].piece.get_color() != color){
                solution.x = x-2;
                solution.y = y+1;
                return solution;
        }

    return solution;
}

string generate_queen_moves(string color){
    point result;
    Empty empty;
    string final_move;

    if(color == "White"){
        for(int j = 1; j <= 8; j++)
            for(int i = 1; i<=8; i++){
                if(game.Board[i][j].piece.get_name() == "Queen"
                   && game.Board[i][j].piece.get_color() == "Black"){

                       result = queen_valid_move(i,j,"Black");

                       if(result.x != -1 && result.y != -1) {

                            game.Board[result.x][result.y] = game.Board[i][j];
                            game.Board[i][j].piece = empty;

                            final_move.push_back((char)(j+96));
                            final_move.push_back((char)(57-i));
                            final_move.push_back((char)(result.y+96));
                            final_move.push_back((char)(57-result.x));
                            final_move.push_back('\n');

                            return final_move;
                       }
                       else{
                           return "resign\n";
                       }
                   }
            }
    }
    else{
        for(int j = 8; j >= 1; j--)
            for(int i = 8; i >= 1; i--){
                if(game.Board[i][j].piece.get_name() == "Queen"
                   && game.Board[i][j].piece.get_color() == "White"){

                       result = queen_valid_move(i,j,"White");

                       if(result.x != -1 && result.y != -1) {

                            game.Board[result.x][result.y] = game.Board[i][j];
                            game.Board[i][j].piece = empty;

                            final_move.push_back((char)(j+96));
                            final_move.push_back((char)(57-i));
                            final_move.push_back((char)(result.y+96));
                            final_move.push_back((char)(57-result.x));
                            final_move.push_back('\n');

                            return final_move;
                       }
                       else{
                           return "resign\n";
                       }
                   }
            }
    }
    return final_move;
}

point queen_valid_move(int x, int y, string color){
    point solution = {
        .x = -1,            //  initializarea pozitiei in care va ajunge
        .y = -1,            //  cu coordonate pentru o mutare invalida:
    };

    

    solution = rook_valid_move(x,y,color);
    
    if(x == -1 || y == -1)
        solution = bishop_valid_move(x,y,color);
    
    return solution;
}

string generate_king_moves(string color){
    point result;
    Empty empty;
    string final_move;

    if(color == "White"){
        for(int j = 1; j <= 8; j++)
            for(int i = 1; i<=8; i++){
                if(game.Board[i][j].piece.get_name() == "king"
                   && game.Board[i][j].piece.get_color() == "Black"){

                       result = king_valid_move(i,j,"Black");

                       if(result.x != -1 && result.y != -1) {

                            game.Board[result.x][result.y] = game.Board[i][j];
                            game.Board[i][j].piece = empty;

                            final_move.push_back((char)(j+96));
                            final_move.push_back((char)(57-i));
                            final_move.push_back((char)(result.y+96));
                            final_move.push_back((char)(57-result.x));
                            final_move.push_back('\n');

                            return final_move;
                       }
                       else{
                           return "resign\n";
                       }
                   }
            }
    }
    else{
        for(int j = 8; j >= 1; j--)
            for(int i = 8; i >= 1; i--){
                if(game.Board[i][j].piece.get_name() == "King"
                   && game.Board[i][j].piece.get_color() == "White"){
                       result = king_valid_move(i,j,"White");

                       if(result.x != -1 && result.y != -1) {

                            game.Board[result.x][result.y] = game.Board[i][j];
                            game.Board[i][j].piece = empty;

                            final_move.push_back((char)(j+96));
                            final_move.push_back((char)(57-i));
                            final_move.push_back((char)(result.y+96));
                            final_move.push_back((char)(57-result.x));
                            final_move.push_back('\n');

                            return final_move;
                       }
                       else{
                           return "resign\n";
                       }
                   }
            }
    }
    return final_move;
}

point king_valid_move(int x, int y, string color){
    point solution = {
        .x = -1,            //  initializarea pozitiei in care va ajunge
        .y = -1,            //  cu coordonate pentru o mutare invalida:
    };

    

    if(isOntable(x+1,y+1))
        if(game.Board[x+1][y+1].piece.get_name() == "Empty" || 
            game.Board[x+1][y+1].piece.get_color() != color){
                solution.x = x+1;
                solution.y = y+1;
                return solution;
        }
    
    if(isOntable(x+1,y))
        if(game.Board[x+1][y].piece.get_name() == "Empty" || 
            game.Board[x+1][y].piece.get_color() != color){
                solution.x = x+1;
                solution.y = y;
                return solution;
        }
    
    if(isOntable(x+1,y-1))
        if(game.Board[x+1][y-1].piece.get_name() == "Empty" || 
            game.Board[x+1][y-1].piece.get_color() != color){
                solution.x = x+1;
                solution.y = y-1;
                return solution;
        }
    if(isOntable(x,y+1))
        if(game.Board[x][y+1].piece.get_name() == "Empty" || 
            game.Board[x][y+1].piece.get_color() != color){
                solution.x = x;
                solution.y = y+1;
                return solution;
        }

    if(isOntable(x-1,y-1))
        if(game.Board[x-1][y-1].piece.get_name() == "Empty" || 
            game.Board[x-1][y-1].piece.get_color() != color){
                solution.x = x-1;
                solution.y = y-1;
                return solution;
            }
            
    if(isOntable(x-1,y))
        if(game.Board[x-1][y].piece.get_name() == "Empty" || 
            game.Board[x-1][y].piece.get_color() != color){
                solution.x = x-1;
                solution.y = y;
                return solution;
        }
    
    if(isOntable(x,y+1))
        if(game.Board[x][y+1].piece.get_name() == "Empty" || 
            game.Board[x][y+1].piece.get_color() != color){
                solution.x = x;
                solution.y = y+1;
                return solution;
        }
    
    if(isOntable(x-1,y+1))
        if(game.Board[x-1][y+1].piece.get_name() == "Empty" || 
            game.Board[x-1][y+1].piece.get_color() != color){
                solution.x = x-1;
                solution.y = y+1;
                return solution;
        }

    return solution;
}
