#include <bits/stdc++.h>

int main()
{
    std::string sentence;
    std::getline(std::cin, sentence);

    for (int i = 0; i < sentence.length(); i++)
    {
        sentence[i] = (char) tolower(sentence[i]);
    }

    int counter = 0;
    while (true)        // to print the first character in uppercase
    {
        if (isalpha(sentence[counter]))
        {
            std::cout << (char) toupper(sentence[counter]);
            counter++;
            break;
        }
        counter++;
    }

    for (int i = counter ; i < sentence.length(); i++)
    {
        if (sentence[i] == '.')
        {
            std::cout << sentence[i];
            break;
        }
        else if (isalnum(sentence[i]) || ispunct(sentence[i]))
        {
            std::cout << sentence[i];
        }
        else if (sentence[i] == ' ')
        {
            std::cout << ' ';
            while (true)
            {
                if (sentence[i] == ' ')
                {
                    i++;
                    continue;
                }
                else 
                {
                    std::cout << sentence[i];
                    break;
                }
            }
        }
    }    
}