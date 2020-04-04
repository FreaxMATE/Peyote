/*
 * Copyright (c) 2019 FreaxMATE
 *
 * This file is part of Peyote.
 *
 * Peyote is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Peyote is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Peyote.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _peyote_h_
#define _peyote_h_

#include <gtk/gtk.h>
#include <glib.h>

typedef struct _PeyoteApplication PeyoteApplication ;
typedef struct _PeyoteFiles PeyoteFiles ;
typedef struct _PeyoteFile PeyoteFile ;
typedef struct _PeyoteRender PeyoteRender ;
typedef struct _PeyoteWindow PeyoteWindow ;
typedef struct _PeyoteFileParser PeyoteFileParser ;
typedef struct _PeyoteTabs PeyoteTabs ;
typedef struct _PeyoteMenu PeyoteMenu ;
typedef struct _PeyoteDialog PeyoteDialog ;


typedef struct _PeyoteApplication
{
   PeyoteWindow     *window ;
   PeyoteFiles      *files ;
   PeyoteRender     *render ;
   PeyoteMenu       *menu ;
   PeyoteDialog     *dialog ;
   PeyoteTabs       *tabs ;

} PeyoteApplication ;

typedef struct _PeyoteFiles
{
   GList *list ;
   PeyoteFile *current ;
   int n ;

} PeyoteFiles ;

typedef struct _PeyoteFile
{
   GtkLabel *tab_label ;
   GtkScrolledWindow *scroll ;
   GtkTextView   *text_view ;
   GtkTextBuffer *text_buffer ;

   PeyoteFileParser *parser ;
   char *path ;

} PeyoteFile ;

typedef struct _PeyoteRender
{
   cairo_surface_t *surface ;
   cairo_t *cr ;

} PeyoteRender ;

typedef struct _PeyoteWindow
{
   GtkBuilder *builder ;
   GtkWindow  *window ;
   GtkAboutDialog *about_dialog ;
   GtkBox *main_box ;
   GtkNotebook *notebook ;

} PeyoteWindow ;

typedef struct _PeyoteFileParser
{
   PeyoteFile *file ;
   char *tabs, *artist, *song, *album ;

} PeyoteFileParser ;

typedef struct _PeyoteTabs
{
   char *tuning ;
   char **tabs ;
   int nlinelen, nlines ;

} PeyoteTabs ;

typedef struct _PeyoteMenu
{
   GtkImageMenuItem *peyote_menu_open ;
   GtkImageMenuItem *peyote_menu_quit ;

} PeyoteMenu ;

typedef struct _PeyoteDialog
{
   GtkDialog *dialog ;
   GtkButton *cancel, *apply ;
   GtkEntry *artist_entry, *song_entry, *album_entry ;
   char *artist, *song, *album ;

} PeyoteDialog ;

#endif /* _peyote_h_ */

