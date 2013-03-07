# Design Document for PA1

## Purpose/Overview
> This software will create a small scale social network. It will do this by utilizing dynamic lists of User objects that I will create to store the appropriate information. Also, the software will take .GML files as input and parse through the lines of information in order to find the name, age and other necessary variables for the software to function. It will also be able to output the stored Lists of Users and friends into a GML format that matches the format used as input. Adding and removing friends will also be made possible through GML input.


## Requirements
> What are the functions that this software is supposed to perform?
> This software is supposed to be able to take GML files as input, parse the data written in them so that names, ages, id numbers, and other information can be extracted and put into an object in a dynamic list, and put these objects into vectors. A vector of edges will also be created to show the relationships (friends) between multiple users. In addition, the program will need to have the ability to take the information stored in the vectors and output them into a GML file that exactly matches the format of the GML files used initially. Adding and removing friends must also be possible.


## Classes
> What classes do you need to create?
> + Describe the purpose of each class.
> + What member data will they have? Why?
> + What methods will they have? Why?
> Make sure you describe each member variable and member function.

> First of all, I will need a `user` class to hold the id number, name, age, and zip of each user. This class will need appropriate getters and setters, so that the information of each user can be called to be output when the output GML file is created. There will also be a `GMLReader` class that has member function `read()` which takes in the GML input file and the two vectors of nodes and edges. I will also have a `GMLWriter` class with a `write()` member function that takes a filename and a list of Users and outputs a GML file in the same format that the program can receive and parse them using the `GMLReader` class. I will also use a `MyList` class that creates a dynamic list of User objects. The `MyList` class will have many member functions similar to the standard vector class, such as `pushBack()`, which takes in a `Type` to be pushed into the list, `at()`, which takes an integer as location and returns the value of that location in the list, `remove()`, which takes out the `Type` of element specified from the list, `size()`, which simply returns the size of the list, and constructors and destructor.


## Global Data/Functions
> What global data & functions do you have? Describe any pieces of your program that are not within a class. You don't need to describe every single variable you use, but are there any global variables or functions that are integral to how your program works?

> I will have a global `DEFAULT_LIST_SIZE` to put in `MyList` constructors to initalize its size and capacity at the same number as well as stay consistant when it is called.

## High-level Architecture
> What is the high level flow of data through your program? How will all of your objects interact? What are the algorithms that your code will use?

> My main objects are the `User`, `MyList`, and GML reader and writer classes. First, the data will be read and stored as a `GMLReader` object, and then parsed and assigned into the `User` class. These `User` object pointers will be pushed back into the `MyList` class. Finally, the `GMLWriter` class will take this information from the list of User pointers and output a GML file of Users and relationships.


## User Interface
> Describe how the user will interact with your software.
The user will primarily interact with the software through the `GMLReader` class which will take in the user's input in the form of a GML file. After this point, the program will interpret the data by creating nodes and edges. The user can still add or remove friends by inputting GML files, as well.


##Test Cases
> I will test the system by testing its parts individually. For example, the `GMLWriter` class will be tested by taking the output and putting it back into the `GMLReader`. To make sure that the User nodes and edges (relationships) are correct, I will iterate through the vectors of users and edges and output their data to the terminal. Potential problems include not being able to read the input file (e.g. not parsing them correctly) and generally pushing back data into a spot that it shouldn't be (such as the zip code int going into the age int).
