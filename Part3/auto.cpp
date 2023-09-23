#include <iostream>
#include <vector>
#include <string>

int main(){
    std::vector<std::string> args(5);
    for (std::vector<std::string>::iterator i = args.begin(); i != args.end(); i++)
    {
        std::cin >> *i;
    }
    for (auto i = args.begin(); i != args.end(); i++)
    {
        std::cout << *i << std::endl;
    }
    return 0;
    
}