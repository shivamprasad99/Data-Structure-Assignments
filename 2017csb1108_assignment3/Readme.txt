CS201
ASSIGNMENT 3 - ADAPTABLE PRIORITY QUEUE
SHIVAM PRASAD
2017CSB1108
---------------------------------------------------------------------------------------------------------------------------
Extract the folder inside the zip file to some location.

To compile the code, place all the files (including fruits.txt and vegetables.txt) in the same directory and give the "make" 
command in the terminal after navigating to the folder. 

To run the compiled code, type "./sample" in the terminal and hit enter.

The terminal will then display a list of the choices user can make. Enter your choice to perform the desired actions.

To exit the program, enter 0 .

To clean the compiled code, enter "make clean" in the terminal.

---------------------------------------------------------------------------------------------------------------------------

The adaptable priority queue has been implemented using a minheap and a parallel tree which stores the modified positions 
of the objects. Two positions are altered after every swap. The altered positions are then stored in objects of locator 
class. The parallel tree has the pointers to these locators so the modified positions are not lost.
The comparator functions are made inside two separate classes in the main.cpp file itself. 
The priority queue also allows the user to replace an object at an index of choice after which it is bubbled to its real 
position in the pQueue. The pQueue class has two templates - one for the object type and one for the comparator.
The VectorTree.hpp file has a class to implement tree using vector and its utitlity functions.

---------------------------------------------------------------------------------------------------------------------------