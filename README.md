# 2048 Development Project
Authors: [Michael Carlin](https://github.com/mrcarlin2003), [Niko Udria](https://github.com/NikOhNo), [Matthew Cedeno](https://github.com/MCdialing14), and [Mark Sapugay](https://github.com/MarkSapugay).

## Project Description
A 2048 C++ game is interesting to us because we all have an interest of making games, and want to see how we can maximize the experience for the player while using terminal based navigation. We plan to use C++ for our project, while Unity and other options were considered, we decided the best course of action was C++. The input will be boxes sliding across the screen and the output will be boxes merging and adding up. We will also output a game over, leaderboard, and setting screens which are more like features. The features the project provides are the ability to restart the game when the player loses, an arcade style leaderboard, score keeping, and a quit game option in game.

## User Interface Specification
### Navigation Diagram
![Navigation Diagram](/Diagrams/NavigationDiagram.png?raw=true "Navigation Diagram")
<p>This diagram displays how our game screens flow into each other. User's enter the program from where "start" is located. From here they can choose to start a new game, go into non-game menus like settings/ leaderboard/ credits, or quit the program. Some menus such as the settings or credits are simple and lead back into menu while others may have a circular pattern like the game and game over where users can keep restarting until they wish to break out by returning to mean or going to the leaderboard/ credits which also ultimately lead to the main menu. The goal is to have all paths lead back to the main menu so the user can easily quit the program or adjust settings at any time.</p>

### Screen Layouts
<div style="display: flex; justify-content: center;">
 <img src="/Diagrams/ScreenLayout/MainMenu.png?raw=true" alt="Main Menu" height="350">
 <p>This menu is intended to be a center of control for the game. From here, you can input which menu you would like to go to or quit the program. Many menus lead back to here.</p>
 </div>

<img src="/Diagrams/ScreenLayout/GameMenu.png?raw=true" alt="Game Menu" height="350">
<p>This menu is where the actual gameplay will occur. The user will input which direction they would like the blocks to slide, and they will either combine or collide, and the game area will update to reflect that. The user will also have the option to quit to the menu available at all times.</p>

<img src="/Diagrams/ScreenLayout/GameOverMenu.png?raw=true" alt="Game Over Menu" height="350">
<p>This menu will occur when the game has concluded (blocks have filled all spaces on the board and no possible moves that could combine). The final score will be calculated and displayed from the last board state. The user can input whether to start a new game, view the leaderboard, or return to the menu from here.</p>

<img src="/Diagrams/ScreenLayout/LeaderboardMenu.png?raw=true" alt="Leaderboard Menu" height="350">
<p>This menu will display the high scores for the game (either locally or online depending on time constraints). From here, users can input whether to return to the main menu or view credits.</p>

<img src="/Diagrams/ScreenLayout/CreditsMenu.png?raw=true" alt="Credits Menu" height="350">
<p>This is a simple menu that can be accessed either through the main menu or after a game. It simply directs back to the main menu upon input so users can start a new game or do any of the other options from there.</p>

<img src="/Diagrams/ScreenLayout/SettingsMenu.png?raw=true" alt="Settings Menu" height="350">
<p>This menu allows users to specify the volume level (from 0 to 100) to play background music and sound effects at. The changes will only be staged until they are applied with the apply input, and the user can return to default settings if they make an unwanted change. It navigates back to the main menu.</p>

## Class Diagram
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on Zoom and should be conducted by Wednesday of week 8.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
