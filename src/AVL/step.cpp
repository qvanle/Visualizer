#include <data_structures/AVL.hpp>
#include <chrono>
#include <thread>

void AVL::waitForStep()
{
    if(isAnimate) 
    {
        ds_mutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(stepWait));
        ds_mutex.lock();
    }
    std::lock_guard<std::mutex> pause_lock(pause_mutex);
    if(isPause == false) 
    {
        return ;
    }

    ds_mutex.unlock();
    std::unique_lock<std::mutex> lk(step_mutex);
    step_cv.wait(lk, [&]{return isQueue == true;});
    isQueue = false;
    ds_mutex.lock();
}

void AVL::goBack()
{
}

void AVL::goNext()
{
}

void AVL::goOn()
{
}

void AVL::goOff()
{
}

void AVL::speedUp()
{
}

void AVL::slowDown()
{
}


