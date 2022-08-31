#include <stdarg.h>
#include <kstring.h>
#include <graphics.h>
#include <print.h>

static int bitmap_letters[256*16] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0000'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0001'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0002'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0003'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0004'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0005'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0006'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0007'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0008'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //'\x0009'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x000a'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x000b'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x000c'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x000d'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x000e'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x000f'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0010'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0011'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0012'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0013'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0014'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0015'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0016'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0017'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0018'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0019'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x001a'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x001b'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x001c'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x001d'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x001e'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x001f'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //' '

    0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x08, 0x08, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, //'!'

    0x00, 0x00, 0x24, 0x24, 0x24, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //'"'

    0x00, 0x00, 0x00, 0x12, 0x24, 0x7f, 0x24, 0x24, 0xfe, 0x44, 0x48, 0x48, 0x00, 0x00, 0x00, 0x00, //'#'

    0x00, 0x00, 0x08, 0x3c, 0x4a, 0x48, 0x48, 0x3c, 0x0a, 0x0a, 0x4a, 0x7c, 0x08, 0x00, 0x00, 0x00, //'$'

    0x00, 0x00, 0x00, 0xe2, 0x92, 0x94, 0xe8, 0x08, 0x17, 0x29, 0x29, 0x47, 0x00, 0x00, 0x00, 0x00, //'%'

    0x00, 0x00, 0x00, 0x3c, 0x24, 0x24, 0x38, 0x72, 0xd2, 0x8c, 0xc4, 0x7b, 0x00, 0x00, 0x00, 0x00, //'&'

    0x00, 0x00, 0x18, 0x18, 0x18, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //'''

    0x00, 0x00, 0x0c, 0x08, 0x10, 0x10, 0x30, 0x30, 0x20, 0x30, 0x30, 0x10, 0x10, 0x08, 0x0c, 0x00, //'('

    0x00, 0x00, 0x30, 0x10, 0x08, 0x08, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x08, 0x08, 0x10, 0x30, 0x00, //')'

    0x00, 0x00, 0x08, 0x2c, 0x18, 0x18, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //'*'

    0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x7e, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, //'+'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x30, 0x20, 0x20, 0x00, 0x00, //','

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //'-'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, //'.'

    0x00, 0x00, 0x02, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, //'/'

    0x00, 0x00, 0x00, 0x3c, 0x66, 0x42, 0x42, 0x5a, 0x42, 0x42, 0x66, 0x3c, 0x00, 0x00, 0x00, 0x00, //'0'

    0x00, 0x00, 0x00, 0x08, 0x18, 0x68, 0x08, 0x08, 0x08, 0x08, 0x08, 0x7f, 0x00, 0x00, 0x00, 0x00, //'1'

    0x00, 0x00, 0x00, 0x3c, 0x66, 0x42, 0x06, 0x0c, 0x18, 0x30, 0x60, 0x7e, 0x00, 0x00, 0x00, 0x00, //'2'

    0x00, 0x00, 0x00, 0x3c, 0x66, 0x42, 0x06, 0x18, 0x06, 0x42, 0x62, 0x3c, 0x00, 0x00, 0x00, 0x00, //'3'

    0x00, 0x00, 0x00, 0x0c, 0x0c, 0x14, 0x24, 0x24, 0x44, 0x7e, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, //'4'

    0x00, 0x00, 0x00, 0x7e, 0x60, 0x40, 0x5c, 0x66, 0x02, 0x02, 0x46, 0x3c, 0x00, 0x00, 0x00, 0x00, //'5'

    0x00, 0x00, 0x00, 0x1c, 0x26, 0x40, 0x5c, 0x66, 0x42, 0x42, 0x26, 0x3c, 0x00, 0x00, 0x00, 0x00, //'6'

    0x00, 0x00, 0x00, 0x7e, 0x06, 0x04, 0x08, 0x08, 0x18, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, //'7'

    0x00, 0x00, 0x00, 0x3c, 0x66, 0x42, 0x66, 0x18, 0x66, 0x42, 0x62, 0x3c, 0x00, 0x00, 0x00, 0x00, //'8'

    0x00, 0x00, 0x00, 0x3c, 0x66, 0x42, 0x42, 0x66, 0x3a, 0x02, 0x64, 0x38, 0x00, 0x00, 0x00, 0x00, //'9'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, //':'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x18, 0x10, 0x10, 0x20, 0x00, 0x00, //';'

    0x00, 0x00, 0x00, 0x00, 0x02, 0x0c, 0x70, 0x40, 0x70, 0x0c, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, //'<'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //'='

    0x00, 0x00, 0x00, 0x00, 0x40, 0x30, 0x0e, 0x02, 0x0e, 0x30, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, //'>'

    0x00, 0x00, 0x00, 0x24, 0x00, 0x42, 0x42, 0x26, 0x24, 0x34, 0x18, 0x18, 0x10, 0x10, 0x60, 0x00, //'ÿ'

    0x00, 0x00, 0x1c, 0x22, 0x42, 0x5d, 0xa5, 0xa5, 0xa5, 0xae, 0xb6, 0x40, 0x42, 0x3c, 0x00, 0x00, //'\x0040'

    0x00, 0x00, 0x00, 0x18, 0x18, 0x24, 0x24, 0x24, 0x7e, 0x42, 0x42, 0x81, 0x00, 0x00, 0x00, 0x00, //'A'

    0x00, 0x00, 0x00, 0x7c, 0x46, 0x42, 0x46, 0x7c, 0x42, 0x42, 0x42, 0x7c, 0x00, 0x00, 0x00, 0x00, //'B'

    0x00, 0x00, 0x00, 0x1c, 0x66, 0x42, 0x40, 0x40, 0x40, 0x42, 0x26, 0x1c, 0x00, 0x00, 0x00, 0x00, //'C'

    0x00, 0x00, 0x00, 0x78, 0x46, 0x42, 0x42, 0x42, 0x42, 0x42, 0x46, 0x7c, 0x00, 0x00, 0x00, 0x00, //'D'

    0x00, 0x00, 0x00, 0x7e, 0x40, 0x40, 0x40, 0x7e, 0x40, 0x40, 0x40, 0x7e, 0x00, 0x00, 0x00, 0x00, //'E'

    0x00, 0x00, 0x00, 0x7e, 0x60, 0x60, 0x60, 0x7e, 0x60, 0x60, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, //'F'

    0x00, 0x00, 0x00, 0x18, 0x66, 0x42, 0x40, 0x4e, 0x42, 0x42, 0x62, 0x3c, 0x00, 0x00, 0x00, 0x00, //'G'

    0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00, //'H'

    0x00, 0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7e, 0x00, 0x00, 0x00, 0x00, //'I'

    0x00, 0x00, 0x00, 0x1c, 0x04, 0x04, 0x04, 0x04, 0x04, 0x64, 0x64, 0x38, 0x00, 0x00, 0x00, 0x00, //'J'

    0x00, 0x00, 0x00, 0x42, 0x44, 0x48, 0x50, 0x68, 0x68, 0x44, 0x46, 0x43, 0x00, 0x00, 0x00, 0x00, //'K'

    0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3e, 0x00, 0x00, 0x00, 0x00, //'L'

    0x00, 0x00, 0x00, 0x66, 0x66, 0x66, 0x5a, 0x5a, 0x5a, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00, //'M'

    0x00, 0x00, 0x00, 0x62, 0x62, 0x52, 0x52, 0x5a, 0x4a, 0x4a, 0x46, 0x46, 0x00, 0x00, 0x00, 0x00, //'N'

    0x00, 0x00, 0x00, 0x3c, 0x66, 0x42, 0x42, 0x42, 0x42, 0x42, 0x66, 0x3c, 0x00, 0x00, 0x00, 0x00, //'O'

    0x00, 0x00, 0x00, 0x7c, 0x46, 0x42, 0x42, 0x46, 0x7c, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, //'P'

    0x00, 0x00, 0x00, 0x3c, 0x66, 0x42, 0x42, 0x42, 0x42, 0x42, 0x66, 0x3c, 0x08, 0x06, 0x00, 0x00, //'Q'

    0x00, 0x00, 0x00, 0x7c, 0x42, 0x42, 0x42, 0x7c, 0x48, 0x44, 0x46, 0x42, 0x00, 0x00, 0x00, 0x00, //'R'

    0x00, 0x00, 0x00, 0x3c, 0x42, 0x40, 0x60, 0x1c, 0x02, 0x02, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, //'S'

    0x00, 0x00, 0x00, 0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, //'T'

    0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x66, 0x3c, 0x00, 0x00, 0x00, 0x00, //'U'

    0x00, 0x00, 0x00, 0xc3, 0x42, 0x42, 0x66, 0x24, 0x24, 0x3c, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, //'V'

    0x00, 0x00, 0x00, 0x81, 0x81, 0xdb, 0x5a, 0x5a, 0x5a, 0x66, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00, //'W'

    0x00, 0x00, 0x00, 0x42, 0x66, 0x24, 0x18, 0x18, 0x18, 0x24, 0x66, 0x42, 0x00, 0x00, 0x00, 0x00, //'X'

    0x00, 0x00, 0x00, 0xc3, 0x42, 0x66, 0x24, 0x1c, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, //'Y'

    0x00, 0x00, 0x00, 0x7e, 0x06, 0x04, 0x08, 0x18, 0x30, 0x20, 0x40, 0xff, 0x00, 0x00, 0x00, 0x00, //'Z'

    0x00, 0x00, 0x1c, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1c, 0x00, //'['

    0x00, 0x00, 0x40, 0x20, 0x20, 0x10, 0x10, 0x08, 0x08, 0x04, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, //'\'

    0x00, 0x00, 0x38, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x38, 0x00, //']'

    0x00, 0x00, 0x00, 0x18, 0x18, 0x24, 0x24, 0x46, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //'^'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, //'_'

    0x00, 0x00, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //'`'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x64, 0x06, 0x3e, 0x46, 0x46, 0x7b, 0x00, 0x00, 0x00, 0x00, //'a'

    0x00, 0x00, 0x40, 0x40, 0x40, 0x5c, 0x66, 0x62, 0x42, 0x62, 0x66, 0x5c, 0x00, 0x00, 0x00, 0x00, //'b'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x66, 0x40, 0x40, 0x40, 0x66, 0x3c, 0x00, 0x00, 0x00, 0x00, //'c'

    0x00, 0x00, 0x02, 0x02, 0x02, 0x3a, 0x66, 0x42, 0x42, 0x46, 0x66, 0x3a, 0x00, 0x00, 0x00, 0x00, //'d'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x66, 0x42, 0x7e, 0x40, 0x62, 0x3c, 0x00, 0x00, 0x00, 0x00, //'e'

    0x00, 0x00, 0x1e, 0x10, 0x10, 0x7e, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, //'f'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x3a, 0x66, 0x46, 0x42, 0x46, 0x66, 0x3a, 0x02, 0x26, 0x3c, 0x00, //'g'

    0x00, 0x00, 0x40, 0x40, 0x40, 0x5c, 0x66, 0x42, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00, //'h'

    0x00, 0x00, 0x08, 0x00, 0x00, 0x78, 0x08, 0x08, 0x08, 0x08, 0x08, 0x7f, 0x00, 0x00, 0x00, 0x00, //'i'

    0x00, 0x00, 0x0c, 0x00, 0x00, 0x7c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x08, 0x08, 0x78, 0x00, //'j'

    0x00, 0x00, 0x20, 0x20, 0x20, 0x26, 0x2c, 0x28, 0x38, 0x28, 0x24, 0x22, 0x00, 0x00, 0x00, 0x00, //'k'

    0x00, 0x00, 0x38, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x7e, 0x00, 0x00, 0x00, 0x00, //'l'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x00, 0x00, 0x00, 0x00, //'m'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x5c, 0x66, 0x42, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00, //'n'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x66, 0x42, 0x42, 0x42, 0x66, 0x3c, 0x00, 0x00, 0x00, 0x00, //'o'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x5c, 0x66, 0x62, 0x42, 0x62, 0x66, 0x5c, 0x40, 0x40, 0x40, 0x00, //'p'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x3a, 0x66, 0x46, 0x42, 0x46, 0x66, 0x3a, 0x02, 0x02, 0x02, 0x00, //'q'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x2e, 0x30, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, //'r'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x66, 0x60, 0x1c, 0x02, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, //'s'

    0x00, 0x00, 0x00, 0x10, 0x30, 0x7e, 0x30, 0x30, 0x30, 0x30, 0x30, 0x1e, 0x00, 0x00, 0x00, 0x00, //'t'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x66, 0x3a, 0x00, 0x00, 0x00, 0x00, //'u'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x66, 0x24, 0x24, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, //'v'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0xc3, 0x5a, 0x5a, 0x5a, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00, //'w'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x24, 0x18, 0x18, 0x38, 0x24, 0x42, 0x00, 0x00, 0x00, 0x00, //'x'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x26, 0x24, 0x34, 0x18, 0x18, 0x10, 0x10, 0x60, 0x00, //'y'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x04, 0x08, 0x18, 0x30, 0x60, 0x7e, 0x00, 0x00, 0x00, 0x00, //'z'

    0x00, 0x00, 0x0e, 0x18, 0x10, 0x10, 0x10, 0x10, 0x60, 0x10, 0x10, 0x10, 0x10, 0x18, 0x0e, 0x00, //'{'

    0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, //'|'

    0x00, 0x00, 0x70, 0x18, 0x08, 0x08, 0x08, 0x08, 0x06, 0x08, 0x08, 0x08, 0x08, 0x18, 0x70, 0x00, //'}'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //'~'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x007f'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0080'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0081'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0082'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0083'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0084'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0085'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0086'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0087'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0088'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0089'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x008a'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x008b'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x008c'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x008d'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x008e'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x008f'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0090'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0091'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0092'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0093'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0094'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0095'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0096'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0097'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0098'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x0099'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x009a'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x009b'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x009c'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x009d'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x009e'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 0x00, //'\x009f'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //'\x00a0'

    0x00, 0x00, 0x00, 0x00, 0x7e, 0x24, 0x42, 0x42, 0x24, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //'¤'

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //'­'
};

int x = 5;
int y = 5;
int fg_color = WHITE_COLOR;
int bg_color = BLACK_COLOR;

void _putchar(char c) {
    int* font_char = &bitmap_letters[c * 16];

    for (int i = 0; i < 16; ++i){
        for (int j = 0; j < 8; ++j){
            if (font_char[i] & (1 << (8 - j))){
                putpixel(x+j, y+i, fg_color);
            } else {
                putpixel(x+j, y+i, bg_color);
            }
        }
    }
    x += 8;
}

void set_x(int _x) {
    x = _x;
}

void set_y(int _y) {
    y = _y;
}

int get_x() {
    return x;
}

int get_y() {
    return y;
}

void newline() {
    x = 5;
    y += 20;
    if (y >= 720)
        y = 0;
}

void putchar(char c) {
    if (c == '\n' || c == '\r') {
        newline();
        return;
    } else if (c == '\t') {
        for (int i = 0; i < 4; i++) 
            putchar(' ');
        return;
    } else {
        _putchar(c);

        if (x >= 1280)
            newline();
    }
}

void printf(const char* _buf, ...) {
    va_list arg;
    va_start(arg, _buf);
    
    int format_int;
    float format_float;
    char format_char;
    char* format_str;
    char bufprint[1024];
    
    for (int i = 0; i < strlen(_buf); i++) {
        char c = _buf[i];
        
        if (c == '%') {
            i++;
            c = _buf[i];
            
            switch (c) {
                case '%':
                    putchar('%');
                    break;
                case 'd': case 'i': case 'D': case 'I': case 'o': case 'O': case 'x': case 'X': case 'h': case 'H':
                    format_int = va_arg(arg, int); 
                    if (format_int < 0) {
                        putchar('-');
                        format_int *= -1;
                    }
                    
                    if (c == 'd' || c == 'i' || c == 'D' || c == 'I') // Decimal
                        itoa(format_int, bufprint, 10);
                    else if (c == 'o' || c == 'O') // Octals
                        itoa(format_int, bufprint, 8);
                    else if (c == 'x' || c == 'X' || c == 'h' || c == 'H') // Hexadecimal
                        itoa(format_int, bufprint, 16);
                    
                    for (int i = 0; bufprint[i] != '\0'; i++)
                        putchar(bufprint[i]);
                    break;
                // case 'f': case 'F':
                //     format_float = va_arg(arg, double);
                //     dtoa(format_float, bufprint);
                //     for (int i2 = 0; i2 < strlen(bufprint); i2++)
                //         putchar(bufprint[i2]);
                case 'c': case 'C':
                    format_char = va_arg(arg, int);
                    putchar((char)format_char);
                    break;
                case 's': case 'S':
                    format_str = va_arg(arg, char*);
                    for (int i2 = 0; i2 < strlen(format_str); i2++) 
                        putchar(format_str[i2]);
                    break;
                default:
                    break;
            }
        }
        else 
            putchar(c);
    }
    va_end(arg);
}

void set_font_color(int _color) {
    fg_color = _color;
}

void set_background_color(int _color) {
    bg_color = _color;
}