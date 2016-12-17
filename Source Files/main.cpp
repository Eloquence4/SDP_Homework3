#include <iostream>
#include <fstream>
#include "../Headers/Word.h"
#include "../Headers/Tree.h"
#include "../Headers/Functions.h"


int main(int argc, char* argv[])
{
    if(argc <= 2)
        std::cout << "Error, not enough launch arguments!\n";
    else
    {
        std::fstream dictionaryFile(argv[1], std::ios::in);
        std::fstream files;
        
        if(!dictionaryFile)
        {
            std::cout << "Error, could not open file!\n";
            return 0;
        }

        Tree<Word> dictionaryTree;

        loadDictionary(dictionaryTree, dictionaryFile);

        dictionaryFile.close();

        for(int i = 2; i < argc; i++)
        {
            files.open(argv[i], std::ios::in);
            if(!files)
            {
                files.close();
                std::cout << "Error, could not open file!\n";
            }
            else
            {
                std::cout << argv[i] << ' ' << evaluate(dictionaryTree, files) << "\n";
                files.close();
            }
        }
    }
    
    return 0;
}
