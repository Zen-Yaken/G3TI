#ifndef GAURD_types7_h
#define GAURD_types7_h
#include "type_interactions.h"
#include <vector>
#include <string>

// BUG
std::vector<std::string> bug_weak = {"Fire", "Flying", "Rock"};
std::vector<std::string> bug_resist = {"Grass", "Fighting", "Ground"};
std::vector<std::string> bug_immunities = {};
std::string bug_str = "Bug";
Type bug(bug_str, bug_weak, bug_resist, bug_immunities);

// DARK
std::vector<std::string> dark_weak = {"Fighting", "Bug"};
std::vector<std::string> dark_resist = {"Ghost", "Dark"};
std::vector<std::string> dark_immunities = {"Psychic"};
std::string dark_str = "Dark";
Type dark(dark_str, dark_weak, dark_resist, dark_immunities);

// DRAGON
std::vector<std::string> dragon_weak = {"Ice", "Dragon"};
std::vector<std::string> dragon_resist = {"Fire", "Water", "Electric", "Grass"};
std::vector<std::string> dragon_immunities = {};
std::string dragon_str = "Dragon";
Type dragon(dragon_str, dragon_weak, dragon_resist, dragon_immunities);

// ELECTRIC
std::vector<std::string> electric_weak = {"Ground"};
std::vector<std::string> electric_resist = {"Electric", "Flying", "Steel"};
std::vector<std::string> electric_immunities = {};
std::string electric_str = "Electric";
Type electric(electric_str, electric_weak, electric_resist,electric_immunities);

// FIGHTING
std::vector<std::string> fighting_weak = {"Flying", "Psychic"};
std::vector<std::string> fighting_resist = {"Bug", "Rock", "Dark"};
std::vector<std::string> fighting_immunities = {};
std::string fighting_str = "Fighting";
Type fighting(fighting_str, fighting_weak, fighting_resist, fighting_immunities);

// FIRE
std::vector<std::string> fire_weak = {"Water", "Ground", "Rock"};
std::vector<std::string> fire_resist = {"Fire", "Grass", "Ice", "Bug", "Steel"};
std::vector<std::string> fire_immunities = {};
std::string fire_str = "Fire";
Type fire(fire_str, fire_weak, fire_resist, fire_immunities);

// FLYING
std::vector<std::string> flying_weak = {"Electric", "Ice", "Rock"};
std::vector<std::string> flying_resist = {"Grass", "Fighting", "Bug"};
std::vector<std::string> flying_immunities = {"Ground"};
std::string flying_str = "Flying";
Type flying(flying_str, flying_weak, flying_resist, flying_immunities);

// GHOST
std::vector<std::string> ghost_weak = {"Ghost", "Dark"};
std::vector<std::string> ghost_resist = {"Poison", "Bug"};
std::vector<std::string> ghost_immunities = {"Normal", "Fighting"};
std::string ghost_str = "Ghost";
Type ghost(ghost_str, ghost_weak, ghost_resist, ghost_immunities);

// GRASS
std::vector<std::string> grass_weak = {"Fire", "Ice", "Poison", "Flying", "Bug"};
std::vector<std::string> grass_resist = {"Water", "Electric", "Grass", "Ground"};
std::vector<std::string> grass_immunities = {};
std::string grass_str = "Grass";
Type grass(grass_str, grass_weak, grass_resist, grass_immunities);

// GROUND
std::vector<std::string> ground_weak = {"Water", "Grass", "Ice"};
std::vector<std::string> ground_resist = {"Poison", "Rock"};
std::vector<std::string> ground_immunities = {"Electric"};
std::string ground_str = "Ground";
Type ground(ground_str, ground_weak, ground_resist, ground_immunities);

// ICE
std::vector<std::string> ice_weak = {"Fire", "Fighting", "Rock", "Steel"};
std::vector<std::string> ice_resist = {"Ice"};
std::vector<std::string> ice_immunities = {};
std::string ice_str = "Ice";
Type ice(ice_str, ice_weak, ice_resist, ice_immunities);

// NORMAL
std::vector<std::string> normal_weak = {"Fighting"};
std::vector<std::string> normal_resist = {};
std::vector<std::string> normal_immunities = {"Ghost"};
std::string normal_str = "Normal";
Type normal(normal_str, normal_weak, normal_resist, normal_immunities);

// POISON
std::vector<std::string> poison_weak = {"Ground", "Psychic"};
std::vector<std::string> poison_resist = {"Grass", "Fighting", "Poison", "Bug"};
std::vector<std::string> poison_immunities = {};
std::string poison_str = "Poison";
Type poison(poison_str, poison_weak, poison_resist, poison_immunities);

// PSYCHIC
std::vector<std::string> psychic_weak = {"Bug", "Ghost", "Dark"};
std::vector<std::string> psychic_resist = {"Fighting", "Psychic"};
std::vector<std::string> psychic_immunities = {};
std::string psychic_str = "Psychic";
Type psychic(psychic_str, psychic_weak, psychic_resist, psychic_immunities);

// ROCK
std::vector<std::string> rock_weak = {"Water", "Grass", "Fighting", "Ground", "Steel"};
std::vector<std::string> rock_resist = {"Normal", "Fire", "Poison", "Flying"};
std::vector<std::string> rock_immunities = {};
std::string rock_str = "Rock";
Type rock(rock_str, rock_weak, rock_resist, rock_immunities);

// STEEL
std::vector<std::string> steel_weak = {"Fire", "Fighting", "Ground"};
std::vector<std::string> steel_resist = {"Normal", "Grass", "Ice", "Flying", "Psychic", "Bug", "Rock", "Ghost", "Dragon", "Dark", "Steel"};
std::vector<std::string> steel_immunities = {"Poison"};
std::string steel_str = "Steel";
Type steel(steel_str, steel_weak, steel_resist, steel_immunities);

// WATER
std::vector<std::string> water_weak = {"Electric", "Grass"};
std::vector<std::string> water_resist = {"Fire", "Water", "Ice", "Steel"};
std::vector<std::string> water_immunities = {};
std::string water_str = "Water";
Type water(water_str, water_weak, water_resist, water_immunities);

// NA
Type na;

std::vector<Type> types = {na, bug, dark, dragon, electric, fighting, fire, flying, ghost, grass, ground, ice, normal, poison, psychic, rock, steel, water};


#endif