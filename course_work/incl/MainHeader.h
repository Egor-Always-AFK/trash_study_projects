#ifndef MAINHEADER_HPP
# define MAINHEADER_HPP

#include "AutoService.h"
#include <fstream>
#include <string>

#define INPUT 0
#define FILEINPUT 1
#define FILEOUTPUT 2 
#define OUTPUT 3
#define SORT 4
#define SEARCH 5
#define EDIT 6
#define EXIT 7

#define DATE 0
#define NUMBER 1
#define NORMHOUR 2

typedef std::vector<void *> null_vector;

void menu();

std::vector<AutoService> fileInput();

AutoService ft_split(const char *str);


#endif