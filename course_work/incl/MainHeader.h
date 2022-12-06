#ifndef MAINHEADER_HPP
# define MAINHEADER_HPP

#include "AutoService.h"
#include <fstream>
#include <string>
#include <cctype>

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

void search(std::vector<AutoService> vec);

void fileOutput(std::vector<AutoService> vec);

std::vector<AutoService> manualInput();

std::size_t find_tokens(const char *str);

bool check_date_validation(int *date);

int *pars_date(const char *str);

std::string pars_number(const char *str);

int pars_norm_hour(const char *str);

AutoService ft_split(const char *str);

std::vector<AutoService> addVectorAtVector(std::vector<AutoService> dst, std::vector<AutoService> src);

std::vector<AutoService> sort(std::vector<AutoService> vec);

std::vector<AutoService> edit(std::vector<AutoService> vec);

void output(std::vector<AutoService> vec);

#endif