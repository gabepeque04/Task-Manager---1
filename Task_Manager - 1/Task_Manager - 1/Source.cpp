#include<iostream>
#include<vector>
#include<string>

using namespace std;
//Defined a structure to represent a task.
struct Task {
	string title; //Title or description of the task.
	bool completed; //Indicates whether the task is completed(True).
};
//Function to add a new task to the task mangager application.
void addTask(vector<Task>& tasks) {
	//Declare a new Task object to represent the task to be added.
	Task newTask;
	//Prompt the user to enter the title or description of the task.
	cout << "Enter task title: ";
	//Read the input from the user and store it in the title member variable of the newTask object.
	getline(cin, newTask.title);
	//Initialize the completion status of the task to false, indicating it is not yet completed.
	newTask.completed = false;
	//Add the newTask object to the end of the tasks vector, effectively adding the task to the task list.
	tasks.push_back(newTask);
	//Print a message to confirm that the task has been successfully added.
	cout << "Task added successfully!" << endl;

}
//Function to display the list of tasks.
void listTasks(const vector<Task>& tasks) {
	//Check if the tasks vector is empty.
	if (tasks.empty()) {
		//If the vector is empty, print a message and return.
		cout << "No tasks found." << endl;
		return;
	}
	//Print the header for the task list.
	cout << "Task List:" << endl;

	//Loop through each task in the tasks vector.
	for (size_t i = 0; i < tasks.size(); i++) {
		//Retrieve the current task.
		const Task& task = tasks[i];

		//Print the task number, title, and completion status.
		cout << i + 1 << ". " << task.title << " - " << (task.completed ? "Completed" : "Incomplete") << endl;
	}
}
//Function to mark a task as completed in the task manager application.
void markTaskCompleted(vector<Task>& tasks) {
	//Display the current list of tasks to the user.
	listTasks(tasks);
	//Declare a variable to store the index of the task to be marked as completed.
	int index;
	//Prompt the user to enter the index of the task to mark as completed.
	cout << "Enter the index of the task to mark as completed: ";
	//Read the user's input for the index of the task.
	cin >> index;
	//Check if the input index is within the valid range of task indices.
	if (index > 0 && index <= tasks.size()) {
		//Mark the selected task as completed by setting its completed status to true.
		tasks[index - 1].completed = true;
		//Print a message to confirm that the task has been marked as completed.
		cout << "Task marked as completed!" << endl;
	}
	else {
		//If the input index is not valid, print an error message.
		cout << "Invalid task index!" << endl;
	}



}
//Main function of the task manager program.
int main() {
	vector <Task> tasks;

	//Main menu loop for user interaction.
	int choice;
	while (true) {
		//Display the main menu options.
		cout << "\nTask Manager Menu:" << endl;
		cout << "1. Add Task" << endl;
		cout << "2. List Tasks" << endl;
		cout << "3. Mark Task as Completed" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";

		//Read the user's choice from the console.
		cin >> choice;
		cin.ignore(); //Clear input buffer.

		//Perform actions based on the user's choice.
		switch (choice) {
		case 1:
			addTask(tasks); //Call addTask function to add a new task.
			break;
		case 2:
			listTasks(tasks); //Call listTasks function to display the task list.
			break;
		case 3:
			markTaskCompleted(tasks); // Call markTaskCompleted function to mark a task as completed.
			break;
		case 4:
			//Exit the program if the user chooses option 4.
			cout << "Exiting program. Goodbye!" << endl;
			return 0;

		default:
			//Display an error message for invalid choices.
			cout << "Invalid choice. Please try again." << endl;
		}
	}
	return 0;
}