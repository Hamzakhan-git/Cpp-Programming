#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Room {
private:
    int roomNumber;
    int capacity;
    int currentOccupancy;
    string hostelName;

public:
    Room(int number, int cap, string hostel) : roomNumber(number), capacity(cap), currentOccupancy(0), hostelName(hostel) {}

    int getRoomNumber() const {
        return roomNumber;
    }

    int getCapacity() const {
        return capacity;
    }

    int getCurrentOccupancy() const {
        return currentOccupancy;
    }

    string getHostelName() const {
        return hostelName;
    }

    bool isFull() const {
        return currentOccupancy >= capacity;
    }

    void addOccupant() {
        if (currentOccupancy < capacity) {
            currentOccupancy++;
        }
    }
};

class Student {
private:
    string name;
    int age;
    string enrollment_Number;
    int year;
    Room* allottedRoom;

public:
    Student(string n, int a, string r, int y) : name(n), age(a), enrollment_Number(r), year(y), allottedRoom(nullptr) {
        if (a < 16 || a > 35) {
            throw invalid_argument("Age must be between 16 and 35.");
        }
    }

    string getName() const {
        return name;
    }

    string getenrollment_Number() const {
        return enrollment_Number;
    }

    int getYear() const {
        return year;
    }

    Room* getAllottedRoom() const {
        return allottedRoom;
    }

    void allotRoom(Room* room) {
        allottedRoom = room;
        room->addOccupant();
    }
};

class Hostel {
private:
    vector<Room> rooms;

public:
    vector<Student> students;
    void addRoom(int number, int capacity, string hostelName) {
        rooms.push_back(Room(number, capacity, hostelName));
    }

    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void allotRoom(string enrollment_Number, int chosenRoomNumber, string chosenHostelName) {
        for (auto& student : students) {
            if (student.getenrollment_Number() == enrollment_Number) {
                for (auto& room : rooms) {
                    if (room.getRoomNumber() == chosenRoomNumber && room.getHostelName() == chosenHostelName && !room.isFull()) {
                        student.allotRoom(&room);
                        cout << "Room " << room.getRoomNumber() << " in " << room.getHostelName() << " allotted to " << student.getName() << endl;
                        return;
                    }
                }
                cout << "No available rooms in " << chosenHostelName << " for " << student.getName() << endl;
                return;
            }
        }
        cout << "Student with enrollment_ number " << enrollment_Number << " not found" << endl;
    }

    void displayAllotment() const {
        for (const auto& student : students) {
            cout << "Student_Name: " << student.getName() << ", enrollment_ Number: " << student.getenrollment_Number() << ", Year: " << student.getYear();
            if (student.getAllottedRoom() != nullptr) {
                cout << ", Room Number: " << student.getAllottedRoom()->getRoomNumber() << " in " << student.getAllottedRoom()->getHostelName() << endl;
            } else {
                cout << ", No room allotted" << endl;
            }
        }
    }

    void applyChanges(string enrollment_Number, string newName, int newAge, int newYear) {
        for (auto& student : students) {
            if (student.getenrollment_Number() == enrollment_Number) {
                student = Student(newName, newAge, enrollment_Number, newYear);
                cout << "Details updated for enrollment_ number " << enrollment_Number << endl;
                return;
            }
        }
        cout << "Student with enrollment_ number " << enrollment_Number << " not found" << endl;
    }
};

int main() {
    Hostel hostel;
    int totalRoomsPerHostel = 50;

    // Adding hostels and their rooms with specific capacities
    for (int i = 1; i <= totalRoomsPerHostel; ++i) {
        if (i <= 50) {
            hostel.addRoom(i, 4, "HM");
            hostel.addRoom(i, 4, "JK");
            hostel.addRoom(i, 4, "MB");
        }
        if (i <= 50) {
            hostel.addRoom(i, 2, "BH");
            hostel.addRoom(i, 2, "AK");
        }
        if (i <= 50) {
            hostel.addRoom(i, 1, "KH");
            hostel.addRoom(i, 1, "QW");
        }
    }

    int numberOfStudents;
    cout << "Enter the number of students: ";
    cin >> numberOfStudents;

    for (int i = 0; i < numberOfStudents; ++i) {
        string name;
        int age;
        string enrollment_Number;
        int year;

        cout << "Enter details for student " << (i + 1) << ":" << endl;
        cout << "Name: ";
        cin >> ws; // To consume any leading whitespace
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cout << "enrollment_ Number: ";
        cin >> enrollment_Number;
        cout << "Year: ";
        cin >> year;

        try {
            Student student(name, age, enrollment_Number, year);
            hostel.addStudent(student);
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
            continue; // Move to the next student
        }
    }

    for (int i = 0; i < numberOfStudents; ++i) {
        string enrollment_Number;
        int chosenRoomNumber;
        string chosenHostelName;

        cout << "Enter enrollment_ number to allot room: ";
        cin >> enrollment_Number;

        // Find the student's year
        int studentYear = -1;
        for (const auto& student : hostel.students) {
            if (student.getenrollment_Number() == enrollment_Number) {
                studentYear = student.getYear();
                break;
            }
        }

        // Validate the student's year and ask for the room number and hostel name accordingly
        if (studentYear == 1 || studentYear == 2) {
            cout << "Enter room number to allot: ";
            cin >> chosenRoomNumber;
            cout << "Enter hostel name to allot (HM, JK, MB): ";
            cin >> chosenHostelName;
        } else if (studentYear == 3) {
            cout << "Enter room number to allot: ";
            cin >> chosenRoomNumber;
            cout << "Enter hostel name to allot (BH, AK): ";
            cin >> chosenHostelName;
        } else if (studentYear == 4) {
            cout << "Enter room number to allot: ";
            cin >> chosenRoomNumber;
            cout << "Enter hostel name to allot (KH, QW): ";
            cin >> chosenHostelName;
        } else {
            cout << "Invalid year for student with enrollment_ number " << enrollment_Number << endl;
            continue;
        }

        hostel.allotRoom(enrollment_Number, chosenRoomNumber, chosenHostelName);
    }

    cout << "\nFinal Room Allotments:\n";
    hostel.displayAllotment();

    return 0;
}
