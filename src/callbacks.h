/*
 * callbacks.h - forward decls of callbacks.c
 * written by Jaka Mocnik <jaka.mocnik@kiss.uni-lj.si>
 */

#ifndef CALLBACKS_H
#define CALLBACKS_H

/* the tale of two entries ;) */
typedef struct _ReplaceCBData ReplaceCBData;

struct _ReplaceCBData {
  GtkEntry *find;
  GtkEntry *replace;
};

void select_buffer_cb();
void quit_app_cb();
void open_cb();
void close_cb();
void save_cb();
void save_as_cb();
void revert_cb();
void set_group_type_cb();
void cancel_cb();
void select_font_cb();
void save_on_exit_cb();

void find_cb();
void replace_cb();
void jump_cb();
void find_next_cb();
void find_prev_cb();
void replace_one_cb();
void replace_all_cb();
void goto_byte_cb();

void open_selected_file();
void save_selected_file();

void about_cb();
void show_help_cb();

#endif