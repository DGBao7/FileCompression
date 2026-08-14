#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include "UI.h"

int OptionSelect()
{
    std::cout << "Slect your option: \n" <<
                "1. Compression\n" <<
                "2. Expression\n" << 
                "User: ";

    int select;

    std:: cin >> select;

    return select;
}

void Writting(std::atomic<bool>& writing)
{
    int counter = 0;

    while (writing)
    {
        std::cout << "\rWritting";

        for (int i = 0; i < counter; i++)
        {
            std::cout << ".";
        }

        std::cout << "   " << std::flush;

        counter++;

        if (counter > 3)
        {
            counter = 0;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}