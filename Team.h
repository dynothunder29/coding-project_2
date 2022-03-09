#ifndef _TEAM_H
#define _TEAM_H

#include "Player.h"
#include <iostream>

const unsigned int MAX_PLAYERS = 12;

class Team {
   private:
      std::string location;
      std::string nickname;

      unsigned int num_players; 
      Player player[MAX_PLAYERS];

   public:
      Team();
      Team(const std::string &loc, const std::string &name);
      std::string getNickname() const {return nickname;};
      bool addPlayer(const Player &p);
      void showTeam() const;
      void showPlayers() const;
      bool read();
      friend std::ostream &operator<<(std::ostream &out, const Team &tm);
};

#endif // _TEAM_H
