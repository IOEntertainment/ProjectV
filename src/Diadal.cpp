/*	Copyright 2016 George Le
    Definitions of functions declared in Diadal.h
*/
#include <iostream>
#include <fstream>
#include "Diadal.h"
#include "combat.h"
#include "support.h"

Diadal::Diadal() : standard_game(1, EASY, "Diadal"), m_game_running(true), m_new_game(true), m_number_of_party_members(0) 
{
    std::ifstream file("Diadal_text_File.txt");
    if(file.is_open())
    {
        std::string line(""), second_line("");
        while(getline(file, line)) // Receives the flags for the file names (ALL CAPS)
        {
            while(getline(file, second_line)) // Receives the actual file name for the script to use
            {
                m_script_names.at(line) = second_line;
            }
        }
    }
}

void Diadal::game_loop()
{
    //game loop
    while(m_game_running)
    {
        std::cout << "Select an option:\n";
        std::cout << "1. New game\n";
        std::cout << "2. Start from game checkpoint\n";
        std::cout << "3. Back\nInput:";
        int choice = get_number_from_user(1, 3);
        std::cout << std::endl;
        if(choice == 1)
        {
            new_game();
        }
        else if(choice == 2)
        {
            if(m_new_game != false)
            {
                //load saved game    
            }
        }
        else if(choice == 3)
        {
            m_game_running = false;
        }
    }
}

bool Diadal::game_menu()
{
    if(standard_game.game_main_menu())
    {
        m_game_running = true;
    }
    else
    {
        m_game_running = false;
    }
    
    return m_game_running;
}

void Diadal::new_game()
{
    // TO BE DESIGNED
    //put here just to test
    if(m_new_game)
    {
        // creates the player character and puts it into the list of player
        // controlled party members
        Primary_character* player = new Primary_character();
        m_list_of_characters.emplace(++m_number_of_party_members, player);
        m_new_game = false;
    }
    Result status;
    // test loop for combat
    do
    {
        // returns a result from the battle, passing in the class method m_list_of_characters 
        // and the class method, another nested class Game's method get_difficulty which
        // returns the game difficulty returned as an int
        status = one_v_one_duel(m_list_of_characters, standard_game.get_difficulty());
    }while(status != PLAYER_DEATH);
}