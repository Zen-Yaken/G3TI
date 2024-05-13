#ifndef GUARD_type_interactions_h
#define GUARD_type_interactions_h
#include <string>
#include <vector>
#include <cstdarg>

class Type
{
private:
    std::string type1;   
    std::vector<std::string> weaknesses;
    std::vector<std::string> resistances;
    std::vector<std::string> immunities;
    void populate_weaknesses(std::vector<std::string>& typeW);
    void populate_resistances(std::vector<std::string>& typeR);
    void populate_immunities(std::vector<std::string>& typeI);

public:
    Type(std::string&, std::vector<std::string>&, std::vector<std::string>&, std::vector<std::string>&);
    Type():type1(""), weaknesses{}, resistances{}, immunities{} {};
    void output_type();
    void output_weakness();
    void output_resistance();
    void output_immune();
    std::string get_type();
    std::vector<std::string>& get_weaknesses();
    std::vector<std::string>& get_resistances();
    std::vector<std::string>& get_immunities();
};


class Pokemon
{
private:
    Type type1;
    Type type2;

    float weakness_multiplyer = 2.0f;
    float resistance_multiplyer = 0.5f;

public:
    void set_type1(Type& x);
    void set_type2(Type& y);
    int calc_immunities(); // always call this one first
    int calc_weaknesses();
    int calc_resistances();
    int calc_neutral();    // only use this function after using calc_weaknesses(), calc_resistances(), calc_immunities()

    void output_immunities();
    void output_weaknesses();
    void output_resitances();
    void output_neutral();


    std::vector<std::string> FourXWeakness;
    std::vector<std::string> TwoXWeakness;
    std::vector<std::string> HalfResist;
    std::vector<std::string> QuarterResist;
    std::vector<std::string> Immunities;
    std::vector<std::string> OneXDamage;

    Pokemon(): type1(), type2(), FourXWeakness{}, TwoXWeakness{}, HalfResist{}, QuarterResist{} {};
    Pokemon(Type x, Type y):  FourXWeakness{}, TwoXWeakness{}, HalfResist{}, QuarterResist{} {set_type1(x); set_type2(y);};
};

void erase_element(std::vector<std::string>&, std::string);

#endif