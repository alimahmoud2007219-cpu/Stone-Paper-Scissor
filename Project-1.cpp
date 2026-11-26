# include <iostream>
# include <cstdlib>
# include <cmath>
# include <string>
# include <windows.h>
using namespace std;

enum enPaperOrStoneOrScissor { Paper = 1 , Stone = 2 , Scissor = 3 };
enum enResults { User = 1 , Computer = 2 , balance = 3  , Nothing = 4 };

string ChoiceName ( enPaperOrStoneOrScissor Card )
{
switch ( Card )
{

case ::Paper :
return "Paper";

case ::Stone :
return "Stone";

case ::Scissor :
return "Scissor";

default :
return "Unknown";

}

}

bool ReplayOrNot ()
{
string Key = " ";

cout << endl << "Do you want to play a game";
cout << " yes : [y]  /  No : [n] \n";
cout << endl << "Enter : ";

cin >> Key;

if ( Key == "y")
return true;

else 
return false;

}

int RandomNumbers ( int from , int to )
{
int Random;

Random = rand() % ( to - from + 1 ) + from;
return Random;
}

int ReadNumber ()
{
int N;

do {
cout << "How many rounds do you want to play ? " << endl; 
cout << "Choose from [1] to [10] :  " ;
cin  >> N ;

}while ( N < 1 || N > 10 );

return N;
}

enPaperOrStoneOrScissor UserChoice ()
{
int Choice;
do {
cout << endl << endl << "Enter your choice" << endl ;
cout << "[1] : Paper  /  [2] : Stone  /  [3] : Scissor \n";
cout << "Enter : ";
cin  >> Choice;

}while ( Choice < 1 || Choice > 3 );

return (enPaperOrStoneOrScissor) Choice;

}

enPaperOrStoneOrScissor ComputerChoice ()
{
return (enPaperOrStoneOrScissor) RandomNumbers ( 1 , 3 );    
}

enResults WhoWins ( enPaperOrStoneOrScissor User , enPaperOrStoneOrScissor Computer )
{

if      ( User == ::Paper && Computer == ::Stone )
{
return ::User;
}

else if ( User == :: Paper && Computer == ::Scissor )
{
return ::Computer;    
}

else if ( User == ::Paper && Computer == ::Paper )
{
return ::balance;   
}

else if ( User == ::Scissor && Computer == ::Paper  )
{
return ::User;
}

else if ( User == ::Scissor && Computer == ::Stone  )
{
return ::Computer;
}

else if ( User == ::Scissor && Computer == ::Scissor  )
{
return ::balance;
}

else if ( User == ::Stone && Computer == ::Scissor  )
{
return ::User;
}

else if ( User == ::Stone && Computer == ::Paper  )
{
return ::Computer;
}

else if ( User == ::Stone && Computer == ::Stone  )
{
return ::balance;
}

return ::Nothing; 
}

void ShowResultsEveryRound ( float& wins , float& loses , float& balances)
{
wins = 0 ;
loses = 0 ; 
balances = 0 ;

int Number_Rounds = ReadNumber ();

for ( int i = 1 ; i <= Number_Rounds ; ++i )
{    
    
enPaperOrStoneOrScissor User = UserChoice ();
enPaperOrStoneOrScissor Computer = ComputerChoice ();

if ( WhoWins ( User , Computer ) == ::User )
{
system ("color 0A");

cout << endl << endl << "________________________Round [ " << i << " ]________________________\n"; 

cout << endl << "Your card [" <<  ChoiceName (User) << "] won " <<  "Computer card ["<<  ChoiceName (Computer) << "] " ;
cout << endl << "You won this round , congratulations!!" << endl ;

cout << "_____________________________________________________________________";

++wins;
}

else if ( WhoWins ( User , Computer ) == ::Computer )
{
system ("color 04");
Beep (750 ,300);

cout << endl << endl << "________________________Round [ " << i << " ]________________________\n"; 

cout << endl << "Your card [" <<  ChoiceName (User) << "] won " <<  "Computer card ["<<  ChoiceName (Computer) << "] " ;
cout << endl << "You lost this game , hardluck" << endl ;

cout << "_____________________________________________________________________";

++loses;
}

else if ( WhoWins ( User , Computer ) == ::balance )
{
system ("color 06");   

cout << endl << endl << "________________________Round [ " << i << " ]________________________\n"; 

cout << endl << "Your card [" <<  ChoiceName (User) << "] won " <<  "Computer card ["<<  ChoiceName (Computer) << "] " ;
cout << endl << "You are balanced" << endl;

cout << "_____________________________________________________________________";

++balances;
}

}

}


void ShowFinalResults ( float wins , float loses , float balances )
{
cout << "\n\n\n__________________________________________________________________________\n";
cout << "_____________________________The final results ____________________________\n\n\n"; 

if ( wins > loses && wins > balances )
{
system ("color 0A");

cout << "Number of wins is = "     << wins << endl;
cout << "Number of loses is = "    << loses << endl;
cout << "Number of balances is = " << balances << endl;

cout << "Your percentage of wins = " << (wins / ( wins + loses + balances) * 100) << " %\n\n";  
cout << "\n\nCongratulations!! , you are the winner of this game \n";

cout << "______________________________________________________________";
}
    
else if ( loses > wins && loses > balances )
{
system ("color 04");

cout << "Number of wins is = "     << wins << endl;
cout << "Number of loses is = "    << loses << endl;
cout << "Number of balances is = " << balances << endl;

cout << "Your percentage of wins = " << (wins / ( wins + loses + balances) * 100) << " %\n\n"; 
cout << "\n\nFor sorry you lost this match\n";

cout << "______________________________________________________________";
}

else if ( (balances > loses && balances > wins ) || ( wins == loses ) ) 
{
system ("color 06");

cout << "Number of wins is = "     << wins << endl;
cout << "Number of loses is = "    << loses << endl;
cout << "Number of balances is = " << balances << endl;

cout << "Your percentage of wins = " << (wins / ( wins + loses + balances) * 100) << " %\n"; 
cout << "\n\nNo winner and No loser , you are balanced \n";

cout << "______________________________________________________________";
}

}

int main ()
{
    srand((unsigned)time(NULL));
     
float wins = 0 ;
float loses = 0 ;
float balances = 0 ;

while (true)
{

if (ReplayOrNot())
{

ShowResultsEveryRound ( wins , loses , balances );

ShowFinalResults ( wins , loses , balances );

}

else
{
break;        
}

}

return 0;
}