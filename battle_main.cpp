#include <map>
#include <iostream>
#include <string>
#include <limits>
#include "Monster.hpp"
using namespace std;

const char* PROMPT_NAME = "Enter your name: ";
const char* PROMPT_COMMAND = "(a) to Attack, (b) to open Bag, (p) to see Monsters, (r) to Run";
const char* PROMPT_MOVE = "Select a move: ";

const char* ERROR_NAME = "Invalid name.";
const char* ERROR_COMMAND = "Invalid command.";

// prints out the information of two monsters
void print_monsters(Monster m1, Monster m2) {
  m1.print_monster(cout);
  cout << endl;
  m2.print_monster(cout);
}

// prints out the moves of a monster
void print_move(Monster mon) {

}

int main() {
  // get player's name
  cout << PROMPT_NAME;
  string name;
  if (!(cin >> name)) {
    throw invalid_argument(ERROR_NAME);
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');


  // Create my two monsters for example
  Monster m1("Hydreigon", 50, 100, Type::DARK, Type::DRAGON);
  Monster m2("Metagross", 50, 100, Type::STEEL, Type::PSYCHIC);

  // start counting turns and start prompting player
  unsigned int turn_count = 1;
  print_monsters(m1, m2);
  cout << "Turn " << turn_count << ": " << PROMPT_COMMAND << endl;

  string command;
  while(getline(cin, command)) {
    // attack command
    if (command == "a") {
      cout << PROMPT_MOVE << endl;
    // bag command
    } else if (command == "b") {
      cout << "Opening bag" << endl;
    // monsters command
    } else if (command == "p") {
      cout << "Displaying Monsters" << endl;
    // run command
    } else if (command == "r") {
      cout << "Successfully ran away!" << endl;
      return 0;
    // invalid command
    } else {
      cout << ERROR_COMMAND << endl;
    }
    turn_count++;
    print_monsters(m1, m2);
    cout << "Turn " << turn_count << ": " << PROMPT_COMMAND << endl;
  }
  return 0;
}