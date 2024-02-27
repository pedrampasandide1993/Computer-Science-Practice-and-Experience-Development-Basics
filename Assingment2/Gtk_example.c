#include <gtk/gtk.h>
// gcc -o Gtk_example Gtk_example.c `pkg-config --cflags --libs gtk+-3.0`
// Function to handle button click event
void button_clicked(GtkWidget *widget, gpointer data) {
    // Cast the data pointer back to its original type
    GtkWidget **entries = (GtkWidget **)data;
    
    // Get the text from the entry fields
    const gchar *text1 = gtk_entry_get_text(GTK_ENTRY(entries[0]));
    const gchar *text2 = gtk_entry_get_text(GTK_ENTRY(entries[1]));

    // Print the text to console (Terminal)
    g_print("Entry 1: %s\n", text1);
    g_print("Entry 2: %s\n", text2);
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *entry[2];
    GtkWidget *button;

    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create a new window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Simple GUI");

    //  The following line of code, closes the app (not just the window opened) from terminal, if you click close
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // 20 size distance from the border of outer window. 
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);

    // Create a new gridls. We will later put buttons in it.
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create two entry fields. The places that user can have entires.
    entry[0] = gtk_entry_new();
    entry[1] = gtk_entry_new();
    // attach the entry(s) to the grid, and specify the location
    gtk_grid_attach(GTK_GRID(grid), entry[0], 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry[1], 0, 1, 1, 1);

    // Create a button with name "Submit"
    button = gtk_button_new_with_label("Submit"); 
    // if the button is click execute the function button_clicked
    g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), entry);
    // attach the button to the grid, and specify the location
    gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 1, 1);


    // It is a loop because the window will be shown and it will stay opened.
    // Show all widgets
    gtk_widget_show_all(window);
    // Start the GTK main loop. 
    gtk_main();

    return 0;
}
