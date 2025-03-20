#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <limits>

using namespace std;

void intro_story();
void start_game();
void save_game(int LEVEL, int LIVES);
void load_game(int &LEVEL, int &LIVES);
void lose_life(int &LIVES);
void game_over();
void random_no_generator();
int get_next_number();
bool get_integer_input(int &choice);

// Level Functions
void L1(), L2(), L3(), L4(), L5(), L6(), L7(), L8(), L9(), L10();
void L1_story(), L2_story(), L3_story(), L4_story(), L5_story(), L6_story(), L7_story(), L8_story(), L9_story(), L10_story();

// Difficulty Functions
void easy(int L1_value);

int random_value_arr[10];
int value_acessor = 0;

int main()
{   
    intro_story();
    start_game();
    return 0;
}

void save_game(int LEVEL, int LIVES)
{
    ofstream file("savegame.txt");
    if (file)
    {
        file << LEVEL << " " << LIVES;
        file.close();
    }
}

void load_game(int &LEVEL, int &LIVES)
{
    ifstream file("savegame.txt");
    if (file >> LEVEL >> LIVES)
    {
        file.close();
    }
    else
    {
        LEVEL = 1;
        LIVES = 3;
    }
}

void start_game()
{
    int saved_level, saved_lives;
    random_no_generator();
    load_game(saved_level, saved_lives);

    if (saved_level == 1)
    {
        save_game(1, 3);
        L1();
    }
    else
    {
        cout << "Game is saved till (Level " << saved_level << ")\n"
             << "You have (" << saved_lives << " Lives)\n";
        cout << "1: Continue\n2: Restart\n";

        int choice;
        while (!get_integer_input(choice) || (choice != 1 && choice != 2))
        {
            cout << "Invalid input. Enter 1 or 2: ";
        }

        if (choice == 1)
        {
            switch (saved_level)
            {
                case 1: L1(); break;
                case 2: L2(); break;
                case 3: L3(); break;
                case 4: L4(); break;
                case 5: L5(); break;
                case 6: L6(); break;
                case 7: L7(); break;
                case 8: L8(); break;
                case 9: L9(); break;
                case 10: L10(); break;
            }
        }
        else
        {
            save_game(1, 3);
            L1();
        }
    }
}

void lose_life(int &LIVES)
{
    LIVES--;
    cout << "You lost a life!\nLives left: " << LIVES << "\n";
    if (LIVES <= 0)
    {
        game_over();
    }
}

void game_over()
{
    cout << "\n========= GAME OVER =========\n";
    cout << "You ran out of lives!\nRestarting game...\n";
    save_game(1, 3);
    L1();
}

void random_no_generator()
{
    for (int i = 0; i < 10; i++)
    {
        random_value_arr[i] = i + 1;
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(random_value_arr, random_value_arr + 10, g);
}

int get_next_number()
{
    if (value_acessor < 10)
    {
        return random_value_arr[value_acessor++];
    }
    value_acessor = 0;  
    return random_value_arr[value_acessor++];
}

void L1_story() { cout << "Level 1\n"; }
void L2_story() { cout << "Level 2\n"; }
void L3_story() { cout << "Level 3\n"; }
void L4_story() { cout << "Level 4\n"; }
void L5_story() { cout << "Level 5\n"; }
void L6_story() { cout << "Level 6\n"; }
void L7_story() { cout << "Level 7\n"; }
void L8_story() { cout << "Level 8\n"; }
void L9_story() { cout << "Level 9\n"; }
void L10_story() { cout << "Level 10\n"; }

void L1() { L1_story(); easy(get_next_number()); L2(); }
void L2() { L2_story(); easy(get_next_number()); L3(); }
void L3() { L3_story(); easy(get_next_number()); L4(); }
void L4() { L4_story(); easy(get_next_number()); L5(); }
void L5() { L5_story(); easy(get_next_number()); L6(); }
void L6() { L6_story(); easy(get_next_number()); L7(); }
void L7() { L7_story(); easy(get_next_number()); L8(); }
void L8() { L8_story(); easy(get_next_number()); L9(); }
void L9() { L9_story(); easy(get_next_number()); L10(); }
void L10() 
{ 
    L10_story(); 
    easy(get_next_number()); 
    cout << "You have completed all levels! Restarting...\n";
    save_game(1, 3);
    L1();
}

void intro_story()
{
    cout << "Welcome to the game!\n";
}

bool get_integer_input(int &choice)
{
    cin >> choice;
    if (cin.fail()) 
    {
        cin.clear();  
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

void easy(int L1_value)
{
    int life = 3;

    while (true)
    {
        if (L1_value == -1)
        {
            cout << "Invalid quest number\n";
            return;
        }

        int choice;
        cout << "Quest " << L1_value << "\n";
        cout << "What is " << L1_value << " + " << L1_value << "?\n";
        cout << "1) " << (L1_value * 2) << "\t2) " << (L1_value + 1) << "\n";
        cout << "3) " << (L1_value - 1) << "\t4) " << (L1_value * 3) << "\n";

        while (!get_integer_input(choice) || choice < 1 || choice > 4)
        {
            cout << "Invalid input. Enter 1, 2, 3, or 4: ";
        }

        if (choice == 1)
        {
            cout << "Correct!\n";
            save_game(L1_value + 1, life);
            return;
        }
        else
        {
            cout << "Wrong!\n";
            lose_life(life);
            save_game(L1_value, life);
            if (life <= 0) return;
        }
    }
}
