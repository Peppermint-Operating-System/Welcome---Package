//Original copywrite Dolphin Oracle 2020 for the Peppermint Linux Project
//this one was for mark.

//this file is part of peppermint-welcome

#include <gtk/gtk.h>
#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

GtkWidget *g_image_title;
GtkWidget *g_label_main_text;
GtkWidget *g_button_app_one;
GtkWidget *g_button_app_two;
GtkWidget *g_button_app_three;
GtkWidget *g_button_app_four;
GtkWidget *g_button_back;
GtkWidget *g_button_next;
GtkWidget *g_button_close;
GtkWidget *g_image_screenshot;
int page_index;
void page_switch();

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
    
    //Setting the i18n environment
    setlocale (LC_ALL, "");
    bindtextdomain ("peppermint-welcome", "/usr/share/locale/");
    textdomain ("peppermint-welcome");

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("/usr/share/peppermint-welcome/glade/window_main.glade");
    //builder = gtk_builder_new_from_file("/home/dolphin/development/Welcome---Package/assets/glade/window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);
    
    // get pointers to the gui pieces
    g_image_title = GTK_WIDGET(gtk_builder_get_object(builder, "image_title"));
    g_label_main_text = GTK_WIDGET(gtk_builder_get_object(builder, "label_main_text"));
    g_button_app_one = GTK_WIDGET(gtk_builder_get_object(builder, "button_app_one"));
    g_button_app_two = GTK_WIDGET(gtk_builder_get_object(builder, "button_app_two"));
    g_button_app_three = GTK_WIDGET(gtk_builder_get_object(builder, "button_app_three"));
    g_button_app_four = GTK_WIDGET(gtk_builder_get_object(builder, "button_app_four"));
    g_button_back = GTK_WIDGET(gtk_builder_get_object(builder, "button_back"));
    g_button_next = GTK_WIDGET(gtk_builder_get_object(builder, "button_next"));
    g_button_close = GTK_WIDGET(gtk_builder_get_object(builder, "button_close"));
    g_image_screenshot = GTK_WIDGET(gtk_builder_get_object(builder, "image_screenshot"));

    g_object_unref(builder);
       
    page_index = 1;
    page_switch();

	system("rm ~/.config/autostart/peppermint-welcome-autostart.desktop 2>/dev/null");
    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}

//forward button
void on_button_next_clicked()
{
    page_index++;
    if (page_index == 6 ) {
        page_index = 5;
    }
    
    page_switch();
    
}

//back button
void on_button_back_clicked()
{

    page_index--;
    if (page_index == 0 ) {
        page_index = 1;
    }
    
    page_switch();
    
}

//close button
void on_button_close_clicked()
{

    gtk_main_quit();
    
}


void page_switch()
{
    GtkWidget *image;
    GtkWidget *image2;
    GtkWidget *image3;
    GtkWidget *image4;
    
    switch(page_index)
    {
        case 1:
        gtk_widget_hide(g_button_back);
        gtk_widget_hide(g_button_app_one);
        gtk_widget_hide(g_button_app_two);
        gtk_widget_hide(g_button_app_three);
        gtk_widget_hide(g_button_app_four);
        gtk_widget_hide(g_button_close);
        gtk_image_set_from_file(GTK_IMAGE(g_image_screenshot), "/usr/share/peppermint-welcome/glade/images/Peppermint.png");
        gtk_label_set_text(GTK_LABEL(g_label_main_text), _("Welcome to Peppermint OS! \n \nPeppermint is based on a Long Term Support (LTS) release schedule and provides a minimal set of preinstalled applications to get you started.  \n\nPeppermint gives the user the choice to shape their ideal linux operating system!"));
        break;
        
        case 2:
        gtk_widget_hide(g_button_app_one);
        gtk_widget_show(g_button_app_two);
        gtk_widget_hide(g_button_app_three);
        gtk_widget_hide(g_button_app_four);
        gtk_widget_show(g_button_back);
        gtk_widget_hide(g_button_close);
        gtk_image_set_from_file(GTK_IMAGE(g_image_screenshot), "/usr/share/peppermint-welcome/glade/images/peppermint-hub-screenshot.png");
        gtk_label_set_text(GTK_LABEL(g_label_main_text), _("The new Peppermint Hub makes it easier to access all your system settings in a tidy and familiar location."));
        image = gtk_image_new_from_file ("/usr/share/peppermint-welcome/glade/images/Peppermint-small.png");
        gtk_button_set_always_show_image (GTK_BUTTON (g_button_app_two), TRUE);
        gtk_button_set_image (GTK_BUTTON (g_button_app_two), image);
        gtk_button_set_label (GTK_BUTTON (g_button_app_two), "Hub");
        break;
        
        case 3:
        gtk_widget_hide(g_button_app_one);
        gtk_widget_show(g_button_app_two);
        gtk_widget_hide(g_button_app_three);
        gtk_widget_hide(g_button_app_four);
        gtk_widget_hide(g_button_close);
        gtk_image_set_from_file(GTK_IMAGE(g_image_screenshot), "/usr/share/peppermint-welcome/glade/images/ice-screenshot.png");
        gtk_label_set_text(GTK_LABEL(g_label_main_text), _("Part of the Peppermint magic is ICE SSB (Single Site Browsers).\n\nSet up your favorite web sites in ICE Single Site Browser instances and access them from the menu just like local applications!"));
        image = gtk_image_new_from_file ("/usr/share/peppermint-welcome/glade/images/ice-small.png");
        gtk_button_set_always_show_image (GTK_BUTTON (g_button_app_two), TRUE);
        gtk_button_set_image (GTK_BUTTON (g_button_app_two), image);
        gtk_button_set_label (GTK_BUTTON (g_button_app_two), "ICE SSB");
        break;
        
        case 4:
        gtk_widget_show(g_button_app_one);
        gtk_widget_show(g_button_app_two);
        gtk_widget_show(g_button_app_three);
        gtk_widget_show(g_button_app_four);
        gtk_widget_show(g_button_next);
        gtk_widget_hide(g_button_close);
        gtk_image_set_from_file(GTK_IMAGE(g_image_screenshot), "/usr/share/peppermint-welcome/glade/images/software-center-screenshot.png");
        gtk_label_set_text(GTK_LABEL(g_label_main_text), _("Yes, you can install traditional local applications.\n\nWe offer the traditional Synaptic Package Manager as well as the Snapcraft and flathub ICE-SSB instances to help you get the software you need!  \n\nMake your own software choices!"));
        image = gtk_image_new_from_icon_name ("synaptic", 32);
        image2= gtk_image_new_from_icon_name("softwarecenter-ubuntu", 32);
        image3= gtk_image_new_from_icon_name("softwarecenter-ubuntu", 32);
        image4= gtk_image_new_from_icon_name("softwarecenter-ubuntu", 32);
        gtk_button_set_always_show_image (GTK_BUTTON (g_button_app_one), TRUE);
        gtk_button_set_image (GTK_BUTTON (g_button_app_one), image);
        gtk_button_set_label (GTK_BUTTON (g_button_app_one), "Synaptic");
        gtk_button_set_always_show_image (GTK_BUTTON (g_button_app_three), TRUE);
        gtk_button_set_image (GTK_BUTTON (g_button_app_three), image2);
        gtk_button_set_label (GTK_BUTTON (g_button_app_three), "Snapcraft");
        gtk_button_set_always_show_image (GTK_BUTTON (g_button_app_two), TRUE);
        gtk_button_set_image (GTK_BUTTON (g_button_app_two), image3);
        gtk_button_set_label (GTK_BUTTON (g_button_app_two), "flathub");
        gtk_button_set_always_show_image (GTK_BUTTON (g_button_app_four), TRUE);
        gtk_button_set_image (GTK_BUTTON (g_button_app_four), image4);
        gtk_button_set_label (GTK_BUTTON (g_button_app_four), "appimages");
        break;
        
        case 5:
        gtk_widget_hide(g_button_next);
        gtk_widget_show(g_button_close);
        gtk_widget_show(g_button_app_one);
        gtk_widget_hide(g_button_app_two);
        gtk_widget_show(g_button_app_three);
        gtk_widget_hide(g_button_app_four);
        gtk_image_set_from_file(GTK_IMAGE(g_image_screenshot), "/usr/share/peppermint-welcome/glade/images/online-guide-screenshot.png");
        image = gtk_image_new_from_file ("/usr/share/peppermint-welcome/glade/images/Peppermint-small.png");
        gtk_button_set_always_show_image (GTK_BUTTON (g_button_app_one), TRUE);
        gtk_button_set_image (GTK_BUTTON (g_button_app_one), image);
        gtk_button_set_label (GTK_BUTTON (g_button_app_one), "Online Manual");
        image2 = gtk_image_new_from_file ("/usr/share/peppermint-welcome/glade/images/Peppermint-small.png");
        gtk_button_set_always_show_image (GTK_BUTTON (g_button_app_three), TRUE);
        gtk_button_set_image (GTK_BUTTON (g_button_app_three), image2);
        gtk_button_set_label (GTK_BUTTON (g_button_app_three), "Peppermint Forums");
        gtk_label_set_text(GTK_LABEL(g_label_main_text), _("If you need help, check out the Online Manual and the Peppermint Forums.\n\nThank you for joining us!"));
        break;
    }
}

void on_button_app_one_clicked()
{
    switch(page_index)
    {
        case 1:
        ;
        break;
        
        case 2:
        ;
        break;
        
        case 3:
        ;
        
        break;
        
        case 4:
        system("synaptic-pkexec &");
        break;
        
        case 5:
        system("ice-firefox http://peppermintos.com/guide/ &");
        break;
    }
}

void on_button_app_two_clicked()
{
    switch(page_index)
    {
        case 1:
        ;
        break;
        
        case 2:
        system("pephub.py &");
        break;
        
        case 3:
        system("ice &");
        break;
        
        case 4:
        system("ice-firefox https://snapcraft.io/store &");
        ;
        break;
        
        case 5:
        ;
        break;
    }
}
void on_button_app_three_clicked()
{
    switch(page_index)
    {
        case 1:
        ;
        break;
        
        case 2:
        ;
        break;
        
        case 3:
        ;
        break;
        
        case 4:
        system("ice-firefox https://flathub.org/home");
        ;
        break;
        
        case 5:
        system("ice-firefox https://forum.peppermintos.com/ &");
        break;
    }
}

void on_button_app_four_clicked()
{
    switch(page_index)
    {
        case 1:
        ;
        break;
        
        case 2:
        ;
        break;
        
        case 3:
        ;        
        break;
        
        case 4:
        system("ice-firefox https://appimage.github.io/apps/ &");
        break;
        
        case 5:
        ;
        break;
    }
}
