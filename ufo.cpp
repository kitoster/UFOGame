//A UFO game that operates similarly to "Hangman," but with a twist. 

#include <iostream>
#include "ufo_functions.hpp"

int main() {

  greet();

  std::string codeword = "motivation";
  std::string answer = "__________";
  int misses = 0;
  std::vector<char> incorrect;
  bool guess = false;
  char letter;

  //Runs input and output for each turn. 
  while (answer != codeword && misses < 8) 
  {
    display_misses(misses);
    display_status(incorrect, answer);
    std::cout << "\n\nPlease enter your guess: ";
    std::cin >> letter;

    //For loop in the case that the player guesses a letter correctly. Else, outputs incorrect and increases the misses counter. 
    for (int i = 0; i < codeword.length(); i++) 
    {
      if (letter == codeword[i]) 
      {
        answer[i] = letter;
        guess = true;
      }
    }
    if (guess)
    {
      std::cout << "\nCorrect!\n";
    } else 
    {
      std::cout << "\nIncorrect! The tractor beam pulls the person in further.\n";
      incorrect.push_back(letter);
      misses++;
    }

    guess = false;
    
  }

  end_game(answer, codeword);

}
