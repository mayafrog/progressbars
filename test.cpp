#include "progressbar.hpp"
#include <thread>
#include <chrono>

int main()
{
    int displayWidth = 100;
    int totalProgress = 100;
    ProgressBar bar(displayWidth, totalProgress);

    for (int i = 0; i < totalProgress; ++i)
    {
        bar.incrementProgress();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    ProgressBar bar2(displayWidth, totalProgress, "[", "█", "█", "-", "]");

    for (int i = 0; i <= totalProgress; i += 20)
    {
        bar2.setProgress(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
