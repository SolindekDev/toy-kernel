#include <timer.h>
#include <ports.h>
#include <utils.h>
#include <isr.h>

int ticks = 0;
unsigned int frequency = 0;
TIMER_FUNCTION_MANAGER timer_function_manager;

void timer_set_frequency(unsigned int f) {
    frequency = f;
    unsigned int divisor = TIMER_INPUT_CLOCK_FREQUENCY / f;
    outb(TIMER_COMMAND_PORT, 0b00110110);
    outb(TIMER_CHANNEL_0_DATA_PORT, divisor & 0xFF);
    outb(TIMER_CHANNEL_0_DATA_PORT, (divisor >> 8) & 0xFF);
}

int get_ticks() {
    return ticks;
}

void timer_handler(registers_t* r) {
    int i;
    TIMER_FUNC_ARGS *args = NULL;
    ticks++;
    for (i = 0; i < MAXIMUM_TIMER_FUNCTIONS; i++) {
        args = &timer_function_manager.func_args[i];
        if (args->timeout == 0)
            continue;
        if ((ticks % args->timeout) == 0) {
            timer_function_manager.functions[i](args);
        }
    }
}

void add_timer_function(TIMER_FUNCTION fn, int timeout) {
    TIMER_FUNC_ARGS args = {0};
    args.timeout = timeout;
    timer_register_function(fn, &args);
}

void timer_register_function(TIMER_FUNCTION function, TIMER_FUNC_ARGS *args) {
    int index = 0;
    if (function == NULL || args == NULL) {
        printf("ERROR: failed to register timer function %x\n", function);
        return;
    }
    index = (++timer_function_manager.current_index) % MAXIMUM_TIMER_FUNCTIONS;
    timer_function_manager.current_index = index;
    timer_function_manager.functions[index] = function;
    memcopy(&timer_function_manager.func_args[index], args, sizeof(TIMER_FUNC_ARGS));
}

void timer_init() {
    // timer_set_frequency(60);
    // isr_register_interrupt_handler(IRQ_BASE, timer_handler);
}

void sleep(int sec) {
    int end = ticks + sec * frequency;
    while (ticks < end);
}