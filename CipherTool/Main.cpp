//
// Main.cpp
// 2018-May-02
//
#include <iostream>
#include <string>


// displays help on console
void PrintHelp()
{
	std::cout << "CipherTool - Usage:\n";
    std::cout << "\tciphertool input_file output_file" << std::endl;
}


// shift letters a number of times in the alphabet
std::string CaesarOnIt(std::string source, int inc)
{
    for (char &c : source)
    {
        if (isalpha(c))
        {
            c = ((toupper(c) - 'A' + inc) % 26) + 'A';
        }
    }

    return source;
}


// interactive use (type sentence then get ciphered sentence)
void DynamicConsole()
{
    std::cout << "type 'exit' to close.\n > ";

    std::string input;

    while (true)
    {
        //std::cin >> input; // only one word-term per time, getline get the entire line
        getline(std::cin, input);

        if (input.compare("exit") == 0)
        {
            break;
        }
        else
        {
            // TODO: ask user for increment
            std::cout << CaesarOnIt(input, 3) << "\n > ";
        }
    }
}


// entry point
int main(int argc, char **argv)
{
	if (argc == 1)
	{
		// io from stdin/out
        DynamicConsole();
	}
	else if (argc == 3)
	{
		// file io
	}
	else
	{
		PrintHelp();
	}

  	return 0;
}