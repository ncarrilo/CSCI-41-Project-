# CSCI-41-Project 

This program allows the user to view up to twenty 
different streaming services along with 
being given the option to add or delete entries 

Then the user will be given the option to either 1. View the currently
exsting data, 2. To change or edit the streaming serive entries 
and 3. To exit, which will close the program entirely. 

## Project 5: Stack or Queue

Created By: Nathaniel Carrillo

I have implemented a new file where I have to decided to store datta in a stack. The user will chose the WatchList option 
from the main menu to create a watchlist. This can be useful to users that wabt to binge content with a watch party. The file 
streamWatch.cpp is where the submenu is created when the user choses to use the WatchList feature. The menu is then broken off
into multiple functions for the user to add, remove, and display nodes from the stack. In file streamWatch.h I have implemented 
a stack using linked lists. This file [streamWatch.h] is where teh struct can be found that I used for my stack. 

On **line 6-11** in file streamWatch.cpp is where the function prototypes can be located. 

On **line 15** in file streamWatch.cpp is the function menuWatchParty that creates a menu through 
a while loop and a switch statement to create a menu for the user to choose how they would like to proceed. 
The first option to add a title to the list, the second option to remove a title from the list, the third option to 
view the entire stack, and the fourth option to return to the pervious menu. 

On **line 54** in file streamWatch.cpp, prompts the user to enter a title to be added and then passes that string 
to the push() function on **line 93** which stores the entry in a stack

On **line 66** in file streamWatch.cpp, prompts the user to enter a title to be removed from the stack and then passes the 
string entered to the pop() function on **line 107** which then removes the title in the stack. 

On **line 78** in file streamWatch.cpp, calls the displayWatchList() function on **line 121** to print everything in the stack to the
console for the viewer to see. 

On **line 83** in file streamWatch.cpp, the function empty() checks if the stack is empty and returns a true or false value with the 
push() function. 

In streamWatch.h on **line 6-9** is where teh struct can be found that holds the string of listings as well as a pointer that points to the 
next node in the stack. **Line 10** is where the pointer to the top of the stack can be found.
