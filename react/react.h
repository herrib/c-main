#ifndef REACT_H
#define REACT_H

#include <stdio.h>
#include <stdbool.h>

#define CAPA_REACTOR 10
#define CAPA_CALLBACK 10

enum type_cell { INPUT, COMPUTE_1, COMPUTE_2};

typedef int (*compute1)(int);
typedef int (*compute2)(int, int);
typedef void (*callback)(void *, int);
typedef int callback_id;

struct  event{
  enum type_cell type;
  struct cell *input_1;
  struct cell *input_2;
  struct cell *compute;
  bool ok_input_1;
  bool ok_input_2;
} ;

struct reactor {
  struct event * events[CAPA_REACTOR];
  int nb_events;
};

struct cell {
  int value;
  enum type_cell type;
  compute1 f1;
  compute2 f2;
  struct reactor *r;
  callback_id callback_id;
  callback callbacks[CAPA_CALLBACK];    
	void *callbacks_args[CAPA_CALLBACK];
} ;

struct cb {
  int last_value;
  int times_called;
};


void react (struct cell *input, struct reactor *r) ;

struct reactor *create_reactor(void);
// destroy_reactor should free all cells created under that reactor.
void destroy_reactor(struct reactor *);

struct cell *create_input_cell(struct reactor *, int initial_value);
struct cell *create_compute1_cell(struct reactor *, struct cell *, compute1);
struct cell *create_compute2_cell(struct reactor *, struct cell *,
                                  struct cell *, compute2);

int get_cell_value(struct cell *);
void set_cell_value(struct cell *, int new_value);



// The callback should be called with the same void * given in add_callback.
callback_id add_callback(struct cell *, void *  target, callback);
void remove_callback(struct cell *, callback_id);

bool is_in(struct cell **lst, struct cell *c);
void set_reactor(struct reactor *r,enum type_cell type, struct cell *input_1, struct cell *input_2, struct cell *compute ) ;
#endif
