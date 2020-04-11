/*****************************************************
 * Developer: Mohamed Sobhy Fouda
 * File: TripleX.cpp
 * Description: 
    Terminal game. you need to help your secret agents
     to extract X files. Guess the right code combina-
     tion to crack extract encrypted files. Work hard 
     to pass all level difficulities to extraxt all
     filess successfully.
*****************************************************/

#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulity)
{
    std::cout << "___________      .__       .__           ____  ___\n";
    std::cout << "\\__    ___/______|__|_____ |  |   ____   \\   \\/  /\n";
    std::cout << "  |    |  \\_  __ \\  \\____ \\|  | _/ __ \\   \\     /\n";
    std::cout << "  |    |   |  | \\/  |  |_> >  |_\\  ___/   /     \\\n";
    std::cout << "  |____|   |__|  |__|   __/|____/\\___  > /___/\\  \\\n";
    std::cout << "                    |__|             \\/        \\_/\n";

    std::cout << "You are a secret agent breaking into a level " << Difficulity;
    std::cout << " secure server room...\nEnter the correct codes to continue...\n\n";
    
}

bool PlayGame(int Difficulity)
{
    PrintIntroduction(Difficulity);

    // Declare 3 number code
    const int CodeA = rand() % Difficulity + Difficulity;
    const int CodeB = rand() % Difficulity + Difficulity;
    const int CodeC = rand() % Difficulity + Difficulity;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print product and sum to terminal
    std::cout << "\n" << "+ There are 3 numbers in the code" << "\n";
    std::cout << "+ The codes add-up to: " << CodeSum << "\n";
    std::cout << "+ The codes multiply to: " << CodeProduct << "\n";

    int GuessA, GuessB, GuessC;

    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    std::cout << "\nYou entered: " << GuessA << GuessB << GuessC << "\n";

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if((GuessSum == CodeSum) && (CodeProduct == GuessProduct))
    {   
        if (Difficulity != 5)
        {
            std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***\n";
        }
        return true;
    } 
    else 
    {
        std::cout << "\n*** You entered the worng conde! Careful agent! Try again! ***\n\n";
        return false;
    }

    
}

int main()
{   
    srand(time(NULL)); // create new random sequence based on time of day

    int LevelDifficulity = 1;
    const int MaxDifficulity = 5;

    while (LevelDifficulity <= MaxDifficulity)
    {
        bool bLevelComplete = PlayGame(LevelDifficulity);
        std::cin.clear(); // Clear any errors
        std::cin.ignore(); // Discard the buffer

        if (bLevelComplete)
        {
            // increase level difficulity
            ++LevelDifficulity;
        }
        
    }

    std::cout << "*** Great work agent! You got all the files! Now get out of there! ***\n\n";
    return 0;
}