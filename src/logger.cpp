#include <logger.h>

#include <iostream>
#include <string>

Logger::Logger()
{
    
    file.open("seriestracker.log", std::ios::out);
    std::string line;
 
    // Backup streambuffers of  cout
    std::streambuf* stream_buffer_cout = std::cout.rdbuf();
    std::streambuf* stream_buffer_cin = std::cin.rdbuf();
 
    // Get the streambuffer of the file
    std::streambuf* stream_buffer_file = file.rdbuf();
 
    // Redirect cout to file
    std::cout.rdbuf(stream_buffer_file);
 
    std::cout << "Successfully redirected COUT to log file." << std::endl;
 
    // Redirect cout back to screen
    // std::cout.rdbuf(stream_buffer_cout);
    // std::cout << "This line is written to screen" << std::endl;
}

Logger::~Logger()
{
    file.close();
}