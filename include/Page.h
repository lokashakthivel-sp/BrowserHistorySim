#pragma once
#include <string>

class Page
{
private:
    std::string url;
    std::string title = "Page Title";
    std::string content = "Page Content";

public:
    Page() {}
    Page(std::string url);
    Page(std::string url, std::string title, std::string content);
    std::string getURL();
    std::string getTitle();
    std::string getContent();
};