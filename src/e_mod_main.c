#include <e.h>
#include "e_mod_main.h"


/* gadcon requirements */
/*static E_Gadcon_Client *_gc_init(E_Gadcon *gc, const char *name, const char *id, const char *style);*/
/*static void _gc_shutdown(E_Gadcon_Client *gcc);*/
/*static void _gc_orient(E_Gadcon_Client *gcc, E_Gadcon_Orient orient);*/
/*static const char *_gc_label(const E_Gadcon_Client_Class *client_class);*/
/*static Evas_Object *_gc_icon(const E_Gadcon_Client_Class *client_class, Evas *evas);*/
/*static const char *_gc_id_new(const E_Gadcon_Client_Class *client_class);*/
/*static Config_Item *_conf_item_get(const char *id);*/

/* and actually define the gadcon class that this module provides (just 1) */
/*static const E_Gadcon_Client_Class _gadcon_class =*/
/*{*/
   /*GADCON_CLIENT_CLASS_VERSION,*/
   /*"Elive Helper",*/
   /*{*/
      /*_gc_init, _gc_shutdown, _gc_orient, _gc_label, _gc_icon, _gc_id_new, NULL, NULL*/
   /*},*/
   /*E_GADCON_CLIENT_STYLE_PLAIN*/
/*};*/
/**/
/***************************************************************************/

/***************************************************************************/
/*static void _elivehelper_cb_mouse_down(void *data, Evas *e, Evas_Object *obj, void *event_info);*/
/*static void _elivehelper_menu_cb_post(void *data, E_Menu *m);*/
/*static void _elivehelper_menu_cb_cfg(void *data, E_Menu *menu, E_Menu_Item *mi);*/
/*static void _cb_action_activate_ecomorph(void *data);*/
static void _cb_action_activate_ecomorph_expo(E_Object *obj, const char *params, int modifiers);
static void _cb_action_activate_ecomorph_scale(E_Object *obj, const char *params, int modifiers);
static void _cb_action_activate_ecomorph_opacity_increase(E_Object *obj, const char *params, int modifiers);
static void _cb_action_activate_ecomorph_opacity_decrease(E_Object *obj, const char *params, int modifiers);
/*static void _e_border_menu_cb_on_top(void *data, E_Menu *m, E_Menu_Item *mi);*/
/*static void _e_border_menu_cb_normal(void *data, E_Menu *m, E_Menu_Item *mi);*/
/*static void _e_border_menu_cb_below(void *data);*/
static void _cb_action_window_stacking_above_go(E_Object *obj, const char *params, int modifiers);
static void _cb_action_window_stacking_normal_go(E_Object *obj, const char *params, int modifiers);
static void _cb_action_window_stacking_below_go(E_Object *obj, const char *params, int modifiers);

static void _cb_action_window_locks(E_Object *obj, const char *params, int modifiers);
static void _cb_action_window_remembers(E_Object *obj, const char *params, int modifiers);
static void _cb_action_elive_help(E_Object *obj, const char *params, int modifiers);
/*static void _cb_action_activate_ecomorph(const char *params __UNUSED__)*/
/***************************************************************************/

/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
/**/
/* actual module specifics */

typedef struct _Instance Instance;

struct _Instance
{
   E_Gadcon_Client *gcc;
   Evas_Object     *logo;
   E_Gadcon_Popup  *popup;
   E_Menu          *menu;
   Config_Item     *cfg;
};


Config *elivehelper_config = NULL;
static E_Config_DD *conf_edd = NULL;
static E_Config_DD *conf_item_edd = NULL;
static E_Action *act;
static E_Action *act1;
static E_Action *act2;
static E_Action *act3;
static E_Action *act4;
static E_Action *act5;
static E_Action *act6;
static E_Action *act7;
static E_Action *act8;
static E_Action *act9;
static E_Action *act10;

/*static Eina_List *elivehelper_instances = NULL;*/
/*
 * This function is called when you add the Module to a Shelf or Gadgets, it
 * this is where you want to add functions to do things.
 */
/*static E_Gadcon_Client **/
/*_gc_init(E_Gadcon *gc, const char *name, const char *id, const char *style)*/
/*{*/
   /*Evas_Object *o;*/
   /*E_Gadcon_Client *gcc;*/
   /*Instance *inst;*/
   /*char buf[PATH_MAX];*/

   /*inst = E_NEW(Instance, 1);*/

   /*[>get plugin path<]*/
   /*snprintf(buf, sizeof(buf), "%s/elivehelper.edj",*/
           /*e_module_dir_get(elivehelper_config->module));*/

   /*o = edje_object_add(gc->evas);*/
   /*e_theme_edje_object_set(o, "base/theme/modules/elivehelper",*/
           /*"modules/elivehelper/main");*/
   /*edje_object_file_set(o,buf,"modules/elivehelper/main");*/
   /*edje_object_signal_emit(o, "e,state,unfocused", "e");*/
   /*evas_object_show (o);*/

   /*gcc = e_gadcon_client_new(gc, name, id, style, o);*/
   /*gcc->data = inst;*/

   /*inst->gcc = gcc;*/
   /*inst->logo = o;*/

   /*evas_object_event_callback_add(o, EVAS_CALLBACK_MOUSE_DOWN,*/
	 /*_elivehelper_cb_mouse_down, inst);*/

   /*elivehelper_config->instances =*/
       /*eina_list_append(elivehelper_config->instances, inst);*/

   /*return gcc;*/
/*}*/

/*
 * This function is called when you remove the Module from a Shelf or Gadgets,
 * what this function really does is clean up, it removes everything the module
 * displays
 */
/*static void*/
/*_gc_shutdown(E_Gadcon_Client *gcc)*/
/*{*/
   /*Instance *inst;*/

   /*inst = gcc->data;*/
   /*if (inst->menu)*/
     /*{*/
	/*e_menu_post_deactivate_callback_set(inst->menu, NULL, NULL);*/
	/*e_object_del(E_OBJECT(inst->menu));*/
	/*inst->menu = NULL;*/
     /*}*/
   /*evas_object_del(inst->logo);*/
   /*free(inst);*/
/*}*/

/*static void*/
/*_gc_orient(E_Gadcon_Client *gcc, E_Gadcon_Orient orient __UNUSED__)*/
/*{*/
    /*Instance *inst;*/
    /*Evas_Coord mw, mh;*/

    /*inst = gcc->data;*/
    /*mw = 0, mh = 0;*/
    /*edje_object_size_min_get(inst->logo, &mw, &mh);*/
    /*if ((mw < 1) || (mh < 1))*/
        /*edje_object_size_min_calc(inst->logo, &mw, &mh);*/
    /*if (mw < 4) mw = 4;*/
    /*if (mh < 4) mh = 4;*/
    /*e_gadcon_client_aspect_set(gcc, mw, mh);*/
    /*e_gadcon_client_min_size_set(gcc, mw, mh);*/
/*}*/

/*
 * This function sets the Gadcon name of the module, not to confuse this with
 * E_Module_Api
 */
/*static const char **/
/*_gc_label(const E_Gadcon_Client_Class *client_class __UNUSED__)*/
/*{*/
   /*return ("Elive Helper");*/
/*}*/

/*
 * This functions sets the Gadcon icon, the icon you see when you go to add
 * the module to a Shelf or Gadgets.
 */
/*static Evas_Object **/
/*_gc_icon(const E_Gadcon_Client_Class *client_class __UNUSED__, Evas *evas)*/
/*{*/
   /*Evas_Object *o;*/
   /*char buf[PATH_MAX];*/

   /*o = edje_object_add(evas);*/
   /*snprintf(buf, sizeof(buf), "%s/e-module-elivehelper.edj",*/
           /*e_module_dir_get(elivehelper_config->module));*/
   /*edje_object_file_set(o, buf, "icon");*/
   /*return o;*/
/*}*/

/*
 * This function sets the id for the module, so it can be unique from other
 * modules
 */
/*static const char **/
/*_gc_id_new(const E_Gadcon_Client_Class *client_class __UNUSED__)*/
/*{*/
    /*static char buf[PATH_MAX];*/

    /*snprintf(buf, sizeof(buf), "%s.%d", _gadcon_class.name,*/
            /*eina_list_count(elivehelper_config->instances) + 1);*/
    /*return buf;*/
/*}*/

static Config_Item *
_conf_item_get(const char *id)
{
    Config_Item *ci;

    /*GADCON_CLIENT_CONFIG_GET(Config_Item, elivehelper_config->items, _gadcon_class, id);*/

    ci = E_NEW(Config_Item, 1);
    ci->id = eina_stringshare_add(id);

    elivehelper_config->items = eina_list_append(elivehelper_config->items, ci);
    e_config_save_queue();

    return ci;
}

/*static void*/
/*_elivehelper_menu_cb_cfg(void *data, E_Menu *menu __UNUSED__, E_Menu_Item *mi __UNUSED__)*/
/*{*/
    /*Instance *inst = data;*/
    /*E_Container *con;*/

    /*if(inst->popup)*/
    /*{*/
        /*e_object_del(E_OBJECT(inst->popup));*/
        /*inst->popup = NULL;*/
    /*}*/
    /*con = e_container_current_get(e_manager_current_get());*/
    /*e_int_config_elivehelper_module(con, NULL);*/
/*}*/

/*static void*/
/*_elivehelper_cb_mouse_down(void *data, Evas *e __UNUSED__, Evas_Object *obj __UNUSED__, void *event_info)*/
/*{*/
    /*Instance *inst;*/
    /*Evas_Event_Mouse_Down *ev;*/

    /*inst = data;*/
    /*ev = event_info;*/
    /*if((ev->button == 1) && !(inst->menu))*/
    /*{*/
	    /*int x, y;*/

        /*inst->menu = e_int_menus_main_new();*/

        /*e_menu_post_deactivate_callback_set(inst->menu,*/
                /*_elivehelper_menu_cb_post, inst);*/

        /*e_gadcon_locked_set(inst->gcc->gadcon,1);*/
        /*e_gadcon_canvas_zone_geometry_get(inst->gcc->gadcon, &x, &y, NULL, NULL);*/

        /*e_menu_activate_mouse(inst->menu,*/
                /*e_util_zone_current_get(e_manager_current_get())*/
                /*, x + ev->output.x, y + ev->output.y,*/
                /*1, 1, E_MENU_POP_DIRECTION_AUTO, ev->timestamp);*/

        /*edje_object_signal_emit(inst->logo, "e,state,focused", "e");*/
    /*}*/
    /*else if ((ev->button == 3) && (!inst->menu))*/
    /*{*/
        /*E_Zone *zone;*/
        /*E_Menu *m;*/
        /*E_Menu_Item *mi;*/
        /*int x, y;*/

        /*zone = e_util_zone_current_get(e_manager_current_get());*/

        /*m = e_menu_new();*/
        /*mi = e_menu_item_new(m);*/
        /*e_menu_item_label_set(mi, "Settings");*/
        /*e_util_menu_item_theme_icon_set(mi, "configure");*/
        /*e_menu_item_callback_set(mi, _elivehelper_menu_cb_cfg, inst);*/
        /*m = e_gadcon_client_util_menu_items_append(inst->gcc, m, 0);*/
        /*e_menu_post_deactivate_callback_set(m, _elivehelper_menu_cb_post, inst);*/
        /*inst->menu = m;*/

        /*e_gadcon_canvas_zone_geometry_get(inst->gcc->gadcon, &x, &y, NULL, NULL);*/
        /*e_menu_activate_mouse(m, zone, x + ev->output.x, y + ev->output.y,*/
                              /*1, 1, E_MENU_POP_DIRECTION_AUTO, ev->timestamp);*/

        /*evas_event_feed_mouse_up(inst->gcc->gadcon->evas, ev->button,*/
                                 /*EVAS_BUTTON_NONE, ev->timestamp, NULL);*/
     /*}*/
/*}*/

/*
 * This function is a call-back it removes the menu after the use clicks on
 * a item in the menu or click of the menu, basically it removes the menu
 * from being displayed.
 */
/*static void*/
/*_elivehelper_menu_cb_post(void *data, E_Menu *m __UNUSED__)*/
/*{*/
    /*Instance *inst;*/

    /*inst = data;*/
    /*if(inst->menu)*/
    /*{*/
        /*edje_object_signal_emit(inst->logo, "e,state,unfocused", "e");*/
        /*e_object_del(E_OBJECT(inst->menu));*/
        /*inst->menu = NULL;*/
    /*}*/
/*}*/

/* This is needed to advertise a label for the module IN the code (not just
 * the .desktop file) but more specifically the api version it was compiled
 * for so E can skip modules that are compiled for an incorrect API version
 * safely) */
EAPI E_Module_Api e_modapi =
{
   E_MODULE_API_VERSION,
   "Elive Helper"
};

/*
 * This is the first function called by e17 when you click the enable button
 */
EAPI void *
e_modapi_init(E_Module *m)
{
    conf_item_edd = E_CONFIG_DD_NEW("Config_Item", Config_Item);
#undef T
#undef D
#define T Config_Item
#define D conf_item_edd
    E_CONFIG_VAL(D, T, id, STR);

    conf_edd = E_CONFIG_DD_NEW("Elive_Helper_Config", Config);
#undef T
#undef D
#define T Config
#define D conf_edd
    E_CONFIG_LIST(D, T, items, conf_item_edd);
    E_CONFIG_VAL(D, T, set, INT);

    elivehelper_config = e_config_domain_load("module.elivehelper", conf_edd);
    if(!elivehelper_config)
        elivehelper_config = E_NEW(Config, 1);

    elivehelper_config->module = m;
    /*e_gadcon_provider_register(&_gadcon_class);*/

   act1 = e_action_add("Eco_Expo_Initiate_Elive");
   if (act1)
     {
        act1->func.go = _cb_action_activate_ecomorph_expo;
        act1->func.go_key = _cb_action_activate_ecomorph_expo;
        act1->func.go_mouse = _cb_action_activate_ecomorph_expo;
        e_action_predef_name_set("Elive Helpers", "Desktops Organizer",
                                 "Eco_Expo_Initiate_Elive", NULL, NULL, 0);
     }

   act2 = e_action_add("Eco_Scale_Initiate_All_Elive");
   if (act2)
     {
        act2->func.go = _cb_action_activate_ecomorph_scale;
        act2->func.go_key = _cb_action_activate_ecomorph_scale;
        act2->func.go_mouse = _cb_action_activate_ecomorph_scale;
        e_action_predef_name_set("Elive Helpers", "Show all your windows",
                                 "Eco_Scale_Initiate_All_Elive", NULL, NULL, 0);
     }

   act3 = e_action_add("Eco_Opacity_Increase_Elive");
   if (act3)
     {
        act3->func.go = _cb_action_activate_ecomorph_opacity_increase;
        act3->func.go_key = _cb_action_activate_ecomorph_opacity_increase;
        act3->func.go_mouse = _cb_action_activate_ecomorph_opacity_increase;
        e_action_predef_name_set("Elive Helpers", "Transparency increase",
                                 "Eco_Opacity_Increase_Elive", NULL, NULL, 0);
     }

   act4 = e_action_add("Eco_Opacity_Decrease_Elive");
   if (act4)
     {
        act4->func.go = _cb_action_activate_ecomorph_opacity_decrease;
        act4->func.go_key = _cb_action_activate_ecomorph_opacity_decrease;
        act4->func.go_mouse = _cb_action_activate_ecomorph_opacity_decrease;
        e_action_predef_name_set("Elive Helpers", "Transparency decrease",
                                 "Eco_Opacity_Decrease_Elive", NULL, NULL, 0);
     }

   act5 = e_action_add("window_stacking_above");
   if (act5)
     {
        act5->func.go = _cb_action_window_stacking_above_go;
        act5->func.go_key = _cb_action_window_stacking_above_go;
        act5->func.go_mouse = _cb_action_window_stacking_above_go;
        e_action_predef_name_set("Elive Helpers", "Stacking Above",
                                 "window_stacking_above", NULL, NULL, 0);
     }

   act6 = e_action_add("window_stacking_normal");
   if (act6)
     {
        act6->func.go = _cb_action_window_stacking_normal_go;
        act6->func.go_key = _cb_action_window_stacking_normal_go;
        act6->func.go_mouse = _cb_action_window_stacking_normal_go;
        e_action_predef_name_set("Elive Helpers", "Stacking Normal",
                                 "window_stacking_normal", NULL, NULL, 0);
     }

   act7 = e_action_add("window_stacking_below");
   if (act7)
     {
        act7->func.go = _cb_action_window_stacking_below_go;
        act7->func.go_key = _cb_action_window_stacking_below_go;
        act7->func.go_mouse = _cb_action_window_stacking_below_go;
        e_action_predef_name_set("Elive Helpers", "Stacking Below",
                                 "window_stacking_below", NULL, NULL, 0);
     }

   act8 = e_action_add("window_locks");
   if (act8)
     {
        act8->func.go = _cb_action_window_locks;
        act8->func.go_key = _cb_action_window_locks;
        act8->func.go_mouse = _cb_action_window_locks;
        e_action_predef_name_set("Elive Helpers", "Window Locks",
                                 "window_locks", NULL, NULL, 0);
     }

   act9 = e_action_add("window_remembers");
   if (act9)
     {
        act9->func.go = _cb_action_window_remembers;
        act9->func.go_key = _cb_action_window_remembers;
        act9->func.go_mouse = _cb_action_window_remembers;
        e_action_predef_name_set("Elive Helpers", "Window Remembers",
                                 "window_remembers", NULL, NULL, 0);
     }

   act10 = e_action_add("elive_help");
   if (act10)
     {
        act10->func.go = _cb_action_elive_help;
        act10->func.go_key = _cb_action_elive_help;
        act10->func.go_mouse = _cb_action_elive_help;
        e_action_predef_name_set("Elive Helpers", "Elive Help",
                                 "elive_help", NULL, NULL, 0);
     }


   return m;
}

/*_cb_action_activate_ecomorph(const char *params __UNUSED__)*/
/*_cb_action_activate_ecomorph(void *data)*/
static void
_cb_action_activate_ecomorph_expo(E_Object *obj, const char *params, int modifiers)
{
   /*printf("ooooooooo\n");*/
   /*e_util_dialog_show(_("Trigger"),*/
                      /*_("Action triggered, yepeeee"));*/

   E_Module *m;
   E_Action *a;

   m = e_module_find("ecomorph");

   if( !(m) || !(e_module_enabled_get(m)))
     {
         // run ecomorph launcher or suggest to enable it
        if (ecore_file_exists("/usr/bin/ecomorph-launcher"))
          ecore_exe_run("/usr/bin/ecomorph-launcher", NULL);
        else
          e_util_dialog_show(_("Ecomorph is not running"),
                             _("Please enable the emodule Ecomorph first"));

        return;
     }

   a = e_action_find("Eco_Expo_Initiate");
   if ((a) && (a->func.go))
     {
        a->func.go(NULL, "1 2 0 0 0");
     }
   else
     printf("E: 'Eco_Expo_Initiate' not found\n");

}

static void
_cb_action_activate_ecomorph_scale(E_Object *obj, const char *params, int modifiers)
{
   /*printf("ooooooooo\n");*/
   /*e_util_dialog_show(_("Trigger"),*/
                      /*_("Action triggered, yepeeee"));*/

   E_Module *m;
   E_Action *a;

   m = e_module_find("ecomorph");

   if( !(m) || !(e_module_enabled_get(m)))
     {
         // run ecomorph launcher or suggest to enable it
        if (ecore_file_exists("/usr/bin/ecomorph-launcher"))
          ecore_exe_run("/usr/bin/ecomorph-launcher", NULL);
        else
          e_util_dialog_show(_("Ecomorph is not running"),
                             _("Please enable the emodule Ecomorph first"));

        return;
     }

   a = e_action_find("Eco_Scale_Initiate_All");
   if ((a) && (a->func.go))
     {
        a->func.go(NULL, "1 0 0 1 0");
     }
   else
     printf("E: 'Eco_Scale_Initiate_All' not found\n");

}

static void
_cb_action_activate_ecomorph_opacity_increase(E_Object *obj, const char *params, int modifiers)
{
   /*printf("ooooooooo\n");*/
   /*e_util_dialog_show(_("Trigger"),*/
                      /*_("Action triggered, yepeeee"));*/

   E_Module *m;
   E_Action *a;

   m = e_module_find("ecomorph");

   if( !(m) || !(e_module_enabled_get(m)))
     {
         // run ecomorph launcher or suggest to enable it
        if (ecore_file_exists("/usr/bin/ecomorph-launcher"))
          ecore_exe_run("/usr/bin/ecomorph-launcher", NULL);
        else
          e_util_dialog_show(_("Ecomorph is not running"),
                             _("Please enable the emodule Ecomorph first"));

        return;
     }

   a = e_action_find("Eco_Opacity_Increase");
   if ((a) && (a->func.go))
     {
        a->func.go(NULL, "2 8 0 0 1");
     }
   else
     printf("E: 'Eco_Opacity_Increase' not found\n");

}


static void
_cb_action_activate_ecomorph_opacity_decrease(E_Object *obj, const char *params, int modifiers)
{
   /*printf("ooooooooo\n");*/
   /*e_util_dialog_show(_("Trigger"),*/
                      /*_("Action triggered, yepeeee"));*/

   E_Module *m;
   E_Action *a;

   m = e_module_find("ecomorph");

   if( !(m) || !(e_module_enabled_get(m)))
     {
         // run ecomorph launcher or suggest to enable it
        if (ecore_file_exists("/usr/bin/ecomorph-launcher"))
          ecore_exe_run("/usr/bin/ecomorph-launcher", NULL);
        else
          e_util_dialog_show(_("Ecomorph is not running"),
                             _("Please enable the emodule Ecomorph first"));

        return;
     }

   a = e_action_find("Eco_Opacity_Decrease");
   if ((a) && (a->func.go))
     {
        a->func.go(NULL, "2 8 0 0 2");
     }
   else
     printf("E: 'Eco_Opacity_Decrease' not found\n");

}

/*static void*/
/*_e_border_menu_cb_on_top(void *data, E_Menu *m __UNUSED__, E_Menu_Item *mi __UNUSED__)*/
/*{*/
   /*E_Border *bd;*/

   /*bd = data;*/
   /*if (bd->layer != E_LAYER_ABOVE)*/
     /*e_border_layer_set(bd, E_LAYER_ABOVE);*/
/*}*/

static void _cb_action_window_stacking_above_go(E_Object *obj, const char *params, int modifiers)
{
   if (!obj) obj = E_OBJECT(e_border_focused_get());
   if (!obj) return;
   if (obj->type != E_BORDER_TYPE)
     {
        obj = E_OBJECT(e_border_focused_get());
        if (!obj) return;
     }

   E_Border *bd;
   bd = (E_Border *)obj;

   if (bd->layer != E_LAYER_ABOVE)
     e_border_layer_set(bd, E_LAYER_ABOVE);
}

static void _cb_action_window_stacking_normal_go(E_Object *obj, const char *params, int modifiers)
{
   if (!obj) obj = E_OBJECT(e_border_focused_get());
   if (!obj) return;
   if (obj->type != E_BORDER_TYPE)
     {
        obj = E_OBJECT(e_border_focused_get());
        if (!obj) return;
     }

   E_Border *bd;
   bd = (E_Border *)obj;

   if (bd->layer != E_LAYER_NORMAL)
     e_border_layer_set(bd, E_LAYER_NORMAL);
}

static void _cb_action_window_stacking_below_go(E_Object *obj, const char *params, int modifiers)
{
   if (!obj) obj = E_OBJECT(e_border_focused_get());
   if (!obj) return;
   if (obj->type != E_BORDER_TYPE)
     {
        obj = E_OBJECT(e_border_focused_get());
        if (!obj) return;
     }

   E_Border *bd;
   bd = (E_Border *)obj;

   if (bd->layer != E_LAYER_BELOW)
     e_border_layer_set(bd, E_LAYER_BELOW);
}

static void _cb_action_window_locks(E_Object *obj, const char *params, int modifiers)
{
   if (!obj) obj = E_OBJECT(e_border_focused_get());
   if (!obj) return;
   if (obj->type != E_BORDER_TYPE)
     {
        obj = E_OBJECT(e_border_focused_get());
        if (!obj) return;
     }

   E_Border *bd;

   bd = (E_Border *)obj;
   if (bd->border_locks_dialog)
     {
        e_border_desk_set(bd->border_locks_dialog->dia->win->border, bd->desk);
        e_win_raise(bd->border_locks_dialog->dia->win);
        e_border_focus_set(bd->border_locks_dialog->dia->win->border, 1, 1);
        return;
     }
   e_int_border_locks(bd);
}

static void _cb_action_window_remembers(E_Object *obj, const char *params, int modifiers)
{
   if (!obj) obj = E_OBJECT(e_border_focused_get());
   if (!obj) return;
   if (obj->type != E_BORDER_TYPE)
     {
        obj = E_OBJECT(e_border_focused_get());
        if (!obj) return;
     }

   E_Border *bd;

   bd = (E_Border *)obj;
   if (bd->border_remember_dialog)
     {
        e_border_desk_set(bd->border_remember_dialog->dia->win->border, bd->desk);
        e_win_raise(bd->border_remember_dialog->dia->win);
        e_border_focus_set(bd->border_remember_dialog->dia->win->border, 1, 1);
        return;
     }
   e_int_border_remember(bd);
}

static void _cb_action_elive_help(E_Object *obj, const char *params, int modifiers)
{
   if (ecore_file_exists("/usr/bin/elive-help"))
     ecore_exe_run("/usr/bin/elive-help", NULL);
   else
     e_util_dialog_show(_("Elive Help not installed"),
                        _("Please install the package elive-help first"));

}

/*static void*/
/*_e_border_menu_cb_normal(void *data, E_Menu *m __UNUSED__, E_Menu_Item *mi __UNUSED__)*/
/*{*/
   /*E_Border *bd;*/

   /*bd = data;*/
   /*if (bd->layer != E_LAYER_NORMAL)*/
     /*e_border_layer_set(bd, E_LAYER_NORMAL);*/
/*}*/


static int config_module_enable_get(const char *name)
{
   E_Module *m;
   if(!name) return -1;

   m = e_module_find(name);
   if((m) && (e_module_enabled_get(m)))
      return 1;

   return 0;
}

static void config_module_unload_set(const char *name)
{
   E_Module *m;
   if(!name) return;

   m = e_module_find(name);
   if((m) && (e_module_enabled_get(m)))
     {
        e_module_disable(m);
     }
}

static void config_module_load_set(const char *name)
{
   E_Module *m;
   if(!name) return;

   m = e_module_find(name);
   if(m)
     {
        e_module_enable(m);
     }
}

/*
 * This function is called by e17 when you disable the module, in e_modapi_shutdown
 * you should try to free all resources used while the module was enabled.
 */
EAPI int
e_modapi_shutdown(E_Module *m __UNUSED__)
{
    Config_Item *ci;

    /*e_gadcon_provider_unregister(&_gadcon_class);*/

    if (act1)
      {
         e_action_predef_name_del("Elive Helpers", "Eco_Expo_Initiate_Elive");
         e_action_del("Eco_Expo_Initiate_Elive");
         act1 = NULL;
      }
    if (act2)
      {
         e_action_predef_name_del("Elive Helpers", "Eco_Scale_Initiate_ALL_Elive");
         e_action_del("Eco_Scale_Initiate_All_Elive");
         act2 = NULL;
      }
    if (act3)
      {
         e_action_predef_name_del("Elive Helpers", "Eco_Opacity_Increase_Elive");
         e_action_del("Eco_Opacity_Increase_Elive");
         act3 = NULL;
      }
    if (act4)
      {
         e_action_predef_name_del("Elive Helpers", "Eco_Opacity_Decrease_Elive");
         e_action_del("Eco_Opacity_Decrease_Elive");
         act4 = NULL;
      }
    if (act5)
      {
         e_action_predef_name_del("Elive Helpers", "window_stacking_above");
         e_action_del("window_stacking_above");
         act5 = NULL;
      }
    if (act6)
      {
         e_action_predef_name_del("Elive Helpers", "window_stacking_normal");
         e_action_del("window_stacking_normal");
         act6 = NULL;
      }
    if (act7)
      {
         e_action_predef_name_del("Elive Helpers", "window_stacking_below");
         e_action_del("window_stacking_below");
         act7 = NULL;
      }
    if (act8)
      {
         e_action_predef_name_del("Elive Helpers", "window_locks");
         e_action_del("window_locks");
         act8 = NULL;
      }

    if (act9)
      {
         e_action_predef_name_del("Elive Helpers", "window_remembers");
         e_action_del("window_remembers");
         act9 = NULL;
      }

    if (act10)
      {
         e_action_predef_name_del("Elive Helpers", "elive_help");
         e_action_del("elive_help");
         act10 = NULL;
      }




    if(elivehelper_config)
    {
        elivehelper_config->module = NULL;
        elivehelper_config->instances = NULL;

        EINA_LIST_FREE(elivehelper_config->items, ci)
        {
            eina_stringshare_del(ci->id);
            free(ci);
        }
        E_FREE(elivehelper_config);
        elivehelper_config = NULL;
   }
   E_CONFIG_DD_FREE(conf_edd);
   E_CONFIG_DD_FREE(conf_item_edd);
   conf_edd = NULL;
   conf_item_edd = NULL;

   return 1;
}

/*
 * e_modapi_save is used to save and store configuration info on local
 * storage
 */
EAPI int
e_modapi_save(E_Module *m __UNUSED__)
{
   return 1;
}

/**/
/***************************************************************************/

