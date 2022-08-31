#include <cmos.h>
#include <stdbool.h>
#include <ports.h>
#include <kstring.h>
#include <timer.h>
#include <utils.h>

int milisecond;
int seconds;

void milisecond_callback(TIMER_FUNC_ARGS* args) {
    printf("%d", milisecond);
    if (get_rtc_register(RTC_REGISTER_SECOND) == seconds)
        milisecond += 10;
    else
        milisecond = 0;
    seconds = get_rtc_register(RTC_REGISTER_SECOND);
}

bool get_update_in_progress_flag() {
    outb(CMOS_ADDRESS, 0x0A);
    return inb(CMOS_DATA) & 0x80;
}

unsigned char get_rtc_register(int reg) {
    outb(CMOS_ADDRESS, reg);
    return inb(CMOS_DATA);
}

// char* get_pretty_date(Date date) {

// }

Date get_date_cmos() {
    Date date;
    while (get_update_in_progress_flag());
    date.second      = get_rtc_register(RTC_REGISTER_SECOND);
    date.minut       = get_rtc_register(RTC_REGISTER_MINUT);
    date.hour        = get_rtc_register(RTC_REGISTER_HOUR);
    date.day         = get_rtc_register(RTC_REGISTER_DAY);
    date.month       = get_rtc_register(RTC_REGISTER_MONTH);
    date.year        = get_rtc_register(RTC_REGISTER_YEAR);
    date.milisecond  = milisecond;
    date.century     = 20; // em change in 2100 ;)

    seconds = date.second;

    unsigned char register_b = get_rtc_register(RTC_REGISTER_B);
    if  (!(register_b & 0x04)) {
        date.second = (date.second & 0x0F) + ((date.second / 16) * 10);
        date.minut = (date.minut & 0x0F) + ((date.minut / 16) * 10);
        date.hour = ( (date.hour & 0x0F) + (((date.hour & 0x70) / 16) * 10) ) | (date.hour & 0x80);
        date.day = (date.day & 0x0F) + ((date.day / 16) * 10);
        date.month = (date.month & 0x0F) + ((date.month / 16) * 10);
        date.year = (date.year & 0x0F) + ((date.year / 16) * 10);
    }

    return date;
}