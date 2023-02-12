#include <iostream>
#include <cstring>
#include <numeric>
#include <math.h>
#include <algorithm>
using namespace std;
void printStudent( struct Students student );\
int findMaxScore(struct Students student[], char maxName[]);\
int findMinScore( struct Students student[] , char minName[]);\
double findAverageScore( struct Students student[] );\
int findModeScore( struct Students student[] );\
double findMedianScore(struct Students student[]);\
double findSDScore(struct Students student[]);\
void findGrade(struct Students student[]);\

struct Students{
    char name[50];
    int score;
    char grade[1];
};

int main( ){
        struct Students student[10];
        char maxName[50];
        char minName[50];
        //add data
        strcpy( student[0].name, "Jay"); student[0].score = 95;
        strcpy( student[1].name, "Mary"); student[1].score = 90;
        strcpy( student[2].name, "John"); student[2].score = 65;
        strcpy( student[3].name, "Mike"); student[3].score = 59;
        strcpy( student[4].name, "Oscar"); student[4].score = 59;
        strcpy( student[5].name, "Lily"); student[5].score = 79;
        strcpy( student[6].name, "Zoe"); student[6].score = 60;
        strcpy( student[7].name, "Tom"); student[7].score = 55;
        strcpy( student[8].name, "Jerry"); student[8].score = 23;
        strcpy( student[9].name, "Mickey"); student[9].score = 86;
        //find grade
        findGrade(student);
        //print
        printStudent( student[0] ); printStudent( student[1] );
        printStudent( student[2] ); printStudent( student[3] );
        printStudent( student[4] ); printStudent( student[5] );
        printStudent( student[6] ); printStudent( student[7] );
        printStudent( student[8] ); printStudent( student[9] );
        cout << "==========================" << endl;
        int maxScore = findMaxScore(student, maxName);
        int minScore = findMinScore(student, minName);
        cout << "Max score is " << maxScore << " by " << maxName << endl;
        cout << "Min score is " << minScore << " by " << minName << endl;
        cout << "Average score is " << findAverageScore(student) << endl;
        cout << "Mode score: " << findModeScore( student ) << endl;
        cout << "Median score: " << findMedianScore(student) << endl;
        cout << "Standard deviation score: " << findSDScore(student) << endl;

        
    return 0;
}
void printStudent( struct Students student ){
    cout << "Name :" << student.name ;
    cout << ", Score :" << student.score;
    cout << ", Grade :" << student.grade <<endl;
}
int findMaxScore(struct Students student[], char maxName[]) {
  int max = 0;
  for (int i = 0; i < 10; i++) {
    if (student[i].score > max) {
      max = student[i].score;
      strcpy(maxName, student[i].name);
    }
  }
  return max;
}

int findMinScore(struct Students student[], char minName[]) {
  int min = 100;
  for (int i = 0; i < 10; i++) {
    if (student[i].score < min) {
      min = student[i].score;
      strcpy(minName, student[i].name);
    }
  }
  return min;
}


double findAverageScore( struct Students student[] ){
    double sum = 0;
    for (int i = 0; i < 10; i++){
        sum += student[i].score;
    }
    return sum/10;
}

int findModeScore( struct Students student[] ){
    int curr_count = 1, max_count = 1, mode_score = student[0].score;
    for (int i = 1; i < 10; i++) {
        if (student[i].score == student[i-1].score) {
            curr_count++;
        } else {
            if (curr_count > max_count) {
                max_count = curr_count;
                mode_score = student[i-1].score;
            }
            curr_count = 1;
        }
    }
    if (curr_count > max_count) {
        max_count = curr_count;
        mode_score = student[10-1].score;
    }

    return mode_score;
}
double findMedianScore(struct Students student[]) {
    sort(student, student + 10, [](const Students &a, const Students &b) {
        return a.score < b.score;
    });
    if (10 % 2 == 0) {
        return (student[10 / 2 - 1].score + student[10 / 2].score) / 2.0;
    } else {
        return student[10 / 2].score;
    }
}

double findSDScore(struct Students student[]) {
    double average = findAverageScore(student);
    double sum = 0;
    double finish;
    for (int i = 0; i < 10; i++) {
        sum += pow(student[i].score - average, 2);
    }
    return sqrt(sum / 10);
    
}
void findGrade(struct Students student[]) {
    double avr = findAverageScore(student);
    double sd = findSDScore(student);
    double A = avr + (2 * sd);
    double B = avr + sd;
    double C = avr;
    double D = avr - sd;
    for (int i = 0; i < 10; i++){
    if (student[i].score >= A) {
        strcpy(student[i].grade, "A");
    } else if (student[i].score >= B && student[i].score < A) {
        strcpy(student[i].grade, "B");
    } else if (student[i].score >= C && student[i].score < B) {
        strcpy(student[i].grade, "C");
    } else if (student[i].score >= D && student[i].score < C) {
        strcpy(student[i].grade, "D");
    } else {
        strcpy(student[i].grade, "F");
    }
    }
}
