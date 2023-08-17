#include <window.hpp>

bool MyWindow::isClosed()
{
    std::lock_guard<std::mutex> lg(status_mutex);
    return status == WINDOW_STATUS::IS_CLOSED;
}

bool MyWindow::isOpen()
{
    std::lock_guard<std::mutex> lg(status_mutex);
    return status == WINDOW_STATUS::IS_OPEN;
}
