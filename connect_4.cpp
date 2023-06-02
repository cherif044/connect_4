



#include <iostream>
#include <string>
using namespace std;

        class tile {

        public:
            string color;
            string win_scheme;

            tile() {
                color = "Blank";
                win_scheme = "";

            }
            tile(int c) {
                switch (c) {

                case  0:
                        color = "orange";
                        win_scheme = "v";

                        break;
                case 1:

                            color = "green";
                            win_scheme = "h";

                            break;
                case 2:

                                color = "yellow";
                                win_scheme = "dlr";

                                break;
                case 3:

                                    color = "purple";
                                    win_scheme = "drl";
                                    break;

                }


            }

            bool operator==(tile t2) {

                if (this->color == t2.color) {

                    return true;
                }
                else {
                    return false;

                }
            }
            bool isEmpty() {
                if (color == "Blank") {

                    return true;
                }
                else {
                    return false;

                }

            }
            tile *operator=(tile t2) {

                this->color = t2.color;
                this->win_scheme = t2.win_scheme;
                return this;

            }


            tile& operator=(tile* t2) {

                *this = *t2;
                return *this;

            }

            void display() {

                cout << color << endl;
                cout << win_scheme << endl;
            }
            void print() {

                cout << color;
            }

        };
            class board {

            public:
                int no_of_rows = 6;
                int no_of_cols = 7;
                tile Board[6][7];
                int blankCount;

                board() {

                    blankCount = 42;
                }



                void display_board() {
                    cout << endl;
                    for (int i = 1; i <= 7; i++) {

                        cout << "col " << i << "          ";
                    }
                    cout << endl;
                    for (int i = 0; i < 6; i++) {
                        for (int j = 0; j < 7; j++)
                        {
                            cout << "|  ";
                            Board[i][j].print();
                            cout << "  |" << '\t';
                        }
                        cout << endl;

                    }

                }
                void insert(tile x, int col)
                {
                    bool flag = false;
                    int temp = no_of_rows - 1;
                    while (flag == false && temp != -1)
                    {
                        if (Board[temp][col].isEmpty())
                        {
                            Board[temp][col] = x;
                            flag = true;
                            blankCount--;
                        }
                        temp--;
                        
                    }
                    if (temp == -1)
                    {
                        cout << "column is full" << endl;
                    }
                }
                bool checkRTLConnected(tile* winner)
                {
                    int row = no_of_rows;
                    int col = no_of_cols;
                    bool flag = false;
                    int temp_row;
                    int temp_cols;
                    for (int row = 0; row < no_of_rows; row++)
                    {
                        for (int col = 0; col < no_of_cols; col++)
                        {
                            temp_row = row;
                            temp_cols = col;
                            int equivilant = 0;
                            int sequence = 0;
                            while (temp_row < no_of_rows && temp_cols >= 0 && sequence < 4)
                            {
                                if (Board[temp_row][temp_cols].color == "purple")
                                {
                                    equivilant++;
                                }
                                temp_row++;
                                temp_cols--;
                                sequence++;
                            }
                            if (equivilant == 4)
                            {
                                winner->color = "purple";
                                winner->win_scheme = "drl";
                                flag = true;

                            }
                        }
                    }

                    return flag;
                }
                bool checkLTRConnected(tile* winner)
                {
                    int row = no_of_rows;
                    int col = no_of_cols;
                    bool flag = false;
                    int temp_row;
                    int temp_cols;
                    for (int row = 0; row < no_of_rows; row++)
                    {
                        for (int col = 0; col < no_of_cols; col++)
                        {
                            temp_row = row;
                            temp_cols = col;
                            int equivilant = 0;
                            int sequence = 0;
                            while (temp_row < no_of_rows && temp_cols < no_of_cols && sequence < 4)
                            {
                                if (Board[temp_row][temp_cols].color == "yellow")
                                {
                                    equivilant++;
                                }
                                temp_row++;
                                temp_cols++;
                                sequence++;
                            }
                            if (equivilant == 4)
                            {
                                winner->color = "yellow";
                                winner->win_scheme = "dlr";
                                flag = true;

                            }
                        }
                    }

                    return flag;
                }
                bool checkHorizontallyConnected(tile* winner)
                {
                    int row = no_of_rows;
                    int col = no_of_cols;
                    bool flag = false;
                    int temp_row;
                    int temp_cols;
                    for (int row = 0; row < no_of_rows; row++)
                    {
                        for (int col = 0; col < no_of_cols; col++)
                        {

                            temp_cols = col;
                            int equivilant = 0;
                            int sequence = 0;
                            while (temp_cols < no_of_cols && sequence < 4)
                            {
                                if (Board[row][temp_cols].color == "green")
                                {
                                    equivilant++;
                                }
                                temp_cols++;
                                sequence++;
                            }
                            if (equivilant == 4)
                            {
                                winner->color = "green";
                                winner->win_scheme = "h";
                                flag = true;

                            }
                        }
                    }

                    return flag;
                }
                bool checkVerticallyConnected(tile* winner)
                {
                    int row = no_of_rows;
                    int col = no_of_cols;
                    bool flag = false;
                    int temp_row;
                    int temp_cols;
                    for (int row = 0; row < no_of_rows; row++)
                    {
                        for (int col = 0; col < no_of_cols; col++)
                        {

                            temp_row = row;
                            int equivilant = 0;
                            int sequence = 0;
                            while (temp_row < no_of_rows && sequence < 4)
                            {
                                if (Board[temp_row][col].color == "orange")
                                {
                                    equivilant++;
                                }
                                temp_row++;
                                sequence++;
                            }
                            if (equivilant == 4)
                            {
                                winner->color = "orange";
                                winner->win_scheme = "v";
                                flag = true;

                            }
                        }
                    }

                    return flag;
                }
            };
            
            class player {
            public:
                string name;
                int number;
                int score;
                tile Tile;


                player(string n, int num, tile T) {

                    name = n;
                    number = num;
                    Tile = T;

                }
                void info() {

                    cout <<"name " << name << " and its color " << Tile.color;


                }

            };
            class game {
            public:
                int* score;
                int* tilenumber;
                int* playernumber;
                int numberofplayers;
                player** Player;
                board Board;
                tile* winner;
                bool win;

                game() {

                    win = false;


                    score = new int[numberofplayers];

                    tilenumber = new int[numberofplayers];

                    playernumber = new int[numberofplayers];

                    Player = new player*[numberofplayers];
                    
                  

                    winner = new tile;
                }
                void GameStart() {

                    cout << "how many players?";
                    cin >> numberofplayers;

                    IntializeTeams();
                   
                    Board.display_board();

                    PlayStart();
                }
                void PlayStart() 
                {

                    int chosen, temp = 0;
                    win = false;
                    while (win == false)
                    {
                        temp = temp % numberofplayers;
                        cout << "player number: " << temp + 1 << " enter column number " << endl;
                        cin >> chosen;
                        chosen--;
                        Board.insert(Player[temp]->Tile, chosen);
                        
                        int x = 0;
                        if (checkState())
                        {
                            
                            Board.display_board();
                            cout << "player number: " << temp + 1 << " is the winner" << endl;

                            Player[temp]->info();
                            win = true;
                        }
                        else if (Board.blankCount == 0)
                        {
                            cout << endl;
                            cout << "tie";
                            win = true;
                            Board.display_board();
                        }
                        else
                        {
                            temp++;
                            Board.display_board();
                            
                        }

                    }
                        
                }               
                void IntializeTeams() {
                    choosetile(numberofplayers);
                    


                }
                bool checkState() 
                {
                    
                    if (Board.checkRTLConnected(winner) == true) 
                    {
                        cout << "checkRTLConnected";
                        return true;

                    }
                    else if (Board.checkLTRConnected(winner) == true) 
                    {
                        cout << "checkLTRConnected";
                        return true;

                    }
                    else if (Board.checkHorizontallyConnected(winner) == true) 
                    {
                        cout << "checkHorizontallyConnected";
                        return true;

                    }
                    else if (Board.checkVerticallyConnected(winner) == true) 
                    {
                        cout << "checkVerticallyConnected";
                        return true;

                    }
                    return false;
                    



                }

                void choosetile(int numberofplayers)
                {
                    int* array = new int[numberofplayers];
                    int chosen;
                    string name;
                    srand(time(0));
                    bool unique = true;
                    
                    for (int i = 0; i < numberofplayers; i++)
                    {

                        cout << "enter name" << endl;
                        cin >> name;
                        do
                        {
                            unique = true;
                            chosen = rand() % numberofplayers;
                            for (int j = 0; j < i; j++)
                            {
                                if (chosen == array[j])
                                {
                                    unique = false;
                                }
                            }
                        } 
                        while (unique == false);

                        
                        tile t(chosen);
                        Player[i] = new player(name, i + 1, t);
                        
                        array[i] = chosen;
                    }
                    cout << "team:" << endl;
                    for (int i = 0; i < numberofplayers; i++)
                    {
                        cout << "player number: " << i+1 << endl;
                        cout << Player[i]->name << " has the color: "<<Player[i]->Tile.color << endl;
                    }
                }


            };




            int main() 
            {
                game g;
                g.GameStart(); 


                    return 0;
            }
