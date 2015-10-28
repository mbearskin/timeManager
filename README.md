# timeManager
Intro to C++ assigment 5
Prompt:

For this assignment, you will submit a single C++ compilable file containing a program written in C++. Remember, to electronically submit a file to for this course, first change to the directory in which the file resides and then type in, at the UNIX prompt, the command:

		  cssubmit  53  section_letter  assignment_number
Be sure that only the file you want to submit is in that directory - make a directory for every assignment! Remember that the submit system will deliver every .cpp file in the current directory to me, so you should only have the file for hw 5 in that directory. Name your file a meaningful name and give it a .cpp extension since you will be compiling it. Also, make sure that you compile and run your program using the GNU (g++) compiler before submitting to make sure that it will work for the submit script. 

Background: You know that Marge.  She's a "stay at home mom", and staying at home to take care of America's MOST dysfunctional family is a humongous task.  So she needs you to write a program that will manage her time for her.  Each morning, Marge attends to each of her family members' needs in order to get them each ready for their day and out the door.  The time that task takes determines how much time she has to spend on her household chores.  Your program is to calculate that time (time left for her chores).  Your program is to use functions to accomplish the calculation.  We outline below the several functions you will need for the program.  We also give you pseudo-code for your main function.


Specifications: Your main function will look like this:

                                        begin main
                                            declarations
                                            greetings()
                                            msm = get_msm()                 //msm is Marge's state of mind
                                            ttt += serv_Lisa(msm)           //ttt is total task time  (initialized to 0)
                                            ttt += serv_Maggie(msm)
                                            ttt += serv_Homer(msm)
                                            ttt += serv_Bart(msm,ttt)
                                            mtt = Marge_time(ttt)        //mtt is Marge's task time, the time she has for the rest of the day
                                            present_results(mtt)
                                            signoff()
                                        end main
    
Details: First of all, you can use the function names we've stated above.  But the variables used here are terrible because it's pseudo-code - you will come up with better variable names!  Second, in each of the "serv" functions and the Marge_time function, declare a constant called BASE_TIME with initial values of 1, 5, 50, 25, and 30, for Lisa, Maggie, Homer, Bart, and Marge.  These represent a sort of minimum time required for each (in Marge's case, it's a "cool down" time).  Third, here are descriptions of the functions:
greetings() will return nothing and output an appropriate message to the user - Marge.
get_msm() returns a short that is prompted for input by Marge.  Ok, so you should change the name of this function also.  The acceptable range of msm is between 0 and 100, inclusive.  (msm of 0 means Marge is a zombie, while 100 indicates she has taken too much Valium.)
serv_Lisa is passed the value of msm and it returns a short.  The return value is the BASE_TIME. The function will output to the screen "Have a wonderful day, Lisa" if msm is even, and "Try not to kill your brother" otherwise. This function is relatively simple because Lisa is so intelligent and agreeable; thus she is Marge's first attention.  
serv_Maggie() is passed msm and returns a short.  This function should prompt Marge for the amount of baby food (food made for babies, not from babies) Marge has fed Maggie (0 to 10, inclusive), then return BASE_TIME times the lesser of food and msm.  (In this particular function, BASE_TIME would more appropriately be called DIAPER_CHANGE_TIME.  The preceding formula is rationalized as follows:  Marge is only willing to spend so much time changing diapers - as a function of the amount of food fed to Maggie, but only up to the level of her state of mind.)
serv_Homer() is passed msm and returns a short.  This function should first prompt for and read in hh, Homer's hunger value. There are three levels of hh: 1 for hungry, 2 for very hungry, 3 for Homerian hungry. If hh is 1, return BASE + doh(hh); if hh is 2, return BASE + doh(twice hh) + msm; if hh is 3, return BASE + doh(5 times hh).  The doh() function:
doh(val) returns val squared minus 1.
serv_Bart() is passed msm and a short, and returns a short.  The second parameter of this function is the time Marge has spent on the other family members so far.  The function will return BASE_TIME plus the (second parameter squared divided by the first parameter).  (It's sort of a tolerance computation.)

Marge_time() is passed ttt and returns 600 - ttt - BASE_TIME.  (600 is the number of minutes in a ten hour day for Marge to work.)
present_results() will output to the screen your findings in a user-friendly format.
signoff() will output a goodbye message to the screen. 

When you submit, enter the following values:
75 for Marge's state of mind (msm)
4 for Maggie's food consumption
2 for Homer's hunger level
As usual, make your output nice.
Also as usual, if you have any questions, be sure to ask your instructor or get help from the LEAD guys.
