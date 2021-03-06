/*  Copyright 2016 George Le
    Definition of functions declared in ingame_entity.h
*/
#include <iostream>
#include "Entity/Ingame_entity.h"
#include "Support/support.h"

unsigned int CIngameEntityHuman::s_next_valid_ID = 0;

// special constructor for passing ints in the creation of an object
CIngameEntityHuman::CIngameEntityHuman(const std::string& name, int gender, int race, int job, bool is_hostile) 
                                        : m_is_hostile(is_hostile), m_entity_name(name)
{
    // MAX_GENDER value found in ingame_entity.h
    if(gender > 0 && gender <= MAX_GENDER)
    {
        // private member function of ingame_entity_human
	    SetGender(gender); 
    }
    
    // MAX_RACE value found in ingame_entity.h
	if(race > 0 && race <= MAX_RACE)
	{
	    // private member function of ingame_entity_human
	    SetRace(race); 
	}
	
	// MAX_CLASSES value found in ingame_entity.h
	if(job > 0 && job<= MAX_CLASSES)
	{
	    // private member function of ingame_entity_human
	    SetJob(job);
	}
	
	SetID();
}

std::string CIngameEntityHuman::GetGenderAsString() const
{
    // m_entity_gender is a member variable of the CIngameEntityHuman class found in ingame_entity.h
    switch(m_entity_gender)
    {
        case 1:
        return "male";
        break;
        case 2:
        return "female";
        break;
        case 3:
        return "other";
        break;
        default:
        break;
    }
    return "UNINIT Programmer messed up... Wait that's me...";
}

std::string CIngameEntityHuman::GetRaceAsString() const
{
    // m_entity_race is a member variable of the CIngameEntityHuman class found in ingame_entity.h
    switch(m_entity_race)
    {
        case 1:
        return "white";
        break;
        case 2:
        return "black";
        break;
        case 3:
        return "asian";
        break;
        case 4:
        return "hispanic";
        break;
        case 5:
        return "indigenous";
        break;
        case 6:
        return "other";
        break;
        default:
        break;
    }
    return "UNSET Programmer messed up... Wait that's me...";
}

std::string CIngameEntityHuman::GetJobAsString() const
{
    // m_entity_class is a member variable of the CIngameEntityHuman class found in ingame_entity.h
    switch(m_entity_class)
    {
        case 1:
        return "marine";
        break;
        case 2:
        return "captain";
        break;
        case 3:
        return "lawyer";
        break;
        case 4:
        return "armorer";
        break;
        case 5:
        return "economist";
        break;
        case 6:
        return "gambler";
        break;
        case 7:
        return "reporter";
        break;
        case 8:
        return "nomad";
        break;
        default:
        break;
    }
    return "UNEMPLOYED Programmer messed up... Wait that's me...";
}

// TO BE REDONE
void CIngameEntityHuman::SetInformation()
{
    std::cout << "This is a temporary build\n";
    std::cout << "What would you like your ingame name to be?\nInput:";
    m_entity_name = getline_from_user_restricted(1, 10);
    std::cout << "What is your preferred gender?\n1.Male\n2.Female\n3.Other\nInput:";
    m_entity_gender = static_cast<Gender>(get_number_from_user(1,3));
    std::cout << "What is your race?\n1.White\n2.Black\n3.Asian or Pacific Islander\n4.Hispanic\n5.Indigenous People\n6.Other\nInput:";
    m_entity_race = static_cast<Race>(get_number_from_user(1, 6));
    std::cout << "What is your class?\n1.Marine\n2.Captain\n3.Lawyer\nInput:";
    m_entity_class = static_cast<Job>(get_number_from_user(1, 3));
}

void CIngameEntityHuman::SetID()
{
    m_ID = s_next_valid_ID;
    ++s_next_valid_ID;
}