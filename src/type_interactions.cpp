#include "type_interactions.h"
#include <iostream>
#include <iterator>
#include <algorithm>
using std::vector;
using std::string;
using std::cout; using std::endl;
using std::iterator;
using std::find;

std::vector<std::string> type_names = {"", "Bug", "Dark", "Dragon", "Electric", "Fighting", "Fire", "Flying", "Ghost", "Grass", "Ground", "Ice", "Normal",
                                       "Poison", "Psychic", "Rock", "Steel", "Water"};

// erases element type in 4xweakness, 2xweakness, Halfresist, quarterresist, 1xdamage, and / or immunities vectors
void erase_element(vector<string>& v, string K)
{
    auto it = find(v.begin(), v.end(), K);

    //if element was found
    if(it != v.end())
    {
        int index = it - v.begin();
        v.erase(v.begin() + index);
        return;
    }
    else
    {
        return;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Type::Type(string& typeA, vector<string>& weak, vector<string>& resist, vector<string>& immune)
{
    this->type1 = typeA;
    populate_weaknesses(weak);
    populate_resistances(resist);
    populate_immunities(immune);
}

void Type::populate_weaknesses(vector<string>& typeW)
{
    copy(typeW.begin(), typeW.end(), back_inserter(this->weaknesses));
    return;
}

void Type::populate_resistances(vector<string>& typeR)
{
    copy(typeR.begin(), typeR.end(), back_inserter(this->resistances));
    return;
}

void Type::populate_immunities(vector<string>& typeI)
{
    copy(typeI.begin(), typeI.end(), back_inserter(this->immunities));
    return;
}

void Type::output_type()
{
    cout << "Type: " << type1 << endl;
}

void Type::output_weakness()
{
    std::cout << ("Weaknesses: ");
    if (this->weaknesses.size() == 0)
    {
        cout << "None" << endl;
        return;
    }

    for(vector<string>::iterator it = this->weaknesses.begin(); it != this->weaknesses.end(); it++)
    {
        cout << *it + " ";
    }

    cout << endl;
    return;
}

void Type::output_resistance()
{
    cout << "Resistances: ";

    if(this->resistances.size() == 0)
    {
        cout << "None " << endl;
        return;
    }

    for(vector<string>::iterator it=this->resistances.begin(); it != this->resistances.end(); it++)
    {
        cout << *it + " ";
    }

    cout << endl;
    return;
}

void Type::output_immune()
{
    cout << "Immunities: ";

    if(this->immunities.size() == 0)
    {
        cout << "None " << endl;
        return;
    }

    for(vector<string>::iterator it=this->immunities.begin(); it != this->immunities.end(); it++)
    {
        cout << *it + " ";
    }

    cout << endl;
    return;
}

string Type::get_type()
{
    return this->type1;
}

vector<string>& Type::get_weaknesses()
{
    return this->weaknesses;
}

vector<string>& Type::get_resistances()
{
    return this->resistances;
}

vector<string>& Type::get_immunities()
{
    return this->immunities;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                 

// Pokemon class
void Pokemon::set_type1(Type& x)
{
    this->type1 = x;
}

void Pokemon::set_type2(Type& y)
{
    this->type2 = y;
}

int Pokemon::calc_immunities()
{
    this->Immunities.clear();

    bool single_type = false;
    if(type2.get_type() == "")
    {
        Immunities = type1.get_immunities();
        single_type = true;
    }

    if(! single_type)
    {
        for(vector<string>::iterator it = type1.get_immunities().begin(); it != type1.get_immunities().end(); it++)
        {
            Immunities.push_back(*it);
        }

        if (!type2.get_immunities().empty())
        {
            for(vector<string>::iterator it = type2.get_immunities().begin(); it!=type2.get_immunities().end(); it++)
            {
                vector<string>::iterator temp = find(Immunities.begin(), Immunities.end(), *it);
                if(temp == Immunities.end())
                {
                    Immunities.push_back(*it);
                }
            }
        }
    }
    return 0;
}

int Pokemon::calc_weaknesses()
{
    this->FourXWeakness.clear();
    this->TwoXWeakness.clear();

    bool single_type = false;
    // if only 1 type only output 
    if(type2.get_type() == "")
    {
        TwoXWeakness = type1.get_weaknesses();
        single_type = true;
    }

    //dual type
    if(!single_type)
    {
        // get 4xWeakness
        for (vector<string>::iterator it = type1.get_weaknesses().begin(); it != type1.get_weaknesses().end(); it++)
        {
            //vector<string>::iterator immunities_temp = find(type)
            vector<string>::iterator temp = find(type2.get_weaknesses().begin(), type2.get_weaknesses().end(), *it);
            if(temp != type2.get_weaknesses().end())
            {
                FourXWeakness.push_back(*it);
                continue;
            }
            TwoXWeakness.push_back(*it); // add 2xweakness from type1
        }

        // add 2xweakness from type2
        for (vector<string>::iterator it = type2.get_weaknesses().begin(); it != type2.get_weaknesses().end(); it++)
        {
            vector<string>::iterator temp = find(FourXWeakness.begin(), FourXWeakness.end(), *it);
            if(temp == FourXWeakness.end())
            {
                TwoXWeakness.push_back(*it);
            }
        }
    }

    // get rid of any Immunities the pokemon has that are in any of the weakness vectors
    for(vector<string>::iterator it = Immunities.begin(); it != Immunities.end(); it++)
    {
        erase_element(FourXWeakness, *it);
        erase_element(TwoXWeakness, *it);
    }

    return 0;
}

int Pokemon::calc_resistances()
{
    this->HalfResist.clear();
    this->QuarterResist.clear();

    bool single_type = false;
    // if only 1 type only output 
    if(type2.get_type() == "")
    {
        HalfResist = type1.get_resistances();
        single_type = true;
    }

    //dual type
    if(!single_type)
    {
        // get 1/4 resistances
        for (vector<string>::iterator it = type1.get_resistances().begin(); it != type1.get_resistances().end(); it++)
        {
            vector<string>::iterator temp = find(type2.get_resistances().begin(), type2.get_resistances().end(), *it);
            if(temp != type2.get_resistances().end())
            {
                QuarterResist.push_back(*it);
                continue;
            }
            HalfResist.push_back(*it); // add 2xweakness from type1
        }

        // add 2xweakness from type2
        for (vector<string>::iterator it = type2.get_resistances().begin(); it != type2.get_resistances().end(); it++)
        {
            vector<string>::iterator temp = find(QuarterResist.begin(), QuarterResist.end(), *it);
            if(temp == QuarterResist.end())
            {
                HalfResist.push_back(*it);
            }
        }
    }

    // get rid of any Immunities the pokemon has that are in any of the weakness vectors
    for(vector<string>::iterator it = Immunities.begin(); it != Immunities.end(); it++)
    {
        erase_element(QuarterResist, *it);
        erase_element(HalfResist, *it);
    }
    return 0;
}

int Pokemon::calc_neutral() // always call this function after calc_immunities(), calc_weaknesses(), calc_resistances()
{
    this->OneXDamage.clear();

    bool in4xWeak = false;
    bool in2xWeak = false;
    bool inQuarterResist = false;
    bool inHalfResist = false;
    bool inImmune = false;

    for(vector<string>::iterator it = type_names.begin(); it != type_names.end(); it++)
    {
        if(find(FourXWeakness.begin(), FourXWeakness.end(), *it) != FourXWeakness.end())
        {   // if we enter any for loop than it was found in the resepctive vector and we do NOT have a neutral type
            in4xWeak = true;
            continue;
        }
            
        if(find(TwoXWeakness.begin(), TwoXWeakness.end(), *it) != TwoXWeakness.end())
        {
            in2xWeak = true;
            continue;
        }
            
        if(find(QuarterResist.begin(), QuarterResist.end(), *it) != QuarterResist.end())
        {
            inQuarterResist = true;
            continue;
        }
            
        if(find(HalfResist.begin(), HalfResist.end(), *it) != HalfResist.end())
        {
            inHalfResist = true;
            continue;
        }
            
        if(find(Immunities.begin(), Immunities.end(), *it) != Immunities.end())
        {
            inImmune = true;
            continue;
        }
            
        OneXDamage.push_back(*it);

    }

    vector<string>::size_type weak_len = TwoXWeakness.size();
    vector<string>::size_type count = 0;
    // go through TwoXWeakness and HalfResist vectors and remove any elements that are in both and place those elements in OneXDamage vec
    for(vector<string>::size_type i = 0; i != weak_len; i++)
    {
        vector<string>::iterator temp = find(HalfResist.begin(), HalfResist.end(), TwoXWeakness[count]);
        if(temp != HalfResist.end()) // found the same type in both weakness and resist vectors
        {
            //OneXDamage.push_back(*it);
            OneXDamage.push_back(TwoXWeakness[count]);
            erase_element(HalfResist, TwoXWeakness[count]);
            erase_element(TwoXWeakness, TwoXWeakness[count]);
            count--;
        }
        count++;
    }

    return 0;
}

void Pokemon::output_immunities()
{
    cout << "0x Damage:\n";
    for(vector<string>::iterator it = Immunities.begin(); it != Immunities.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void Pokemon::output_weaknesses()
{
    cout << "4x Damage:\n";
    for(vector<string>::iterator it = FourXWeakness.begin(); it != FourXWeakness.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "2x Damage:\n";
    for(vector<string>::iterator it = TwoXWeakness.begin(); it != TwoXWeakness.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void Pokemon::output_resitances()
{
    cout << "1/2x Damage\n";
    for(vector<string>::iterator it = HalfResist.begin(); it != HalfResist.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "1/4x Damage:\n";
    for(vector<string>::iterator it = QuarterResist.begin(); it != QuarterResist.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void Pokemon::output_neutral()
{
    cout << "1x Damage:\n";
    for(vector<string>::iterator it = OneXDamage.begin(); it != OneXDamage.end(); it++)
        cout << *it << " ";
    cout << endl;
}


