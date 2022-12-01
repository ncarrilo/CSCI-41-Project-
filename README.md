# CSCI-41-Project 

This program allows the user to view up to twenty 
different streaming services along with 
being given the option to add or delete entries 

Then the user will be given the option to either 1. View the currently
exsting data, 2. To change or edit the streaming serive entries 
and 3. To exit, which will close the program entirely. 

## Project 7: Data Retrieval and Processing 

Created By: Nathaniel Carrillo & Jacob Galaviz 

The data structures implemented in this program is a linked list and a stack implmented 
through a linked list. We have chosen to remove the hash table and keep the array of structures 
as well as the stack that stored data the user entered into a linked list. 

On **line 18** on file[streamProfit.cpp]. Here is where you can find the function that uses an array of 
structures to calculate the profit each streamin service makes monthly. This array can be searched on **line 155** 
and can be sorted on **line 99**

On **line 47** on file[stream.h]. Here is where you can find our implementation of a linked
list which allows the user to view and edit the charges of the streaming service. On **line 121** is the function
that displays the linked list in file[streamCharge.cpp]. On **line 133** is the function to remove an element. Lastly **line 161** 
is the function to search the linked list 

On **line 6** on file[streamWatch.cpp]. This is where we implemented our stack via a linked list. On **line 93** in [streamWatch.cpp]
is where the user can add an element. On **line 107** is where the user can remove an element and **line 121** is where the stack can be displayed.
