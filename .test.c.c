#include <gtk/gtk.h>
#include <stdio.h>

void destroy( GtkWidget *widget,  
                     gpointer   data )  
{  
    gtk_main_quit ();  
}


int main( int   argc,
          char *argv[] )
{
    GtkWidget *window;
   
    GtkWidget *new_window;
    gtk_init (&argc, &argv);

    new_window = gtk_window_new( GTK_WINDOW_POPUP ); 
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect (G_OBJECT (window), "destroy",  
                                 G_CALLBACK (destroy), NULL);
    gtk_window_set_keep_above(GTK_WINDOW (new_window), TRUE);
    //gtk_window_set_transient_for(GTK_WINDOW (new_window), GTK_WINDOW (window));
    gtk_widget_show (new_window);
    gtk_widget_show (window);
    gtk_main ();
    
    return 0;
}
