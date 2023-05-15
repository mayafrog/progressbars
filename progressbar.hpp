#ifndef PROGRESS_BAR
#define PROGRESS_BAR

#include <iostream>

class ProgressBar
{
private:
    int width;
    int totalProgress;

public:
    ProgressBar(int w, int t) : width(w), totalProgress(t) {}

    void update(int progress)
    {
        int percent = (progress * 100) / totalProgress;
        int pos = (width * progress) / totalProgress;

        std::cout << "\r[";
        for (int i = 0; i < width; ++i)
        {
            if (i < pos)
            {
                std::cout << "-";
            }
            else if (i == pos)
            {
                std::cout << ">";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << "] " << percent << "% " << std::flush;

        if (progress == totalProgress)
        {
            std::cout << std::endl;
        }
    }
};

#endif