#include "Page.h"

Page::Page(std::string url) : url(url) {}

Page::Page(std::string url, std::string title, std::string content) : url(url), title(title), content(content) {}

std::string Page::getURL()
{
    return url;
}

std::string Page::getTitle()
{
    return title;
}

std::string Page::getContent()
{
    return content;
}