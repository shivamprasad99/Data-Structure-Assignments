SHIVAM PRASAD 
2017CSB1108
CS201 ASSIGNMENT 1

Extract the folder inside the zip file to some location.

To compile the code, place all the files (including fruits.txt and vegetables.txt) in the same directory and give the "make" command in the terminal after navigating to the folder. 

To run the compiled code, type "./sample" in the terminal and hit enter.

The terminal will then display a list of the choices user can make. Enter your choice to perform the desired actions.

To exit the program, enter 9 or any other character.

To clean the compiled code, enter "make clean" in the terminal.

ASSUMPTIONS:
1) The items are maintained in the same linked list of item* (item pointers)
2) The input files are named "fruits.txt" and "vegetables.txt" and have the data already ordered in the
   way given in the original files.
3) The  store::sell(string type) function acts as a remove function where a user can buy(removed when no item left)
   the object of their choice.
4) I have assumed that the user wants to be sold the cheapest items first as the statement given in the problem was a 
   little ambiguous. Suppose the user wants to buy 100 mangoes, then he will be sold the 100 cheapest mangoes from
   the system first.
5) When displaying the items available within an area, the user needs to input the coordinates of the top-left and 
   bottom-right corners of rectangular region. (I have assumed the area to be rectangular).
6) In the store::sellbyCalories(int calories) function, the user has to input the calories limit. 
   Whichever item has the highest number of items within the calories limit will be sold to the customer.
   (i.e if user enters 100 calories then he will get the largest amount of a single type of item which is within that limit).
7) + operator has been overloaded to add nodes to the linked list whenever a new item is read from file or entered by user.
8) The items are assigned a unique purchase ID when they are added to the linked list.
