#ifndef __tp3_H__
#define __tp3_H__

/** Opaque definition of type Stack */
typedef struct s_stack* Stack;
/** Opaque definition of type Step */
typedef struct s_step* Step;

/** Create a new Step */
Step step(int,int,int,int);
int getX_ori(Step);
int getY_ori(Step);
int getX_fin(Step);
int getY_fin(Step);

/** Create and initialize a stack */
Stack stack(void);

/** Push a value */
Stack push(Stack, Step);

/** Pop a value
 * @pre pop(s) defined if non(isEmpty(s))
 */
Stack pop(Stack);

/** Test if Stak isEmpty */
int isEmpty(Stack);

/** return the top of the stack
 * @pre top(s) defined if non(isEmpty(s))
 */
 
Step top(Stack); 
#endif