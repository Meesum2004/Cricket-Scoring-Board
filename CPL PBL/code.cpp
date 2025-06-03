#include <iostream>
#include <fstream>
#include <iomanip> // input/output formatting ko control karte hain
#include <cstring> // C-style strings (character arrays) strcmp(str1, str2)
using namespace std;

struct Batsman {
    char name[25];
    int ones, twos, threes, fours, sixes;
    int balls;
    int runs;
    float sr;
} ;
Batsman batsmen[100];
struct Bowler {
    char name[25];
    int runsGiven;
    int overs;
    int wickets;
    float econ;
}; 

Bowler bowlers[100];

int batsmanCount = 0, bowlerCount = 0;

void calculateBatsmanStats(int i) {
    batsmen[i].runs = batsmen[i].ones * 1 + batsmen[i].twos * 2 + batsmen[i].threes * 3 +
                      batsmen[i].fours * 4 + batsmen[i].sixes * 6;
    batsmen[i].sr = (batsmen[i].balls != 0) ? (batsmen[i].runs * 100.0f / batsmen[i].balls) : 0;
    // 100.0f se float multiplication hota hai taake decimal bhi accurate aaye.
}

void calculateBowlerStats(int i) {
    bowlers[i].econ = (bowlers[i].overs != 0) ? (bowlers[i].runsGiven * 1.0f / bowlers[i].overs) : 0;
    //1.0f float type ka number hai taake decimal division ho (float division).
}

void addBatsman() {
    if (batsmanCount >= 100) {
        cout << "Maximum batsmen reached!\n";
        return;
    }
    cout << "Enter name of new batsman: ";
    cin >> batsmen[batsmanCount].name;
    cout << "Enter ones: "; cin >> batsmen[batsmanCount].ones;
    cout << "Enter twos: "; cin >> batsmen[batsmanCount].twos;
    cout << "Enter threes: "; cin >> batsmen[batsmanCount].threes;
    cout << "Enter fours: "; cin >> batsmen[batsmanCount].fours;
    cout << "Enter sixes: "; cin >> batsmen[batsmanCount].sixes;
    cout << "Enter balls played: "; cin >> batsmen[batsmanCount].balls;

    calculateBatsmanStats(batsmanCount);
    batsmanCount++;
    cout << "Batsman added.\n";
}

void addBowler() {
    if (bowlerCount >= 100) {
        cout << "Maximum bowlers reached!\n";
        return;
    }
    cout << "Enter name of new bowler: ";
    cin >> bowlers[bowlerCount].name;
    cout << "Enter runs given: "; cin >> bowlers[bowlerCount].runsGiven;
    cout << "Enter overs bowled: "; cin >> bowlers[bowlerCount].overs;
    cout << "Enter wickets taken: "; cin >> bowlers[bowlerCount].wickets;

    calculateBowlerStats(bowlerCount);
    bowlerCount++;
    cout << "Bowler added.\n";
}   

// batsmen[i].name jo array ke current batsman ka naam hai,aur name jo input parameter hai.
int findBatsmanIndex(const char* name) {
    for (int i = 0; i < batsmanCount; i++) {
        if (strcmp(batsmen[i].name, name) == 0) return i;
    }
    return -1;
}

int findBowlerIndex(const char* name) {
    for (int i = 0; i < bowlerCount; i++) {
        if (strcmp(bowlers[i].name, name) == 0) return i;
    }
    return -1;
}

void updateBatsman() {
    char name[25];
    cout << "Enter batsman name to update: ";
    cin >> name;
    int idx = findBatsmanIndex(name);
    if (idx == -1) {
        cout << "Batsman not found.\n";
        return;
    }
    cout << "Enter updated ones: "; cin >> batsmen[idx].ones;
    cout << "Enter updated twos: "; cin >> batsmen[idx].twos;
    cout << "Enter updated threes: "; cin >> batsmen[idx].threes;
    cout << "Enter updated fours: "; cin >> batsmen[idx].fours;
    cout << "Enter updated sixes: "; cin >> batsmen[idx].sixes;
    cout << "Enter updated balls: "; cin >> batsmen[idx].balls;

    calculateBatsmanStats(idx);
    cout << "Batsman updated.\n";
}

void updateBowler() {
    char name[25];
    cout << "Enter bowler name to update: ";
    cin >> name;
    int idx = findBowlerIndex(name);
    if (idx == -1) {
        cout << "Bowler not found.\n";
        return;
    }
    cout << "Enter updated runs given: "; cin >> bowlers[idx].runsGiven;
    cout << "Enter updated overs bowled: "; cin >> bowlers[idx].overs;
    cout << "Enter updated wickets taken: "; cin >> bowlers[idx].wickets;

    calculateBowlerStats(idx);
    cout << "Bowler updated.\n";
}

void deleteBatsman() {
    char name[25];
    cout << "Enter batsman name to delete: ";
    cin >> name;
    int idx = findBatsmanIndex(name);
    if (idx == -1) {
        cout << "Batsman not found.\n";
        return;
    }
    // Shift all batsmen after idx one position left
    for (int i = idx; i < batsmanCount - 1; i++) {
        batsmen[i] = batsmen[i + 1];
    }
    batsmanCount--;
    cout << "Batsman deleted.\n";
}

void deleteBowler() {
    char name[25];
    cout << "Enter bowler name to delete: ";
    cin >> name;
    int idx = findBowlerIndex(name);
    if (idx == -1) {
        cout << "Bowler not found.\n";
        return;
    }
    // Shift all bowlers after idx one position left
    for (int i = idx; i < bowlerCount - 1; i++) {
        bowlers[i] = bowlers[i + 1];
    }
    bowlerCount--;
    cout << "Bowler deleted.\n";
}

void viewBatsmen() {
    cout << "\nBatsmen List:\n";
    cout << "Name           Runs  Balls  Fours  Sixes  SR\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < batsmanCount; i++) {
        cout << setw(15) << left << batsmen[i].name
             << setw(6) << batsmen[i].runs
             << setw(7) << batsmen[i].balls
             << setw(7) << batsmen[i].fours
             << setw(7) << batsmen[i].sixes
             << fixed << setprecision(2) << batsmen[i].sr << "\n";
    }
    cout << "\n";
}

void viewBowlers() {
    cout << "\nBowlers List:\n";
    cout << "Name           RunsGiven  Overs  Wickets  Economy\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < bowlerCount; i++) {
        cout << setw(15) << left << bowlers[i].name
             << setw(11) << bowlers[i].runsGiven
             << setw(7) << bowlers[i].overs
             << setw(9) << bowlers[i].wickets
             << fixed << setprecision(2) << bowlers[i].econ << "\n";
    }
    cout << "\n";
}

void saveToFile() {
    ofstream fout("summary.txt");
    fout << "Batsmen:\n";
    fout << "Name           Runs  Balls  Fours  Sixes  SR\n";
    fout << "---------------------------------------------\n";
    for (int i = 0; i < batsmanCount; i++) {
        fout << setw(15) << left << batsmen[i].name
             << setw(6) << batsmen[i].runs
             << setw(7) << batsmen[i].balls
             << setw(7) << batsmen[i].fours
             << setw(7) << batsmen[i].sixes
             << fixed << setprecision(2) << batsmen[i].sr << "\n";
    }

    fout << "\nBowlers:\n";
    fout << "Name           RunsGiven  Overs  Wickets  Economy\n";
    fout << "------------------------------------------------\n";
    for (int i = 0; i < bowlerCount; i++) {
        fout << setw(15) << left << bowlers[i].name
             << setw(11) << bowlers[i].runsGiven
             << setw(7) << bowlers[i].overs
             << setw(9) << bowlers[i].wickets
             << fixed << setprecision(2) << bowlers[i].econ << "\n";
    }
    fout.close();
    cout << "Data saved to summary.txt\n";
}

int main() {
    int choice;
    cout << "Welcome to Simple Cricket Scoring Program!\n";

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Batsman\n2. Add Bowler\n3. Update Batsman\n4. Update Bowler\n";
        cout << "5. Delete Batsman\n6. Delete Bowler\n7. View Batsmen\n8. View Bowlers\n";
        cout << "9. Save to File\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBatsman(); break;
            case 2: addBowler(); break;
            case 3: updateBatsman(); break;
            case 4: updateBowler(); break;
            case 5: deleteBatsman(); break;
            case 6: deleteBowler(); break;
            case 7: viewBatsmen(); break;
            case 8: viewBowlers(); break;
            case 9: saveToFile(); break;
            case 10: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice, try again.\n";
        }
    }
    return 0;
}
