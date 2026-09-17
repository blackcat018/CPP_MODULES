#ifndef CORE_HPP
#define CORE_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


base * generate(void);
void identify(base* p);
void identify(base& p);

#endif