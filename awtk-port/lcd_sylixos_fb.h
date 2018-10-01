﻿/**
 * File:   lcd_sylixos_fb.h
 * Author: AWTK Develop Team
 * Brief:  sylixos framebuffer lcd
 *
 * Copyright (c) 2018 - 2018  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2018-10-01 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#ifndef TK_LCD_SYLIXOS_FB_H
#define TK_LCD_SYLIXOS_FB_H

#include "base/lcd.h"

BEGIN_C_DECLS

lcd_t* lcd_sylixos_fb_create(const char* filename);

END_C_DECLS

#endif /*TK_LCD_SYLIXOS_FB_H*/
