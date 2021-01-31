#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

int print_menu() {
    int choice;
    cout << "1. Load problem" << endl;
    cout << "2. Load solution" << endl;
    cout << "3. Solve problem" << endl;
    cout << "4. Solve all" << endl;
    cout << "5. Exit" << endl;
    cout << "Select: ";
    cin >> choice;
    return choice;
}

int print_problems() {
    int choice;
    cout << "1. car-f-92" << endl;
    cout << "2. car-s-91" << endl;
    cout << "3. ear-f-83" << endl;
    cout << "4. hec-s-92" << endl;
    cout << "5. kfu-s-93" << endl;
    cout << "6. lse-f-91" << endl;
    cout << "7. pur-s-93" << endl;
    cout << "8. rye-s-93" << endl;
    cout << "9. sta-f-83" << endl;
    cout << "10. tre-s-92" << endl;
    cout << "11. uta-s-92" << endl;
    cout << "12. ute-s-92" << endl;
    cout << "13. yor-f-83" << endl;
    cout << "Select the problem: ";
    cin >> choice;
    return choice;
}

int count_common_elements(set<int> s1, set<int> s2) {
    int c = 0;
    for (int x : s1) // range based for
    {
        for (int y : s2) {
            if (x == y) {
                c++;
                break;
            }
        }
    }
    return c;
}

void read_data(string fn, int students, int exams) {

    vector<set<int>> exam_students(exams + 1); // διάνυσμα που περιέχει sets
    fstream fs(fn);
    if (!fs.is_open()) {
        cerr << "Could not open file " << fn << std::endl;
        exit(-1);
    }
    int student_id = 0;
    string line;
    while (getline(fs, line))  // παιρνει συνεχομενα γραμμες απο το αρχειο
    {
        if (line.empty())
            continue;
        student_id++;             // αριθμος γραμμων = αριθμος μαθητων
        istringstream iss(line); 
		int exam_id;
        while (iss >> exam_id)  
        {
            exam_students[exam_id].insert(
                    student_id);
        }
    }
    fs.close();

    cout << "#################################" << endl;

//    for (int i = 1; i <= exams; i++) {
//        cout << "Exam " << i << " Enrolled students: ";
//        for (int student_id : exam_students[i]) 
//        {
//            cout << student_id << " ";
//        }
//        cout << endl;
//    }

 //   cout << "Adjacency Matrix" << endl;
    int *adj_matrix = new int[exams * exams];
    for (int i = 0; i < exams; i++) {
        for (int j = 0; j < exams; j++) {
            if (i == j) {
                adj_matrix[i * exams + j] = 0; // adj_matrix[i][j]
                continue;
            }
            int c = count_common_elements(exam_students[i + 1], exam_students[j + 1]);
//            if (c > 0) {
//                cout << i + 1 << " " << j + 1 << " " << c << endl;
//            }
            adj_matrix[i * exams + j] = c;
        }
    }

    int c = 0;
    for (int i = 0; i < exams; i++) {
        for (int j = 0; j < exams; j++) {
            if (adj_matrix[i * exams + j] > 0) {
                c++;
            }
        }
    }

    double cd = double(c) / double(exams * exams);
    cout << "Conflict Density: " << cd << endl;

    int max = 0;
    for (int i = 0; i < exams; i++) {
        int d = 0;
        for (int j = 0; j < exams; j++) {
            if (adj_matrix[i * exams + j] > 0) {
                d++;
            }
        }
        if (d > max) {
            max = d;
        }
    }

    cout << "Degree Max: " << max << endl;

    delete[] adj_matrix;
}


void read_solved_probs(string fn) {
    fstream fs(fn);
    if (!fs.is_open()) {
        cerr << "Could not open file " << fn << std::endl;
        exit(-1);
    }
}

int main() {
    while (true) {
        int sel = print_menu();

        switch (sel) {
            case 1: {
                int prob = print_problems();
                int students, exams;
                cout << "Give the num of students: ";
                cin >> students;
                cout << "Give the num of exams: ";
                cin >> exams;
                switch (prob) {
                    case 1:
                        read_data("datasheets/car-f-92.stu", students, exams);
                        break;
                    case 2:
                        read_data("datasheets/car-s-91.stu", students, exams);
                        break;
                    case 3:
                        read_data("datasheets/ear-f-83.stu", students, exams);
                        break;
                    case 4:
                        read_data("datasheets/hec-s-92.stu", students, exams);
                        break;
                    case 5:
                        read_data("datasheets/kfu-s-93.stu", students, exams);
                        break;
                    case 6:
                        read_data("datasheets/lse-f-91.stu", students, exams);
                        break;
                    case 7:
                        read_data("datasheets/pur-s-93.stu", students, exams);
                        break;
                    case 8:
                        read_data("datasheets/rye-s-93.stu", students, exams);
                        break;
                    case 9:
                        read_data("datasheets/sta-f-83.stu", students, exams);
                        break;
                    case 10:
                        read_data("datasheets/tre-s-92.stu", students, exams);
                        break;
                    case 11:
                        read_data("datasheets/uta-s-92.stu", students, exams);
                        break;
                    case 12:
                        read_data("datasheets/ute-s-92.stu", students, exams);
                        break;
                    case 13:
                        read_data("datasheets/yor-f-83.stu", students, exams);
                        break;
                    default:
                        exit(0);
                }
                break;
            }
            case 2: {
                int sol = print_problems();
                switch (sol) {
                    case 1:
                        read_solved_probs("datasheets/solutions/car-f-92(3.71).sol");
                        break;
                    case 2:
                        read_solved_probs("datasheets/solutions/car-s-91(4.39).sol");
                        break;
                    case 3:
                        read_solved_probs("datasheets/solutions/ear-f-83(32.63).sol");
                        break;
                    case 4:
                        read_solved_probs("datasheets/solutions/hec-s-92(10.04).sol");
                        break;
                    case 5:
                        read_solved_probs("datasheets/solutions/kfu-s-93(12.90).sol");
                        break;
                    case 6:
                        read_solved_probs("datasheets/solutions/lse-f-91(9.82).sol");
                        break;
                    case 7:
                        read_solved_probs("datasheets/solutions/pur-s-93(4,49).sol");
                        break;
                    case 8:
                        read_solved_probs("datasheets/solutions/rye-s-93(7.93).sol");
                        break;
                    case 9:
                        read_solved_probs("datasheets/solutions/sta-f-83(157.03).sol");
                        break;
                    case 10:
                        read_solved_probs("datasheets/solutions/tre-s-92(7.72).sol");
                        break;
                    case 11:
                        read_solved_probs("datasheets/solutions/uta-s-92(3.04).sol");
                        break;
                    case 12:
                        read_solved_probs("datasheets/solutions/ute-s-92(24.77).sol");
                        break;
                    case 13:
                        read_solved_probs("datasheets/solutions/yor-f-83(34.71).sol");
                        break;
                    default:
                        exit(0);
                }
                break;
            }
            case 3:
                break;
            case 4:
                break;
            case 5:
                exit(0);
            default:
                exit(0);
        }
    }
}

