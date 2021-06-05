// ships_project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"

int main()
{
  cout << "GRA W STATKI\n kliknnij dowolny przycisk: ";
  char c;
  cin >> c;
  system("CLS");
  cout << "Aby zagrac w trybie Hot Seat kliknij: 1\nAby zagrac z komputerem "
          "kliknij: 2\nAby zakonczyc rozgrywke kliknij: 3\n";
  int a;
  cin >> a;
  switch (a) {
    case 1: {
      HotSeat pvp;
    } break;
    case 2: {
      cout << "Wybierz poziom trudnosci.\nAby zagrac w tryb dla poczatkujacych "
              "graczy kliknij: 1\nAby zagrac w tryb dla doswiadczonych graczy "
              "kliknij: 2\n";
      int b;
      cin >> b;
      switch (b) {
        case 1: {
          easyAI gg;
        } break;
        case 2: {
          AI ggwp;
        } break;
        default:
          break;
      }
    } break;
    default:
      break;
  }
  
  

  return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
