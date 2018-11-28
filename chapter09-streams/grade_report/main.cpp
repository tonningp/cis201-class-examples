#include "gradereport.h"


int main()
{
    Gradereport gr;
    gr.open("classes.txt");
    gr.read();
    while(1)
    {
        std::string id; 
        // ask the user for an id
        std::cin >> id;
        gr.print(id);
        
        char resp;
        std::cout << "Print more students (y/n)?)";
        std::cin >> resp;
        if(resp != 'y')
        {
           break;
        }
    
    }
    return 0;
}
