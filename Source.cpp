#include "Header.h"
#include <cmath>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>

// preapering to play
Board::Board() : four(1), three(1), two(0), one(0), allDown(false) { // potem poprawic liczbe statkow 1 2 3 4
  for (int i = 0; i < size; i++) {
    numBar[i] = i + 1;
  }
  for (int i = 0; i < size; i++) {
    chaBar[i] = i + 65;
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      board[i][j] = 'X';
    }
  }
}

void Board::display() {
  cout << " ";
  for (int i = 0; i < size; i++) {
    cout << " " << numBar[i];
  }
  cout << endl;
  for (int i = 0; i < size; i++) {
    cout << chaBar[i];
    for (int j = 0; j < size; j++) {
      cout << ' ' << board[i][j];
    }
    cout << endl;
  }

}

void Board::shipsFrame(char p1, int n1, char p2, int n2, bool isChar) {
  //int x = abs(n2 - n1) + 1, y = abs(p2 - p1) + 1;
    for (int i = (p1 - 66 > 0) ? (p1 - 66) : 0; i < p2 - 63 and i < 10; i++) {
      for (int j = (n1 - 2 > 0) ? (n1 - 2) : 0; j < n2 + 1 and j < 10; j++) {
        if (board[i][j] != 'O')
          board[i][j] = 'H';
      }
    }
}

void Board::setShip(char p1, int n1, char p2, int n2, bool isChar) {
  int counter = abs(n2 - n1) + abs(p2 - p1) + 1;
  if (isChar) {
    for (int i = 0; i < counter; i++) {
      board[p1 - 65 + i][n1 - 1] = 'O';
      shipsFrame(p1, n1, p2, n2, isChar);
    }
  } else {
    for (int i = 0; i < counter; i++) {
      board[p1 - 65][n1 - 1 + i] = 'O';
      shipsFrame(p1, n1, p2, n2, isChar);
    }
  }
  display();
  ships.push_back(Ship(p1, n1, p2, n2));
}

bool Board::isOccupied(char p1, int n1, char p2, int n2, bool isChar) {
  int counter = abs(n2 - n1) + abs(p2 - p1) + 1;
  if (isChar) {
    for (int i = 0; i < counter; i++) {
      if (board[p1 - 65 + i][n1 - 1] != 'X') {
        return true;
      }
    }
  } else {
    for (int i = 0; i < counter; i++) {
      if (board[p1 - 65][n1 - 1 + i] != 'X') {
        return true;
      }
    }
  }
  return false;
}

bool Board::placeShip(char p1, int n1, char p2, int n2, int sizeOfShip) {
  int check1, check2;
  check1 = abs(p1 - p2);
  check2 = abs(n1 - n2);
  bool isChar = (check1 != 0) ? true : false;
  bool notSettled = true;
  if (check1 == (sizeOfShip - 1) && check2 == 0) {
    if (!isOccupied(p1, n1, p2, n2, isChar)) {
      setShip(p1, n1, p2, n2, isChar); 
      notSettled = false;
    }
  } else if (check2 == (sizeOfShip - 1) && check1 == 0) {
    if (!isOccupied(p1, n1, p2, n2, isChar)) {
      setShip(p1, n1, p2, n2, isChar);
      notSettled = false;
    }
  } else
    return notSettled;
}

void Board::setSails(int plaNumber) {
  int number;
  while ((four + three + two + one) > 0) {
    system("CLS");
    cout << "Gracz nr " << plaNumber << " rozmieszcza swoje statki\n";
    display();
    cout << "Masz do dyspozycji " << four << " czteromasztowcow, " << three << 
        " trojmasztowcow, " << two << " dwumasztowcow i " << one << " jednomasztowcow.\n";
    cout << "Podaj ilosc masztow dla statku, ktory chcesz rozmiescic: ";
    cin >> number;
    switch (number) {
      case 1: {
        if (one == 0) {
          cout << "Nie ma juz jednomasztowcow.\n";
        } else {
          bool shipNotSettled = true;
          char a, b;
          int A, B;
          while (shipNotSettled) {
            cout << "Podaj wspolzedna poczatku statku: ";
            cin >> a >> A;
            cout << "Podaj wspolzena konca statku: ";
            cin >> b >> B;
            shipNotSettled = placeShip(a, A, b, B, 1);
            if (shipNotSettled == true) {
              cout << "Bledne wspolrzedne.\nJezeli chesz ustawic inny statek "
                      "wcisnij: 0\nJezeli chesz ponownie podac wspolrzedne "
                      "podaj liczbe rozna od 0\n";
              int choice;
              cin >> choice;
              if (!choice)
                shipNotSettled = false;
            } else
              --one;
          }
        }
      } break;
      case 2: {
        if (two == 0) {
          cout << "Nie ma juz dwumasztowcow.\n";
        } else {
          bool shipNotSettled = true;
          char a, b;
          int A, B;
          while (shipNotSettled) {
            cout << "Podaj wspolzedna poczatku statku: ";
            cin >> a >> A;
            cout << "Podaj wspolzena konca statku: ";
            cin >> b >> B;
            shipNotSettled = placeShip(a, A, b, B, 2);
            if (shipNotSettled) {
              cout << "Bledne wspolrzedne.\nJezeli chesz ustawic inny statek "
                      "wcisnij: 0\nJezeli chesz ponownie podac wspolrzedne "
                      "podaj liczbe rozna od 0\n";
              int choice;
              cin >> choice;
              if (!choice)
                shipNotSettled = false;
            } else
              --two;
          }
        }
      } break;
      case 3: {
        if (three == 0) {
          cout << "Nie ma juz trojmasztowcow.\n";
        } else {
          bool shipNotSettled = true;
          char a, b;
          int A, B;
          while (shipNotSettled) {
            cout << "Podaj wspolzedna poczatku statku: ";
            cin >> a >> A;
            cout << "Podaj wspolzena konca statku: ";
            cin >> b >> B;
            shipNotSettled = placeShip(a, A, b, B, 3);
            if (shipNotSettled) {
              cout << "Bledne wspolrzedne.\nJezeli chesz ustawic inny statek "
                      "wcisnij: 0\nJezeli chesz ponownie podac wspolrzedne "
                      "podaj liczbe rozna od 0\n";
              int choice;
              cin >> choice;
              if (!choice)
                shipNotSettled = false;
            } else
              --three;
          }
        }
      } break;
      case 4: {
        if (four == 0) {
          cout << "Nie ma juz czteromasztowcow.\n";
        } else {
          bool shipNotSettled = true;
          char a, b;
          int A, B;
          while (shipNotSettled) {
            cout << "Podaj wspolzedna poczatku statku: ";
            cin >> a >> A;
            cout << "Podaj wspolzena konca statku: ";
            cin >> b >> B;
            shipNotSettled = placeShip(a, A, b, B, 4);
            if (shipNotSettled) {
              cout << "Bledne wspolrzedne.\nJezeli chesz ustawic inny statek "
                      "wcisnij: 0\nJezeli chesz ponownie podac wspolrzedne "
                      "podaj liczbe rozna od 0\n";
              int choice;
              cin >> choice;
              if (!choice)
                shipNotSettled = false;
            } else
              --four;
          }
        }
      } break;
      default:
        cout << "Nie ma statku z tyloma masztami.\n";
        break;
    }
    cout << "Aby przejsc dalej wcisnij dowolny przycisk. ";
    char lalal;
    cin >> lalal;
  }
}

// during the game

bool Board::isThereShip(char p, int n) {
  int y = p - 65, x = n - 1;
  if (board[y][x] == 'O') {
    return true;
  }
  else
    return false;
}

bool Board::didILost() {
  for (int i = 0; i < ships.size(); i++) {
    if (!ships[i].isDestroyed())
      return false;
  }
  return true;
}

int Board::getShipsPosition(char p, int n) {
  for (int i = 0; i < ships.size(); i++) {
    if (ships[i].itIs(p, n)) {
      return i;
    }
  }
  return 420;
}

bool Board::move(Board &help, int number, Board playersBoard) {
  char p;
  int n;
  bool moveEnd = true;
  while (moveEnd) {
    system("CLS");
    cout << "Ruch gracza nr. " << number << endl;
    cout << "Twoja plansza\n";
    playersBoard.display();
    cout << "Plansza pomocnicza, na ktorej beda twoje trafione strzely.\n";
    help.display();
    cout << "Podaj wspolrzedne punktu, ktoryr chcesz zaatakowac: ";
    cin >> p >> n;
    if ((p < 65 or p > 74) or (n < 1 or n > 10)) {
      cout << "Dane z poza przedzialu, podaj wspolrzedne ponownie.\n";
      continue;
    }
    moveEnd = isThereShip(p, n);
    if (moveEnd) {
      int y = p - 65, x = n - 1;
      help.board[y][x] = 'T';
      int position = getShipsPosition(p, n);
      if (position != 420) {

        if (ships[position].isDestroyed()) {
          cout << "Trafiony, zatopiony!\n";
          if (didILost()) {
            cout << "Zwyciezyl gracz " << number << "!" << endl;
            return false;
          }
        } else
          cout << "Trafiony!\n";
      }
    } else {
      cout << "Pudlo!\n";
      int g = p - 65, h = n - 1;
      help.board[g][h] = '~';
    }
    char stoper; // it is needed to inform player about his move, otherwise it would be cleared
    cout << "Wcisnij dowolny przycisk. ";
    cin >> stoper;
  }
  return true;
}

// methodes for AI

void Board::AISetSails() {
    char p1, p2;
    int n1, n2;
    int chose;
      
      // four masts
      while (four) {
        chose = rand() % 2;
        bool notChar = (chose == 1) ? false : true;
        if (chose == 1) {
          n1 = rand() % 7 + 1;
          p1 = rand() % 10 + 65;
          n2 = n1 + 3;
          p2 = p1;
        } else {
          n1 = rand() % 10 + 1;
          p1 = rand() % 7 + 65;
          n2 = n1;
          p2 = p1 + 3;
        }
        if (isOccupied(p1, n1, p2, n2, notChar)) {
          continue;
        } else {
          setShip(p1, n1, p2, n2, notChar);
          four--;
        }
      }
      // three masts
      while (three) {
        chose = rand() % 2;
        bool notChar = (chose == 1) ? false : true;
        if (chose == 1) {
          n1 = rand() % 8 + 1;
          p1 = rand() % 10 + 65;
          n2 = n1 + 2;
          p2 = p1;
        } else {
          n1 = rand() % 10 + 1;
          p1 = rand() % 8 + 65;
          n2 = n1;
          p2 = p1 + 2;
        }
        if (isOccupied(p1, n1, p2, n2, notChar)) {
          continue;
        } else {
          setShip(p1, n1, p2, n2, notChar);
          three--;
        }
      }
      // two masts
      while (two) {
        chose = rand() % 2;
        bool notChar = (chose == 1) ? false : true;
        if (chose == 1) {
          n1 = rand() % 9 + 1;
          p1 = rand() % 10 + 65;
          n2 = n1 + 1;
          p2 = p1;
        } else {
          n1 = rand() % 10 + 1;
          p1 = rand() % 9 + 65;
          n2 = n1;
          p2 = p1 + 1;
        }
        if (isOccupied(p1, n1, p2, n2, notChar)) {
          continue;
        } else {
          setShip(p1, n1, p2, n2, notChar);
          two--;
        }
      }
      // one mast
      while (one) {
        n1 = rand() % 10 + 1;
        p1 = rand() % 10 + 65;
        n2 = n1;
        p2 = p1;
        if (isOccupied(p1, n1, p2, n2, false)) {
          continue;
        } else {
          setShip(p1, n1, p2, n2, false);
          one--;
        }
      }
      /*system("CLS");
      display();*/
}

bool Board::easyAImove(Board &help) {
  char p;
  int n;
  bool moveEnd = true;
  while (moveEnd) {
    n = rand() % 10 + 1;
    p = rand() % 10 + 65;
    int y = p - 65, x = n - 1;
    if (help.board[y][x] == '~') {
      continue;
    }
    moveEnd = isThereShip(p, n);
    if (moveEnd) {

      help.board[y][x] = 'T';
      int position = getShipsPosition(p, n);
      if (position != 420) {
        if (ships[position].isDestroyed()) {
          if (didILost()) {
            cout << "Zwyciezyl gracz " << 2 << "!" << endl;
            return false;
          }
        }
      }
    } else {
      help.board[p - 65][n - 1] = '~';
    }
  }
  return true;
}

void Board::calculations(char& p, int& n, bool& hittenMark, bool& previous, int& counter) {
  if (hittenMark == true and previous == true) {
    if (p < 'J')
      p++;
    else if (n < 10)
      n++;
    else {
      hittenMark = false;
      previous = false;
      counter = counter % 2 + 1;
      p = 'A';
      if (counter == 1) {
        n = 1;
      } else {
        n = 2;
      }
    }
  } else {
    if (counter == 1) {
      if (n < 9) {
        n += 2;
      } else if (p < 'J' and n == 9) {
        p++;
        n = 2;
      } else if (p < 'J' and n == 10) {
        p++;
        n = 1;
      } else {
        counter++;
        p = 'A';
        n = 2;
      }
    } else {
      if (n < 10) {
        n += 2;
      } else if (p < 'J' and n == 10) {
        p++;
        n = 1;
        
      } else if (p < 'J' and n == 9) {
        p++;
        n = 2;
      } else {
        counter--;
        p = 'A';
        n = 2;
      }
    }
  }

}

bool Board::AImove(Board& help) {
  char p = 'A', courseP;
  int n = -1, courseN;
  bool moveEnd = true;
  // obsluga tego czy bylo nowe trafienie w poprzedniej turze
  bool hitTheMark = false;
  bool previousTurnT = false;
  int someCounter = 1;

  
  while (moveEnd) {
    
    calculations(p, n, hitTheMark, previousTurnT, someCounter);

    int y = p - 65, x = n - 1;
    if (help.board[y][x] == '~') {
      continue;
    }


    moveEnd = isThereShip(p, n);
    if (moveEnd) {
      previousTurnT =
          (help.board[y][x] != 'T' and help.board[y][x] != '~') ? true : false;
      hitTheMark = true;
      help.board[y][x] = 'T';
      int position = getShipsPosition(p, n);
      if (position != 420) {
        if (ships[position].isDestroyed()) {
          if (didILost()) {
            cout << "Zwyciezyl gracz " << 2 << "!" << endl;
            return false;
          }
        }
      }
    } else {
      help.board[p - 65][n - 1] = '~';
      hitTheMark = false;
    }
  }
  

  return true;
}


// ===================================================
//                  class Ship methodes
// ===================================================


Ship::Ship(char p1_, int n1_, char p2_, int n2_)
    :p1(p1_), n1(n1_), p2(p2_), n2(n2_) {
  int counter = abs(n2 - n1) + abs(p2 - p1) + 1;
  if (n2_ - n1_ == 0) {
    for (int i = 0; i < counter; i++) {
      hitten.push_back(false);
      n.push_back(n1_);
      p.push_back(p1_ + i);
    }
  } else {
    for (int i = 0; i < counter; i++) {
      hitten.push_back(false);
      n.push_back(n1_ + i);
      p.push_back(p1_);
    }
  }
}
// here i mark part of a ship as destroyed
bool Ship::itIs(char pg, int ng) {
  int counter = hitten.size();
  for (int i = 0; i < counter; i++) {
    if (p[i] == pg and n[i] == ng) {
      hitten[i] = true;
      return true;
    }
  }
  return false;
}

bool Ship::isDestroyed() {
  int a = 0;
  for (int i = 0; i < hitten.size(); i++) {
    if (hitten[i]) {
      a++;
    }
  }
  if (a == hitten.size())
    return true;
  else
    return false;
}


// ===================================================
//                  class HotSeat methodes
// ===================================================

HotSeat::HotSeat() {
  preparation();
  game();
}

void HotSeat::preparation() {
  player1.setSails(1);
  player2.setSails(2);
}

void HotSeat::game() {
  bool gameNotEnded = true;
  int pl1 = 1, pl2 = 2;
  while (gameNotEnded) {
    gameNotEnded = player2.move(help2, pl1, player1);
    cout << "Plansza pomocnicza, ktora wskazuje oddane strzaly przeciwnika.\n";
    help1.display();
    char a;
    cout << "Podaj na wejscie dowolny przycisk: ";
    cin >> a;
    if (!gameNotEnded)
      break;
    gameNotEnded = player1.move(help1, pl2, player2);
    cout << "Plansza pomocnicza, ktora wskazuje oddane strzaly przeciwnika.\n";
    help2.display();
    cout << "Podaj na wejscie dowolny przycisk: ";
    cin >> a;
  }
}

// ===================================================
//                  class easyAI methodes
// ===================================================

easyAI::easyAI() {
  preperation();
  game();
}

void easyAI::preperation() {
  player.setSails(1);
  AI.AISetSails();
}

void easyAI::game() {

  bool gameNotEnded = true;
  while (gameNotEnded) {
    gameNotEnded = AI.move(help, 1, player);
    if (!gameNotEnded)
      break;
    gameNotEnded = player.easyAImove(helpAi);
    cout << "Plansza pomocnicza, ktora wskazuje oddane strzaly przeciwnika.\n";
    helpAi.display();
    char a;
    cout << "Podaj na wejscie dowolny przycisk: ";
    cin >> a;
  }
}

// ===================================================
//                  class AI methodes
// ===================================================

AI::AI() {
  preperation();
  game();
}

void AI::preperation() {
  player.setSails(1);
  al.AISetSails();
}

void AI::game() {
  bool gameNotEnded = true;
  while (gameNotEnded) {
    gameNotEnded = al.move(help, 1, player);
    if (!gameNotEnded)
      break;
    gameNotEnded = player.AImove(helpAi);
    cout << "Plansza pomocnicza, ktora wskazuje oddane strzaly przeciwnika.\n";
    helpAi.display();
    char a;
    cout << "Podaj na wejscie dowolny przycisk: ";
    cin >> a;
  }
}