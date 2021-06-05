#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Ship {
 protected:
  char p1, p2;
  int n1, n2;
  vector<char> p;
  vector<int> n;
  vector<bool> hitten;

 public:
  Ship(char, int, char, int);
  Ship() {}
  bool itIs(char, int);
  int getSize() { return hitten.size(); }
  bool isDestroyed();
  //bool destryed()
};

class Board {
  static const int size = 10;
  int numBar[size];
  char chaBar[size];
  char board[size][size];
  vector<Ship> ships;
  bool allDown;

  int four, three, two, one; // variables that defines number of ships to use
 public:
  Board();
  void display();

  // preapering to play
  void setSails(int); // main methode of placing ships on the board
  bool placeShip(char, int, char, int, int); // it helps setShip by checking errors
  void setShip(char, int, char, int, bool); // sets a ship on the board
  bool isOccupied(char, int, char, int, bool); // checks if the given fields are occupied
  void shipsFrame(char, int, char, int, bool); // creates a frame around the ship
  // jeszcze ewentualnie dopisac metode usuwajaca postawienie statku

  // during the game
  bool move(Board&, int, Board);
  bool isThereShip(char, int);
  bool didILost();
  int getShipsPosition(char, int);

  // methodes for AI
  int shipsNumSum() { return one + two + three + four; }
  void AISetSails();
  bool easyAImove(Board&);
  
  bool AImove(Board&);
  void calculations(char&, int&, bool&, bool&, int&);

  friend class Ship;
};

/*
        Rodzaje statkow (ilosc_jednostek_danego_typu x
   ilosc_kratek_ktore_zajmuje_okret): 1x4 2x3 3x2 4x1
*/

class HotSeat {
 protected:
  Board player1, player2;
  Board help1, help2;

 public:
  HotSeat();
  void preparation();
  void game();
};

class easyAI {
 protected:
  Board player, AI;
  Board help, helpAi;

  public:
  easyAI();
   void preperation();
   void game();
};

class AI {
 protected:
  Board player, al;
  Board help, helpAi;

 public:
  AI();
  void preperation();
  void game();
};