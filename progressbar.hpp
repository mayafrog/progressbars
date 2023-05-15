#ifndef PROGRESS_BAR
#define PROGRESS_BAR

#include <iostream>

class ProgressBar
{
private:
    int currentProgress;
    int totalProgress;
    int width;

    std::string startBorder;
    std::string completed;
    std::string indicator;
    std::string fill;
    std::string endBorder;

    void printProgress(int percent, int pos)
    {
        std::cout << "\r" << startBorder;
        for (int i = 0; i < width; ++i)
        {
            if (i < pos)
            {
                std::cout << completed;
            }
            else if (i == pos)
            {
                std::cout << indicator;
            }
            else
            {
                std::cout << fill;
            }
        }
        std::cout << endBorder << " " << percent << "% " << std::flush;

        if (currentProgress == totalProgress)
        {
            std::cout << std::endl;
        }
    }

public:
    ProgressBar(int w, int t) : width(w), totalProgress(t), currentProgress(0), startBorder("["), completed("="), indicator(">"), fill(" "), endBorder("]") {}

    ProgressBar(int w, int t, std::string start, std::string comp, std::string ind, std::string fill, std::string end) : width(w), totalProgress(t), currentProgress(0), startBorder(start), completed(comp), indicator(ind), fill(fill), endBorder(end) {}

    void setProgress(int progress)
    {
        currentProgress = progress;
        int percent = (currentProgress * 100) / totalProgress;
        int pos = (width * currentProgress) / totalProgress;
        printProgress(percent, pos);
    }

    void tickProgress()
    {
        setProgress(currentProgress + 1);
    }

    void reset()
    {
        currentProgress = 0;
    }
};

#endif