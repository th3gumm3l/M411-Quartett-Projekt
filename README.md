# M411-Quartett-Projekt

## Short description
With this project work, you programme a simple quartet game with a freely selectable theme, such as cars, animals, agricultural machines, locomotives, rockets, etc. 
The game consists of individual cards that differ by a text (designation) and at least 2 different values. 
The programme user (referred to as user in the following text) plays against the computer. <br> <br>

In a group work (max. two learners) or in an individual work, you create a programme with which this game is programmed with the help of linked lists. 
Except for strings, no arrays may be used. The structure and content of the linked lists are predefined. <br><br>

The program (a Windows console program) must be written in C, using Visual Studio 2019 using the ANSI C Library (from Visual Studio or Visual C++ 2019). 
No C++ commands and libraries or any other libraries are allowed, except the C++ data type "bool" with "true" and "false", which may be used.


## Rules of the game
The game consists of an even number of at least ten cards. Each card has at least two values (an integer and a double value) in addition to the name. 
For example, there could be a card with the name "Ferrari Roma", the value1 = 650 hp for the power (integer) and the value2 = 3.4 s (double) for the time to accelerate from 0 to 100 km/h. <br><br>

To start the game, the available cards are shuffled and distributed to the two players (user and computer) so that each player has the same number of cards. <br><br>

The user is shown the first card on the talon (card list). All other cards are and remain face down. He now chooses one of the two values to compare with the first card from the computer's talon. 
If the value on the user's card is better (e.g. higher for horsepower and lower for 0-100 km/h), the user wins. 
The loser must then hand over his card to the winner, i.e. the card of the loser is moved to the end of the winner's talon. 
The card played by the winner is also moved to the end of his or her talon. <br><br>
As soon as a player has no more cards, this player has lost and the game is over.


## Data structure and structure of the linked list
The programme uses several linked lists of individual data elements. Each data element corresponds to a playing card. <br>
The data elements or card elements are based on the following structure:
```
typedef struct Card {
char Bez[50];
int value1;
double Value2;
struct Card* pNext;
} struCard;
```
Your structure must contain a string (array of characters), an integer and a double variable. 
must be contained. You may choose the names of the structure and the structure variables yourself. <br><br>
For the above example, for the variables "Value1" and "Value2" you could use the names "PS" and "Time100" for the time from 0 to 100 km/h.

## Programme sequence
First, a linked list of all playing cards (at least ten) is created.
The names and values of the individual of the individual cards are programmed in the programme or the same talon (card list) is always (card list) is always created. <br><br> 

For each turn, the number of cards available to both players and the current playing card should be displayed by the user be displayed. 
Afterwards, the value to be compared is determined via a small menu or the game in progress is aborted. 
The result per turn is then displayed and the next turn follows if the game is not finished. game is not finished. <br><br>

At the end of a game, the winner is displayed and then you are asked whether you want to start a new game should be started.

## Programme structure (coding rules)
The whole programme consists of a minimal main function, which calls a corresponding function for each task, such as CreateList, StartGame, etc. <br><br>
No global variables may be used. The variables that apply to the whole programme must be declared in the "main" function or other functions and, if necessary, passed to corresponding sub-functions as required. <br><br>
Constants may be declared globally. <br><br>
The card lists (talons) must be programmed as concatenated lists, without using arrays. For strings (character arrays), arrays must be used...

## Expected result
This project must contain the following elements:
- Programme with the functionality described above, coded according to the rules described above.
- Clear, comprehensible code with blockwise commenting, i.e. not every line must be commented!
- One comment per function with the information described above, including the name of the programmer.

## Evaluation
The following criteria are included in the assessment:
- Task → are all points according to the task fulfilled?
- Functionality → does the programme work?
- Coding → is the code clear and understandable?
- Technical discussion → each group must be able to answer questions about their solution/code
