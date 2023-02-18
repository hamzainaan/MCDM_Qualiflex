#pragma once

#ifndef DEFS_HPP_
#define DEFS_HPP_

//Headers
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

//Typedefs
typedef std::string s;
typedef unsigned int u;

//Structs
typedef struct Alternative {

    s alt_name;
    std::vector<u> alt_cr;

}alt;

//Methods
extern std::vector<alt> evaluate(std::vector<alt>&, std::vector<u>&, std::vector<u>&);

//Variables
extern std::vector<alt> choose_best;
extern std::vector<u> indxs;

#endif //DEFS_HPP_