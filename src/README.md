

# Course Planner

Course Planner is a C++ command-line application designed to help academic advisors and students view and manage information about Computer Science courses. The program allows users to load a CSV file containing course data, organize the courses in a binary search tree, and perform tasks such as displaying a list of courses in alphanumeric order or retrieving specific course information along with prerequisites.

## Features

1. **Load Course Data**: Load course data from a user-specified CSV file into a binary search tree. Each course entry includes a course number, title, and optional prerequisites.
2. **Print Course List**: Display an alphanumeric list of all courses in the Computer Science department, sorted automatically using an in-order traversal of the binary search tree.
3. **Search for Course Information**: Look up a specific course by its course number and view its title and list of prerequisites.
4. **User-Friendly Menu**: Navigate the program with a menu that guides users through available options and provides helpful error messages for invalid inputs.

## How to Use

### Prerequisites
- **C++ Compiler**: Ensure you have a C++ compiler (e.g., `g++` from Xcode Command Line Tools) installed on macOS.

### Running the Program
1. **Clone or Download** the repository to your local machine.
2. **Open a Terminal** and navigate to the directory containing `course_planner.cpp`.
3. **Compile the Code**:
   ```bash
   g++ -o course_planner course_planner.cpp
   ```
4. **Run the Program**:
   ```bash
   ./course_planner
   ```

### Menu Options

1. **Load Data Structure**: Prompts the user to enter the filename (e.g., `CS 300 ABCU_Advising_Program_Input.csv`) containing the course data. The program will load the course data into a binary search tree.
2. **Print Course List**: Displays a list of all courses sorted in alphanumeric order by course number.
3. **Print Course**: Prompts the user to enter a course number to retrieve specific information about that course, including its title and prerequisites.
4. **Exit**: Exits the program.

### Example Usage

```
Welcome to the course planner.

1. Load Data Structure.
2. Print Course List.
3. Print Course.
9. Exit

What would you like to do? 1
Enter the file name: CS 300 ABCU_Advising_Program_Input.csv
Course data loaded successfully.

What would you like to do? 2
Here is a sample schedule:

CSCI100, Introduction to Computer Science
CSCI101, Introduction to Programming in C++
CSCI200, Data Structures
...

What would you like to do? 3
What course do you want to know about? CSCI400
CSCI400, Large Software Development
Prerequisites: CSCI301, CSCI350

What would you like to do? 9
Thank you for using the course planner!
```

## File Format

The program expects the course data file to be in CSV format, with the following structure:
```
CourseNumber,CourseTitle,Prerequisite1,Prerequisite2,...
```
For example:
```
CSCI100,Introduction to Computer Science
CSCI200,Data Structures,CSCI100
CSCI300,Introduction to Algorithms,CSCI200
```

## Code Structure

- **Course Struct**: Holds course number, title, and a list of prerequisites.
- **TreeNode Struct**: Represents each node in the binary search tree.
- **Binary Search Tree Functions**:
  - **insertCourseIntoTree**: Adds a course to the tree.
  - **printCoursesInOrder**: Prints all courses in sorted order.
  - **printCourseInfo**: Searches for and displays information about a specific course.

--------------------------------------------------------------------------------------------
Reflection

In this course, my projects focused on solving key organizational and retrieval challenges in managing course data for an academic advising program. The primary problem was to effectively structure, sort, and display course information in a way that would be efficient for both storage and access. I analyzing their runtime approached of different to choose the best fit for the task. Understanding data structures is essential because it allows developers to optimize operations like searching, sorting, and inserting data, which is crucial when handling large datasets.

Throughout the project I encountered and overcame several challenges, especially around data organization and tree traversal. Using a structured approach and breaking down each requirement step-by-step allowed me to isolate and address specific roadblocks. This experience has expanded my approach to software design. I also emphasizing the importance of selecting data structures that align with a program's specific needs for efficiency and maintainability. My work on this project has refined my coding style, focusing on writing clean, maintainable code that adheres to best practices. This including modularization and detailed documentation, making the code more readable and easier to modify in the future.

