#include "Team.h"
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>

using namespace std;

Team::Team() {
   location = "";
   nickname = "";
   num_players = 0;
}

Team::Team(const std::string &loc, const std::string &name) {
   location = loc; 
   nickname = name; 
   num_players = 0; 
}

bool Team::addPlayer(const Player &p) {
   if (num_players == MAX_PLAYERS)
      return false;
   player[num_players++] = p;
   //num_players++;
   //player[0] = p;  
   return true;
}

void Team::showTeam() const {
   std::cout << location << " " << nickname << endl;	 
}

void Team::showPlayers() const {
   std::cout << "   Players:" << std::endl;
   for (unsigned int i = 0; i < num_players; i++) {
      player[i].show();
   }
}

bool Team::read() {
   string line;

   std::cout << "     Location: "; 
   std::getline(std::cin, location);
   std::cout << "     Nickname: "; 
   std::getline(std::cin, nickname);
   return true; 
}

std::ostream &operator<<(std::ostream &out, const Team &tm) {
   tm.showTeam();
   return out;
}
