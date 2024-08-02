#include <gtk/gtk.h>
#include <iostream>
#include <string>

static void print_hello(GtkWidget *widget, gpointer data) {
	g_print("Hello World\n");
}

static void activate(GtkApplication *app, gpointer user_data) {
	GtkWidget *window;
	GtkWidget *grid;
	GtkWidget *button;
	GtkWidget *label;
	GtkWidget *listbox;

	/* create a new window, and set its title */
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Window");

	/* Here we construct the container that is going pack our buttons */
	grid = gtk_grid_new();

	/* Pack the container in the window */
	gtk_window_set_child(GTK_WINDOW(window), grid);

	const char* weekdays[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	for(int i = 0; i < 7; ++i) {
		label = gtk_label_new(weekdays[i]);
		gtk_grid_attach(GTK_GRID(grid), label, i + 1, 0, 1, 1);
	}
	
	for(int i = 0; i < 25; ++i) {
		std::string time(std::to_string(i) + ":00");
		if (i < 10)
			time = "0" + time;
	
		label = gtk_label_new(time.c_str());
		gtk_grid_attach(GTK_GRID(grid), label, 0, i + 1, 1, 1);
	}

	button = gtk_button_new_with_label("Button 2");
	g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
	gtk_grid_attach(GTK_GRID(grid), button, 1, 1, 1, 1);

	button = gtk_button_new_with_label("Quit");
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), window);
	gtk_grid_attach(GTK_GRID(grid), button, 1, 3, 2, 1);

 	listbox = gtk_list_box_new();
 	
 	label = gtk_label_new("First task"); 
  	gtk_list_box_append(GTK_LIST_BOX(listbox), label);
  	
  	label = gtk_label_new("Second task"); 
  	gtk_list_box_append(GTK_LIST_BOX(listbox), label);
  	
  	label = gtk_label_new("Third task"); 
  	gtk_list_box_append(GTK_LIST_BOX(listbox), label);
  	
  	gtk_grid_attach(GTK_GRID(grid), listbox, 3, 3, 1, 1);
  
	gtk_grid_set_row_spacing(GTK_GRID(grid), 20);
	gtk_grid_set_column_spacing(GTK_GRID(grid), 30);

	gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
	GtkApplication *app;
	int status;

	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}

