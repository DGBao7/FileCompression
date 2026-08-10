#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include "Waiting.h"

void Loading(std::atomic<bool>& writing)
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