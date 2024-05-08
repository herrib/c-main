#include "grade_school.h"
#include <string.h>

void init_roster(roster_t *roster) { roster->count = 0; }

int add_student(roster_t *actual, char *name, uint8_t grade) {
  for (size_t i = 0; i < actual->count; i++) {
    if (strcmp(name, actual->students[i].name) == 0) {
      return 0;
    }
  }
  student_t student;
  student.grade = grade;
  strcpy(student.name, name);
  actual->students[actual->count] = student;
  actual->count++;
  student_t tmp;
  int swap = 1;
  while (swap) {
    swap = 0;
    for (size_t i = 0; i < actual->count - 1; i++) {
      swap = 0;
      if (strcmp(actual->students[i].name, actual->students[i + 1].name) > 0) {
        swap = 1;
        tmp = actual->students[i + 1];
        actual->students[i + 1] = actual->students[i];
        actual->students[i] = tmp;
      }
    }
  }
  swap = 1;
  while (swap) {
    swap = 0;
    for (size_t i = 0; i < actual->count - 1; i++) {
      if (actual->students[i].grade > actual->students[i + 1].grade) {
        swap = 1;
        tmp = actual->students[i + 1];
        actual->students[i + 1] = actual->students[i];
        actual->students[i] = tmp;
      }
    }
  }
  return 1;
}

roster_t get_grade(roster_t *roster, uint8_t desired_grade) {
  roster_t output = (roster_t){0} ;
    if (roster->count == 0) {
    return output;
  }
  for (uint8_t i = 0; i < roster->count; i++) {
    if (roster->students[i].grade == desired_grade) {
      add_student(&output, roster->students[i].name, desired_grade);
    }
  }
  return output;
}
