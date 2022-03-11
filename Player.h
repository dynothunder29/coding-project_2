#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>

class Player {
   private:
      std::string firstName;
      std::string lastName;
      unsigned int jerseyNumber;
      std::string team_nickname;
     // bool is_active;

   public:
      Player();
      Player(const std::string &first, const std::string &last,
             unsigned int jersey, /*bool active, */ const std::string &nickname);
      std::string getTeam() {return team_nickname;};
      bool read();
      void show() const;
};

#endif // _PLAYER_H
