#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <gtk/gtk.h>

#define BUTTON_NEW_INTIALIZE(n) n = gtk_button_new_with_label ("press me")
#define BUTTON_NEW_INTIALIZE_RANGE(button_array, n, m) do{\
									assert(n <= m);\
									int i = n ;\
									for(;i <= m ;i++){\
										BUTTON_NEW_INTIALIZE(button_array[i]);\
									}\
								}while(0)
#define ROOT_MENU_COUNT 2
static gboolean button_0_press(GtkWidget *button, GtkEntryBuffer* (*buffer)[][3][3][3]);
static gboolean button_1_press(GtkWidget *button, GtkEntryBuffer* (*buffer)[][3][3][3]);
static void menuitem_response (gchar *);
static void menuitem_response_1 (gchar *message, GtkWidget *);
GtkWidget *window;

int main( int   argc,
          char *argv[] )
{
    GtkWidget *menu[ROOT_MENU_COUNT];
    GtkWidget *menu_bar;
    GtkWidget *menu_bar_2;
    GtkWidget *root_menu[ROOT_MENU_COUNT];
    GtkWidget *menu_items;
    GtkWidget *menu_items_;
    GtkWidget *vbox;

    GtkWidget *hbox_1[3][3][3];//行列  列
    GtkWidget *vbox_1[3][3];//行列
    GtkWidget *hbox_2[3];//行
/*
    GtkWidget *hbox[9];
    GtkWidget *vbox_1;
*/

    GtkWidget *entry[3][3][3][3];
    GtkWidget *button[2];
    GtkWidget *hbuttonbox;
    GtkEntryBuffer *buffer[3][3][3][3];
	GSList *group = NULL;
	//GtkWidget *item;
    char buf[128];
    int i,j,k,l;
    int order = 0;

    gtk_init (&argc, &argv);

    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET (window), 590, 600);
    gtk_window_set_title (GTK_WINDOW (window), "GTK Menu Test");
    g_signal_connect (window, "delete-event",
                      G_CALLBACK (gtk_main_quit), NULL);

    hbuttonbox = gtk_hbutton_box_new();
    gtk_button_box_set_layout(GTK_BUTTON_BOX (hbuttonbox), GTK_BUTTONBOX_SPREAD);
    for(i = 0; i < 2; i++){
        button[i] = gtk_button_new();
        gtk_container_add(GTK_CONTAINER (hbuttonbox), button[i]);
    }
    /* Init the menu-widget, and remember -- never
     * gtk_show_widget() the menu widget!! 
     * This is the menu that holds the menu items, the one that
     * will pop up when you click on the "Root Menu" in the app */
    for(i = 0; i < ROOT_MENU_COUNT; i++){
		menu[i] = gtk_menu_new ();
	}

    /* Next we make a little loop that makes three menu-entries for "test-menu".
     * Notice the call to gtk_menu_shell_append.  Here we are adding a list of
     * menu items to our menu.  Normally, we'd also catch the "clicked"
     * signal on each of the menu items and setup a callback for it,
     * but it's omitted here to save space. */

    for (i = 0; i < 4; i++){
			/* Copy the names to the buf. */
			sprintf (buf, "Test-undermenu - %d", i);

			/* Create a new menu-item with a name... */
			//menu_items = gtk_menu_item_new_with_label (buf);

			menu_items = gtk_radio_menu_item_new_with_label (group, "This is an example");
			group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (menu_items));
			/* ...and add it to the menu. */
			gtk_menu_shell_append (GTK_MENU_SHELL (menu[0]), menu_items);

			/* Do something interesting when the menuitem is selected */
			g_signal_connect_swapped (menu_items, "toggled",
					G_CALLBACK (menuitem_response_1), 
					(gpointer) g_strdup (buf));
			
            /* Show the widget */
            gtk_widget_show (menu_items);

		}
	for(i = 0; i < 4; i++){
			menu_items_ = gtk_menu_item_new_with_label (buf);
			/* ...and add it to the menu. */
			gtk_menu_shell_append (GTK_MENU_SHELL (menu[1]), menu_items_);

			/* Do something interesting when the menuitem is selected */
			g_signal_connect_swapped (menu_items_, "activate",
					G_CALLBACK (menuitem_response), 
					(gpointer) g_strdup (buf));
            /* Show the widget */
            gtk_widget_show (menu_items_);
	}

    /* This is the root menu, and will be the label
     * displayed on the menu bar.  There won't be a signal handler attached,
     * as it only pops up the rest of the menu when pressed. */
    root_menu[0] = gtk_menu_item_new_with_label ("Root Menu");
    root_menu[1] = gtk_menu_item_new_with_label ("Root Menu");

    gtk_widget_show (root_menu[0]);
    gtk_widget_show (root_menu[1]);

    /* Now we specify that we want our newly created "menu" to be the menu
     * for the "root menu" */
    gtk_menu_item_set_submenu (GTK_MENU_ITEM (root_menu[0]), menu[0]);
    gtk_menu_item_set_submenu (GTK_MENU_ITEM (root_menu[1]), menu[1]);

    /* A vbox to put a menu and a button in: */
//    vbox = gtk_vbox_new (FALSE, 0);
    
    vbox = gtk_vbox_new (FALSE, 0);
    gtk_container_add(GTK_CONTAINER (window), vbox);

    /* Create a menu-bar to hold the menus and add it to our main window */
//
//    menu_bar = gtk_menu_bar_new ();
//    gtk_box_pack_start (GTK_BOX (vbox), menu_bar, FALSE, FALSE, 2);
//	//gtk_box_reorder_child(GTK_BOX (vbox), menu_bar , order++);
//    gtk_widget_show (menu_bar);
//
//    //menu_bar_2 = gtk_menu_bar_new ();
//    //gtk_box_pack_start (GTK_BOX (vbox), menu_bar_2, FALSE, FALSE, 2);
//	////gtk_box_reorder_child(GTK_BOX (vbox), menu_bar_2 , 5);
//    //gtk_widget_show (me)u_bar_2);
//
//    /* Create a button to which to attach menu as a popup */
//	BUTTON_NEW_INTIALIZE_RANGE(button, 0, 3);
//	for(i = 0; i <= 3; i++){
//		g_signal_connect_swapped (button[i], "event",
//				G_CALLBACK (button_press), 
//				menu[0]);
//		gtk_box_pack_start (GTK_BOX (vbox), button[i], FALSE, TRUE, 2);
//		//gtk_box_reorder_child(GTK_BOX (vbox), button[i] , order++);
//		gtk_widget_show (button[i]);
//	}
//
//    gtk_box_pack_start (GTK_BOX (vbox_1), vbox, TRUE, TRUE, 0);
//    //gtk_box_reorder_child(GTK_BOX (vbox_1), vbox , order++);
//	
//	/* And finally we append the menu-item to the menu-bar -- this is the
//	 * "root" menu-item I have been raving about =) */
//	for(i = 0; i < 2; i++){
//		gtk_menu_shell_append (GTK_MENU_SHELL (menu_bar), root_menu[i]);
//	}
//
//

    order = 0;
    for (i = 0 ; i < 3; i++)
    {
        hbox_2[i] = gtk_hbox_new (FALSE, 10);
        gtk_box_pack_start(GTK_BOX (vbox), hbox_2[i], FALSE, FALSE, 0);
        //gtk_box_reorder_child(GTK_BOX (vbox), hbox_2[i], order++);
    }

    for (i = 0; i < 3; i++)
    {
        order = 0;
        for(j = 0; j < 3;j++){
            vbox_1[i][j] = gtk_vbox_new(FALSE, 0);
            gtk_box_pack_start(GTK_BOX (hbox_2[i]), vbox_1[i][j], FALSE, FALSE, 0);
            //gtk_box_reorder_child(GTK_BOX (hbox_2[i]), vbox_1[i][j], order++);
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            order = 0;
            for (k = 0; k < 3; k++)
            {
                hbox_1[i][j][k] = gtk_hbox_new(FALSE, 0);
                gtk_box_pack_start(GTK_BOX (vbox_1[i][j]), hbox_1[i][j][k], FALSE, FALSE, 0);
                //gtk_box_reorder_child(GTK_BOX (vbox_1[i][j]), hbox_1[i][j][k], order++);
            }
        }
    }

    for(i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            for (k = 0; k < 3; k++){
                order = 0;
                for (l = 0; l < 3; l++){
                    {
                        buffer[i][j][k][l] = gtk_entry_buffer_new (NULL, 0);
                        entry[i][j][k][l] = gtk_entry_new_with_buffer (buffer[i][j][k][l]);
                        gtk_box_pack_start(GTK_BOX (hbox_1[i][j][k]), entry[i][j][k][l], FALSE, FALSE, 0);
                        gtk_widget_set_size_request(entry[i][j][k][l], 60, 60);
                        //gtk_box_reorder_child(GTK_BOX (hbox_1[i][j][k]), entry[i][j][k][l] , order++);
                    }
                }
            }
        }
    }
    gtk_box_pack_start(GTK_BOX (vbox), hbuttonbox, TRUE, TRUE , 0);
//    gtk_widget_set_size_request(button, 20, 20);


    g_signal_connect (G_OBJECT(button[0]), "clicked",
            G_CALLBACK (button_0_press), 
            (gpointer)&buffer);
    gtk_button_set_label (GTK_BUTTON (button[0]), "start analysize!");

    g_signal_connect (G_OBJECT(button[1]), "clicked",
            G_CALLBACK (button_1_press), 
            (gpointer)&buffer);
    gtk_button_set_label (GTK_BUTTON (button[1]), "press me to see next!");

	/* always display the window as the last step so it all splashes on
	 * the screen at once. */
	gtk_widget_show_all (window);

	gtk_main ();

	return 0;
}

/* Respond to a button-press by posting a menu passed in as widget.
 *
 * Note that the "widget" argument is the menu being posted, NOT
 * the button that was pressed.
 */

static gboolean button_0_press(GtkWidget *button, GtkEntryBuffer* (*buffer)[][3][3][3])
{
    FILE *fp = NULL;
    int i,j,k,l;
    const gchar *str;
    if((fp = fopen("matrix.txt", "w")) == NULL){
        exit(1);        
    }
    fseek(fp, 0, SEEK_SET);
    for(i = 0 ; i < 3; i++)
        for(j = 0 ; j < 3; j++){
            for(k = 0 ; k < 3; k++){
                for(l = 0 ; l < 3; l++){
                    str = gtk_entry_buffer_get_text((*buffer)[i][k][j][l]);
                    g_printf("%c ", str[0]);
                    if(str[0] > '9' || str[0] < '0'){
                        fputc('.', fp);
                    }
                    else{
                        fputc(str[0], fp);
                    }
                }
            }
            fputc('\n', fp);
        }
    fclose(fp);
    system("./main");
    //	if (event->type == GDK_BUTTON_PRESS) {
//		GdkEventButton *bevent = (GdkEventButton *) event; 
//		gtk_menu_popup (GTK_MENU (widget), NULL, NULL, NULL, NULL,
//				bevent->button, bevent->time);
//		/* Tell calling code that we have handled this event; the buck
//		 * stops here. */
//		return TRUE;

	/* Tell calling code that we have not handled this event; pass it on. */
	return TRUE;
}

static gboolean button_1_press(GtkWidget *button, GtkEntryBuffer* (*buffer)[][3][3][3]){
    FILE *fp = NULL;
    int i,j,k,l;
    gchar ch;
    if((fp = fopen("result.txt", "r")) == NULL){
        exit(1);        
    }
    fseek(fp, 0, SEEK_SET);
    for(i = 0 ; i < 3; i++)
        for(j = 0 ; j < 3; j++){
            for(k = 0 ; k < 3; k++){
                for(l = 0 ; l < 3; l++){
                    ch = fgetc(fp);
                    if(ch > '9' || ch < '0'){
                        printf("failure!\n");
                        return FALSE;
                    }
                    else{
                        gtk_entry_buffer_set_text((*buffer)[i][k][j][l], &ch, 1);
                    }
                }
            }
            fgetc(fp);
        }
    fclose(fp);
    //fputc(' ', stdin);
    return TRUE;
}

/* Print a string when a menu item is selected */

static void menuitem_response(gchar *message)
{
	GtkWidget *dialog, *label, *content_area;

	printf("%s\n", __func__);
	/* Create the widgets */
	dialog = gtk_dialog_new_with_buttons ("Message",
			GTK_WINDOW (window),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_STOCK_OK,
			GTK_RESPONSE_NONE,
			NULL);
	content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
	label = gtk_label_new (message);
	/* Ensure that the dialog box is destroyed when the user responds. */
	g_signal_connect_swapped (dialog,
			"response",
			G_CALLBACK (gtk_widget_destroy),
			dialog);
	/* Add the label, and show:w everything we've added to the dialog. */
	gtk_container_add (GTK_CONTAINER (content_area), label);
	gtk_widget_show_all (dialog);
}

static void menuitem_response_1(gchar *message, GtkWidget *widget)
{
	if(gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM (widget))){
		printf("%s\n", __func__);
		menuitem_response(message);
	}
}
