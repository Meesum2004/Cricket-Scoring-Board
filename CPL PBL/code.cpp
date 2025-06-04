#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Batsman {
    string name;
    int ones, twos, threes, fours, sixes;
    int balls;
    int runs;
    float sr;
};

struct Bowler {
    string name;
    int runsGiven;
    int overs;
    int wickets;
    float econ;
};

Batsman batsmen[100];
Bowler bowlers[100];
int batsmanCount = 0, bowlerCount = 0;

void calculateBatsmanStats(int i) {
    batsmen[i].runs = batsmen[i].ones * 1 + batsmen[i].twos * 2 + batsmen[i].threes * 3 +
                      batsmen[i].fours * 4 + batsmen[i].sixes * 6;
    batsmen[i].sr = (batsmen[i].balls != 0) ? (batsmen[i].runs * 100.0f / batsmen[i].balls) : 0;
}

void calculateBowlerStats(int i) {
    bowlers[i].econ = (bowlers[i].overs != 0) ? (bowlers[i].runsGiven * 1.0f / bowlers[i].overs) : 0;
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

int findBatsmanIndex(string name) {
    for (int i = 0; i < batsmanCount; i++) {
        if (batsmen[i].name == name) return i;
    }
    return -1;
}

int findBowlerIndex(string name) {
    for (int i = 0; i < bowlerCount; i++) {
        if (bowlers[i].name == name) return i;
    }
    return -1;
}

void updateBatsman() {
    string name;
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
    string name;
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
    string name;
    cout << "Enter batsman name to delete: ";
    cin >> name;
    int idx = findBatsmanIndex(name);
    if (idx == -1) {
        cout << "Batsman not found.\n";
        return;
    }
    for (int i = idx; i < batsmanCount - 1; i++) {
        batsmen[i] = batsmen[i + 1];
    }
    batsmanCount--;
    cout << "Batsman deleted.\n";
}

void deleteBowler() {
    string name;
    cout << "Enter bowler name to delete: ";
    cin >> name;
    int idx = findBowlerIndex(name);
    if (idx == -1) {
        cout << "Bowler not found.\n";
        return;
    }
    for (int i = idx; i < bowlerCount - 1; i++) {
        bowlers[i] = bowlers[i + 1];
    }
    bowlerCount--;
    cout << "Bowler deleted.\n";
}

void viewBatsmen() {
    cout << "\nBatsmen List:\n";
    cout << "Name\tRuns\tBalls\tFours\tSixes\tSR\n";
    for (int i = 0; i < batsmanCount; i++) {
        cout << batsmen[i].name << "\t"
             << batsmen[i].runs << "\t"
             << batsmen[i].balls << "\t"
             << batsmen[i].fours << "\t"
             << batsmen[i].sixes << "\t"
             << batsmen[i].sr << "\n";
    }
}

void viewBowlers() {
    cout << "\nBowlers List:\n";
    cout << "Name\tRunsGiven\tOvers\tWickets\tEconomy\n";
    for (int i = 0; i < bowlerCount; i++) {
        cout << bowlers[i].name << "\t"
             << bowlers[i].runsGiven << "\t\t"
             << bowlers[i].overs << "\t"
             << bowlers[i].wickets << "\t"
             << bowlers[i].econ << "\n";
    }
}

void saveToFile() {
    ofstream fout("summary.txt");
    fout << "Batsmen:\n";
    fout << "Name\tRuns\tBalls\tFours\tSixes\tSR\n";
    for (int i = 0; i < batsmanCount; i++) {
        fout << batsmen[i].name << "\t"
             << batsmen[i].runs << "\t"
             << batsmen[i].balls << "\t"
             << batsmen[i].fours << "\t"
             << batsmen[i].sixes << "\t"
             << batsmen[i].sr << "\n";
    }

    fout << "\nBowlers:\n";
    fout << "Name\tRunsGiven\tOvers\tWickets\tEconomy\n";
    for (int i = 0; i < bowlerCount; i++) {
        fout << bowlers[i].name << "\t"
             << bowlers[i].runsGiven << "\t\t"
             << bowlers[i].overs << "\t"
             << bowlers[i].wickets << "\t"
             << bowlers[i].econ << "\n";
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
