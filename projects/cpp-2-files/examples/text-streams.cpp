#include <fstream>
#include <iostream>
#include <string>

/**
 * @brief Writes a text file, then reads and prints it using two stream types.
 * @details Creates or overwrites myFile.md in the current working directory.
 *          Prints its contents once with ifstream and once with fstream.
 * @return 0 on success, or 1 if opening, writing, or reading the file fails.
 */
int main()
{
    const std::string filePath = "myFile.md";

    /**
     * @brief Open the file for writing.
     * @details fstream supports both input and output. Here, ios::out selects
     *          output only, and ios::trunc explicitly discards existing contents.
     */
    std::fstream outputFile(filePath, std::ios::out | std::ios::trunc);
    if (!outputFile.is_open())
    {
        std::cerr << "Could not open " << filePath << " for writing.\n";
        return 1;
    }

    // Each '\n' ends a line without forcing an immediate flush.
    outputFile << "1. Hiiiiiiiiiiiiiiiiiiiii\n"
               << "2. Hiiiiiiiiiiiiiii\n"
               << "3. Hiiiiiiiiiiiiiii\n"
               << "4. Hiiiiiiiiiiiiiii\n"
               << "5. Hiiiiiiiiiiiiiii\n";

    // Close flushes buffered output before the file is opened for reading.
    outputFile.close();
    if (!outputFile)
    {
        std::cerr << "Could not finish writing " << filePath << ".\n";
        return 1;
    }

    /** @brief Read the file with ifstream, which defaults to input-only mode. */
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open())
    {
        std::cerr << "Could not open " << filePath << " for reading.\n";
        return 1;
    }

    std::string line;
    // getline preserves spaces and removes the newline. Test the read itself
    // so a failed read does not print an extra line.
    while (std::getline(inputFile, line))
    {
        std::cout << line << '\n';
    }
    if (!inputFile.eof())
    {
        std::cerr << "Could not finish reading " << filePath << ".\n";
        return 1;
    }
    inputFile.close();

    /**
     * @brief Read the same file again with fstream.
     * @details Its default mode is ios::in | ios::out, requesting both read
     *          and write access. This example uses only its reading capability.
     */
    std::fstream readWriteFile(filePath);
    if (!readWriteFile.is_open())
    {
        std::cerr << "Could not open " << filePath << " for reading and writing.\n";
        return 1;
    }

    while (std::getline(readWriteFile, line))
    {
        std::cout << line << '\n';
    }
    if (!readWriteFile.eof())
    {
        std::cerr << "Could not finish reading " << filePath << ".\n";
        return 1;
    }

    // The remaining open stream closes automatically when it leaves scope.
    return 0;
}
