/*
Program: Basketball Shooting Game
Purpose: Simulates a basketball shooting game for two players.
Author: Keona Abad
Date Finished: October 11, 2023
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to display a welcome message
void displayWelcomeMessage() {
    cout << "Welcome to the Basketball Shooting Game" << '\n';
}

// Function to get the player's choice of where to place their money-ball rack
int getPlayerChoice(int player) {
    int choice;
    while (true) {
        cout << "Player " << player << ": Where do you want to put your money-ball rack? Enter 1-5: ";
        cin >> choice;
        if (choice >= 1 && choice <= 5) {
            return choice;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    }
}


// Function to display the placement of the money-ball for a player
void displayMoneyBallPlacement(int player, int choice) {
    cout << "Player " << player << ": Your money-ball is placed at position " << choice << "." << endl;
}


int main() {
    bool playAgain = true;
    while (playAgain) {
        displayWelcomeMessage();

        int choice = getPlayerChoice(1);
        int choice2 = getPlayerChoice(2);

        displayMoneyBallPlacement(1, choice);
        displayMoneyBallPlacement(2, choice2);

        const int numShots = 5;
        const int numRacks = 5;

        char player1Racks[numRacks][numShots];
        char player2Racks[numRacks][numShots];
        int player1Points[numRacks] = {0};
        int player2Points[numRacks] = {0};
        srand(time(nullptr));

        // Simulation of the basketball shooting game
        for (int rack = 0; rack < numRacks; rack++) {
            for (int i = 0; i < numShots; i++) {
                int shotResult = rand() % 2;
                if (rack == choice - 1) {
                    // Update player 1's racks and points based on shot results
                    if (shotResult == 0) {
                        player1Racks[rack][i] = 'X';
                    } else {  // Update player 1's racks and points for a different rack
                        player1Racks[rack][i] = 'M';
                        player1Points[rack] += 2;
                    }
                } else {
                    if (i == numShots - 1) {
                        if (shotResult == 0) {
                            player1Racks[rack][i] = 'X';
                        } else {
                            player1Racks[rack][i] = 'M';
                            player1Points[rack] += 2;
                        }
                    } else {   
                        if (shotResult == 0) { 
                            player1Racks[rack][i] = 'X';
                        } else {
                            player1Racks[rack][i] = 'O';
                            player1Points[rack] += 1;
                        }
                    }
                }

                int shotResult2 = rand() % 2;
                if (rack == choice2 - 1) {    // Update player 2's racks and points for a different rack
                    if (shotResult2 == 0) {
                        player2Racks[rack][i] = 'X';
                    } else {
                        player2Racks[rack][i] = 'M';
                        player2Points[rack] += 2;
                    }
                } else { // Update player 2's racks and points based on shot results
                    if (i == numShots - 1) {
                        if (shotResult2 == 0) {
                            player2Racks[rack][i] = 'X';
                        } else {
                            player2Racks[rack][i] = 'M';
                            player2Points[rack] += 2;
                        }
                    } else {
                        if (shotResult2 == 0) {
                            player2Racks[rack][i] = 'X';
                        } else {
                            player2Racks[rack][i] = 'O';
                            player2Points[rack] += 1;
                        }
                    }
                }
            }
            // Special shooting round for starry racks
            if (rack == 1) {
                int starryShotResult = rand() % 2;
                if (starryShotResult == 0) {
                    cout << "Starry: X | 0 pts" << endl;
                } else {
                    cout << "Starry: W | 3 pts" << endl;
                    player1Points[rack] += 3;
                    player2Points[rack] += 3;
                }
            } else if (rack == 3) {
                int starryShotResult = rand() % 2;
                if (starryShotResult == 0) {
                    cout << "Starry: X | 0 pts" << endl;
                } else {
                    cout << "Starry: W | 3 pts" << endl;
                    player1Points[rack] += 3;
                    player2Points[rack] += 3;
                } // Update points for starry racks
            }
             // Display the results for the current rack

            cout << "Rack " << (rack + 1) << " - Player 1: ";
            for (int i = 0; i < numShots; i++) {
                cout << player1Racks[rack][i] << " ";
            }
            cout << "| " << player1Points[rack] << " pts" << " - Player 2: ";
            for (int i = 0; i < numShots; i++) {
                cout << player2Racks[rack][i] << " ";
            }
            cout << "| " << player2Points[rack] << " pts" << endl;
        }
        // Calculate and display the overall game results
        int overallTotalPoints1 = 0;
        int overallTotalPoints2 = 0;
        for (int rack = 0; rack < numRacks; rack++) {
            overallTotalPoints1 += player1Points[rack];
            overallTotalPoints2 += player2Points[rack];
        }
        cout << "Player 1 Total: " << overallTotalPoints1 << " pts" << " - Player 2 Total: " << overallTotalPoints2 << " pts" << endl;

        if (overallTotalPoints1 > overallTotalPoints2) {// Determine and display the winner or tie
            cout << "Player 1 is the winner!" << endl;
        } else if (overallTotalPoints2 > overallTotalPoints1) {
            cout << "Player 2 is the winner!" << endl;
        } else {
            cout << "It's a tie! There is no winner." << endl;
        }

        cout << "Do you want to play again? (yes/no): ";  // Ask the user if they want to play again
        string playAgainChoice;
        cin >> playAgainChoice;
        if (playAgainChoice != "yes") { // Continue the loop and play again.
            playAgain = false;
            cout << "Thank you for playing." << endl;
        }

    }

    return 0;
}
