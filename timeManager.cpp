//Programmer: Martha Winger-Bearskin      Date: 03/06/2013
//File Name: timeManager.cpp              Class: CS 53 A
//Purpose:This program with help marge calculate how much time she spends
//        helping each of her family members in the morning and then from that
//        calculate how much time she has left to complete her chores


#include <iostream>
using namespace std;

//Function Prototypes:


//The greetings() will display a welcome message to the user
//Pre: none
//Post: gretting message displayed to screen
void greeting();

//The get_stateOFmind() will prompt user for marge's current state of mind from
// 0-100
//Pre: none
//Post: returns the number between 0-100 for marge's state of mind
short get_stateOFmind();

//The serv_Lisa() calculate the time marge spends on Lisa and return that value
//Pre: parameter must be positive or 0.
//Post: displays message to lisa beased on marge's state of mind being even or
//      odd and returns the base time spent on Lisa.
short serv_Lisa(short const margesMind);

//The serv_Maggie() will calculate the amount of time spent on Maggie and return
//that value.
//Pre: Parameter must be positive or 0.
//Post: returns time spent on maggie.
short serv_Maggie(short const margesMind);

//The serv_Homer() will calculate the time spent on homer and return that value
//Pre: the first parameter must be positive or 0. The secnd 
//Post:return the time marge spends on homer
short serv_Homer(short const margesMind);

//The doh() squares the number is is passed and then sutracts 1
//Pre: none
//Post: returns val squared minus 1.
short doh(short val);

//The serv_Bart() calculates and returns the time marge spends on Bart.
//Pre: first parameter must be > 0. Second parameter must be positive. 
//Post: returns time spent on Bart.
short serv_Bart(short const margesMind, short const totalTaskTime);

//The marge_Time() calculates the time marge has left for her chores
//Pre: parameter must be positive
//Post: returns the amount of time Marge has left.
short marge_Time(short const totalTaskTime);

//The presentResults() displays the amount of time Marge has left to do chores
//Pre: none
//Post: displays Marge's Task Time.
void presentResults(short const margeTime);

//The signOff() displays a goodbye message
//Pre: none
//Post: displays message to the screen.
void signOff();


int main()
{
  //variables
  short mind; //Marge's State of Mind
  short totalTime = 0; //Total task time
  short mTaskTime = 0;//Marge's Taks Time(time she has leftover for rest of day)
  
  greeting();
  mind = get_stateOFmind();
  totalTime += serv_Lisa(mind);
  totalTime += serv_Maggie(mind);
  totalTime += serv_Homer(mind);
  totalTime += serv_Bart(mind, totalTime);
  mTaskTime = marge_Time(totalTime);
  presentResults(mTaskTime);
  signOff();
  
  return 0;
}

// Function Definitions

void greeting()
{
  cout << "Welcome to Marge's Time Managment Calculator!" << endl;
  return;
}

short get_stateOFmind()
{
  int state; // holds marge's state of mind 
  do
  {
    cout << "Please enter your state of mind:";
    cin >> state;
    cout << endl;
    if (state <= 0 || state > 100)
      cout << "error This number must be between 1 and 100" << endl;
  } while (state <= 0 || state >100);
  return state;
}

short serv_Lisa(short const margesMind)
{
  short const BASE_TIME = 1;
  
  if (margesMind % 2 == 0)
    cout << "Have a wonderful day Lisa!" << endl << endl;
  else
    cout << "Try not to Kill your brother!" << endl << endl;
  return BASE_TIME;
}

short serv_Maggie(short const margesMind)
{
  short const BASE_TIME = 5;
  short babyFood;
  
  do
  {
    cout << "How many jars of baby food has Maggie had for breakfast?";
    cin >> babyFood;
    cout << endl;
    if (babyFood < 0 || babyFood > 10)
      cout << "The number must be between 0 and 10...TRY AGAIN!" << endl;
  }while(babyFood < 0 || babyFood > 10);
  return BASE_TIME * (babyFood < margesMind ? babyFood : margesMind);
}

short serv_Homer(short const margesMind)
{
  short const BASE_TIME = 50;
  short hunger;
  short homerTime;
  
  do
  {
    cout << "Homer's Hunger Level" << endl;
    cout << "1 - Hungry" << endl;
    cout << "2 - Very Hungry" << endl;
    cout << "3 - Homerian Hungry" << endl;
    cout << "How hungry is homer: ";
    cin >> hunger;
    cout << endl;
    
    switch(hunger)
    {
      case 1:
        homerTime = (BASE_TIME + doh(hunger));
        break;
      case 2:
        homerTime =  (BASE_TIME + doh(hunger *2) + margesMind);
        break;
      case 3:
        homerTime =  (BASE_TIME + doh(hunger *5));
        break;
      default:
        cout << "Error!! Enter a number 1-3" << endl;
    }
    
  }while (hunger <= 1 || hunger >= 3);
  
  return homerTime;
}


short doh(short val)
{
  return ((val * val) - 1);
}


short serv_Bart(short const margesMind, short const totalTaskTime)
{
  short const BASE_TIME = 25;
  
  return (BASE_TIME + ((totalTaskTime * totalTaskTime) / margesMind));
}


short marge_Time(short const totalTaskTime)
{
  short const BASE_TIME= 30;
  
  return (600 - totalTaskTime - BASE_TIME);
}


void presentResults(short const margeTime)
{
  
  cout << "You have " << margeTime << " mins left to complete your chores" 
      << "today!" << endl;
}


void signOff()
{
  cout << "Have a great Day!!" << endl;
  return;
}