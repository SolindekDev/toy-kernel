#pragma once

#define TIMER_INPUT_CLOCK_FREQUENCY    1193180
#define TIMER_CHANNEL_0_DATA_PORT    0x40
#define TIMER_CHANNEL_1_DATA_PORT    0x41
#define TIMER_CHANNEL_2_DATA_PORT    0x42
#define TIMER_COMMAND_PORT    0x43

typedef struct {
    int timeout; 
    void *user;
} TIMER_FUNC_ARGS;

typedef void (*TIMER_FUNCTION) (TIMER_FUNC_ARGS*);

#define MAXIMUM_TIMER_FUNCTIONS    32

typedef struct {
    int current_index;
    TIMER_FUNCTION functions[MAXIMUM_TIMER_FUNCTIONS];
    TIMER_FUNC_ARGS func_args[MAXIMUM_TIMER_FUNCTIONS];
} TIMER_FUNCTION_MANAGER;

void timer_init();
void sleep(int sec);
void timer_register_function(TIMER_FUNCTION function, TIMER_FUNC_ARGS *args);
void add_timer_function(TIMER_FUNCTION fn, int timeout);
int get_ticks();