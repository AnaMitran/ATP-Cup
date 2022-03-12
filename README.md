# ATP-Cup
Creating automated results at a tennis tournament

In order to solve the proposed problem, we created several .c and .h files
The list stack and bst files contain the functions and structures needed to work with:
1. a double chained circular list with sentinel that contains as values country-type structures in the championship
2. a stack that will contain the list of countries
3. a stack for match winners
4. an auxiliary stack for retaining the last 4 countries in the caption required for the fourth requirement
5. a BST in which to introduce the players of those 4 countries


The structures.h and utils.h files designate the Country and Player structures, respectively the standard libraries needed in most other functions.
- The readQuery function reads the requirements.in file and calls the "big" functions that solve the requirements. We went through each value of 1 in this file one by one to ensure a customization of each requirement and to allocate the necessary variables accordingly. 
- Initially, I put only the first player from the first team in the queue and then I include all the players from the other team in turn, making the matches. The next step is to remove the first player from team 1 from the queue, add the second player at the end and make the match with the first player from the second team that is now at the top of the queue. I also remove this player from team 2 and listen to him at the end of the queue, but I retain the value of the player from team 1 and add it again in the queue. It is repeated until I have finished playing all the matches that include the second player. For the rest of the first team players, I will first remove the tip of the queue because it contains a teammate. Now a player from the second team with whom I can have a match. The process is continued, retaining and restoring that player from the first team.

