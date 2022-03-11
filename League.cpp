#include "League.h"
using namespace std;

bool League::addTeam(const Team &new_team) {
   if (new_team.getNickname().empty())
      return false;
   if (teamExists(new_team.getNickname()))
      return false;
  
   Team* temp = new Team[size + 1];
    for(unsigned int i = 0; i < size; i++){
	temp[i] = team[i]; 
    } 
    delete[] team; 
    size++;
    team = temp; 
     
    team[size-1] = new_team; 
    
//   team.push_back(new_team);
   return true;
} 

bool League::teamExists(const std::string &nickname) const {
   for (unsigned i = 0; i < size; i++) 
      if (team[i].getNickname() == nickname)
         return true;
   return false;
}

bool League::addPlayer(const Player &new_player, const std::string &nickname) {
  
   for (unsigned i = 0; i < size; i++){
      
      if (team[i].getNickname() == nickname) {
         
         team[i].showTeam(); 
         //Player player = Player("joe", "Mama", 233, "Giants"); 
         team[i].addPlayer(new_player);
         cout << "seg fault????" << endl; 
         return true;
      }
   }
   return false;
} 

void League::showTeams() const {
   cout << "Teams: " << size  << std::endl;
   for (unsigned i = 0; i < size; i++) 
      team[i].showTeam();
   return;
}

bool League::showPlayers(const std::string &nickname) const {  
   for (unsigned i = 0; i < size ; i++) 
      if (team[i].getNickname() == nickname) {
         team[i].showTeam();
         team[i].showPlayers();
         return true;
      }
   return false;
}
