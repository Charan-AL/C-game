#include<iostream>
using namespace std;

void Gun() {
    cout << "         /\\______________________\n";
    cout << "        \\    \\                   |_\n";
    cout << "         |-------------------------| - - - - - - -|>\n";
    cout << "         |       ________________|\n";
    cout << "         |      |\\     |\n";
    cout << "         |      |-----\n";
    cout << "         |      |\n";
    cout << "         |______|\n";
}
    

void Sword() {
    cout << "                                   ^\n";
    cout << "                                  /   \\\n";
    cout << "                                 /     \\\n";
    cout << "                                |       |\n";
    cout << "                                |       |\n";
    cout << "                                |       |\n";
    cout << "                                |       |\n";
    cout << "                                |       |\n";
    cout << "                                |       |\n";
    cout << "                                |       |\n";
    cout << "                        ________|       |________\n";
    cout << "                       |________         ________|\n";
    cout << "                                |       |\n";
    cout << "                                 \\     /\n";
    cout << "                                  |   |\n";
    cout << "                                  |   |\n";
    cout << "                                  |   |\n";
    cout << "                                  |___|\n";
}  
    

void Ninja_Star() {
    cout << "        *\n";
    cout << "       ***\n";
    cout << "     *******\n";
    cout << " ***************\n";
    cout << "     *******\n";
    cout << "       ***\n";
    cout << "        *\n";
}    
    

int main()
{
    string name; 
    int weapon; 
    cout << "Enter the your name : ";
    cin >> name; 
    cout<<"\nSelect the weapon \n 1.Gun\n2.Sword\n3.Ninja Star\n";
    while(1)
    {
        cout<<"\nEnter your choice : ";
        cin >> weapon;
        switch(weapon)
        {
            case 1:Gun();return 0; 
            case 2:Sword();return 0;
            case 3:Ninja_Star();return 0;
            default :cout<<"\nInvalid Choice ";break;
        }
        
    }
}
