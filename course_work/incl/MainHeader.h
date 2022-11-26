#ifndef MAINHEADER_HPP
# define MAINHEADER_HPP

#include "AutoService.h"
#include <fstream>
#include <string>

#define INPUT 0
#define FILEINPUT 1
#define FILEOUTPUT 2 
#define SORT 3
#define SEARCH 4
#define EDIT 5
#define EXIT 6

typedef std::vector<void *> null_vector;

void menu();

std::vector<AutoService> fileInput();


#endif