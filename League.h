#ifndef _LEAGUE_H
#define _LEAGUE_H
#include <iostream>
#include <vector>
#include "Team.h"

class League {
   private:
       std::vector<Team> team;

   public:
       League() {};
       bool addTeam(const Team &new_team);
       bool teamExists(const std::string &nickname) const;
       bool addPlayer(const Player &new_player, const std::string &teamMascot);
       void showTeams() const;
       bool showPlayers(const std::string &nickname) const;
};

#endif // _LEAGUE_H
