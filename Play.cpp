#include "Player.h"
#include "Team.h"
#include "League.h"
#include "Parser.h"
#include <iostream>
#include <string>
using namespace std;

void do_AddPlayer(string first, string last, int jersey, string team){
	cout << "do_AddPlayer(" << first << ", " << last << ", " << jersey << ", "  << team << " )" << endl; 
}

void do_AddTeam(string location, string nickname){
	cout << "do_AddTeam(" << location << ", " << nickname << ")" << endl; 
}

void do_GetLeague(){
	cout << "do_GetLeague()" << endl; 
}

void do_GetRoster(string teamName){
	cout << "do_GetRoster(" << teamName << ")" << endl; 	
}


int main() {
  // string command;  
   Team team;
   Player player;
   League league;
   string line;
   int int_param;
   Team freeAgents("", "Free Agents"); 
   //int try_this; 
//hi
  //freeAgents = Team("", "Free Agents");
 // league.addTeam(freeAgents); 
   while (1) {
      //freeAgents = Team("", "Free Agents");
      //league.addTeam(freeAgents); 


      std::string teamName;
      cout << endl << "Enter a command: " << endl;
      cout << "Choose from [\"Team\" \"Player\" \"League\" \"Roster\" \"Quit\"]" << endl; 
      cout << ": "; 

      std::getline(std::cin, line);
      Parser command(line); 

      if (command.getOperation()  == "Team") {
		team = Team(command.getArg1(), command.getArg2());
		
            if (!league.teamExists(team.getNickname())){
               league.addTeam(team);
	    	do_AddTeam(command.getArg1(), command.getArg2()); 
	    }
	    	
            else 
	       cout << "Duplicate team nickname " << team.getNickname() <<       
		       " not added" << std::endl;;
        // }
	// else
          //  cout << "Team didn't read properly" << std::endl;
      }
      else if (command.getOperation() == "Player") {
     
          
		if (Parser::isInteger(command.getArg3())){
			 int_param = stoi(command.getArg3());
            player = Player(command.getArg1(), command.getArg2(), int_param, command.getArg4());

             if (!league.addPlayer(player, player.getTeam())){
		         cout << "Could not add the player to team" << player.getTeam() << std::endl;;
               do_AddPlayer(command.getArg1(), command.getArg2(), int_param, command.getArg4() );
             }
		 }else{
			cout << "Error: arg 3: " << command.getArg3() << " is not an integer" << endl; 
       }
        
      }
      else if (command.getOperation()  == "League")
            league.showTeams();
      else if (command.getOperation() == "Roster") {
            teamName = command.getArg1(); 
            if(teamName == "" ){
               league.showPlayers("Free Agents");
               do_GetRoster("Free Agents");
            }else{

        //    cout << "Team: ";
	   // std::getline(std::cin, teamName);
            league.showPlayers(teamName);
            do_GetRoster(command.getArg1()); 
            }
      }
      else if (command.getOperation() == "Quit") {
         break;
      }
      else {
         cout << "Command " << command.getOperation() << " not recognized. Please try again." << endl; 
      }
   }
}
