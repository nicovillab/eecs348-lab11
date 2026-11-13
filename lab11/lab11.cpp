// EECS 348 Lab 11: Debugging and Testing
// Answers to Q1-Q5 are in ANSWERS.md

#include <iostream>  // console output
#include <string>    // string type
#include <vector>    // vector type

using namespace std;  // skip std::

// Function under test (from handout)
bool fail_lecture(const vector<int>& attendance_records) {  // faulty checker
    int absent_count = 0;  // absence counter
    for (int i = 1; i < attendance_records.size(); ++i) {  // FAULT: skips index 0
        absent_count += attendance_records[i] == 0;  // count absences
    }  // end loop
    return absent_count >= 3;  // fail threshold
}  // end function

int faulty_absent_count(const vector<int>& attendance_records) {  // faulty count
    int absent_count = 0;  // absence counter
    for (int i = 1; i < attendance_records.size(); ++i) {  // same fault
        absent_count += attendance_records[i] == 0;  // count absences
    }  // end loop
    return absent_count;  // actual count
}  // end function

int correct_absent_count(const vector<int>& attendance_records) {  // reference count
    int absent_count = 0;  // absence counter
    for (int i = 0; i < attendance_records.size(); ++i) {  // starts correctly
        absent_count += attendance_records[i] == 0;  // count absences
    }  // end loop
    return absent_count;  // expected count
}  // end function

string bool_str(bool b) { return b ? "true (fails course)" : "false (passes course)"; }  // readable bool

void run_test(const string& name, const vector<int>& record) {  // run one test
    int expected_count = correct_absent_count(record);  // expected count
    int actual_count   = faulty_absent_count(record);  // actual count
    bool expected_out  = expected_count >= 3;  // expected output
    bool actual_out    = fail_lecture(record);  // actual output

    cout << "==== " << name << " ====\n";  // test header
    cout << "Attendance record:      [";  // record label
    for (size_t i = 0; i < record.size(); ++i) {  // each lecture
        cout << record[i] << (i + 1 < record.size() ? ", " : "");  // print value
    }  // end loop
    cout << "]\n";  // close bracket
    cout << "Expected absence count: " << expected_count << "\n";  // print expected
    cout << "Actual absence count:   " << actual_count << "\n";  // print actual
    cout << "Expected output:        " << bool_str(expected_out) << "\n";  // print expected
    cout << "Actual output:          " << bool_str(actual_out) << "\n";  // print actual
    cout << "Error state (wrong internal count): " << (expected_count != actual_count ? "YES" : "no") << "\n";  // error check
    cout << "Failure (output differs): " << (expected_out != actual_out ? "YES" : "no") << "\n\n";  // failure check
}  // end function

int main() {  // program entry
    cout << "Q2: impossible, the faulty statement (int i = 1) runs on every call.\n";  // Q2 answer
    cout << "Q3: impossible, executing int i = 1 immediately gives the wrong state (i = 1 instead of 0).\n\n";  // Q3 answer

    run_test("Q4: error state, no failure", {0, 0, 0, 0, 1, 1, 1, 1, 1, 1});  // Q4 test
    run_test("Q5: failure", {0, 0, 0, 1, 1, 1, 1, 1, 1, 1});  // Q5 test

    return 0;  // exit success
}  // end main
