// to-do-list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ToDoItem.h"

int main()
{
    char input_option;
    int input_id;
    std::string input_description;
    std::string version = "0.0.1";
    std::list<ToDoItem> to_do_items;
    std::list<ToDoItem>::iterator it;

    srand(time(NULL));

    to_do_items.clear();

    ToDoItem test;
    test.create("this is a test");
    to_do_items.push_back(test);

    while (1)
    {
        system("cls");
        std::cout << "To-Do-List " << version << std::endl << std::endl << std::endl;

        for (it = to_do_items.begin(); it != to_do_items.end(); it++)
        {
            std::string completed = it->isCompleted() ? "done" : "not done";

            std::cout << it->getId() << " | " << it->getDescription() << " | "
                << completed << std::endl;
        }
        

        if (to_do_items.empty())
        {
            std::cout << "Add your first To DO! \n";
        }

        std::cout << "[a]dd a new To DO \n";
        std::cout << "[c]complete a To DO \n";
        std::cout << "[q]uit\n";

        std::cout << "choice: ";

        std::cin >> input_option;

        if (input_option == 'q')
        {
            std::cout << "Have a great day!\n";
            break;
        }
        else if (input_option == 'a')
        {
            std::cout << "Add a new description: ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, input_description);

            ToDoItem newItem;
            newItem.create(input_description);
            to_do_items.push_back(newItem);
        }
        else if (input_option == 'c')
        {
            std::cout << "Enter ID to mark completed: ";
            std::cin >> input_id;

            for (it = to_do_items.begin(); it != to_do_items.end(); it++)
            {
                if (input_id == it->getId())
                {
                    it->setCompleted(true);
                    break;
                }
            }
        }
    }

    
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
