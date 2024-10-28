//============================================================================
// Name        : CoursePlanner.cpp
// Author      : Cameron Chenault
// Version     : 1.0
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure to hold course information
struct Course {
    string courseNumber;             // Unique course identifier
    string courseTitle;              // Course title
    vector<string> prerequisites;    // List of prerequisite course numbers
};

// TreeNode structure for the binary search tree
struct TreeNode {
    Course course;                   // Course data for this node
    TreeNode* left;                  // Pointer to the left child
    TreeNode* right;                 // Pointer to the right child
};

// Function to insert a course into the binary search tree
TreeNode* insertCourseIntoTree(TreeNode* root, Course course) {
    // If tree is empty or we've reached an empty spot, create new node
    if (root == nullptr) {
        root = new TreeNode{course, nullptr, nullptr};
    // If course number is less than current node, recurse left
    } else if (course.courseNumber < root->course.courseNumber) {
        root->left = insertCourseIntoTree(root->left, course);
    // Else course number is greater than or equal, recurse right
    } else {
        root->right = insertCourseIntoTree(root->right, course);
    }
    return root;
}

// Function to load courses from a CSV file into the binary search tree
TreeNode* loadCourseDataIntoTree(string filename) {
    // Open the CSV file
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: File cannot be opened." << endl;
        return nullptr;
    }

    TreeNode* root = nullptr;
    string line;

    // Read each line from the file
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> tokens;
        string token;

        // Split the line by commas
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        // Ensure line has at least course number and title
        if (tokens.size() < 2) {
            cout << "Error: Invalid line format." << endl;
            continue;
        }

        // Create a course object from tokens
        Course course;
        course.courseNumber = tokens[0];
        course.courseTitle = tokens[1];

        // Process any prerequisites
        for (size_t i = 2; i < tokens.size(); ++i) {
            course.prerequisites.push_back(tokens[i]);
        }

        // Insert the course into the binary search tree
        root = insertCourseIntoTree(root, course);
    }

    // Close CSV file
    file.close();
    cout << "Course data loaded successfully." << endl;
    return root;
}

// In-order traversal to print courses in alphanumeric order
void printCoursesInOrder(TreeNode* root) {
    if (root != nullptr) {
        // Traverse left subtree
        printCoursesInOrder(root->left);
        // Print current node
        cout << root->course.courseNumber << ", " << root->course.courseTitle << endl;
        // Traverse right subtree
        printCoursesInOrder(root->right);
    }
}

// Search for a course in the tree and print its details
void printCourseInfo(TreeNode* root, string courseNumber) {
    if (root == nullptr) {
        cout << "Course not found." << endl;
        return;
    }

    // Binary search through the tree
    if (courseNumber < root->course.courseNumber) {
        // Search left subtree if course number is less than current node
        printCourseInfo(root->left, courseNumber);
    } else if (courseNumber > root->course.courseNumber) {
        // Search right subtree if course number is greater than current node
        printCourseInfo(root->right, courseNumber);
    } else {
        // Course found
        cout << root->course.courseNumber << ", " << root->course.courseTitle << endl;
        // Print prerequisites if they exist
        if (!root->course.prerequisites.empty()) {
            cout << "Prerequisites: ";
            for (size_t i = 0; i < root->course.prerequisites.size(); ++i) {
                cout << root->course.prerequisites[i];
                // Add comma separator between prerequisites (except for last one)
                if (i < root->course.prerequisites.size() - 1) cout << ", ";
            }
            cout << endl;
        } else {
            cout << "No prerequisites." << endl;
        }
    }
}

// Function to display the menu and handle user input
void menu(TreeNode*& root) {
    int choice = 0;
    string filename;

    cout << "Welcome to the course planner." << endl;

    while (choice != 9) {
        cout << "\n1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;
        cout << "\nWhat would you like to do? ";
        cin >> choice;

        // Process menu selection using switch statement
        switch (choice) {
            case 1:  // Load Data Structure
                cout << "Loading Data...";
                filename = "ABCU_Advising_Program_Input.csv";
                root = loadCourseDataIntoTree(filename);
                break;

            case 2:  // Print Course List
                if (root == nullptr) {
                    cout << "Error: No data loaded. Please load data first." << endl;
                } else {
                    cout << "Here is a sample schedule:" << endl;
                    printCoursesInOrder(root);
                }
                break;

            case 3:  // Print Course Information
                if (root == nullptr) {
                    cout << "Error: No data loaded. Please load data first." << endl;
                } else {
                    cout << "What course do you want to know about? ";
                    string courseNumber;
                    cin >> courseNumber;
                    // Transform to uppercase for consistent formatting
                    transform(courseNumber.begin(), courseNumber.end(), courseNumber.begin(), ::toupper);
                    printCourseInfo(root, courseNumber);
                }
                break;

            case 9:  // Exit
                cout << "Thank you for using the course planner!" << endl;
                break;

            default:  // Invalid Option
                cout << choice << " is not a valid option." << endl;
                break;
        }
    }
}


// Main function to initialize the tree and run the menu
int main() {
    TreeNode* root = nullptr;
    menu(root);
    return 0;
}
