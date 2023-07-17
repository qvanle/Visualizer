#include <window.hpp>

bool MyWindow::isClosed()
{
    return status == WINDOW_STATUS::IS_CLOSED;
}

bool MyWindow::isOpen()
{
    return status == WINDOW_STATUS::IS_OPEN;
}
