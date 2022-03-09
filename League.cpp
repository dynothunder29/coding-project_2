#include "League.h"
using namespace std;

bool League::addTeam(const Team &new_team) {
   if (new_team.getNickname().empty())
      return false;
   if (teamExists(new_team.getNickname()))
      return false;
   team.push_back(new_team);
   return true;
} 

bool League::teamExists(const std::string &nickname) const {
   for (unsigned i = 0; i < team.size(); i++) 
      if (team[i].getNickname() == nickname)
         return true;
   return false;
}

bool League::addPlayer(const Player &new_player, const std::string &nickname) {
   for (unsigned i = 0; i < team.size(); i++) 
      if (team[i].getNickname() == nickname) {
         team[i].addPlayer(new_player);
         return true;
      }
   return false;
} 

void League::showTeams() const {
   cout << "Teams: " << team.size() << std::endl;
   for (unsigned i = 0; i < team.size(); i++) 
      team[i].showTeam();
   return;
}

bool League::showPlayers(const std::string &nickname) const {
   for (unsigned i = 0; i < team.size(); i++) 
      if (team[i].getNickname() == nickname) {
         team[i].showTeam();
         team[i].showPlayers();
         return true;
      }
   return false;
}
