#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Namelist.h"
#include "Stack.h"

using namespace std;

void correctAnswer(int);
void winner();

int main() {
	
  // Declare all the variables
  srand(time(0));
  int answer;
  int player;
  int round;
  int guess;
  int score1;
  int score2;
  int counterPlayer;
  int counterPlayer1;
  int counterPlayer2;
  int x;
  bool correct;
  bool correct1 = false;
  bool correct2 = false;
  DynIntStack stackAnswer;
  DynIntStack stackScore1;
  DynIntStack stackScore2;
  Namelist<int> team1;
  Namelist<int> team2;
  
  // Display Main Menu
  cout << "///////////////////////////////////////////////////" << endl;
  cout << "/////Welcome to the random guessing number game////" << endl;
  cout << "///////////////////////////////////////////////////" << endl;
  
  cout << endl;
  // Program ask user to enter the number of player that will play the game
  cout << "Please enter the number of player(minimun 2) " << endl;
  cout << "Number of player: ";
  cin >> player;
  
  //Input validation and ask user to enter the input again if the input wrong
  while(player<2)
  {
  	cout << "That is an invalid number of player, please try again"<< endl;
  	cout << "Number of player: ";
  	cin >> player;
  }
  
  // Appendnode operations for team 1 and team 2
  for(int h=0; h<player; h++)
  {
  	team1.appendNode(h+1);
  	team2.appendNode(h+1);
  }
  
  // Stack score operations for team 1 and team 2
  stackScore1.push(0);
  stackScore2.push(0);
  
  cout << endl;
  
  // Program display the range number that user need to guess
  cout << "Guess a number between 1 and " << (player * 10) << endl;
  cout << "********************************"<< endl;
  cout << endl;
  
  // Program ask user to enter the round that they intended
  cout << "Please enter the number of round(minimun 1) " << endl;
  cout << "Number of round: ";
  cin >> round;
  
  // input validation
  while(round<1)
  {
  	cout << "That is an invalid number of round, please try again"<< endl;
  	cout << "Number of round: ";
  	cin >> round;
  }
  
  cout << endl;
  
  // Game start with first round 
  for (int i = 0; i < round; i++) 
  {
  	cout << "Round " << i+1 << endl; // Program display the round 
  	cout << "___________________________________________________" << endl;
  	
  	// Declaring the variables
  	correct=false;
  	counterPlayer=0;
  	counterPlayer1=0;
  	counterPlayer2=0;
    answer = rand() % (player * 10) + 1; // Program will generate random number from the range 
    stackAnswer.push(answer); // stackAnswer operations
    
    // while true and counterPlayer isn't same with player
    while(!correct && counterPlayer!=player)
    {
    	if(i%2==0) // if the remainder equal to 0
    	{
    		
    	counterPlayer++; //update the counterPlayer value
    	
    	// while true and counterPlayer1 isn't same with counterPlayer
    	while(!correct && counterPlayer1!=counterPlayer)
    	{
    		// Program display team 1 and the players number
    		// Program will ask the players/user to guess the number
    		cout << "Team 1" << endl;
    		cout << "Player " << team1.searchnode(counterPlayer) << endl;
    		cout << "Guess the number: ";
    		cin >> guess;
    		
    		// if the answer is wrong
    		// Progam will display the answer is wrong and too low
    		if(guess<stackAnswer.top())
    		{
    			cout<<"incorrect answer, too low" << endl;
    			counterPlayer1++; // CounterPlayer1 value will be update
			}
			// if the answer is wrong
    		// Progam will display the answer is wrong and too high
			else if(stackAnswer.top()<guess)
    		{
    			cout<<"incorrect answer, too high" << endl;
    			counterPlayer1++; // CounterPlayer1 value will be update
			}
			
			// if the answer is right
			else
			{
				// Program will display congratulations to the user
				cout<<"Congratulations you got the correct answer" << endl;
				correct=true; // Correct will be set to true
				correct1=true; // Correct1 will be set to true
			}
			cout << endl;
		}
		
		// while true and counterPlayer2 isn't same with counterPlayer
		while(!correct && counterPlayer2!=counterPlayer)
    	{
    		// Program display team 2 and the players number
    		// Program will ask the players/user to guess the number
    		cout << "Team 2" << endl;
    		cout << "Player " << team2.searchnode(counterPlayer) << endl;
    		cout << "Guess the number: ";
    		cin >> guess;
    		
    		// if the answer is wrong
    		// Progam will display the answer is wrong and too low
    		if(guess<stackAnswer.top())
    		{
    			cout<<"incorrect answer, too low" << endl;
    			counterPlayer2++; // CounterPlayer2 value will be update
			}
			// if the answer is wrong
    		// Progam will display the answer is wrong and too high
			else if(stackAnswer.top()<guess)
    		{
    			cout<<"incorrect answer, too high" << endl;
    			counterPlayer2++; // CounterPlayer2 value will be update
			}
			
			// if the answer is right
			else
			{
				// Program will display congratulations to the user
				cout<<"Congratulations you got the correct answer" << endl;
				correct=true; // Correct will be set to true
				correct2=true; // Correct2 will be set to true
			}
			cout << endl;
		}
		
		// If correct is true or counterPlayer same with player
		if(correct || counterPlayer==player)
		{
			
		// if player from team 1 guess the right answer
		if(correct && correct1)
		{
			// Program will awarded the point to team 1
			cout << "1 point is awarded to Team 1" << endl;
			cout << endl;
			correct1=false; // correct1 will be set to false
			//score1 will be set to the stackScore1.top
			score1=stackScore1.top();
			stackScore1.push(score1+1);//stackScore1 will be push
		}
	    // if player from team 2 guess the right answer
		else if(correct && correct2)
		{
			// Program will awarded the point to team 2
			cout << "1 point is awarded to Team 2" << endl;
			cout << endl;
			correct2=false; // correct2 will be set to false
			//score2 will be set to the stackScore1.top
			score2=stackScore2.top();
			stackScore2.push(score2+1);	//stackScore2 will be push
		}
		// if both teams can't guess the answer 
		// no point will be awarded to the both teams
		else
		{
			cout << "No team guess correctly, no point is awarded" << endl;
			cout << endl;
		}
	    }
	    }
	    
	    // If the remainder not equal to 0
	    else
	    {
	    	
    	counterPlayer++; // counetrPlayer value will be update
    	
    	// while true and counterPlayer2 isn't same with counterPlayer
    	while(!correct && counterPlayer2!=counterPlayer)
    	{
    		// Program display team 2 and the players number
    		// Program will ask the players/user to guess the number
    		cout << "Team 2" << endl;
    		cout << "Player " << team2.searchnode(counterPlayer) << endl;
    		cout << "Guess the number: ";
    		cin >> guess;
    		
    		// if the answer is wrong
    		// Progam will display the answer is wrong and too low
    		if(guess<stackAnswer.top())
    		{
    			cout<<"incorrect answer, too low" << endl;
    			counterPlayer2++; // CounterPlayer2 value will be update
			}
			
			// if the answer is wrong
    		// Progam will display the answer is wrong and too high
			else if(stackAnswer.top()<guess)
    		{
    			cout<<"incorrect answer, too high" << endl;
    			counterPlayer2++; // CounterPlayer2 value will be update
			}
			
			// if the answer is right
			else
			{
				// Program will display congratulations to the user
				cout<<"Congratulations you got the correct answer" << endl;
				correct=true; // Correct will be set to true
				correct2=true; // Correct2 will be set to true
		
			}
			cout << endl;
		}
		
		// while true and counterPlayer1 isn't same with counterPlayer
    	while(!correct && counterPlayer1!=counterPlayer)
    	{
    		// Program display team 1 and the players number
    		// Program will ask the players/user to guess the number
    		cout << "Team 1" << endl;
    		cout << "Player " << team1.searchnode(counterPlayer) << endl;
    		cout << "Guess the number: ";
    		cin >> guess;
    		
    		// if the answer is wrong
    		// Progam will display the answer is wrong and too low
    		if(guess<stackAnswer.top())
    		{
    			cout<<"incorrect answer, too low" << endl;
    			counterPlayer1++;
			}
			
			// if the answer is wrong
    		// Progam will display the answer is wrong and too high
			else if(stackAnswer.top()<guess)
    		{
    			cout<<"incorrect answer, too high" << endl;
    			counterPlayer1++;
			}
			// if the answer is right
			else
			{
				// Program will display congratulations to the user
				cout<<"Congratulations you got the correct answer" << endl;
				correct=true; // Correct will be set to true
				correct1=true; // Correct2 will be set to true
			}
			cout << endl;
		}
		
		// If correct is true or counterPlayer same with player
		if(correct || counterPlayer==player)
		{
		// if player from team 1 guess the right answer	
		if(correct && correct1)
		{
			// Program will awarded the point to team 1
			cout << "1 point is awarded to Team 1" << endl;
			cout << endl;
			correct1=false;// correct1 will be set to false
			//score1 will be set to the stackScore1.top
			score1=stackScore1.top();
			stackScore1.push(score1+1);//stackScore1 will be push
		}
		// if player from team 2 guess the right answer
		else if(correct && correct2)
		{
			// Program will awarded the point to team 2
			cout << "1 point is awarded to Team 2" << endl;
			cout << endl;
			correct2=false;// correct2 will be set to false
			//score2 will be set to the stackScore1.top
			score2=stackScore2.top();
			stackScore2.push(score2+1);//stackScore2 will be push
		}
		
		// if both teams can't guess the answer 
		// no point will be awarded to the both teams
		else
		{
			cout << "No team guess correctly, no point is awarded" << endl;
			cout << endl;
		}
	    }
	    }
	}
  }
  // Program will display answer for every round
  for(int j=0; j<round; j++)
  {
  	cout << "The answer for round " << round-j << " :" << stackAnswer.top() << endl;
	stackAnswer.pop(x);
  }
  
  cout << endl;
  
  // If team 1 score higher than team 2
  // Program will display team 1 win with a score of and display team 2 score
  if(stackScore2.top()<stackScore1.top())
  {
  	cout << "Team 1 win with a score of " << stackScore1.top() << " point while Team 2 scored " << stackScore2.top() << " point" << endl;
  }
  
  // If team 2 score higher than team 1
  // Program will display team 2 win with a score of and display team 2 score
  else if(stackScore1.top()<stackScore2.top())
  {
  	cout << "Team 2 win with a score of " << stackScore2.top() << " point while Team 1 scored " << stackScore1.top() << " point" << endl;
  }
  // If both teams score is same 
  // Program will display both team score and both team tied
  else
  {
  	cout << "Both Team tied with a score of " << stackScore1.top() << " point" << endl;
  }
  
  return 0;
}


