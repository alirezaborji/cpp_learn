#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::string filename = "myFile.txt";

    while (1)
    {
        std::cout << "1. Add note\n"
                  << "2. Show all notes\n"
                  << "3. Search notes\n"
                  << "4. Clear notes\n"
                  << "5. remove a char\n"
                  << "6. Exit" << std::endl;

        std::string content;
        getline(std::cin, content);
        // cin >> content;


        if (content == "1")
        {
            std::cout << "chosed: " << content << std::endl;

            std::fstream meStream(filename, std::ios::app);

            if (!meStream.is_open())
            {
                meStream.close();
                return 0;
            }

            getline(std::cin, content);

            meStream << content << std::endl;

            getline(meStream, content);

            std::cout << content << std::endl;

            meStream.close();
        }else if(content == "2")
        {
            std::cout << "chosed: " << content << std::endl;

            std::fstream meStream(filename, std::ios::in);

            if (!meStream.is_open())
            {
                meStream.close();
                return 0;
            }

            while (getline(meStream, content))
            {
                std::cout << content << std::endl;
            }

            meStream.close();
        }else if(content == "3")
        {
            std::cout << "chosed: " << content << std::endl;

            std::fstream meStream(filename, std::ios::in);

            if (!meStream.is_open())
            {
                meStream.close();
                return 0;
            }

            std::cout << "Enter what to find:" << std::endl;
            std::string findContent;
            getline(std::cin, findContent);

            while (getline(meStream, content))
            {
                int found = content.find(findContent);

                if (!found)
                {
                    std::cout << "found" << std::endl;
                    break;
                }
            }

        }else if(content == "4")
        {
            std::cout << "chosed: " << content << std::endl;

            std::fstream meStream(filename, std::ios::out);

            if (!meStream.is_open())
            {
                meStream.close();
                return 0;
            }

            meStream << "" << std::endl;

            meStream.close();
        }else if(content == "5")
        {
            std::cout << "chosed: " << content << std::endl;

            std::fstream meStream(filename, std::ios::out);

            if (!meStream.is_open())
            {
                meStream.close();
                return 0;
            }

            std::string meContent;
            std::string delimiter;
            getline(std::cin, delimiter);

            auto position = meContent.find(delimiter);

            std::cout << position << std::endl;

        }else if(content == "6")
        {
            break;
        }
    }










    return 0;
}
