#include "Player.h"
#include <iostream>
#include <sstream>

using namespace std;

Player::Player() {
   firstName = "";
   lastName = "";
   jerseyNumber = -1;
  // is_active = false;
   team_nickname = "";
}

Player::Player(const std::string &first, const std::string &last,
		unsigned int jersey, /*bool active,*/ const std::string &nickname) {
   firstName = first;
   lastName = last;
   jerseyNumber = jersey;
  // is_active = active;
   team_nickname = nickname;
}

bool Player::read() {
   std::string line;
   std::cout << "       First Name: "; 
   std::getline(cin, firstName);
   std::cout << "        Last Name: "; 
   std::getline(cin, lastName);
   std::cout << "           Number: "; 
   std::getline(cin, line);

   std::stringstream is;	       
   is.str(line);
   is >> jerseyNumber; 

   /*std::cout << "     Active (y/n): "; 
   std::getline(cin, line);
   is_active = false;
   if (!line.empty() && line[0] == 'y')
       is_active = true;
       */
         
   std::cout << "             Team: "; 
   std::getline(cin, team_nickname);

   return true; 
}

void Player::show() const {
   std::cout << lastName << ", " << firstName << " (#" << jerseyNumber << ") "
	     /*<< " [" << (!is_active ? "not " : "") << "active]" */ << std::endl;
}
