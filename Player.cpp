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
   preferred = -1; 
   size = 1; 
   elements = 0;
   career = new string[size]; 
   

   
}

Player::Player(const std::string &first, const std::string &last,
		unsigned int jersey, /*bool active,*/ const std::string &nickname) {
   firstName = first;
   lastName = last;
   jerseyNumber = jersey;
  // is_active = active;
   team_nickname = nickname;
   preferred = jersey; 
   size = 1; 
   elements = 0; 
   career = new string[size];
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

bool Player::record(const std::string &teamName, unsigned int num){
  std::string t = std::to_string(num); 
   std::string recording = teamName + "(#" + t + ")";
   //cout<< "CHEck" << endl; 

if(size == elements){
   std::string* tempArray = new std::string[size + 1]; 

   for(unsigned int i = 0; i < elements; i++){
         tempArray[i] = career[i];
   }
   delete[] career; 
   size++; 
   elements++; 
   career = tempArray; 

   career[size - 1] = recording;
   }else if (elements == 0){
          career[elements] = recording;
          elements++; 
      }else{
      career[size - elements] = recording;  
      elements++; 

   } 
   //cout << career[0] << endl; 
   //player[num_players++] = p;
   //num_players++;
   //player[0] = p;  
   return true;
   
}

void Player::showCareer(){
   cout << "dO SOMETHING" << endl;
   for(unsigned int i = 0; i < elements; i++){
      cout << career[i] << endl; 
   }
   

}