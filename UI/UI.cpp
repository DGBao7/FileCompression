#include <iostream>
#include "UI.h"
#include <string>

std::string TakePath()
{
    std::string path;

    std::cout << "Enter location: ";
    std::getline(std::cin , path);
    std::cout << "TAKE PATH = [" << path << "]\n";

    return path;
}

void Writing()
{
    std::cout << "Writing...";
}