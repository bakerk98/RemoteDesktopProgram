#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>

/* this program makes a window that can be used with Steam */
/* Remote Desktop to use the desktop of a host computer while afk from that host computer */

/* this is my first venture into gtk, i had fun making this */

static GtkWidget *close_window_please;
static GtkWidget *minimize;
static GtkWidget *window;

void minimize_the_window(GtkWidget *minimize, gpointer data){
  gtk_window_iconify(window);
}

int main(int argc, char **argv){
  GtkWidget *grid;
  gtk_init(&argc, &argv);
  
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(window), grid);
  gtk_grid_set_row_homogeneous(GTK_GRID(grid),TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(grid),TRUE);

  close_window_please=gtk_button_new_with_label("Exit");
  g_signal_connect(close_window_please, "clicked", G_CALLBACK(gtk_main_quit), NULL);
  gtk_grid_attach(GTK_GRID(grid), close_window_please, 0,0,300,300);

  minimize=gtk_button_new_with_label("Minimize this window and begin Remote Desktopping...");
  g_signal_connect(minimize, "clicked", G_CALLBACK(minimize_the_window), NULL);
  gtk_grid_attach(GTK_GRID(grid), minimize,300,0,300,300);
  
  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}
