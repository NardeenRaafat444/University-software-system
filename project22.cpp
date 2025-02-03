#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string ID;
    string Phone;
    string Name;
    string Email;
    string Address;
    string Password;
    Student* next;

    // Default constructor
    Student() {
        ID = Phone = Name = Email = Address = Password = " ";
    }

    // constructor to intialize data
    Student(string in_ID, string in_Phone, string in_Name, string in_Email, string in_Address, string in_Pass) {
        ID = in_ID;
        Phone = in_Phone;
        Name = in_Name;
        Email = in_Email;
        Address = in_Address;
        Password = in_Pass;
    }
};

class Courses {
public:
    string CourseID;
    string CourseName;
    string CourseInstructor;
    int CourseCredits;
    Courses* next;

    // default constructor
    Courses() {
        CourseID = CourseName = CourseInstructor = " ";
        CourseCredits = 0;
    }

    // constructor to initialize data
    Courses(string ID, string Name, string Instructor, int Credits) {
        CourseID = ID;
        CourseName = Name;
        CourseInstructor = Instructor;
        CourseCredits = Credits;
    }

    void display() {
        cout << "Course ID: " << CourseID << endl;
        cout << "Course Name: " << CourseName << endl;
        cout << "Course Instructor: " << CourseInstructor << endl;
        cout << "Course Credits: " << CourseCredits << endl;
    }
};

class StudentRecords {
public:
    Student* head;

    StudentRecords() {
        head = nullptr;
    }

    bool isempty() {
        return (head == nullptr);
    }

    // Add a new student from head
    void add_function(string ID, string Name, string Email, string Phone, string Address, string Password) {
        Student* newstudent = new Student(ID, Phone, Name, Email, Address, Password);
        if (isempty()) {
            newstudent->next = nullptr;
            head = newstudent;
        }
        else {
            newstudent->next = head;
            head = newstudent;
        }
        cout << "Student is added" << endl;
    }

    // Delete using ID
    void deleteStudent(string id) {
        if (isempty()) {
            cout << "Sorry, the list is empty" << endl;
            return;
        }

        // If head needs to be deleted
        if (head->ID == id) {
            Student* temp = head;
            head = temp->next;
            delete temp;
            cout << "Student deleted successfully!" << endl;
        }
        else {
            Student* current = head;
            Student* prev = nullptr;

            while (current != nullptr && current->ID != id) {
                prev = current;
                current = current->next;
            }

            if (current == nullptr) {
                cout << "Student with ID " << id << " not found." << endl;
                return;
            }

            prev->next = current->next;
            delete current;
            cout << "Student deleted successfully!" << endl;
        }
    }
    void bubbleSort() {
        if (isempty()) return;

        bool swapped;
        Student* ptr1;
        Student* lptr = nullptr;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->ID > ptr1->next->ID) {
                    // swap the value
                    swap(ptr1->ID, ptr1->next->ID);
                    swap(ptr1->Name, ptr1->next->Name);
                    swap(ptr1->Email, ptr1->next->Email);
                    swap(ptr1->Phone, ptr1->next->Phone);
                    swap(ptr1->Address, ptr1->next->Address);
                    swap(ptr1->Password, ptr1->next->Password);

                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    // Binary search algorthim
    int binarySearch(Student* sortedList, int size, string key) {
        int low = 0, high = size - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;


            Student* midNode = sortedList;
            for (int i = 0; i < mid; i++) {
                midNode = midNode->next;
            }

            if (midNode->ID == key) {
                return mid;
            }
            if (midNode->ID < key) {
                low = mid + 1; // searching in right
            }
            else {
                high = mid - 1; // searching in  left
            }
        }
        return -1; // does not exist
    }

    // searching for student by ID
    void binarySearchStudentByID(string id) {
        if (isempty()) {
            cout << "The student list is empty.\n";
            return;
        }

        // calculate size
        int size = 0;
        Student* current = head;
        while (current != nullptr) {
            size++;
            current = current->next;
        }

        //  Apply bublle sorting
        bubbleSort();

        // Apply binary search
        int index = binarySearch(head, size, id);

        if (index != -1) {
            cout << "Student with ID " << id << " found at position " << index + 1 << "." << endl;
        }
        else {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    // Linear Search by ID
    void linearSearchStudentByID(string id) {
        if (isempty()) {
            cout << "The student list is empty.\n";
            return;
        }

        Student* current = head;
        while (current != nullptr) {
            if (current->ID == id) {
                cout << "Student found:\n";
                cout << "ID: " << current->ID << "\nName: " << current->Name
                    << "\nEmail: " << current->Email << "\nPhone: " << current->Phone
                    << "\nAddress: " << current->Address << "\n";
                return;
            }
            current = current->next;
        }
        cout << "Student with ID " << id << " not found.\n";
    }

    void display() {
        if (head == nullptr) {
            cout << "There are no students" << endl;
            return;
        }

        Student* temp = head;
        cout << "Students record:" << endl;

        while (temp != nullptr) {
            cout << "ID: " << temp->ID << endl;
            cout << "Name: " << temp->Name << endl;
            cout << "Email: " << temp->Email << endl;
            cout << "Phone: " << temp->Phone << endl;
            cout << "Address: " << temp->Address << endl;
            temp = temp->next;
        }
    }
};
class Node {
public:
    Courses* course;
    Node* left;
    Node* right;
    Node(Courses* c) : course(c), left(nullptr), right(nullptr) {}
};

class Binary_search_tree {
public:
    Node* root;
    // Constructor
    Binary_search_tree() {
        root = nullptr;
    }

    void add_course(string id, string name, int credits, string instructor) {
        Courses* newCourse = new Courses(id, name, instructor, credits);

        if (root == nullptr) {
            root = new Node(newCourse);
        }
        else {
            Node* current = root;
            Node* parent = nullptr;

            while (current != nullptr) {
                parent = current;
                if (id < current->course->CourseID) {
                    current = current->left;
                }
                else if (id > current->course->CourseID) {
                    current = current->right;
                }
                else {
                    cout << "Course ID " << id << " already exists." << endl;
                    return;
                }
            }

            if (id < parent->course->CourseID) {
                parent->left = new Node(newCourse);
            }
            else {
                parent->right = new Node(newCourse);
            }
        }
    }

    bool searchCourse(Node* node, string courseID) {
        if (node == nullptr) return false;

        if (node->course->CourseID == courseID) return true;
        if (courseID < node->course->CourseID) {
            return searchCourse(node->left, courseID);
        }
        else {
            return searchCourse(node->right, courseID);
        }
    }

    void displayCoursesRecursive(Node* node) {
        if (node != nullptr) {
            displayCoursesRecursive(node->left);
            node->course->display();
            displayCoursesRecursive(node->right);
        }
    }
};

class Enrollment_History_Node {
public:
    Courses* course;
    Enrollment_History_Node* prev;
    Enrollment_History_Node* next;

    // Default constructor
    Enrollment_History_Node(Courses* newCourse) {
        course = newCourse;
        prev = next = NULL;
    }
};

class Enrollment_History_DLL {
public:
    Enrollment_History_Node* head;
    Enrollment_History_Node* tail;

    // Default constructor
    Enrollment_History_DLL() {
        head = tail = NULL;
    }

    bool isEmpty() {
        return (head == NULL);
    }

    void addEnrollment(Courses* newCourse) {
        Enrollment_History_Node* newEnrollment = new Enrollment_History_Node(newCourse);

        // Add at head
        if (isEmpty()) {
            head = tail = newEnrollment;
        }
        else {
            // Add at tail
            tail->next = newEnrollment;
            newEnrollment->prev = tail;
            tail = newEnrollment;
            tail->next = NULL;
        }

        cout << "Enrollment is added for the course with ID: " << newEnrollment->course->CourseID << "\n";
    }

    void viewEnrollment() {
        if (isEmpty()) {
            cout << "No enrollments to display!\n";
            return;
        }

        Enrollment_History_Node* curr = head;
        while (curr != NULL) {
            cout << "Course ID: " << curr->course->CourseID << "\n";
            curr = curr->next;
        }
    }
    // Linear Search by ID
    void linearSearchCourseByID (string id)
    {
        // Check if the course list is empty
        if (head == nullptr) {
            cout << "The Course list is empty.\n";
            return;
        }

        Enrollment_History_Node* current = head; // Start from the head of the list

        // Traverse through the list
        while (current != nullptr) {
            // Check if the current course matches the given ID
            if (current->course->CourseID == id) {
                cout << "Course found:\n";
                cout << "ID: " << current->course->CourseID
                    << "\nName: " << current->course->CourseName
                    << "\nInstructor: " << current->course->CourseInstructor
                    << "\nCredits: " << current->course->CourseCredits << "\n";
                return; // Exit the function as the course is found
            }
            current = current->next; // Move to the next node
        }

        // If the course is not found in the list
        cout << "Course with ID " << id << " not found.\n";
    }


};

class StackNode {
public:
    Courses* course;
    StackNode* next;

    // Constructor to initialize the course
    StackNode(Courses* course) {
        this->course = course;
        next = NULL;
    }
};

class Course_Registeration_Stack {
public:
    StackNode* top;

    Course_Registeration_Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return (top == NULL);
    }

    void push(Courses* course) {
        StackNode* newNode = new StackNode(course);
        newNode->next = top;
        top = newNode;
        cout << "Course prerequisites: " << course->CourseID << "\n";
    }

    void pop() {
        if (top == NULL) {
            cout << "No prerequisites to remove" << "\n";
            return;
        }
        else {
            StackNode* temp = top;
            cout << "Prerequisite " << top->course->CourseID << " completed and removed from the stack." << "\n";
            top = top->next;
            delete temp;
        }
    }

    void display() {
        StackNode* temp = top;
        while (temp != NULL) {
            cout << "Course ID: " << temp->course->CourseID << endl;
            temp = temp->next;
        }
    }

    bool validatePrerequisites(Course_Registeration_Stack& stack1, string completedCourses[], int completedCount) {
        for (int i = 0; i < completedCount; i++) {
            if (!stack1.isEmpty() && stack1.top->course->CourseID == completedCourses[i]) {
                stack1.pop(); // Pop the course if it matches a completed course
            }
        }
        return stack1.isEmpty(); // If the stack is empty, all prerequisites are met
    }
};

class queuewaitlist {
private:
    int maxs;
    string* list;
    int qfront;
    int qrear;
    int count;
public:
    queuewaitlist() {
        maxs = 100;
        qfront = 0;
        qrear = maxs - 1;
        list = new string[maxs];
        count = 0;
    }
    bool isempty() {
        return count == 0;
    }
    bool isfull() {
        return count == maxs;
    }
    void enqueue(string studentid) {
        if (isfull()) {
            cout << "Waitlist is full." << endl;
        }
        else {
            qrear = (qrear + 1) % maxs;
            list[qrear] = studentid;
            count++;
        }
    }
    string dequeue() {
        if (isempty()) {
            cout << "Waitlist is empty." << endl;
        }
        else {
            string studentid = list[qfront];
            qfront = (qfront + 1) % maxs;
            count--;
            return studentid;
        }
    }
};

class HashTable {
private:
    static const int TABLE_SIZE = 10; // Size of hash table (adjustable)
    struct HashNode {
        Courses* course;
        HashNode* next;
        HashNode(Courses* c) : course(c), next(nullptr) {}
    };
    HashNode* table[TABLE_SIZE];

    // Hash function to map CourseID to an index
    int hashFunction(string courseID) {
        int hash = 0;
        for (char c : courseID) {
            hash += c; // Sum ASCII values of characters
        }
        return hash % TABLE_SIZE; // Modulo operation to keep index within range
    }

public:
    // Constructor to initialize the hash table
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    // Insert a course into the hash table
    void insert(Courses* course) {
        int index = hashFunction(course->CourseID);
        HashNode* newNode = new HashNode(course);

        if (table[index] == nullptr) {
            table[index] = newNode; // Insert if slot is empty
        }
        else {
            // Collision: use chaining
            HashNode* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "Course " << course->CourseID << " inserted into hash table.\n";
    }

    // Search for a course by CourseID
    Courses* search(string courseID) {
        int index = hashFunction(courseID);
        HashNode* current = table[index];

        while (current != nullptr) {
            if (current->course->CourseID == courseID) {
                return current->course; // Found
            }
            current = current->next;
        }
        return nullptr; // Not found
    }

    // Display all courses in the hash table
    void displayHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            HashNode* current = table[i];
            if (current == nullptr) {
                cout << "Empty\n";
            }
            else {
                while (current != nullptr) {
                    cout << current->course->CourseID << " -> ";
                    current = current->next;
                }
                cout << "NULL\n";
            }
        }
    }
};

int main() {
    StudentRecords studentRecords;
    Binary_search_tree courseTree;
    Enrollment_History_DLL enrollmentHistory;
    Course_Registeration_Stack prereqStack;
    queuewaitlist waitlist;
    HashTable courseHashTable;

    int choice;
    string id, name, email, phone, address, password, courseID, courseName, instructor;
    int courseCredits;
    string completedCourses[10];
    int completedCount;

    // Declare courseToEnroll outside the switch statement
    Courses* courseToEnroll = nullptr;

    do {
        cout << "\n*** Main Menu ***" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display All Students" << endl;
        cout << "4. Search Student by ID (Linear Search)" << endl;
        cout << "5. Search Student by ID (Binary Search)" << endl;
        cout << "6. Search course by ID  (Linear Search)" << endl;
        cout << "7. Add Course" << endl;
        cout << "8. Display All Courses" << endl;
        cout << "9. Search Course by ID" << endl;
        cout << "10. Add Enrollment" << endl;
        cout << "11. View Enrollment History" << endl;
        cout << "12. Register for Course (with Prerequisites)" << endl;
        cout << "13. Add to Waitlist" << endl;
        cout << "14. Display Waitlist" << endl;
        cout << "15. Insert Course into Hash Table" << endl;
        cout << "16. Display Hash Table" << endl;
        cout << "17. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: // Add Student
            cout << "Enter Student ID: "; cin >> id;
            cout << "Enter Name: "; cin >> name;
            cout << "Enter Email: "; cin >> email;
            cout << "Enter Phone: "; cin >> phone;
            cout << "Enter Address: "; cin >> address;
            cout << "Enter Password: "; cin >> password;
            studentRecords.add_function(id, name, email, phone, address, password);
            break;

        case 2: // Delete Student
            cout << "Enter Student ID to delete: "; cin >> id;
            studentRecords.deleteStudent(id);
            break;

        case 3: // Display All Students
            studentRecords.display();
            break;

        case 4: // Search Student by ID (Linear Search)
            cout << "Enter Student ID to search: "; cin >> id;
            studentRecords.linearSearchStudentByID(id);
            break;

        case 5: // Search Student by ID (Binary Search)
            cout << "Enter Student ID to search: "; cin >> id;
            studentRecords.binarySearchStudentByID(id);
            break;
        case 6: // Search Course by ID (Linear Search)
        cout << "Enter Course ID to search: ";cin >> id;
        enrollmentHistory.linearSearchCourseByID(id); break;


        case 7: // Add Course
            cout << "Enter Course ID: "; cin >> courseID;
            cout << "Enter Course Name: "; cin >> courseName;
            cout << "Enter Course Instructor: "; cin >> instructor;
            cout << "Enter Course Credits: "; cin >> courseCredits;
            courseTree.add_course(courseID, courseName, courseCredits, instructor);
            break;

        case 8: // Display All Courses
            courseTree.displayCoursesRecursive(courseTree.root);
            break;

        case 9: // Search Course by ID
            cout << "Enter Course ID to search: "; cin >> courseID;
            if (courseTree.searchCourse(courseTree.root, courseID)) {
                cout << "Course found!" << endl;
            }
            else {
                cout << "Course not found." << endl;
            }
            break;

        case 10: // Add Enrollment
            cout << "Enter Course ID to enroll: "; cin >> courseID;
            courseToEnroll = new Courses(courseID, courseName, instructor, courseCredits); // Now this line is outside the case block
            enrollmentHistory.addEnrollment(courseToEnroll);
            break;

        case 11: // View Enrollment History
            enrollmentHistory.viewEnrollment();
            break;

        case 12: // Register for Course with Prerequisites
    cout << "Enter Course ID to register: ";
    cin >> courseID;

    // Prompt for prerequisites dynamically
    cout << "Enter the number of prerequisites: ";
    int prereqCount;
    cin >> prereqCount;

    Course_Registeration_Stack prereqStack;
    cout << "Enter the prerequisite course IDs:\n";
    for (int i = 0; i < prereqCount; i++) {
        string prereqID, prereqName, prereqInstructor;
        int prereqCredits;
        cout << "Prerequisite Course ID: ";
        cin >> prereqID;
        cout << "Prerequisite Course Name: ";
        cin >> prereqName;
        cout << "Prerequisite Instructor: ";
        cin >> prereqInstructor;
        cout << "Prerequisite Credits: ";
        cin >> prereqCredits;

        Courses* prereqCourse = new Courses(prereqID, prereqName, prereqInstructor, prereqCredits);
        prereqStack.push(prereqCourse); // Push each prerequisite into the stack
    }

    cout << "Enter the number of completed courses: ";
    cin >> completedCount;
    string completedCourses[completedCount];
    for (int i = 0; i < completedCount; i++) {
        cout << "Enter completed course ID: ";
        cin >> completedCourses[i];
    }

    if (prereqStack.validatePrerequisites(prereqStack, completedCourses, completedCount)) {
        cout << "All prerequisites met! Registered for course " << courseID << endl;
    } else {
        cout << "Prerequisites not met!" << endl;
    }
    break;

        case 13: // Add to Waitlist
            cout << "Enter Student ID to add to waitlist: "; cin >> id;
            waitlist.enqueue(id);
            break;

        case 14: // Display Waitlist
            cout << "Waitlist: " << endl;
            while (!waitlist.isempty()) {
                cout << "Student ID: " << waitlist.dequeue() << endl;
            }
            break;

        case 15: // Insert Course into Hash Table
            cout << "Enter Course ID: "; cin >> courseID;
            cout << "Enter Course Name: "; cin >> courseName;
            cout << "Enter Course Instructor: "; cin >> instructor;
            cout << "Enter Course Credits: "; cin >> courseCredits;
            courseHashTable.insert(new Courses(courseID, courseName, instructor, courseCredits));
            break;

        case 16: // Display Hash Table
            courseHashTable.displayHashTable();
            break;

        case 17: // Exit
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 17);

    return 0;
}
