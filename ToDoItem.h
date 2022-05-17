#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <ctime>

class ToDoItem
{
	int id;
	std::string description;
	bool completed;

public:
	ToDoItem(): id(0), description(""), completed(false)	{}
	~ToDoItem() = default;

	//Getters
	int getId() { return id; }
	std::string getDescription() { return description; }
	bool isCompleted() { return completed; }

	//Methods
	bool create(std::string new_description) {
		
		id = rand() % 100 + 1; // creating random number between 1 and 100

		description = new_description;
		return true;
	}

	void setCompleted(bool val) { completed = val; }

};

