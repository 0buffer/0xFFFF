/*
 *  0xFFFF - Open Free Fiasco Firmware Flasher
 *  Copyright (C) 2007  pancake <pancake@youterm.com>
 *  Copyright (C) 2012  Pali Rohár <pali.rohar@gmail.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NOLO_H
#define NOLO_H

#include "image.h"
#include "usb-device.h"

int nolo_init(struct usb_device_info * dev);

enum device nolo_get_device(struct usb_device_info * dev);

int nolo_load_image(struct usb_device_info * dev, struct image * image);
int nolo_flash_image(struct usb_device_info * dev, struct image * image);
int nolo_boot(struct usb_device_info * dev, char * cmdline);
int nolo_boot_to_update_mode(struct usb_device_info * dev);
int nolo_reboot_device(struct usb_device_info * dev);

int nolo_get_root_device(struct usb_device_info * dev);
int nolo_set_root_device(struct usb_device_info * dev, int device);

int nolo_get_usb_host_mode(struct usb_device_info * dev);
int nolo_set_usb_host_mode(struct usb_device_info * dev, int enable);

int nolo_get_rd_mode(struct usb_device_info * dev);
int nolo_set_rd_mode(struct usb_device_info * dev, int enable);

int nolo_get_rd_flags(struct usb_device_info * dev, char * flags, size_t size);
int nolo_set_rd_flags(struct usb_device_info * dev, const char * flags);

int nolo_get_hwrev(struct usb_device_info * dev, char * hwrev, size_t size);
int nolo_set_hwrev(struct usb_device_info * dev, const char * hwrev);

int nolo_get_kernel_ver(struct usb_device_info * dev, char * ver, size_t size);
int nolo_set_kernel_ver(struct usb_device_info * dev, const char * ver);

int nolo_get_nolo_ver(struct usb_device_info * dev, char * ver, size_t size);
int nolo_set_nolo_ver(struct usb_device_info * dev, const char * ver);

int nolo_get_sw_ver(struct usb_device_info * dev, char * ver, size_t size);
int nolo_set_sw_ver(struct usb_device_info * dev, const char * ver);

int nolo_get_content_ver(struct usb_device_info * dev, char * ver, size_t size);
int nolo_set_content_ver(struct usb_device_info * dev, const char * ver);


void flash_image(struct image * image);

extern char strbuf[1024];

int boot_board(char *cmdline);

int reboot_board();

int get_status();

int get_usb_mode();
int set_usb_mode(unsigned int);

int get_rd_mode();
int set_rd_mode(unsigned short mode);

int get_rd_flags();
int set_rd_flags(unsigned short flags);

int get_hw_revision(char *str, int len);

int get_root_device();
int set_root_device(unsigned short);

int get_nolo_version();

int get_sw_version();

#define NOLO_GET_STATUS   1
#define NOLO_GET_BOARD_ID 2
#define NOLO_GET_VERSION  3
#define NOLO_GET_HWVERSION 4
#define NOLO_SET_RDFLAGS   16
#define NOLO_GET_RDFLAGS  17

#endif
