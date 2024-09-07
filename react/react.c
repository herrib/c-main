#include "react.h"
#include <stdlib.h>

struct reactor *create_reactor(void) {
  struct reactor *r = calloc(sizeof(struct reactor), 1);
  r->nb_events = 0;
  return r;
}

void destroy_reactor(struct reactor *r) {

  struct cell **lst = calloc(sizeof(struct cell *), r->nb_events * 3);
  int start = 0;

  for (int i = 0; i < r->nb_events; i++) {

    struct cell *a = r->events[i]->input_1;
    struct cell *b = r->events[i]->input_2;
    struct cell *c = r->events[i]->compute;

    if ((a != NULL) && is_in(lst, a)) {
      lst[start++] = a;
    }
    if ((b != NULL) && is_in(lst, b)) {
      lst[start++] = b;
    }
    if ((c != NULL) && is_in(lst, c)) {
      lst[start++] = c;
    }
  }
  for (int j = 0; j < start; j++) {
    free(lst[j]);
  }
  for (int i = 0; i < r->nb_events; i++) {
    free(r->events[i]);
  }
  free(r);
  free(lst);
}

struct cell *create_input_cell(struct reactor *r, int initial_value) {
  struct cell *c = calloc(sizeof(struct cell), 1);
  c->type = INPUT;
  c->value = initial_value;
  c->r = r;
  set_reactor(r, INPUT, c, NULL, NULL);
  return c;
}

struct cell *create_compute1_cell(struct reactor *r, struct cell *input,
                                  compute1 f1) {
  struct cell *c = calloc(sizeof(struct cell), 1);
  c->type = COMPUTE_1;
  c->f1 = f1;
  c->value = c->f1(input->value);
  c->r = r;
  set_reactor(r, COMPUTE_1, input, NULL, c);
  return c;
}

struct cell *create_compute2_cell(struct reactor *r, struct cell *input_1,
                                  struct cell *input_2, compute2 f2) {
  struct cell *c = calloc(sizeof(struct cell), 1);
  c->type = COMPUTE_2;
  c->f2 = f2;
  c->value = c->f2(input_1->value, input_2->value);
  c->r = r;
  set_reactor(r, COMPUTE_2, input_1, input_2, c);
  return c;
}

int get_cell_value(struct cell *c) { return c->value; }

void set_cell_value(struct cell *c, int new_value) {
  bool changed = (new_value == c->value) ? false : true;
  c->value = new_value;
  react(c, c->r);
  if (changed) {
    for (int i = 0; i < c->callback_id; i++) {
      callback cb = c->callbacks[i];
      void *target = c->callbacks_args[i];
      if (target)
        cb(target, c->value);
    }
  }
}

void react(struct cell *input, struct reactor *r) {
  for (int i = 0; i < input->r->nb_events; i++) {

    if (r->events[i]->type == INPUT) {
      continue;
    }
    if ((r->events[i]->type == COMPUTE_1) && (input == r->events[i]->input_1)) {
      set_cell_value(r->events[i]->compute,
                     r->events[i]->compute->f1(input->value));
    }
    if ((r->events[i]->type == COMPUTE_2) && (input == r->events[i]->input_1)) {
      r->events[i]->ok_input_1 = true;
    }
    if ((r->events[i]->type == COMPUTE_2) && (input == r->events[i]->input_2)) {
      r->events[i]->ok_input_2 = true;
    }
    if ((r->events[i]->ok_input_1 == 1) && (r->events[i]->ok_input_2 == 1)) {
      r->events[i]->ok_input_1 = false;
      r->events[i]->ok_input_2 = false;
      set_cell_value(r->events[i]->compute,
                     r->events[i]->compute->f2(r->events[i]->input_1->value,
                                               r->events[i]->input_2->value));
    }
  }
}

callback_id add_callback(struct cell *c, void *target, callback callback) {

  if (c->callback_id + 1 < CAPA_CALLBACK) {
    c->callbacks[c->callback_id] = callback;
    c->callbacks_args[c->callback_id] = target;
  }
  c->callback_id++;
  return c->callback_id - 1;
}

void remove_callback(struct cell *c, callback_id id) {

  c->callbacks[id] = NULL;
  c->callbacks_args[id] = NULL;
}

bool is_in(struct cell **lst, struct cell *c) {

  for (int j = 0; lst[j] != NULL; j++) {
    if (c == lst[j]) {
      return false;
    }
  }
  return true;
}

void set_reactor(struct reactor *r, enum type_cell type, struct cell *input_1,
                 struct cell *input_2, struct cell *compute) {
  if (r->nb_events < CAPA_REACTOR - 1) {
    struct event *e = calloc(sizeof(struct event), 1);
    e->type = type;
    e->input_1 = input_1;
    e->input_2 = input_2;
    e->compute = compute;
    r->events[r->nb_events] = e;
    r->nb_events++;
  }
}